using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class AreaCircle
    {
        double rad;
        public AreaCircle(double rad)
        {
            this.rad = rad;
        }
        internal void area()
        {
            Console.WriteLine("Area of Circle = " + (3.14 * rad * rad));
        }

    }

}
