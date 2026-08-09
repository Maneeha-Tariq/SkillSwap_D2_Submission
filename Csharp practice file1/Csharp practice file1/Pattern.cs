using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class Pattern
    {
        static void Main(string[] args)
        {
            int n = 6;
            for(int i=1;i<=(n/2)+1;i++)
            {
                for(int j=1;j< 4-i;j++)
                {
                    Console.Write(" ");
                }
                for(int k = 1;k<=2*i-1;k++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
            for(int i=1;i<=n/2;i++)
            {
                for(int j=1;j<=i;j++)
                {
                    Console.Write(" ");
                }
                for (int k = 1; k <= n - 2*i;k++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
        }
    }
}
