using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class SI
    {
        float principal;
        public SI(float p)
        {
            principal = p;
        }
        void interest(int r,int y)
        {
            float si = (principal *r*y)/ 100;
            Console.WriteLine("Simple Interest is " + si);
        }
        void amountotal(float i)
        {
            float amount = principal + i;
            Console.WriteLine("Total amount after interest is " + amount);
        }

    }
}
