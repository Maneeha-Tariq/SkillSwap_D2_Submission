using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class AccessModifierMain : AccessModifier
    {
        internal static void Main(string[] args)
        {
            AccessModifierMain obj = new AccessModifierMain();
            obj.Func2();
            obj.Func3();
            obj.Func4();
            obj.Func5();
        }
    }
}
