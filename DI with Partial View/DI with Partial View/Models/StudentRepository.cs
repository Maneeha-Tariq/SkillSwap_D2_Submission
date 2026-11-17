namespace DI_with_Partial_View.Models
{
    public class StudentRepository:IStudentRepository
    {
        static List<Student> students = new List<Student>()
        {
            new Student{Id=1, Name="John Doe", Department="Computer Science"},
            new Student{Id=2, Name="Jane Smith", Department="Mathematics"},
            new Student{Id=3, Name="Michael Johnson", Department="Physics"}
        };

        public List<Student> GetAllStudents()
        {
            return students;
        }
        public void AddStudent(Student student )
        {
            students.Add(student);
        }
    }   
}
