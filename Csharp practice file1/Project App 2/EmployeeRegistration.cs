using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_App_2
{
    internal class EmployeeRegistration
    {
        string name;
        int age;
        int salary;
        internal void input()
        {
            Console.WriteLine("Enter Name: ");
            name = Console.ReadLine();
            if (string.IsNullOrWhiteSpace(name))
            {
                throw new InvalidNameException();
            }
            foreach (char c in name)
            {
                if (char.IsDigit(c))
                {
                    throw new InvalidNameException();
                }
            }
            Console.WriteLine("Enter Age: ");
            age = int.Parse(Console.ReadLine());
            if (age < 18 ||  age > 60)
            {
                throw new InvalidAgeException();
            }
            Console.WriteLine("Enter Salary: ");
            salary = int.Parse(Console.ReadLine());
            if (salary < 15000)
            {
                throw new InvalidSalaryException();
            }
        }
        internal void display()
        {
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Age: " + age);
            Console.WriteLine("Salary: " + salary);
        }
        internal class InvalidNameException : ApplicationException
        {
            public InvalidNameException() : base("Name cannot be empty and must contain numbers.")
            {

            }
        }
        internal class InvalidAgeException : ApplicationException
        {
            public InvalidAgeException() : base("Age must be between 18 and 60.")
            {

            }
           
        }
        internal class InvalidSalaryException : ApplicationException
        {
            public InvalidSalaryException() : base("Salary must be at least 15000.")
            {

            }
        }
        internal class MainClass
        {
            internal static void Main(string[] args)
            {
                EmployeeRegistration emp = new EmployeeRegistration();
                try
                {
                    emp.input();
                }
                catch (InvalidNameException ex)
                {
                    Console.WriteLine(ex.Message);
                    return;
                }
                catch (InvalidAgeException ex)
                {
                    Console.WriteLine(ex.Message);
                    return;
                }
                catch (InvalidSalaryException ex)
                {
                    Console.WriteLine(ex.Message);
                    return;
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid input format.");
                    return;
                }
                catch (Exception ex)
                {
                    Console.WriteLine("An error occurred: " + ex.Message);
                    return;
                }
                emp.display();


                //ConsoleKeyInfo key = Console.ReadKey();

                //Console.WriteLine();
                //Console.WriteLine("You pressed: " + key.KeyChar);
            }
        }
    }
}
