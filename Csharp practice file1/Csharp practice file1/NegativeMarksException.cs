using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class NegativeMarksException : ApplicationException
    {
        string message = "Marks cannot be negative";
        public string Msg
        {
            get
            {
                return message;
            }
        }

    }
    public class InvalidFormatException : ApplicationException
    {
        string message = "The input must contain only interger numbers ";
        public string Msg
        {
            get
            {
                return message;
            }
        }

    }
    internal class MarksOutOfRangeException : ApplicationException
    {
        string message = "Marks can never be greater than 100";
        public string Msg
        {
            get
            {
                return message;
            }
        }

    }
}
