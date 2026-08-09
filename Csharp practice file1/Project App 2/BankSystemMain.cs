using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_App_2
{
    internal class BankSystemMain
    {
        internal static void Main(string[] args)
        {

            BankManagementSystem obj = new BankManagementSystem();


            try
            {
                obj.AccountDetails();
            }
            catch (NameInvalidException e)
            {
                Console.WriteLine(e.Message);
                return;
            }
            catch (NegativeBalanceException e)
            {
                Console.WriteLine(e.Message);
                return;
            }
            catch (FormatException e)
            {
                Console.WriteLine(e.Message);
                return;
            }
            catch (IOException e)
            {
                Console.WriteLine(e.Message.ToString());
                return;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message.ToString());
                return;
            }

            char choice; char ch;
            do
            {
                Console.WriteLine("Enter your choice either C,D,B,E");
                choice = Convert.ToChar(Console.ReadLine());

                try
                {
                    if (choice == 'C' || choice == 'D' || choice == 'B' || choice == 'E' || choice == 'c' || choice == 'd' || choice == 'b' || choice == 'e')
                    {
                        switch (choice)
                        {
                            case 'C':
                            case 'c':
                                {
                                    double amount;
                                    Console.WriteLine("How much Amount you want to Credit");
                                    amount = Convert.ToInt32(Console.ReadLine());
                                    if (amount == 0)
                                    {
                                        throw new ZeroBalanceException();
                                    }
                                    else if (amount < 0)
                                    {
                                        throw new NegativeAmountException();
                                    }
                                    obj.Credit(amount);
                                    break;
                                }
                            case 'D':
                            case 'd':
                                {
                                    double amount;
                                    Console.WriteLine("How much Amount you want to Debit");
                                    amount = Convert.ToInt32(Console.ReadLine());
                                    if (amount == 0)
                                    {
                                        throw new ZeroBalanceException();
                                    }
                                    else if (amount < 0)
                                    {
                                        throw new NegativeAmountException();
                                    }
                                    obj.Debit(amount);
                                    break;
                                }
                            case 'B':
                            case 'b':
                                {
                                    double b = obj.CheckBalance();
                                    Console.WriteLine("Your current Balance is " + b);
                                    break;
                                }
                            default:
                                {
                                    Console.WriteLine("You want to exit now");
                                    return;
                                }
                        }
                    }
                    else
                    {
                        throw new InvalidCharException();
                    }
                }
                catch (FormatException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (InvalidCharException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (ZeroBalanceException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (NegativeAmountException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (OverflowException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (AmountExceedsBalanceException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                }
                Console.WriteLine("Do you want to take choices again? yes/No");
                ch = Convert.ToChar(Console.ReadLine());
            } while (ch == 'Y' || ch == 'y');
        }
    }
}
