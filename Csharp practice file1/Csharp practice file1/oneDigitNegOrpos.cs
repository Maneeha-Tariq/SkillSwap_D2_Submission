using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class oneDigitNegOrpos
    {
        static void Main(string[] args)
        {
            int num = -15;
            if(num>=0&& num<=9)
            {
                Console.WriteLine("The number is one digit positive number");
            }
            else if(num < 0 && num >= -9)
            {
                Console.WriteLine("The number is one digit negative number");
            }
            else
            {
                Console.WriteLine("The number is neither one digit positive or negative") ;
            }
        }
    }
}
