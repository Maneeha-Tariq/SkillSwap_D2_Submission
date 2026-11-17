using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyFirstApplication
{
    internal class CharacterOriented
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Enter name of a student: ");
            //string name = Console.ReadLine();
            //Console.WriteLine("Enter age of a student: ");
            //int age = int.Parse(Console.ReadLine());
            //Console.WriteLine("Enter Department of a student: ");
            //string dept= Console.ReadLine();
            //FileStream fs = new FileStream("student.txt", FileMode.Create);
            //StreamWriter sw = new StreamWriter(fs);
            //sw.WriteLine(name);
            //sw.WriteLine(age);
            //sw.WriteLine(dept);
            //sw.Close();
            //fs.Close();

            // Read from file
            //FileStream f = new FileStream("student.txt", FileMode.Open);
            //StreamReader sr = new StreamReader(f);
            //string line = sr.ReadLine();
            //while(line!=null)
            //{
            //    Console.WriteLine(line);
            //    line = sr.ReadLine();
            //}
            //sr.Close();
            //f.Close();

            //Read from file and print it in uppercase in console
            //FileStream fs = new FileStream("student.txt", FileMode.Open);
            //StreamReader sr = new StreamReader(fs);
            //string line = sr.ReadLine();
            //while(line!=null)
            //{
            //    Console.WriteLine(line.ToUpper());
            //    line = sr.ReadLine();
            //}
            //sr.Close();
            //fs.Close();

            // file analyzer print total characters vowels and total lines
            //FileStream fss = new FileStream("student.txt", FileMode.Open);
            //StreamReader srr = new StreamReader(fss);
            //int charCount = 0;
            //int totalLines = 0;
            //int totalVowels = 0;
            //string line = srr.ReadLine();
            //while(line!=null)
            //{
            //    for(int i=0;i<line.Length;i++)
            //    {
            //        if (line[i]!=' ')
            //        {
            //            charCount++; 
            //        }
            //        if (line[i] == 'a' || line[i] == 'e' || line[i]=='i'|| line[i] == 'o' || line[i]=='u'
            //            || line[i]=='A'|| line[i]=='E'|| line[i] == 'I' || line[i]=='O'|| line[i]=='U')
            //        {
            //            totalVowels++;
            //        }
            //    }
            //    totalLines++;
            //    line = srr.ReadLine();
            //}
            //Console.WriteLine($"Total no of characters in a file are {charCount}");
            //Console.WriteLine($"Total no of lines are {totalLines}");
            //Console.WriteLine($"Total no of vowel characters are {totalVowels}");
            //srr.Close();
            //fss.Close();

            // byte+character streams
            //FileStream fs = new FileStream("test.txt", FileMode.Create);
            //StreamWriter sw = new StreamWriter(fs);
            //sw.WriteLine("This is a character oriented file");
            //sw.WriteLine("I want to read it using the byte oriented streams");
            //sw.Close();
            //fs.Close();
            //read using byte stream
            FileStream ff = new FileStream("test.txt", FileMode.Open);
            int line = ff.ReadByte();
            while (line != -1)
            {
                Console.Write((char)line);
                line = ff.ReadByte();
            }
            ff.Close();

        }
    }
}
