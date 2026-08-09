using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class greatest
    {
        static void Main(string[] args)
        {
            int a = 23, b = 45, c = 12, d = 67;
            if (a > b)
            {
                if (a > c)
                {
                    if (a > d)
                        Console.WriteLine("A is greatest");
                    else
                        Console.WriteLine("D is greatest");
                }
                else
                {
                    if (c > d)
                        Console.WriteLine("C is greatest");
                    else
                        Console.WriteLine("D is greatest");
                }
            }
            else
            {
                if (b > c)
                {
                    if (b > d)
                        Console.WriteLine("B is greatest");
                    else
                        Console.WriteLine("D is greatest");
                }
                else
                {
                    if (c > d)
                        Console.WriteLine("C is greatest");
                    else
                        Console.WriteLine("D is greatest");
                }
            }

            //string greatest = (a > b) ? ((a > c) ? ((a > d) ? "a is greatest" : "d is greatest")
            //                  : (c > d) ? "c is greatest" : "d is greatest") 
            //                  : (b > c) ? ((b > d) ? "b is greatest" : "d is greatest")
            //                  : (c > d) ? "c is greatest" : "d is greatest";
            //Console.WriteLine(greatest);
        }
    }
}
