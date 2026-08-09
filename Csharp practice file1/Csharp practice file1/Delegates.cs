using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class Delegates
    {
       internal void Welcome()
       {
            Console.WriteLine(" Welcome to C#");
       }
       internal void DisplayName(string name)
       {
            Console.WriteLine("Name is {0}", name);
       }
       internal int Add(int a,int b)
       {
            return a + b;
       }
       public delegate void WelcomeHandler();
       public delegate void NamePrint(string name);
       public delegate int Calculate(int a, int b);
        internal static void Main(string[] args)
        {
            Delegates obj = new Delegates();
            //  WelcomeHandler wh = new WelcomeHandler(obj.Welcome); // correct
            //WelcomeHandler wh = obj.Welcome; // correct too but shorter 
            //wh(); 

            //NamePrint n = obj.DisplayName;
            //n("Maneeha");
            Calculate c = obj.Add;
            Console.WriteLine(c(1, 3));


        }
    }
    internal class MulticastDelegate
    {
        internal void A()
        {
            Console.WriteLine("A");
        }

        internal void B()
        {
            Console.WriteLine("B");
        }
        internal void C()
        {
            Console.WriteLine("C");
        }
        public delegate void MyMultiDelegate();
        internal static void Main(string[] args)
        {
            MulticastDelegate obj = new MulticastDelegate();
            MyMultiDelegate m = obj.A;
            m += obj.B;
            m += obj.C;
            m();
        }
    }
}

