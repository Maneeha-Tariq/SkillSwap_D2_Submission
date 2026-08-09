using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class Electricitybill
    {
       static void CalcBill(int p,int consume)
        {
            int total = consume * p;
           Console.WriteLine( (total < 400) ? "Pay only 100 RS" : "50% amount will be paid");
        }
        public static void Main(string[] args)
        {
            int unitPrice = Convert.ToInt32(Console.ReadLine());
            int unitConsumed = Convert.ToInt32(Console.ReadLine());   
            Electricitybill.CalcBill(unitPrice, unitConsumed);
        }
    }
}
