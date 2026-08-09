using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Csharp_practice_file1;

namespace Project_App_2
{
    internal class Bank_Account
    {
        int balance = 5000;
        internal void withdraw(int amount)
        {
            if (amount < 0)
            {
                throw new NegativeAmountException();
            }
            else if (amount == 0)
            {
                throw new ZeroBalanceException();
            }
            else if (amount > balance)
            {
                throw new AmountExceedsBalanceException();
            }
            else
            {
                balance = balance - amount;
                Console.WriteLine("Withdrawl successful. Current balance is: " + balance);
            }
        }
        internal void deposit(int amount)
        {
            if (amount < 0)
            {
                throw new NegativeAmountException();
            }
            else if (amount == 0)
            {
                throw new ZeroBalanceException();
            }
            else
            {
                balance = balance + amount;
                Console.WriteLine("Deposit successful. Current balance after deposit is: " + balance);
            }
        }
    }
    internal class Bank_Account_Test
    {
        internal static void Main(string[] args)
        {
            int choice = 0;
            Console.Write("Enter 1 for Withdrawl and 2 for Deposit: ");
            try
            {
                try
                {
                    choice = Convert.ToInt32(Console.ReadLine());
                }
                catch (FormatException)
                {
                    throw new InvalidFormatException();
                }
            }
            catch (InvalidFormatException ex)
            {
                Console.WriteLine(ex.Msg);
                return;
            }

            Console.WriteLine();
            int amount = 0;
            Bank_Account account = new Bank_Account();

            try
            {

                switch (choice)
                {
                    case 1:
                        Console.Write("Enter amount to withdraw: ");
                        try
                        {
                            amount = Convert.ToInt32(Console.ReadLine());
                        }
                        catch (FormatException)
                        {
                            throw new InvalidFormatException();
                        }
                        account.withdraw(amount);
                        break;
                    case 2:
                        Console.Write("Enter amount to deposit: ");
                        try
                        {
                            amount = Convert.ToInt32(Console.ReadLine());
                        }
                        catch (FormatException)
                        {
                            throw new InvalidFormatException();
                        }
                        account.deposit(amount);
                        break;
                    default:
                        Console.WriteLine("Invalid Choice");
                        break;
                }
            }
            catch (NegativeAmountException ex)
            {
                Console.WriteLine(ex.message);
                return;
            }
            catch (AmountExceedsBalanceException ex)
            {
                Console.WriteLine(ex.message);
                return;
            }
            catch (ZeroBalanceException ex)
            {
                Console.WriteLine(ex.message);
                return;
            }
            catch (InvalidFormatException ex)
            {
                Console.WriteLine(ex.Msg);
                return;
            }
            finally
            {
                Console.WriteLine("Transaction Completed");
            }
        }
    }   
}
