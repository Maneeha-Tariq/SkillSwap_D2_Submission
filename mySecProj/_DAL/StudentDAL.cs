using System;
using System.Collections.Generic;
using System.Text;
using Business_Objects;
namespace _DAL
{
    public class StudentDAL
    {
        public void AddStudent(Student std)
        {
            StreamWriter sw = new StreamWriter("student.txt", true);
            string str = $"{std.Id},{std.Name},{std.Age},{std.Roll_Number}";
            sw.WriteLine(str);
            sw.Close();
        }
        public List<Student> ReadStudent()
        {
            StreamReader sr = new StreamReader("student.txt");
            string line = sr.ReadLine();
            List<Student> std = new List<Student>();
            while (line != null)
            {
                string[] arr = line.Split(',');
                Student b = new Student();
                b.Id = int.Parse(arr[0]);
                b.Name = arr[1];
                b.Age = int.Parse(arr[2]);
                b.Roll_Number = arr[3];
                std.Add(b);
                line = sr.ReadLine();
            }
            sr.Close();
            return std;
        }
    }
}
