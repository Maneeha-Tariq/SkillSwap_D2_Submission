using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyFirstApplication
{
    internal class StudentManagementSystem
    {
        string rollno;
        string name;
        int age;
        double marks;
        internal void input()
        {
            Console.WriteLine("Enter name of student: ");
            name = Console.ReadLine();
            Console.WriteLine("Enter your age: ");
            age = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter your rollno: ");
            rollno = Console.ReadLine();
            Console.WriteLine("Enter your marks: ");
            marks = double.Parse(Console.ReadLine());
        }
        internal void AddStudentUsingByteOrientedStream()
        {
            FileStream fs = new FileStream("student.txt",FileMode.Append);
            for(int i=0;i<rollno.Length;i++)
            {
                fs.WriteByte((byte)rollno[i]);
            }
            char c = ',';
            fs.WriteByte((byte)c);
            for (int i = 0; i < name.Length; i++)
            {
                fs.WriteByte((byte)name[i]);
            }
            fs.WriteByte((byte)c);
            string ageStr = age.ToString();
            foreach(char ch in ageStr)
            {
                fs.WriteByte((byte)ch);
            }
            fs.WriteByte((byte)c);
            string marksStr = marks.ToString();
            foreach(char ch in marksStr)
            {
                fs.WriteByte((byte)ch);
            }
            char nline = '\n';
            fs.WriteByte((byte)nline);
            fs.Close();
        }   
        internal void AddStudentUsingCharacterOrientedStream()
        {
            FileStream fs = new FileStream("student.txt", FileMode.Append);
            using(StreamWriter sw = new StreamWriter(fs))
            {
                sw.Write(rollno);
                sw.Write(',');
                sw.Write(name);
                sw.Write(',');
                sw.Write(age);
                sw.Write(',');
                sw.Write(marks);
                sw.Write('\n');
            }
        }
        internal void ViewAllStudentsUsingCharacterOrientedStream()
        {
            FileStream fs = new FileStream("student.txt", FileMode.Open);
            using (StreamReader sr = new StreamReader(fs))
            {
                string line;
                while((line = sr.ReadLine())!=null)
                {
                    Console.WriteLine(line);
                }
            }
        }
        internal void ViewAllStudentsUsingByteOrientedStream()
        {
            FileStream fs = new FileStream("student.txt", FileMode.Open);
            int res;
            while((res=fs.ReadByte())!=-1)
            {
                Console.Write((char)res);
            }
            fs.Close();
        }
        internal void SearchStudentUsingCharacterOrientedStream(string rollno)
        {
            FileStream fs = new FileStream("student.txt", FileMode.Open);
            using(StreamReader sr = new StreamReader(fs))
            {
                string line;
                while((line = sr.ReadLine())!=null)
                {
                    string rno = "";
                    for(int i=0;i<line.Length&& line[i]!=',';i++)
                    {
                        rno += line[i];
                    }
                    if(rno == rollno)
                    {
                        Console.WriteLine("Student found and here are the details ");
                        Console.WriteLine(line);
                        return;
                    }
                }
                Console.WriteLine("Student not found");
            }
        }
        internal void SearchStudentUsingByteOrientedStream(string rollno)
        {
            FileStream fs = new FileStream("student.txt", FileMode.Open);
            int res;
            bool exists = false;
            string rno = "";
            while ((res = fs.ReadByte())!=-1)
            {
                char c = (char)res;
                if(c != ',' && !exists)
                {
                    rno += c;
                }
                else if(c == ',' && !exists)
                {
                    exists = true;
                    if(rno == rollno)
                    {
                        char rec = (char)fs.ReadByte();
                        string record = "";
                        while(rec!='\n' )
                        {
                            record += rec;
                            rec = (char)fs.ReadByte();
                        }

                        Console.WriteLine("Student found and here are the details ");
                        Console.Write(rno);
                        Console.Write(',');
                        Console.Write(record);
                        return;
                    }
                    else
                    {
                        exists = false;
                        rno = "";
                    }
                }
            }
            Console.WriteLine("Student not found");
        }

        static void Main(string[] args)
        {
            StudentManagementSystem sms = new StudentManagementSystem();
            sms.SearchStudentUsingByteOrientedStream("bsef24m046");
        }
    }
}
