using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Project_App_2
{
    internal class synchorizationPrimitivesPractice
    {
        private static int counter = 0;
        public int count
        {
            get
            {
                return counter;
            }
        }
        internal void increment()
        {
            for (int i = 0; i < 1000; i++)
            {
                Interlocked.Increment(ref counter);
            }
        }
        internal static void Main(string[] args)
        {
            synchorizationPrimitivesPractice sp = new synchorizationPrimitivesPractice();
            ThreadStart ts = sp.increment;
            Thread t1 = new Thread(ts);
            Thread t2 = new Thread(ts);
            Thread t3 = new Thread(ts);
            Thread t4 = new Thread(ts);
            Thread t5 = new Thread(ts);
            t1.Start();
            t2.Start();
            t3.Start();
            t4.Start();
            t5.Start();
            t1.Join();
            t2.Join();
            t3.Join();
            t4.Join();
            t5.Join();
            Console.WriteLine($"Count is {sp.count}");
        }
    }
    internal class SemaphorSlimPractice
    {
        private static SemaphoreSlim pool = new SemaphoreSlim(2);

        internal async Task WorkerEnter(int i)
        {
            await pool.WaitAsync();
            try
            {
                Console.WriteLine($"Worker {i} is entering and the current count is {pool.CurrentCount}");
                await Task.Delay(2000);
                Console.WriteLine($"Worker {i} is leaving and the current Count is  {pool.CurrentCount}");
            }
            finally
            {
                pool.Release();
            }
        }
        public static async Task Main(string[] args)
        {
            SemaphorSlimPractice sm = new SemaphorSlimPractice();
            var tasks = new Task[5];
            for (int i = 0; i < 5; i++)
            {
                tasks[i] = sm.WorkerEnter(i);
            }
            await Task.WhenAll(tasks);
        }
    }
    internal class VolatilePractice
    {
        private static volatile bool check = true;
        internal void print()
        {
            while (check)
            {
                Console.WriteLine("Writing....");
            }
        }
        internal static void Main(string[] args)
        {
            VolatilePractice vp = new VolatilePractice();
            ThreadStart ts = vp.print;
            Thread t = new Thread(ts);
            t.Start();
            Thread.Sleep(5000);
            check = false;
            t.Join();
        }
    }
    internal class MonitorTryEnterPractice
    {
        private static readonly object locker = new object();
        internal void Print()
        {
            lock (locker)
            {
                Console.WriteLine("Lock 1 print");
                Thread.Sleep(5000);
            }
        }
        internal void fun2()
        {
            bool lockToken = false;

            try
            {
                Monitor.TryEnter(locker, TimeSpan.FromSeconds(2), ref lockToken);
                if (lockToken)
                {
                    Console.WriteLine("Lock acquired");
                }
                else
                {
                    Console.WriteLine("Could'nt acquire Lock");
                }
            }
            finally
            {
                if (lockToken)
                {
                    Monitor.Exit(locker);
                }
            }

        }
        internal static void Main(string[] args)
        {
            MonitorTryEnterPractice vp = new MonitorTryEnterPractice();
            ThreadStart ts = vp.Print;
            Thread t = new Thread(ts);
            Thread t1 = new Thread(vp.fun2);
            t.Start();
            t1.Start();

            t.Join();
            t1.Join();
        }


    }
    internal class PAsynch
    {

        static async Task Main()
        {
            Console.WriteLine("Customer placed an order.");

            Task<string> foodTask = PrepareFood();

            Task<string> billTask = GenerateBill();

            string food = await foodTask;

            string bill = await billTask;

            Console.WriteLine(food);
            Console.WriteLine(bill);

            Console.WriteLine("Order Completed.");
        }

        static async Task<string> PrepareFood()
        {
            Console.WriteLine("Kitchen Started");

            await Task.Delay(3000);

            return "Pizza Ready";
        }

        static async Task<string> GenerateBill()
        {
            Console.WriteLine("Cashier Started");

            await Task.Delay(2000);

            return "Bill Ready";
        }
}
    internal class P2Arch
    {
        static async Task Main()
        {
            Console.WriteLine("Application Started");

            await Login();

            Console.WriteLine("Application Finished");
        }

        static async Task Login()
        {
            Console.WriteLine("Checking Login...");

            string user = await GetUser();

            Console.WriteLine($"Welcome {user}");

            await GetOrders(user);
        }

        static async Task<string> GetUser()
        {
            Console.WriteLine("Loading User...");

            await Task.Delay(2000);

            return "Maneeha";
        }

        static async Task GetOrders(string user)
        {
            Console.WriteLine($"Loading Orders of {user}");

            await Task.Delay(3000);

            Console.WriteLine("Orders Loaded");
        }
    }
    internal class p3Async
    {
       static async Task Main(string[] args)
        {
            //await StartExam();
            //string str = await SubmitExam();
            //Console.WriteLine($"{str}");
         await Task.Run(() =>
           {
               Console.WriteLine("Downloading");
           })
           .ContinueWith(t =>
           {
               Console.WriteLine("Processing");
           })
           .ContinueWith(t => {
               Console.WriteLine("Saving");
           });
       
            Console.WriteLine("Main finished");
        }
        static async Task StartExam()
        {
            Console.WriteLine("Exam Started");
           string str =  await LoadQuestions();
           Console.WriteLine(str);
        }
        static async Task<string> LoadQuestions()
        {
            string str = await CheckInternet();
            Console.WriteLine(str);
            await Task.Delay(TimeSpan.FromSeconds(2));
            return "Questions Loaded";
        }
        static async Task<string> CheckInternet()
        {
            await Task.Delay(TimeSpan.FromSeconds(1));
            return "Internet Connected";
        }
        static async Task<string> SubmitExam()
        {
            await Task.Delay(TimeSpan.FromSeconds(1));
            return "Exam Submitted Successfully";
        }
    }

}

