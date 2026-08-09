
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_App_2
{
    internal class ATM_SimulationUsingThread_
    {
        private int balance;
        private  static object obj = new object();
        internal ATM_SimulationUsingThread_()
        {
            balance = 0;
        }
        internal void deposit(int b)
        {
            Thread t = new Thread(() =>
            {
                try
                {
                    if (b <= 0)
                    {
                        throw new ZeroBalanceException();
                    }
                    lock (obj)
                    {
                        balance += b;
                        Console.WriteLine($"Rs.{b} deposited successfully.");
                    }
                }
                catch (ZeroBalanceException e)
                {
                    Console.WriteLine(e.message);
                }
            });
            t.Start();
            t.Join();

        }
        internal void withdraw(int b)
        {
            Thread t = new Thread(() =>
            {
                try
                {
                    if (b <= 0)
                    {
                        throw new ZeroBalanceException();
                    }
                    lock (obj)
                    {
                        if (b > balance)
                        {
                            throw new AmountExceedsBalanceException();
                        }

                        balance -= b;
                        Console.WriteLine($"Rs.{b} withdrawn successfully.");
                    }
                }
                catch (ZeroBalanceException e)
                {
                    Console.WriteLine(e.message);
                }
                catch (AmountExceedsBalanceException e)
                {
                    Console.WriteLine(e.message);
                }
            });
            t.Start();
            t.Join();
        }
        internal void DisplayBalance()
        {
            Thread t = new Thread(() =>
            {
                try
                {
                    lock (obj)
                    {
                        if (balance <= 0)
                        {
                            throw new ZeroBalanceException();
                        }
                        else
                        {
                            Console.WriteLine($"Your Current Balance is {balance}");
                        }
                    }
                }
                catch (ZeroBalanceException e)
                {
                    Console.WriteLine(e.message);
                }
            });
            t.Start();
            t.Join();
        }
        internal static void Main()
        {
            ATM_SimulationUsingThread_ obj = new ATM_SimulationUsingThread_();
            try
            {
                char again;
                do
                {
                    char c;
                    Console.WriteLine("Enter character d/w/p: ");
                    c = Convert.ToChar(Console.ReadLine());
                    switch (c)
                    {
                        case 'd':
                        case 'D':
                            {
                                int bal;
                                Console.WriteLine("Enter balance to deposit");
                                bal = Convert.ToInt32(Console.ReadLine());
                                obj.deposit(bal);
                                break;
                            }
                        case 'w':
                        case 'W':
                            {
                                int bal;
                                Console.WriteLine("Enter balance to withdraw");
                                bal = Convert.ToInt32(Console.ReadLine());
                                obj.withdraw(bal);
                                break;
                            }
                        case 'p':
                        case 'P':
                            {
                                obj.DisplayBalance();
                                break;
                            }
                        default:
                            {
                                Console.WriteLine("Invalid character entered");
                                break;
                            }
                    }
                    Console.WriteLine("Do you want to make any transaction again? if then enter Y otherwise N");
                    again = Convert.ToChar(Console.ReadLine());
                } while (again=='y'|| again== 'Y');
            }
            catch(FormatException e)
            {
                Console.WriteLine(e.Message);
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message.ToString());
            }
        }
    }
    
}
