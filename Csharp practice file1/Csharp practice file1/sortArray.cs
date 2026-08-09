using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class sortArray
    {
        internal static void Selectionsort(ref int[] arr)
        {
            for(int i=0;i<arr.Length;i++)
            {
                for(int j=i+1;j<arr.Length;j++)
                {
                    if (arr[j] < arr[i])
                    {
                        int temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                    }
                }
            }
        }
        internal static void bubbleSort(ref int[] arr)
        {
            for(int i=0;i<(arr.Length)-1;i++)
            {
                for(int j=0;j<(arr.Length)-1;j++)
                {
                    if (arr[j + 1] < arr[j])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
        //swapped base version 
        internal static void insertionSort(ref int[] arr)
        {
            for(int i=1;i<arr.Length;i++)
            {
                for(int j=i;j>0;j--)
                {
                    if (arr[j] < arr[j-1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = temp;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        //standard version 
        internal static void InsertionSort(ref int[] arr)
        {
            for (int i = 1; i < arr.Length; i++)
            {
                int key = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j]; // shift right
                    j--;
                }

                arr[j + 1] = key;
            }
        }
        static void Main(string[] args)
        {
            int[] arr = { 7,9,3,6,5,0,1 };
            sortArray.insertionSort(ref arr);
            for(int i=0;i<arr.Length;i++)
            {
                Console.Write($"{arr[i]} ");
            }
        }
    }
}
