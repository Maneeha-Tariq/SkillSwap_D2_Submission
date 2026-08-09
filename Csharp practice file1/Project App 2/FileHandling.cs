using Project_App_2;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static Project_App_2.FileHandling;
namespace Project_App_2
{
    internal class FileHandling
    {
        string name;
        int age;
        double CGPA;
        string path = "studentDetail3.txt";
        internal void input()
        {
            Console.WriteLine("Enter Name: ");
            name = Console.ReadLine();

            if (string.IsNullOrWhiteSpace(name))
                throw new NameInvalidException();


            foreach (char ch in name)
            {
                if (!char.IsLetter(ch) && ch != ' ')
                    throw new NameInvalidException();
            }

            Console.WriteLine("Enter Age: ");
            age = Convert.ToInt32(Console.ReadLine());

            if (age <= 0)
                throw new AgeNullException();

            Console.WriteLine("Enter CGPA: ");
            CGPA = Convert.ToDouble(Console.ReadLine());

            if (CGPA < 0.0 || CGPA > 4)
                throw new CGPAException();

        }
        internal void createFile()
        {
            if (!File.Exists(path))
            {
                File.Create(path).Close();
                Console.WriteLine("File Created Successfully");
            }
            else
            {
                Console.WriteLine("File already exists");
            }


        }
        internal void writeToFile()
        {

            using (StreamWriter sw = new StreamWriter(path))
            {
                sw.WriteLine($"Name = {name}");
                sw.WriteLine($"Age = {age}");
                sw.WriteLine($"CGPA = {CGPA}");
            }
        }
        internal void ReadFromFile()
        {
            try
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    while (!sr.EndOfStream)
                    {
                        string line = sr.ReadLine();
                        Console.WriteLine(line);
                    }
                }
            }
            catch (IOException e)
            {
                Console.WriteLine($"An I/O error occurred: {e.Message}");
            }
        }
        internal void CountLines()
        {
            try
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    int count = 0;
                    while (!sr.EndOfStream)
                    {
                        sr.ReadLine();
                        count++;
                    }
                    Console.WriteLine($"Total number of lines in the file: {count}");
                }
            }
            catch (IOException e)
            {
                Console.WriteLine($"An I/O error occurred: {e.Message}");
            }
        }
        internal void Delete()
        {
            try
            {
                File.Delete(path);
                Console.WriteLine("File deleted successfully.");
            }
            catch (IOException e)
            {
                Console.WriteLine($"An I/O error occurred: {e.Message}");
            }
        }
    }
        internal class NameInvalidException : ApplicationException
        {
            internal NameInvalidException() : base("Name cannot be empty and must contain only letters and spaces.")
            {

            }
        }
        internal class AgeNullException : ApplicationException
        {
            internal AgeNullException() : base("Age cannot be zero or negative")
            {

            }
        }
        internal class CGPAException : ApplicationException
        {
            internal CGPAException() : base("CGPA must be between 0.0 and 4.0")
            {
            }
        }
        internal class FMain
        {
            internal static void Main(string[] args)
            {
                FileHandling fh = new FileHandling();
                try
                {
                   fh.input();
                   fh.createFile();
                   fh.Delete();
                   fh.writeToFile();
                   fh.ReadFromFile();
                }
                catch (NameInvalidException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (AgeNullException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid input format");
                }
                catch (CGPAException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (IOException e)
                {
                    Console.WriteLine($"An I/O error occurred: {e.Message}");
                }
            }
        }
    

}
