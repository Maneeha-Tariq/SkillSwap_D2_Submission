using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    public class AccessModifier
    {
        private void Func1()
        {
            Console.WriteLine("Private method Func1");
        }
        internal virtual void Func2()
        {
            Console.WriteLine("Internal method AccessModifier -> Func2");
        }
        protected void Func3()
        {
            Console.WriteLine("Protected method Func3");
        }
        protected internal void Func4()
        {
            Console.WriteLine("Protected Internal method Func4");
        }
        public void Func5()
        {
            Console.WriteLine("Public method Func5");
        }
    }
    internal class A : AccessModifier
    {
        internal  override void Func2()
        {
            Console.WriteLine("Internal method A-> overrided Func2");
        }
    }
    internal class B : A
    {
        internal new void Func2()
        {
            Console.WriteLine("Internal method B-> overrided Func2");
        }
    }
    internal class CMain
    {
        internal static void Main(string[] args)
        {
            AccessModifier obj3 = new B();
            obj3.Func2();
        }
    }
    
}
