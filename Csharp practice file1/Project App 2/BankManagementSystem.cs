using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security.Cryptography;
namespace Project_App_2
{
    struct BankAccount
    {
        public int accountNo;
        public string name;
        public double currentBalance;
    }
    internal class BankManagementSystem
    {
        BankAccount account;
        FileD file;
        internal BankManagementSystem()
        {
            account = new BankAccount();
            file = new FileD();
        }
        internal void AccountDetails()
        {

            int accountNumber;
            Console.WriteLine("Enter Account Number: ");
            accountNumber = Convert.ToInt32(Console.ReadLine());
            if(accountNumber <= 0)
            {
                throw new Exception("Invalid Account Number");
            }

            string name;
            Console.WriteLine("Enter Account Holder Name: ");
            name = Console.ReadLine();

            if (string.IsNullOrWhiteSpace(name))
                throw new NameInvalidException();


            foreach (char ch in name)
            {
                if (!char.IsLetter(ch) && ch != ' ')
                    throw new NameInvalidException();
            }

            double balance;
            Console.WriteLine("Enter your current Balance: ");
            balance = Convert.ToDouble(Console.ReadLine());
            if(balance<0)
            {
                throw new NegativeBalanceException();
            }

            CreateAccount(accountNumber, name, balance);
            // store account details into file

            file.CreateFile();
            file.WriteToFile(accountNumber,name,balance);

        }
        internal void CreateAccount(int accountNumber,string n,double balance)
        {
            account.accountNo = accountNumber;
            account.name = n;
            account.currentBalance = balance;
            Console.WriteLine("Your Account have been successfully created");
        }
        internal void Credit(double amount)
        { 
            account.currentBalance+=  amount;
            Console.WriteLine($"{amount} amount have been added to your account successfully");
            Console.WriteLine($"Your current balance is {account.currentBalance}");
            DateTime dt = DateTime.Now;
            using(StreamWriter sw = new StreamWriter(file.path,true))
            {
                sw.WriteLine($"You have credited {amount} amount at time {dt.ToLongTimeString()} and on {dt.ToShortDateString()}");
                sw.WriteLine($"After credit your current balance is {account.currentBalance}");
            }
        }
        internal void Debit(double amount)
        {
            if (amount > account.currentBalance)
            {
                throw new AmountExceedsBalanceException();
            }
            account.currentBalance -= amount;
            Console.WriteLine($"{amount} amount have been debited from your account successfully");
            Console.WriteLine($"Your current balance is {account.currentBalance}");
            DateTime dt = DateTime.Now;
            using (StreamWriter sw = new StreamWriter(file.path, true))
            {
                sw.WriteLine($"You have debited {amount} amount at time {dt.ToLongTimeString()} and on {dt.ToShortDateString()}");
                sw.WriteLine($"After debit your current balance is {account.currentBalance}");
            }
        }
        internal double CheckBalance()
        {
            return account.currentBalance;
        }
    }
   
   
}
