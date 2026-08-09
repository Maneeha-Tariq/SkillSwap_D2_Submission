using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_App_2
{
    internal class ZeroBalanceException: ApplicationException
    {
        string _message = "Credit or Debit Amount can never be zero";
        public string message
        {
            get
            {
                return _message;
            }
        }
    }
    internal class NegativeAmountException: ApplicationException
    {
        string _message = "Credit or Debit Amount can never be negative ";
        public string message
        {
            get
            {
                return _message;
            }
        }
    }
    internal class AmountExceedsBalanceException: ApplicationException
    {
        string _message = "Withdrawl Amount cannot exceed the balance";
        public string message
        {
            get
            {
                return _message;
            }
        }
    }
    internal class NegativeBalanceException : Exception
    {
        internal NegativeBalanceException() : base("Balance can't be negative")
        { }
    }
    internal class InvalidCharException : Exception
    {
        internal InvalidCharException() : base("Invalid character entered it must be either C,D,E and B")
        { }
    }

}
