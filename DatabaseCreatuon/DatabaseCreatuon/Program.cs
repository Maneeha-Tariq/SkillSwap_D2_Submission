using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Data.SqlClient;

namespace DatabaseCreation
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // read data from database 
            //string connectionString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=MyFirstDatabase;Integrated Security=True;";
            //SqlConnection conn = new SqlConnection(connectionString);
            //string query = "SELECT * FROM STUDENTS";
            //SqlCommand cmd = new SqlCommand(query, conn);
            //conn.Open();
            //SqlDataReader sr = cmd.ExecuteReader();
            //while(sr.Read())
            //{
            //    Console.WriteLine($"Id: {sr["Id"]}, Name: {sr["Name"]}, RollNum: {sr["RollNum"]}, Batch: {sr["Batch"]}");
            //}
            //conn.Close();
            // insert data into db
            //string connectionString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=MyFirstDatabase;Integrated Security=True;";
            //SqlConnection conn = new SqlConnection(connectionString);
            //Console.WriteLine("Enter name: ");
            //string name = Console.ReadLine();
            //Console.WriteLine("Enter rollno: ");
            //string rollno = Console.ReadLine();
            //Console.WriteLine("Enter batch: ");
            //string batch = Console.ReadLine();
            //string query = $"INSERT INTO STUDENTS(Name,RollNum,Batch) VALUES('{name}','{rollno}','{batch}')";
            //SqlCommand cmd = new SqlCommand(query, conn);
            //conn.Open();
            //int i =  cmd.ExecuteNonQuery();
            //Console.WriteLine($"{i} rows effected");
            //conn.Close();

            //update
            //string connectionString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=MyFirstDatabase;Integrated Security=True;";
            //SqlConnection conn = new SqlConnection(connectionString);
            //Console.WriteLine("Enter id to update");
            //int id = int.Parse(Console.ReadLine());
            //Console.WriteLine("Enter name: ");
            //string name = Console.ReadLine();
            //Console.WriteLine("Enter rollno: ");
            //string rollno = Console.ReadLine();
            //Console.WriteLine("Enter batch: ");
            //string batch = Console.ReadLine();
            //string query = $"UPDATE STUDENTS SET Name = '{name}',RollNum = '{rollno}',Batch = '{batch}' WHERE Id ={id}";
            //SqlCommand cmd = new SqlCommand(query, conn);
            //conn.Open();
            //int i = cmd.ExecuteNonQuery();
            //Console.WriteLine($"{i} rows effected");
            //conn.Close();

            // delete
            string connectionString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=MyFirstDatabase;Integrated Security=True;";
            SqlConnection conn = new SqlConnection(connectionString);
            Console.WriteLine("Enter id to delete");
            int id = int.Parse(Console.ReadLine());
            string query = $"DELETE FROM STUDENTS WHERE Id = {id}";
            SqlCommand cmd = new SqlCommand(query, conn);
            conn.Open();
            int i = cmd.ExecuteNonQuery();
            Console.WriteLine($"{i} rows effected");
            conn.Close();


        }
    }
}
