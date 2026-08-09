using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class yesNo
    {
        string GetDayType_New(int day) => day switch
        {
            6 => "Weekend",
            7 => "Weekend",
            _ => "Weekday"
        };

        static void Main(string[] args)
        {
            yesNo yn = new yesNo();
           Console.WriteLine( yn.GetDayType_New(1));
            //char ch = Convert.ToChar(Console.ReadLine());
            //switch (ch)
            //{
            //    case 'y':
            //        Console.WriteLine("Yes");
            //        break;
            //    case 'n':
            //        Console.WriteLine("No");
            //        break;
            //    default:
            //        Console.WriteLine("cancel");
            //        break;
            //}
        }
    }
}
