using Business_Object;
using Microsoft.Data.SqlClient;

namespace EmployeeDAL
{
    public class Employeedal
    {
        const string connectionStr = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=EmployeeDb;Integrated Security=True;";
      
        public void AddEmployee(Employee emp)
        {
            FileStream fs = new FileStream("employee_log.txt",FileMode.Append);
            StreamWriter sw = new StreamWriter(fs);
            SqlConnection conn = new SqlConnection(connectionStr);
            string query = $"INSERT INTO EMPLOYEES(Name,Department,Salary,Email) VALUES('{emp.Name}','{emp.Dept}',{emp._Salary},'{emp.Email}')";
            SqlCommand cmd = new SqlCommand(query, conn);
            conn.Open();
            cmd.ExecuteNonQuery();
            sw.WriteLine($"Employee Added | Name = {emp.Name}, Dept = {emp.Dept}");
            conn.Close();
        }
        public void UpdateEmployee(Employee emp)

        {
            FileStream fs = new FileStream("employee_log.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fs);
            SqlConnection conn = new SqlConnection(connectionStr);
            string query = $"UPDATE EMPLOYEES SET Name = '{emp.Name}',Department = '{emp.Dept}',Salary = {emp._Salary},Email = '{emp.Email}' WHERE Id = {emp.Id})";
            SqlCommand cmd = new SqlCommand(query, conn);
            conn.Open();
            cmd.ExecuteNonQuery();
            sw.WriteLine($"Employee Updated | Name = {emp.Name}");
            conn.Close();
        }
        public void SearchEmployee(int id)
        {
           
            SqlConnection conn = new SqlConnection(connectionStr);
            string query = $"SELECT * FROM EMPLOYEES WHERE Id = {id}";
            SqlCommand cmd = new SqlCommand(query, conn);
            conn.Open();
            SqlDataReader sr = cmd.ExecuteReader();
            if (sr.Read())
            {
                Console.WriteLine($"Id: {sr["Id"]}, Name: {sr["Name"]}, Dept: {sr["Department"]}, Salary: {sr["Salary"]},Email: {sr["Email"]}");
            }
            else
            {
                Console.WriteLine("No employee found with Id = " + id);
            }
            conn.Close();
        }
        public void DeleteEmployee(int id)
        {
            SqlConnection conn = new SqlConnection(connectionStr);
            string query = $"DELETE FROM STUDENTS WHERE Id = {id}";
            SqlCommand cmd = new SqlCommand(query, conn);
            conn.Open();
            cmd.ExecuteNonQuery();
            FileStream fs = new FileStream("employee_log.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fs);
            sw.WriteLine("Employee Deleted | Id = " + id);
            conn.Close();
        }
        public List<Employee> ViewAllEmployees()
        {
            SqlConnection conn = new SqlConnection(connectionStr);
            string query = $"SELECT * FROM EMPLOYEES";
            SqlCommand cmd = new SqlCommand(query, conn);
            conn.Open();
            SqlDataReader sr = cmd.ExecuteReader();
            List<Employee> list = new List<Employee>();
            while(sr.Read())
            {
                Employee emp = new Employee();
                emp.Id = Convert.ToInt32(sr["Id"]);
                emp.Name = Convert.ToString(sr["Name"]);
                emp.Dept = Convert.ToString(sr["Department"]);
                emp._Salary = Convert.ToInt32(sr["Salary"]);
                emp.Email = Convert.ToString(sr["Email"]);
                list.Add(emp);
            }
            conn.Close();

            return list;
        }

    }
}
