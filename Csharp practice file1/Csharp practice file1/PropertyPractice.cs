using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class PropertyPractice
    {
        public static int A { get; set; }
        static PropertyPractice()
        {
            A = 70;
        }
        internal static void Main(string[] args)
        {
            PropertyPractice obj = new PropertyPractice();
            PropertyPractice.A = 30;
            Console.WriteLine(PropertyPractice.A);
        }

    }
   
}

