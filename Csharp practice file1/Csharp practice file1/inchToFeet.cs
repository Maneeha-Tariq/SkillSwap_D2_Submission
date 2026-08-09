using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class inchToFeet
    {
        int inch;
        public inchToFeet(int i)
        {
            inch = i;
        }
        void convert()
        {
            int feet = inch / 12;
            Console.WriteLine("Feet is " + feet);
        }
    }
}

namespace Csharp_practice_file1
{
    internal class FeetToInch
    {
        int feet;
        public FeetToInch(int f)
        {
            feet = f;
        }
        void convert()
        {
            int inch = feet * 12;
            Console.WriteLine("inch is " + inch);
        }
    }
}
