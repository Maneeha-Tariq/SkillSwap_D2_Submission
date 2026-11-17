
using Microsoft.Data.SqlClient;

namespace TransactionPractice
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string connStr = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HotelDb;Integrated Security=True;";
            SqlConnection conn = new SqlConnection(connStr);
            string availQuery = 
                "SELECT * FROM ROOMS WHERE RoomNumber = @rno AND IsAvailable = 1";

            Console.Write("Enter Room number: ");
            int room = int.Parse(Console.ReadLine());
           
            Console.Write("Enter Customer name: ");
            string? name = Console.ReadLine();
          
            Console.Write("Enter Number of nights: ");
            int night = int.Parse(Console.ReadLine());

            SqlCommand cmd = new SqlCommand(availQuery,conn);
            cmd.Parameters.AddWithValue("@rno", room);
            conn.Open();
            SqlTransaction trans = conn.BeginTransaction();
            cmd.Transaction = trans;
            
            try
            {
                SqlDataReader sr = cmd.ExecuteReader();
                if(sr.Read())
                {
                    sr.Close();
                    string bookQuery = 
                        "INSERT INTO BOOKINGS(RoomNumber,CustomerName,Nights) VALUES(@roomNo,@Cname,@night)";

                    SqlCommand cmd1 = new SqlCommand(bookQuery, conn);
                    cmd1.Transaction = trans;
                    cmd1.Parameters.AddWithValue("@roomNo", room);
                    cmd1.Parameters.AddWithValue("@Cname", name);
                    cmd1.Parameters.AddWithValue("@night", night);
                    cmd1.ExecuteNonQuery();

                    string updateQuery = 
                        "UPDATE ROOMS SET IsAvailable = @available WHERE RoomNumber = @rno1";
                    SqlCommand cmd2 = new SqlCommand(updateQuery, conn);
                    cmd2.Transaction = trans;
                    bool avail = false;
                    cmd2.Parameters.AddWithValue("@available", avail);
                    cmd2.Parameters.AddWithValue("@rno1", room);
                    cmd2.ExecuteNonQuery();

                    trans.Commit();
                    Console.WriteLine("Booking successful!");
                }
                else
                {
                    Console.WriteLine(
                        $"Room Number {room} is not Available.You should book another one."
                    );
                    return;
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
                trans.Rollback();
            }

        }
    }
}
