using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal abstract class AbstractClass
    {
        internal int par1, par2;
        internal int area;
        internal  void Accept(int par1,int par2)
        {
            this.par1 = par1;
            this.par2 = par2;   
        }
        internal abstract void triangleArea();
        internal abstract void rectangleArea();
        internal void Display()
        {
            Console.WriteLine("Area is {0}", area);
        }
    }
    internal class AbstractChild: AbstractClass
    {
        internal override void triangleArea()
        {
            area = (par1 * par2) / 2;
        }
        internal override void rectangleArea()
        {
            area = par1 * par2;
        }
    }
    internal class AbsMain
    {
        internal static void Main(string[] args)
        {
            AbstractClass obj = new AbstractChild();
            obj.Accept(10, 20);
            obj.triangleArea();
            obj.Display();
            obj.rectangleArea();
            obj.Display();
        }
    }

}
