using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_App_2
{
    internal class threadwithlambda
    {
        static void Add(int a, int b)
        {
            Console.WriteLine(a + b);
        }
        internal static void Main(string[] args)
        {
            // it doesnot execute the function it is just thread
            // creation if you want to execute start the thread 
            Thread t4 = new Thread(() =>
            {
                for(int i=0;i<5;i++)
                {
                    Console.WriteLine($"Task Started on {Thread.CurrentThread.ManagedThreadId}");
                    Thread.Sleep(300);
                }
            });
           
            Thread t3= new Thread(() =>
            {
                Add(2, 3);
            });

            Thread t = new Thread(() =>
            {
                Console.WriteLine("------Even numbers btw 2 to 50(inclusive)------");
                int n = 7;
                for (int i = 2; i <= 50; i++)
                {
                    if (i % 2 == 0)
                    {
                        Console.WriteLine($"{i}");
                    }
                    Thread.Sleep(200);
                }
            });
           
            Thread t1 = new Thread(() =>
            {
                Console.WriteLine("-----Alphabets from A to J-----");
                for (char i = 'A'; i <= 'J'; i++)
                {
                    Console.WriteLine(i);
                    Thread.Sleep(500);
                }
            });

            // Console.WriteLine("Even numbers completed.");
            string name=" ";
            int age = default;
            Thread th = new Thread(() =>
            {
                Console.WriteLine("Enter name of student");
                name = Console.ReadLine();
            });
            th.Start();
            th.Join();
            Thread th1 = new Thread(() =>
            {
                Console.WriteLine("Enter age of student");
                age = Convert.ToInt32(Console.ReadLine());
            });
            th1.Start();
            th1.Join();
            Thread th2 = new Thread(() =>
            {
                Console.WriteLine("-------Student Details-------");
                Console.WriteLine($"Student name = {name},age = {age}");
            });
            th2.Start();
            th2.Join();
        }
    }
}
