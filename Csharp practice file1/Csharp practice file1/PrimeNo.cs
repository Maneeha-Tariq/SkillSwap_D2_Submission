using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class PrimeNo
    {
        internal static bool isPrime(int num)
        {
            if (num <=1 ) return false;
            if(num == 2)
            {
                return true;
            }
            if (num % 2 == 0)
            {
                return false;
            }
            for (int i = 3; i < num; i += 2)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
        static void seriesOfPrime(int n)
        {
            Console.WriteLine("Prime Numbers from 1 to N ");
            for(int i=1;i<=n;i++)
            {
                if(isPrime(i))
                {
                    Console.Write($"{i}  ");
                }
            }
        }
        static void Main(string[] args)
        {
            int num = Convert.ToInt32(Console.ReadLine());
            PrimeNo.seriesOfPrime(num);
        }
    }
}
