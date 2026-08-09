using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class JaggedPractice
    {
        static int max(int[][] arr)
        {
            int max = arr[0][0];
            for(int i=0;i<arr.Length;i++)
            {
                for(int j = 0; j < arr[i].Length;j++)
                {
                    if (arr[i][j]>max)
                    {
                        max = arr[i][j];
                    }
                }
            }
            return max;
        }
        static void print(int[][] jag)
        {
            for (int i = 0; i < jag.Length; i++)
            {
                Console.WriteLine($"----------Row {i}-----------");
                for (int j = 0; j < jag[i].Length; j++)
                {
                    Console.WriteLine($"jag[{i}][{j}]-> {jag[i][j]}");
                }
                Console.WriteLine();
            }
        }
        static void sum(int[][] arr)
        {
            for(int i=0;i<arr.Length;i++)
            {
                int sum = 0;
                for(int j = 0; j < arr[i].Length;j++)
                {
                    sum += arr[i][j];
                }
                Console.WriteLine($"Sum of Row {i}: {sum}");
            }
        }
        static void countEvenOdd(int[][] arr)
        {
            for(int i=0;i<arr.Length;i++)
            {
                int even = 0; int odd = 0;
                for(int j = 0; j < arr[i].Length;j++)
                {
                    if (arr[i][j]%2==0)
                    {
                        even++;
                    }
                    else
                    {
                        odd++;
                    }
                }
                Console.WriteLine($"Odd Count: {odd}");
                Console.WriteLine($"Even Count: { even}");
            }
        }
        static void Main(string[] args)
        {
            Console.Write($"Enter no of rows: ");
            int rows = Convert.ToInt32( Console.ReadLine() );
            int[][] jag = new int[rows][];
            for(int i=0;i<jag.Length;i++)
            {
                Console.WriteLine($"Enter size of row: {i}");
                int cols = Convert.ToInt32(Console.ReadLine());
                jag[i] = new int[cols];
                for(int j=0;j<cols;j++)
                {
                    Console.Write($"Enter element of jag[{i}][{j}]: ");
                    jag[i][j] = Convert.ToInt32(Console.ReadLine());
                }
                Console.WriteLine();
            }
            //Console.WriteLine($"Max Element: {JaggedPractice.max(jag)}");
            JaggedPractice.sum(jag);

        }
    }
}
