using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class AreaOfTriangle
    {
        int b, h;
        public AreaOfTriangle(int b,int h)
        {
            this.b = b;
            this.h = h;
        }
        internal void area()
        {
            Console.WriteLine("Area of Triangle = " + (0.5 * b * h));
        }
    }
}
