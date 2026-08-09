using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class vowelOrConsonant
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a character");
            char ch = Convert.ToChar(Console.ReadLine());
            //if(ch>='a'&& ch<='z')
            //{
            //    if (ch == 'a')
            //        Console.WriteLine("The character is vowel");
            //    else if (ch == 'e')
            //        Console.WriteLine("The character is vowel");
            //    else if (ch == 'i')
            //        Console.WriteLine("The character is vowel");
            //    else if (ch == 'o')
            //        Console.WriteLine("The character is vowel");
            //    else if (ch == 'u')
            //        Console.WriteLine("The character is vowel");
            //    else
            //        Console.WriteLine("The character is Consonant");
            //}
            //else if(ch>='A'&& ch<='Z')
            //{
            //   if (ch == 'A')
            //        Console.WriteLine("The character is vowel");
            //    else if (ch == 'E')
            //        Console.WriteLine("The character is vowel");
            //    else if (ch == 'I')
            //        Console.WriteLine("The character is vowel");
            //    else if (ch == 'O')
            //        Console.WriteLine("The character is vowel");
            //    else if (ch == 'U')
            //        Console.WriteLine("The character is vowel");
            //    else
            //        Console.WriteLine("The character is Consonant");
            //}
            //else
            //{
            //    Console.WriteLine("The character is not an alphabet");


            //}

            // using switch 
            switch (ch)
            {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    Console.WriteLine("The character is Vowel");
                    break;

                default:
                    Console.WriteLine("The character is Consonant");
                    break;
            }

        }
    }

}
