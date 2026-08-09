using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class max_element
    {
        static int maxElement(int[] arr)
        {
            int max = arr[0];
            for(int i=1;i<arr.Length;i++)
            {
                if (arr[i] > max)
                    max = arr[i];
            }
            return max;
        }
        internal static void displayPrime(int[] arr)
        {
            for(int i=0;i<arr.Length;i++)
            {
                if (PrimeNo.isPrime(arr[i]))
                {
                    Console.Write($"{arr[i]} ");
                }
            }
        }
       internal static void firPrime(int[] arr,ref int maxPrime)
       {
           
            for(int i=0;i<arr.Length;i++)
            {
                if(PrimeNo.isPrime(arr[i]))
                {
                    maxPrime = arr[i];
                    return;
                }
            }
       }
       static  int maxPrime(int[] args)
        {
            int maxPrime=0;
            max_element.firPrime(args,ref maxPrime );
            for(int i=0;i<args.Length;i++)
            {
                if (PrimeNo.isPrime(args[i]))
                {
                    if (args[i]>maxPrime)
                    {
                        maxPrime = args[i];
                    }
                }
            }
           if(maxPrime>0 )
           {
                return maxPrime;
           }
            else
            {
                return -1;
            }

        }
        static int secMax(int[] args)
        {
            int max = args[0];
            int sec = args[1];
            if (sec>max)
            {
                int m = max;
                max = sec;
                sec = m;
            }
            for(int i=2;i<args.Length;i++)
            {
                if (args[i]>max)
                {
                    sec = max;
                    max = args[i];
                }
                else if (args[i]<max&& args[i]>sec)
                {
                    sec = args[i];
                }
            }
            return sec;
        }

        static void displayUniqueElement(int[] args)
        {
           for(int i=0;i<args.Length;i++)
           {
                int count = 0;
                for (int j = 0; j < args.Length; j++)
                {
                    if (args[i] == args[j])
                    {
                        count++;
                    }
                }
                if(count == 1)
                {
                    Console.Write($"{args[i]} ");
                }
           }
        }
        static void displayRepeated(int[] args)
        {
            for (int i = 0; i < args.Length; i++)
            {
                int count = 0; bool print = false;
                for (int j = 0; j < args.Length; j++)
                {
                    if (args[i] == args[j])
                    {
                        count++;
                    }
                }
                for(int k = 0;k<i;k++)
                {
                    if (args[i] == args[k])
                    {
                        print = true;
                        break;
                    }
                }
                if (count > 1 && print == false)
                {
                    Console.Write($"{args[i]} ");
                }
            }
        }
        static void Main(string[] args)
        {
            int[] arr = { 10, 13, 7, 10, 7,8};
            //Console.WriteLine("First Max: {0}", max_element.maxElement(arr));
            //Console.WriteLine("Second Max: {0}", max_element.secMax(arr));
            //max_element.displayPrime(arr);

            //if(max_element.maxPrime(arr)==-1)
            //{
            //    Console.WriteLine("No prime Number found");
            //}
            //else
            //{
            //    Console.WriteLine(max_element.maxPrime(arr));
            //}
            max_element.displayRepeated(arr);
        }
    }
}
