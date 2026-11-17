using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1_web
{ 
    internal class Program
    {
        int BookId;
        string Title;
        string Author;
        double price;
        internal void AddBook()
        {
            int i = 4;
            Console.WriteLine("You can enter 3-4 book records ");
            FileStream fsByte = new FileStream("books_byte.txt", FileMode.Append);
            FileStream fs = new FileStream("books_char.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fs);
           
            char c = ' ';
            Console.WriteLine("Enter C/c if you want to Add Using character stream or B/b if Byte Stream");
            c = char.Parse(Console.ReadLine());

            char choice;
            do
            {
                string res = "";
                Console.WriteLine("Enter bookId: ");
                BookId = int.Parse(Console.ReadLine());
                Console.WriteLine("Enter book title: ");
                Title = Console.ReadLine();
                Console.WriteLine("Enter book Author: ");
                Author = Console.ReadLine();
                Console.WriteLine("Enter book price: ");
                price = double.Parse(Console.ReadLine());
                res += BookId;
                res += ",";
                res += Title;
                res += ",";
                res += Author;
                res += ",";
                res += price;

                if(c == 'B'|| c=='b')
                {
                    byte[] data = Encoding.UTF8.GetBytes(res);
                    for (int j = 0; j < data.Length; j++)
                    {
                        fsByte.WriteByte(data[j]);
                    }

                    fsByte.WriteByte((byte)'\n');
                }
                else if(c == 'C'|| c == 'c')
                {
                    sw.WriteLine(res);
                }

                Console.WriteLine("Do you want to enter the records again? Y/N");
                choice = char.Parse(Console.ReadLine());
                i--;
            } while (i > 0 && (choice == 'Y' || choice == 'y'));
            sw.Close();
            fs.Close();
            fsByte.Close();
           
        }
        internal void ViewBooksUsingCharacter()
        {
            FileStream fs = new FileStream("books_char.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fs);
            string line = sr.ReadLine();
            while (line != null)
            {
                Console.WriteLine(line);
                line = sr.ReadLine();
            }
            sr.Close();
        }
        internal void ViewBooksUsingByte()
        {
            FileStream fs = new FileStream("books_byte.txt", FileMode.Open);
            int res = fs.ReadByte() ;
            string line = "";
            while(res!=-1)
            {
                char c = (char)res;
                if(c != '\n')
                {
                    line += c;
                }
                else if(c == '\n')
                {
                    Console.WriteLine(line);
                    line = "";
                }
                res = fs.ReadByte();
            }
            fs.Close();
        }
        static void Main(string[] args)
        {
            Program p = new Program();

            char choice = ' ';
            Console.WriteLine("Enter your choice: ");
            Console.WriteLine("1- Add Book");
            Console.WriteLine("2- View Books (Byte Stream) ");
            Console.WriteLine("3- View Books (Character Stream) ");
            Console.WriteLine("4- Exit");
            choice = char.Parse(Console.ReadLine());
            switch(choice)
            {
                case '1':
                    p.AddBook();
                    break;

                case '2':
                    p.ViewBooksUsingByte();
                    break;

                case '3':
                    p.ViewBooksUsingCharacter();
                    break;

                case '4':
                    return;

                default:
                    break;
            }
        }
    }
}


