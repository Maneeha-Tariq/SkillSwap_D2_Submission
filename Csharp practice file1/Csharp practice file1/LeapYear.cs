using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class LeapYear
    {
        static void Main(string[] args)
        {
            int year = 2070;
            switch (year % 400)
            {
                case 0:
                    Console.WriteLine("The year is a Leap year");
                    break;
                default:
                    switch (year % 4)
                    {
                        case 0:
                            switch (year % 100)
                            {
                                case 0:
                                    Console.WriteLine("The year is not a leap year");
                                    break;
                                default:
                                    Console.WriteLine("The year is a Leap year");
                                    break;

                            }
                            break;
                        default:
                            Console.WriteLine("The year is not a leap year:");
                            break;
                    }
                    break;

            }
        }
    }
}
