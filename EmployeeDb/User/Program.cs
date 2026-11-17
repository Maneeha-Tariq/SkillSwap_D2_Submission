using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Data.SqlClient;

namespace User
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //string connStr = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=UserDb;Integrated Security=True;";
            //SqlConnection conn = new SqlConnection(connStr);
            //Console.WriteLine("Enter username: ");
            //string username = Console.ReadLine();
            //Console.WriteLine("Enter password: ");
            //string pass = Console.ReadLine();
            ////string query = "SELECT * FROM USERS WHERE USERNAME = '" + username + "' and PASSWORD = '" + pass + "'";
            ////string query = $"SELECT * FROM USERS WHERE USERNAME = @use and PASSWORD = @pas";
            //string query = $"INSERT INTO USERS(Username,Password) VALUES(@use,@pas)";
            //SqlCommand cmd = new SqlCommand(query, conn);
            //cmd.Parameters.AddWithValue("@use", username);
            //cmd.Parameters.AddWithValue("@pas", pass);
            //conn.Open();
            ////Console.WriteLine(query);
            ////SqlDataReader sr = cmd.ExecuteReader();
            ////if(sr.Read())
            ////{
            ////    Console.WriteLine("Login successful");
            ////}
            ////else
            ////{
            ////    Console.WriteLine("Login Failed");
            ////}
            //cmd.ExecuteNonQuery();
            //conn.Close();

            //Transaction
            //string connStr = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=UserDb;Integrated Security=True;";
            //SqlConnection conn = new SqlConnection(connStr);
            //string query1 = $"UPDATE ACCOUNTS SET BALANCE = Balance - 200 WHERE ACCOUNTName = @name1";
            //string query2 = $"UPDATE ACCOUNTS SET BALANCE = Balance + 200 WHERE ACCOUNTName = @name2 ";
            //SqlCommand cmd = new SqlCommand(query1, conn);
            //cmd.Parameters.AddWithValue("@name1", "Ali");
            //cmd.Parameters.AddWithValue("@name2", "Ahmed");
            //conn.Open();
            //SqlTransaction trans1 = conn.BeginTransaction();
            //cmd.Transaction = trans1;
            //try
            //{
            //    cmd.ExecuteNonQuery();
            //    cmd.CommandText = query2;
            //    cmd.ExecuteNonQuery();
            //    trans1.Commit();
            //}
            //catch(Exception ex)
            //{
            //    Console.WriteLine($"Error: {ex.Message}");
            //    trans1.Rollback();
            //}
            //conn.Close();

            //Transaction of order
            string connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=OrderDb;Integrated Security=True;";
            SqlConnection conn = new SqlConnection(connString);
            string query1 = $"SELECT STOCK FROM PRODUCTS WHERE NAME = 'Laptop' ";
            string query2 = $"SELECT STOCK FROM PRODUCTS WHERE NAME = 'Mouse' ";
            SqlCommand cmd = new SqlCommand(query1, conn);
            conn.Open();
            SqlTransaction trans1 = conn.BeginTransaction();
            cmd.Transaction = trans1;
           

            try
            {
                SqlDataReader sdr = cmd.ExecuteReader();
                if (sdr.Read() && ((Convert.ToInt32(sdr["Stock"]) >= 1)))
                {
                    string qu1 = $"UPDATE PRODUCTS SET STOCK = STOCK -1 WHERE NAME = 'LAPTOP' ";
                    sdr.Close();
                    cmd.CommandText = qu1;
                    cmd.ExecuteNonQuery();
                }
                else
                 throw new Exception("Insufficient stock");
                
                cmd.CommandText = query2;
                SqlDataReader sdr1 = cmd.ExecuteReader();
                if (sdr1.Read() && ((Convert.ToInt32(sdr1["Stock"]) >= 2)))
                {
                    string qu1 = $"UPDATE PRODUCTS SET STOCK = STOCK -2 WHERE NAME = 'Mouse' ";
                    sdr1.Close();
                    cmd.CommandText = qu1;
                    cmd.ExecuteNonQuery();
                }
                else
                 throw new Exception("Insufficient stock");
               
                trans1.Commit();

            }
            catch(Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
                trans1.Rollback();
            }
            finally
            {
                conn.Close();
            }
        }
    }
}
