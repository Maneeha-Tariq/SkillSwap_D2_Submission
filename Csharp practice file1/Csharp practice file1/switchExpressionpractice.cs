using Microsoft.VisualBasic;
using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Intrinsics.X86;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class switchExpressionpractice
    {
        string username, password;
        public switchExpressionpractice(string username, string password)
        {
            this.username = username;
            this.password = password;
        }
        static void books(int b) 
        {
            Console.WriteLine(b switch
            {
                0 => "No books borrowed",
                >= 1 and <= 2 => "Light Reader",
                >= 3 and <= 5  => "Regular Reader",
                _ => "Bookworm"
            });
        }
        static string status(string s) => s switch
        {
            "Pending" => "Your order is pending.",
            "Preparing" => "Your order is being prepared.",
            "Out for Delivery" => "Your order is out for delivery.",
            "Delivered" => "Your order has been delivered.",
            "Cancelled" => "Your order has been cancelled.",
            _ => "Unknown status."
        };
        string login(string u, string p) 
        {
            switchExpressionpractice obj = new switchExpressionpractice("admin", "admin123");
            return (u, p) switch
            {
                var (user, pass)
                when user == obj.username && pass == obj.password => "Login Successful",
                var (user, pass)
                when user == obj.username && pass != obj.password => "Incorrect Password",
                var (user, pass)
               when user != obj.username && pass == obj.password => "Incorrect username",
                _ => "Login Failed"
            };
        }
        static string SimpleSwitchLogin(string u,string p)
        {

            switchExpressionpractice obj = new switchExpressionpractice("admin", "admin123");
            switch (u,p)
            {
                case var (user,pass): 
                    if (user == obj.username && pass == obj.password)
                    {
                        return "Login Successful";
                    }
                    else if (user == obj.username && pass != obj.password)
                    {
                        return "incorrect password";
                    }
                    else if (user != obj.username && pass == obj.password)
                    {
                        return "incorrect username";
                    }
                    break;
            }
            return "Login Failed";
        }
        static void ATMSystem(string acc,string transac)
        {
            switch(acc)
            {
                case "Savings":
                    switch(transac)
                    {
                        case "Deposit":
                            Console.WriteLine("Savings Account Deposit Selected");
                            break;
                        case "Withdraw":
                            Console.WriteLine("Savings Account Withdrawl Selected");
                            break;
                        case "Balance":
                            Console.WriteLine("Savings Account Balance Selected");
                            break;
                        default:
                            Console.WriteLine("INVALID Transaction");
                            break;
                    }
                    break;
                case "Current":
                    switch (transac)
                    {
                        case "Deposit":
                            Console.WriteLine("Current Account Deposit Selected");
                            break;
                        case "Withdraw":
                            Console.WriteLine("Current Account Withdrawl Selected");
                            break;
                        case "Balance":
                            Console.WriteLine("Current Account Balance Selected");
                            break;
                        default:
                            Console.WriteLine("INVALID transaction"); 
                            break;
                    }
                    break;
                default:
                    Console.WriteLine("INVALID Account");
                    break;
            }
        }
        
        static void Main(string[] args)
        {
            //Console.Write("Enter no of Books: ");
            //int book = Convert.ToInt32(Console.ReadLine());
            //switchExpressionpractice.books(book);

            Console.Write("Enter order status: ");  
            string orderStatus = Console.ReadLine();    
            Console.WriteLine(switchExpressionpractice.status(orderStatus));    
        }
    }
}
