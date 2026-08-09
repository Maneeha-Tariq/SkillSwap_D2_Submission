using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class Student
    {
        int rno;
        int fees;
        internal Student(int rno,int fees)
        {
            this.rno = rno;
            this.fees = fees;
        }
        internal void Display()
        {
            Console.WriteLine("Rno is {0} and Fee is {1}", rno, fees);
        }
    }
}
