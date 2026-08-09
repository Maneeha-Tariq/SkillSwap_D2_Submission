using Csharp_practice_file1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class CopyCtor
    {
        int a;
        int b;
        int[] arr;
       internal CopyCtor(int a,int b, int[] arr)
       {
            Console.WriteLine("Parametrized ctor called");
            this.a = a;
            this.b = b;
            this.arr = arr;
       }
       internal CopyCtor(CopyCtor copy)
       {
            Console.WriteLine("Copy ctor called");
            a = copy.a;
            b = copy.b;
            arr = new int[copy.arr.Length];
            for(int i=0;i<copy.arr.Length;i++)
            {
                arr[i] = copy.arr[i];
            }
       }
      internal int getA()
      { 
          return a;
      }
      internal int getB()
      {
          return b;
      }
      internal void setA(int a)
      {
          this.a =  a;
      }
      internal void setB(int b)
      {
          this.b = b;
      }
        internal void setArr(int a,int indx)
        {
            arr[indx] = a;
        }
        internal int getArr(int i)
        {
            return arr[i];
        }
       
    }
}
internal class B
{
    static void Main(string[] args)
    {
        int[] arr = { 10, 20, 30 };
        CopyCtor obj = new CopyCtor(34, 80,arr);
        CopyCtor obj1 = new CopyCtor(obj);
        obj1.setA(78);
        obj1.setArr(89, 1);
        Console.WriteLine("Obj's a: {0}",obj.getA());
        Console.WriteLine("Obj1's a: {0}", obj1.getA());
        Console.WriteLine("Obj's arr: {0}", obj.getArr(1));
        Console.WriteLine("Obj1's arr: {0}", obj1.getArr(1));
    }
}
