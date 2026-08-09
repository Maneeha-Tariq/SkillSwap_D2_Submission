using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_App_2
{
    internal class Student
    {
        int math; int english; int computer;int total;int obtainMarks;
        char grade;
        double percentage;
        internal void CalculateMarks()
        {
            Console.Write("Enter Math Marks: ");
            math = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter English Marks: ");
            english = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter Computer Marks: ");
            computer = Convert.ToInt32(Console.ReadLine());
        }
        internal void calculateTotal()
        {
            total = 3 * 100;
            Console.WriteLine("Total marks are: " + total);
            obtainMarks = math + english + computer;
            Console.WriteLine("Obtain marks are: " + obtainMarks);
        }
        internal void CalculatePercentage()
        {
            percentage = (obtainMarks /(double) total) * 100;
            Console.WriteLine("Percentage = {0}%",percentage);
        }
        internal void CalculateGrade()
        {
            if(percentage<50)
            {
                grade = 'D';
                Console.WriteLine("Grade is " + grade);
            }
            else if(percentage >=50 && percentage<85)
            {
                grade = 'B';
                Console.WriteLine("Grade is " + grade);
            }
            else
            {
                grade = 'A';
                Console.WriteLine("Grade is " + grade);
            }
        }
        internal void DisplayResult()
        {
            if(grade == 'A')
            {
                Console.WriteLine("Student  passes with a grade of A");
            }
            else if(grade=='B')
            {
                Console.WriteLine("Student  passes with a grade of B");
            }
            else
            {
                Console.WriteLine("Student failed :( ");
            }
        }
        public delegate void StudentDelegate();
        internal static void Main(string[] args)
        {
            Student s = new Student();
            StudentDelegate sd = s.CalculateMarks;
            sd += s.calculateTotal;
            sd += s.CalculatePercentage;
            sd += s.CalculateGrade;
            sd += s.DisplayResult;
            sd();
            sd -= s.CalculateMarks;
            sd -= s.DisplayResult;
            sd();

        }
    }
}   
