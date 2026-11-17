using Microsoft.Data.SqlClient;
using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryData
{
    public class MemberRepository
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
        public void AddMember(Member member)
        {
            string query =
                $"INSERT INTO Members(Name) VALUES(@mem)";

            SqlCommand cmd = helperConnOpen(query);
            cmd.Parameters.AddWithValue("@mem", member.Name);
            cmd.ExecuteNonQuery();
            helperConnClose();
        }
        public List<Member> GetAllMembers()
        {
            string query =
                $"SELECT * FROM Members";

            SqlCommand cmd = helperConnOpen(query);

            SqlDataReader s = cmd.ExecuteReader();
            List<Member> list = new List<Member>();
            while (s.Read())
            {
                Member p = new Member();
                p.MemberId = Convert.ToInt32(s["MemberId"]);
                p.Name = Convert.ToString(s["Name"]);

                list.Add(p);
            }
            s.Close();
            helperConnClose();
            return list;
        }
    }
}
