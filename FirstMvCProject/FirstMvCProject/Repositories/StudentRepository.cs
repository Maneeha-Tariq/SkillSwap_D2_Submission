using Microsoft.Data.SqlClient;
using System.Data;
using FirstMvCProject.Models;
namespace FirstMvCProject.Repositories
{
    public class StudentRepository
    {
        const string connectionString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=AttendenceDb;Integrated Security=True;";
        SqlConnection conn = new SqlConnection(connectionString);
        SqlDataAdapter adptr;
        DataTable dt;


        public List<Student> ViewAllStudent()
        {
            string query = "SELECT * FROM STUDENTS";
            adptr = new SqlDataAdapter();
            adptr.SelectCommand = new SqlCommand(query, conn);
            dt = new DataTable();
            adptr.Fill(dt);
            List<Student> list = new List<Student>();
            foreach (DataRow row in dt.Rows)
            {
                Student std = new Student();
                std.StudentId = Convert.ToInt32(row["StudentId"]);
                std.StudentName = row["StudentName"].ToString();
                std.RegistrationNumber = row["RegistrationNumber"].ToString();
                std.Department = row["Department"].ToString();
                std.AttendancePercentage = Convert.ToDecimal(row["AttendancePercentage"]);
                list.Add(std);
            }
            return list;
        }
        public void AddStudent(Student std)
        {
            string query = "SELECT* FROM STUDENTS";
            adptr = new SqlDataAdapter();
            adptr.SelectCommand = new SqlCommand(query, conn);
            dt = new DataTable();
            adptr.Fill(dt);

            DataRow row = dt.NewRow();
            row["StudentName"] = std.StudentName;
            row["RegistrationNumber"] = std.RegistrationNumber;
            row["Department"] = std.Department;
            row["AttendancePercentage"] = std.AttendancePercentage;
            dt.Rows.Add(row);

            string query1 = $"INSERT INTO Students(StudentName,RegistrationNumber,Department,AttendancePercentage)" +
                $" VALUES(@name,@regno,@dept,@perc)";
            SqlCommand cmd = new SqlCommand(query1, conn);
            adptr.InsertCommand = cmd;
            adptr.InsertCommand.Parameters.Add("@name",SqlDbType.VarChar,100, "StudentName");
            adptr.InsertCommand.Parameters.Add("@regno", SqlDbType.VarChar, 100, "RegistrationNumber");
            adptr.InsertCommand.Parameters.Add("@dept", SqlDbType.VarChar, 50, "Department");

           var perc =  adptr.InsertCommand.Parameters.Add("@perc", SqlDbType.Decimal);
           perc.Precision = 5;
           perc.Scale = 2;
           perc.Value = std.AttendancePercentage;

            adptr.Update(dt);
        }
        public void UpdateStudent(int id, Student std)
        {
            string query = "SELECT* FROM STUDENTS";
            adptr = new SqlDataAdapter();
            adptr.SelectCommand = new SqlCommand(query, conn);
            dt = new DataTable();
            adptr.Fill(dt);

            DataRow[] row = dt.Select($"StudentId = {id}");
            if(row.Length>0)
            {
                row[0]["StudentName"] = std.StudentName;
                row[0]["RegistrationNumber"] = std.RegistrationNumber;
                row[0]["Department"] = std.Department;
                row[0]["AttendancePercentage"] = std.AttendancePercentage;
            }

            string query1 = $"UPDATE Students SET StudentName=@name, RegistrationNumber=@regno, Department=@dept, AttendancePercentage=@perc WHERE StudentId=@id";
            SqlCommand cmd = new SqlCommand(query1, conn);
            cmd.Parameters.AddWithValue("@name", std.StudentName);
            cmd.Parameters.AddWithValue("@regno", std.RegistrationNumber);
            cmd.Parameters.AddWithValue("@dept", std.Department);
            cmd.Parameters.AddWithValue("@perc", std.AttendancePercentage);
            cmd.Parameters.AddWithValue("@id", id);
            adptr.UpdateCommand = cmd;
            adptr.Update(dt);
        }
        public void DeleteStudent(int studentId)
        {
            string query = "SELECT* FROM STUDENTS";
            adptr = new SqlDataAdapter();
            adptr.SelectCommand = new SqlCommand(query, conn);
            dt = new DataTable();
            adptr.Fill(dt);
            DataRow[] row = dt.Select($"StudentId = {studentId}");
            if (row.Length > 0)
            {
                row[0].Delete();
            }
            string query1 = $"DELETE FROM Students WHERE StudentId=@id";
            SqlCommand cmd = new SqlCommand(query1, conn);
            cmd.Parameters.AddWithValue("@id", studentId);
            adptr.DeleteCommand = cmd;
            adptr.Update(dt);
        }
    }
}
