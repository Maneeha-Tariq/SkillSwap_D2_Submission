using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class Datatypecs
    {
        public void PrimitiveDatatypeFun()
        {
            // value types
            int a= 10; // 4 byte
            float f = 3.3f; // 4 byte
            byte bh = 2; // 1 byte 
            double d = 3.3; // 8 byte
            char c = 'a'; // 2 byte 
            string s = "hello";
            bool bo = false; // 1 byte

        }
        public void DerivedDatatypeFun()
        {
            // all are reference types 
            Int16 a = 10; 
            Byte bh = 2; 
            Double d = 3.3; 
            Char c = 'a'; 
            String s = "hello";
            Boolean bo = false;
            Object o = 10;
        }
    }
}
