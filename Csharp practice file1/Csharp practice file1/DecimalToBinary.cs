using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class DecimalToBinary
    {
        static void Main(string[] args)
        {

            // Decimal to binary
            //Console.Write("Enter the num: ");
            //int num = Convert.ToInt32(Console.ReadLine());
            //String binary = " ";
            for(int i=1;i<=20;i++)
            {
                int num = i;
                String binary = " ";
                while (num > 0)
                {
                    int digit = num % 2;
                    binary = digit + binary;
                    num = num / 2;
                }
                Console.WriteLine($"Binary of {i}:\t{binary}");
            }
           

            // Binary to Decimal
            //Console.Write("Enter a binary number: ");
            //int binary = Convert.ToInt32(Console.ReadLine());
            //int deci = 0; int i = 0;
            //while(binary>0)
            //{
            //    deci = deci + binary % 10 * (int)Math.Pow(2, i);
            //    binary = binary / 10;
            //    i++;
            //}
            //Console.WriteLine("Decimal: {0}", deci);



        }
    }
}
