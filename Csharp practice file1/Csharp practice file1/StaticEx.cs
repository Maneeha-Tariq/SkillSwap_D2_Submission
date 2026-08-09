using Csharp_practice_file1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class StaticEx
    {
        internal static int x;
        internal static int y ;
        int temp;
        static StaticEx() 
        {
            Console.WriteLine("----Static ctor called----");
            x = 10;
            y = 20;
        }
        //internal StaticEx(int t)
        //{
        //    Console.WriteLine("----Parameterized ctor called----");
        //    temp = t;
        //    x = temp;
        //}
        //internal StaticEx() : this(45)
        //{
        //    Console.WriteLine("----Simple ctor called----");
        //}
        //internal void display()
        //{
        //    Console.WriteLine("Values : x = {0} , y = {1} , temp = {2}", x, y, temp);
        //}
    }
    internal class ChildClass : StaticEx
    {
        internal ChildClass() : base()
        {
            Console.WriteLine("--ChildClass parameterless ctor called--");
        }
    }
}

