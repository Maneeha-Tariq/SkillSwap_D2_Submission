using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class array
    {
        static void Main(string[] args)
        {
            //int[] arr = new int[] { 10, 20, 30 };
            //arr[0] = 40;
            //var a = new int[9];
            //foreach(var i in arr)
            //{
            //    Console.Write($"{i} ");
            //}
            Console.Write("Enter no of rows: ");
            int rows = Convert.ToInt32(Console.ReadLine());
            // Console.Write("Enter no of cols: ");
            // int cols = Convert.ToInt32(Console.ReadLine());
            // int[,] matrix = new int[rows, cols];
            // for(int i=0;i<matrix.GetLength(0);i++)
            // {
            //     for(int j=0;j<matrix.GetLength(1);j++)
            //     {
            //         matrix[i, j] = Convert.ToInt32(Console.ReadLine());
            //     }
            // }
            //// { { 1, 2, 3,9 }, { 4, 5, 6,8 },{ 2, 4, 5, 6 } };
            //foreach(var i in matrix)
            // {
            //     Console.Write($"{i} ");
            // }

            //Console.WriteLine($"Simple .Length: {matrix.Length}");
            //Console.WriteLine($"GetLength(0): {matrix.GetLength(0)}");
            //Console.WriteLine($"GetLength(1): {matrix.GetLength(1)}");

            //jagged array
            int[][] a = new int[rows][];
            for(int i=0;i<rows;i++)
            {
                Console.Write($"Enter no of elements in row [{i}]: ");
                int cols = Convert.ToInt32(Console.ReadLine());
                a[i] = new int[cols];
                for(int j=0;j<cols;j++)
                {
                    Console.Write($"Enter element [{i}][{j}]: ");
                    a[i][j] = Convert.ToInt32(Console.ReadLine());
                }
            }
            int r = 0;
            foreach (var i in a)
            {
                Console.Write($"Row [{r}]-> ");
                foreach(var j in i)
                {
                    Console.Write($"{j} ");
                }
                Console.WriteLine();
                r++;
            }

        }
    }
}
