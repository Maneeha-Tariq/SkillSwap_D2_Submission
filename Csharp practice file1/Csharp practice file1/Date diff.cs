using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class Date_diff
    {
        static void Main(string[] args)
        {
            String date1 = "23062016";
            String date2 = "24052019";
            int d1 = Convert.ToInt32(date1);
            int d2 = Convert.ToInt32(date2);

            int diff = d2%10000 - d1%10000;
            Console.WriteLine("Difference between two dates is: " + diff);
        }
    }
}
