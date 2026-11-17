using DapperPractice.Models.Interface;
using Microsoft.Data.SqlClient;
using Dapper;

namespace DapperPractice.Models.Repository
{
    public class StudentRepository: IStudentRepository
    {
        string connStr= "Server=localhost;Database=Studentdb;User Id=sa;Password=your_password;TrustServerCertificate=True;";
        SqlConnection conn;
        // GET ALL STUDENTS
        public List<Student> GetAllStudents()
        {
            conn = new SqlConnection(connStr);
            string query = "SELECT * FROM Students";

            return conn.Query<Student>(query).ToList();
        }

        // GET STUDENT BY ID
        public Student GetStudentById(int id)
        {
            conn = new SqlConnection(connStr);
            string query = "SELECT * FROM Students WHERE Id = @Id";

            return conn.QueryFirstOrDefault<Student>(query, new { Id = id });
        }

        // INSERT STUDENT
        public void AddStudent(Student student)
        {
            conn = new SqlConnection(connStr);

            string query = @"INSERT INTO Students
                             (Name, Age, Department)
                             VALUES
                             (@Name, @Age, @Department)";

            conn.Execute(query, student);
        }

        // UPDATE STUDENT
        public void UpdateStudent(Student student)
        {
            conn = new SqlConnection(connStr);

            string query = @"UPDATE Students
                             SET Name = @Name,
                                 Age = @Age,
                                 Department = @Department
                             WHERE Id = @Id";

            conn.Execute(query, student);
        }

        // DELETE STUDENT
        public void DeleteStudent(int id)
        {
            conn = new SqlConnection(connStr);

            string query = "DELETE FROM Students WHERE Id = @Id";

            conn.Execute(query, new { Id = id });
        }
    
    }

}
