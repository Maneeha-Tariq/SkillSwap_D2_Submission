using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class reverse5digit
    {
        //12345
        public static void reverse(int num)
        {
            int count = 0; int n = num;
            while (n > 0)
            {
                count++;
                n = n / 10;
            }
            int f = 1;
            for(int i=1;i<count;i++)
            {
                f *= 10;
            }
            int oneD = num / f;      
            num = num % f;
            int last = num % 10;     
            num = num / 10;
            int midCount = count - 2;  
            int rev = 0;
            while(num>0)
            {
                rev = rev * 10 + num % 10;
                num = num / 10;
                midCount--;
            }
            if(midCount>0)
            {
                while(midCount>0)
                {
                    rev = rev * 10;
                    midCount--;
                }
            }
            num = rev * 10 + last;
            num = num + f * oneD;
            Console.WriteLine(num); 
        }
        static void Main(string[] args)
        {
            reverse5digit.reverse(10235);
        }
    }
}
