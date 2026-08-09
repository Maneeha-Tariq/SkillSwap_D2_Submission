using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_App_2
{
    internal class Threading
    {
        int marks;
        double per;
        internal void Hello()
        {
            for(int i=1;i<=10;i++)
            {
                Console.WriteLine("Hello");
                Thread.Sleep(1000);
            }
        }
        internal void Welcome()
        {
            for (int i = 1; i <= 5; i++)
            {
                Console.WriteLine("Welcome");
            }
        }
        internal void PrintNumbr()
        {
            for (int i = 1; i <= 10; i++)
            {
                Console.WriteLine(i);
            }
        }
        internal void Student(object name)
        {
            Console.WriteLine(name);
        }

       internal void InputMarks()
       {
            Console.WriteLine("Enter Marks");
            marks = Convert.ToInt32(Console.ReadLine());
       }
        internal void CalculatePercentage()
        {
            per = (marks / (double)200) * 100;
        }

        internal void DisplayGrade()
        {
            if(per<50)
            {
                Console.WriteLine("F");
            }
            else if(per>=50&& per<=60)
            {
                Console.WriteLine("D");
            }
            else if(per>60&& per<80)
            {
                Console.WriteLine("C");
            }
            else
            {
                Console.WriteLine("A");
            }
        }
        internal static void Main(string[] args)
        {
            //    Threading obj = new Threading();
            //    Thread t = new Thread(obj.InputMarks);
            //    t.Start();
            //    t.Join();
            //    Thread t1 = new Thread(obj.CalculatePercentage);
            //    t1.Start();
            //    t1.Join();
            //    Thread t2 = new Thread(obj.DisplayGrade);
            //    t2.Start();
            //    t2.Join();
            //    //Threading th1 = new Threading();
            //    //ThreadStart ts1 = new ThreadStart(th1.Hello);
            //    //Thread t1 = new Thread(ts1);
            //    //t1.IsBackground = true;
            //    //t1.Start();
            //    //ThreadStart ts2 = new ThreadStart(th1.Welcome);
            //    //Thread t2 = new Thread(ts2);
            //    //t2.Start();
            //    Console.WriteLine("Main Finished");

            for (int i = 0; i < 5; i++)
            {
                int captured = i;
                //ThreadPool.QueueUserWorkItem(state =>
                //{
                //    Console.WriteLine($"Task {captured} on thread " +
                //    $"{Thread.CurrentThread.ManagedThreadId} (pooled: " +
                //    $"{Thread.CurrentThread.IsThreadPoolThread})");
                //});
                Thread t = new Thread(() =>
                {
                    Console.WriteLine($"Task {captured} on thread " +
                    $"{Thread.CurrentThread.ManagedThreadId} (pooled: " +
                    $"{Thread.CurrentThread.IsThreadPoolThread})");
                });
                t.Start();
                Thread.Sleep(500);
            }
        }

    }
}
