using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text;
using Business_Objects;
using _DAL;

namespace ExecutionPoint
{
    internal class StudentMain
    {
        static void Main(string[] args)
        {
            Student stud = new Student();
            stud.Id = 1;
            stud.Name = "John Doe";
            stud.Age = 20;
            stud.Roll_Number = "12345";

            StudentDAL stuDAL = new StudentDAL();
            stuDAL.AddStudent(stud);

            List<Student> students = stuDAL.ReadStudent();
            foreach (Student s in students)
            {
                Console.WriteLine($"{s.Id}, {s.Name}, {s.Age}, {s.Roll_Number}");
            }
        }
    }
}
