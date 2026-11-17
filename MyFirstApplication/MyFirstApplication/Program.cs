using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.InteropServices;

namespace MyFirstApplication
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //byte oriented streams
            //char data = 'A';
            //FileStream fs = new FileStream("data.txt", FileMode.Create);
            //for (int i = 0; i < 26; i++)
            //{
            //    fs.WriteByte((byte)data);
            //    data = (char)(data + 1);
            //}
            //fs.Close();

            //FileStream f = new FileStream("data.txt", FileMode.Open);
            //int line = f.ReadByte();
            //while(line!=-1)
            //{
            //    Console.Write((char)line);
            //    line = f.ReadByte();
            //}
            //f.Close();

            //char oriented streams
            //string data = "This is a test";
            //FileStream fs = new FileStream("file.txt", FileMode.Create);
            //StreamWriter sw = new StreamWriter(fs);
            //sw.WriteLine(data);
            //sw.Close();
            //fs.Close();

            //read all data from file
            //FileStream f = new FileStream("file.txt", FileMode.Open);
            //StreamReader sr = new StreamReader(f);
            //string line = sr.ReadLine();
            //while (line != null)
            //{
            //    Console.WriteLine(line);
            //    line = sr.ReadLine();
            //}
            //sr.Close();
            //f.Close();

            // write 1 to 10 numbers to file
            //char s = ' ';
            //FileStream fs = new FileStream("numbers.txt", FileMode.Create);
            //for(int i=1;i<=10;i++)
            //{
            //    string str = i.ToString();
            //    foreach(char c in str)
            //    {
            //        fs.WriteByte((byte)c);
            //    }
            //    fs.WriteByte((byte)s);
            //}
            //fs.Close();

            // read numbers from file
            //FileStream fr = new FileStream("numbers.txt", FileMode.Open);
            //int ch = fr.ReadByte();
            //while (ch!=-1)
            //{
            //    Console.Write((char)ch);
            //    ch = fr.ReadByte();
            //}
            //fr.Close();

            // copy content of one file to another
            //FileStream fs = new FileStream("numbers.txt", FileMode.Open);
            //FileStream fs1 = new FileStream("copy.txt", FileMode.Create);
            //int ch = fs.ReadByte();
            //while(ch!=-1)
            //{
            //    char c = (char)ch;
            //    fs1.WriteByte((byte)c);
            //    ch = fs.ReadByte();
            //}
            //fs.Close();
            //fs1.Close();

            // Count number of bytes in a file
            FileStream fs3 = new FileStream("data.txt", FileMode.Open);
            int count = 0;
            int ch1 = fs3.ReadByte();
            while(ch1!=-1)
            {
                count++;
                ch1 = fs3.ReadByte();
            }
            Console.WriteLine("Number of bytes in file: " + count);
            fs3.Close();

        }

    }
}
