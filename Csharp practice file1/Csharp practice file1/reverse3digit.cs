using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class reverse3digit
    {
       public void reverse(int num)
        {
            Console.WriteLine("Before  = " + num);
            int sum = 0;
            while(num>0)
            {
                int rem = num % 10;
                num = num / 10;
                sum = sum * 10 + rem;
            }
            num = sum;
            Console.WriteLine("Reverse = " + num);
        }
    }
}
