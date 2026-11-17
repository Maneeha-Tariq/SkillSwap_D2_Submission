using Microsoft.Data.SqlClient;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
namespace LibraryData

{
    public class BookRepository
    {
        const string connectionString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=LibraryDb;Integrated Security=True";
        SqlConnection conn = new SqlConnection(connectionString);
        private SqlCommand helperConnOpen(string query)
        {
            SqlCommand cmd = new SqlCommand(query, conn);
            conn.Open();
            return cmd;
        }
        private void helperConnClose()
        {
            conn.Close();
        }
        public void AddBook(Book book)
        {
            string query =
                $"INSERT INTO BOOKS(Title,Author,Stock) VALUES({book.Title},{book.Author},{book.Stock})";

            SqlCommand cmd = helperConnOpen(query);
            cmd.ExecuteNonQuery();
            helperConnClose();
        }
        public List<Book> GetAllBooks()
        {
            string query =
                $"SELECT * FROM BOOKS";

            SqlCommand cmd = helperConnOpen(query);

            SqlDataReader s = cmd.ExecuteReader();
            List<Book> list = new List<Book>();
            while (s.Read())
            {
                Book p = new Book();
                p.Title = Convert.ToString(s["Title"]);
                p.Author = Convert.ToString(s["Author"]);
                p.Stock = Convert.ToInt32(s["Stock"]);

                list.Add(p);
            }
            helperConnClose();
            return list;
        }
        public void updateStock(int bookId, int stoc)
        {
            string query =
                $"Update BOOK SET Stock = @stk  WHERE BOOKID = @id";

            SqlCommand cmd = helperConnOpen(query);
            cmd.Parameters.AddWithValue("@stk", stoc);
            cmd.Parameters.AddWithValue("@id", bookId);
            cmd.ExecuteNonQuery();
            helperConnClose();
        }
        public void deleteBook(int bookId)
        {
            string query =
                $"Delete from Book where bookid = @bid";
            SqlCommand cmd = helperConnOpen(query);
            cmd.Parameters.AddWithValue("@bid", bookId);
            cmd.ExecuteNonQuery();
            helperConnClose();
        }
        public bool IssueBook(int bookId, int memberId)
        {
            string query =
                "Select * from books where bookid = @id ";
            SqlCommand sq = helperConnOpen(query);
           
            SqlTransaction trans = conn.BeginTransaction();
            sq.Transaction = trans;
            sq.Parameters.AddWithValue("@id", bookId);
            try
            {
                SqlDataReader sr = sq.ExecuteReader();
                if (sr.Read() && Convert.ToInt32(sr["Stock"]) > 0)
                {
                    updateStock(bookId, Convert.ToInt32(sr["Stock"]) - 1);
                    sr.Close();
                    string query1 =
                        "INSERT INTO ISSUEBOOK(BookId,MemberId,IssueDate) VALUES(@bid,@memid,@date)";

                    SqlCommand cmd = new SqlCommand(query1, conn);
                    cmd.Transaction = trans;
                    cmd.Parameters.AddWithValue("@bid", bookId);
                    cmd.Parameters.AddWithValue("@memid", memberId);
                    cmd.Parameters.AddWithValue("@date", DateTime.Now);
                    cmd.ExecuteNonQuery();
                    trans.Commit();
                    return true;
                }
                else
                {
                    sr.Close();
                    throw new Exception("Book can't be issued due to Out of Stock");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                trans.Rollback();
                return false;
            }
            finally
            {
                helperConnClose();
            }

        }
        public bool ReturnBook(int issueId)
        {
            string query =
                "SELECT BOOKID FROM ISSUEBOOK WHERE ISSUEID = @issue";
            SqlCommand sq = helperConnOpen(query);
            sq.Parameters.AddWithValue("@issue", issueId);
            SqlTransaction trans = conn.BeginTransaction();
            sq.Transaction = trans;
            try
            {
                SqlDataReader dr = sq.ExecuteReader();
                if (dr.Read())
                {
                    int book = Convert.ToInt32(dr["BookId"]);
                    dr.Close();
                    string q3 =
                           "SELECT STOCK FROM BOOKS WHERE BOOKID = @idd";
                    SqlCommand sqq = new SqlCommand(q3, conn);
                    sqq.Parameters.AddWithValue("@idd", book);
                    sqq.Transaction = trans;
                    SqlDataReader sdc = sqq.ExecuteReader();
                    if (sdc.Read())
                    {
                        int stock = Convert.ToInt32(sdc["Stock"]);
                        sdc.Close();
                        string query1 =
                       "UPDATE BOOKS SET STOCK = @stk WHERE BOOKID = @id";
                        SqlCommand cmd = new SqlCommand(query1, conn);
                        cmd.Transaction = trans;
                        cmd.Parameters.AddWithValue("@stk", stock + 1);
                        cmd.Parameters.AddWithValue("@id", book);
                        cmd.ExecuteNonQuery();
                    }
                    else
                    {
                        sdc.Close();
                        throw new Exception("Book not found");
                    }

                    string date =
                        "UPDATE ISSUEBOOK SET RETURNDATE = @d WHERE ISSUEID = @ide";
                    SqlCommand cmd1 = new SqlCommand(date, conn);
                    cmd1.Transaction = trans;
                    cmd1.Parameters.AddWithValue("@d", DateTime.Now);
                    cmd1.Parameters.AddWithValue("@ide", issueId);
                    cmd1.ExecuteNonQuery();

                    trans.Commit();
                    return true;
                }
                else
                {
                    dr.Close();
                    throw new Exception("Book have not issued yet");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                trans.Rollback();
                return false;
            }
            finally
            {
                helperConnClose();
            }

        }
    }
    public class BackupHelper
    {
        public void AddToFile(List<Book>book,string filePath)
        {
            FileStream fs = new FileStream(filePath, FileMode.Append);
            StreamWriter sw = new StreamWriter(fs);
            foreach(Book b in book)
            {
                string serStr = JsonSerializer.Serialize(b);
                sw.WriteLine(serStr);
            }
            sw.Close();
        }
        public List<Book> ReadFromFile(string filePath)
        {
            FileStream fs = new FileStream(filePath, FileMode.Open);
            StreamReader sr = new StreamReader(fs);
            List<Book> list = new List<Book>();
            string line = "";
            while((line = sr.ReadLine())!=null)
            {
                Book b = JsonSerializer.Deserialize<Book>(line);
                list.Add(b);
            }
            sr.Close();
            return list;
        }
    }
}
