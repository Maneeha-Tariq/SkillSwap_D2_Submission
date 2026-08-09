using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class CompoundInterest
    {
        int principal;
        double rate;
        int n, t;
        public CompoundInterest(int p, int n,int t,double r)
        {
            principal = p; 
            rate = r;
            this.n = n;
            this.t = t; 
        }
        public void interest()
        {
            int amount = (int)(principal * Math.Pow((1 + (rate / n)), n * t));
            int inter = amount - principal;
            Console.WriteLine("Interest is " + inter);
        }

    }
}
