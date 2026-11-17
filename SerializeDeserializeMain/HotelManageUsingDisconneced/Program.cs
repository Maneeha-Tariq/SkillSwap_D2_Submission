using Microsoft.Data.SqlClient;
using System.Data;
using System.Data.Common;


namespace HotelManageUsingDisconnected
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string connStr = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HotelDb;Integrated Security=True;";
            // Move the database data to in memory table
            SqlConnection conn = new SqlConnection(connStr);
            string query = "SELECT* FROM ROOMS";
            SqlCommand cmd = new SqlCommand(query, conn);
            SqlDataAdapter adptr = new SqlDataAdapter();
            adptr.SelectCommand = cmd;
            DataTable dt = new DataTable();
            adptr.Fill(dt);
            foreach(DataRow row in dt.Rows)
            {
                Console.WriteLine
                (
                    $"{row["RoomId"]}," +
                    $"{row["RoomNumber"]}," +
                    $"{row["RoomType"]}," +
                    $"{row["PricePerNight"]}," +
                    $"{row["IsAvailable"]}"
                );
            }

            Console.WriteLine("===============================");
            Console.WriteLine("            INSERT             ");
            Console.WriteLine("===============================");
            // INSERT NEW ROW
            DataRow newRow = dt.NewRow();
            newRow["RoomNumber"] = 203;
            newRow["RoomType"] = "Deluxe";
            newRow["PricePerNight"] = 13000;
            newRow["IsAvailable"] = 1;
            dt.Rows.Add(newRow);

            // to save the inserted row into the database you have to write insert query
            string insertQuery = $"INSERT INTO ROOMS(RoomNumber,RoomType,PricePerNight,IsAvailable) VALUES(@no,@type,@price,@available)";
            adptr.InsertCommand = new SqlCommand(insertQuery, conn);
            adptr.InsertCommand.Parameters.Add("@no", SqlDbType.Int, 0, "RoomNumber");
            adptr.InsertCommand.Parameters.Add("@type", SqlDbType.VarChar, 100, "RoomType");
            adptr.InsertCommand.Parameters.Add("@price", SqlDbType.Int, 0, "PricePerNight");
            adptr.InsertCommand.Parameters.Add("@available", SqlDbType.Bit, 0, "IsAvailable");

            adptr.Update(dt);

            foreach (DataRow row in dt.Rows)
            {
                Console.WriteLine
                (
                    $"{row["RoomId"]}," +
                    $"{row["RoomNumber"]}," +
                    $"{row["RoomType"]}," +
                    $"{row["PricePerNight"]}," +
                    $"{row["IsAvailable"]}"
                );
            }

            Console.WriteLine("===============================");
            Console.WriteLine("            UPDATE             ");
            Console.WriteLine("===============================");
            DataRow[] search = dt.Select("RoomNumber = 102");
            if (search.Length > 0)
            {
                search[0]["PricePerNight"] = 9000;
                search[0]["IsAvailable"] = 0;
            }
            string updateQuery = $"UPDATE ROOMS SET PricePerNight = @prNight, IsAvailable = @avail WHERE RoomNumber = @rno";
            adptr.UpdateCommand = new SqlCommand(updateQuery, conn);
            adptr.UpdateCommand.Parameters.Add("@rno", SqlDbType.Int, 0, "RoomNumber");
            adptr.UpdateCommand.Parameters.Add("@prNight", SqlDbType.Int, 0, "PricePerNight");
            adptr.UpdateCommand.Parameters.Add("@avail", SqlDbType.Bit, 0, "IsAvailable");

            adptr.Update(dt);

            foreach (DataRow row in dt.Rows)
            {
                Console.WriteLine
                (
                    $"{row["RoomId"]}," +
                    $"{row["RoomNumber"]}," +
                    $"{row["RoomType"]}," +
                    $"{row["PricePerNight"]}," +
                    $"{row["IsAvailable"]}"
                );
            }
            Console.WriteLine("===============================");
            Console.WriteLine("            DELETE            ");
            Console.WriteLine("===============================");
            DataRow[] searchRoom = dt.Select("RoomNumber = 203");
            if (searchRoom.Length > 0)
            {
                int i = 0;
                while (i < searchRoom.Length)
                {
                    searchRoom[i].Delete();
                    i++;
                }
            }
            string deleteQuery = $"DELETE FROM ROOMS WHERE RoomNumber = @rno";
            adptr.DeleteCommand = new SqlCommand(deleteQuery, conn);
            adptr.DeleteCommand.Parameters.Add("@rno", SqlDbType.Int, 0, "RoomNumber");

            adptr.Update(dt);
            foreach (DataRow row in dt.Rows)
            {
                Console.WriteLine
                (
                    $"{row["RoomId"]}," +
                    $"{row["RoomNumber"]}," +
                    $"{row["RoomType"]}," +
                    $"{row["PricePerNight"]}," +
                    $"{row["IsAvailable"]}"
                );
            }
        }
    }
}
