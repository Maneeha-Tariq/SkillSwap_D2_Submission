using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class SwapProgram
    {
        //static int temp;
        //internal  void swap(ref int num1, ref int num2)
        //{
        //    temp = num1;
        //    num1 = num2;
        //    num2 = temp;
        //}
        internal void swap(ref int num1,ref int num2)
        {
            num1 = num1 + num2;
            num2 = num1 - num2;
            num1 = num1 - num2;
        }
    }
}
