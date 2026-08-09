using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class Asynchorous_Programmingcs
    {


        //static async Task Work(int id, int seconds)
        //{
        //    Console.WriteLine($"Start {id}");

        //    await Task.Delay(seconds * 1000);

        //    Console.WriteLine($"End {id}");
        //}
        //// mainstart Start1 start2 Middle End2 End1 MainEnd
        //static async Task Main()
        //{
        //    Console.WriteLine("Main Start");

        //    Task t1 = Work(1, 3);

        //    await Task.Delay(1000);

        //    Task t2 = Work(2, 1);

        //    Console.WriteLine("Middle");

        //    await Task.WhenAll(t1, t2);

        //    Console.WriteLine("Main End");
        //}

        static SemaphoreSlim pool = new SemaphoreSlim(3); // max 3 concurrent
     
        static async Task AccessResource(int id)
        {
            await pool.WaitAsync();
            try
            {
                Console.WriteLine($"Worker {id} entered ({pool.CurrentCount} slots left)");
                await Task.Delay(1000);
                Console.WriteLine($"Worker {id} leaving ({pool.CurrentCount} slots left)");
            }
            finally
            {
                pool.Release();
            }
        }
        static async Task Main()
        {
            var tasks = new Task[6];
            for (int i = 0; i < 6; i++)
                tasks[i] = AccessResource(i);
            
            await Task.WhenAll(tasks);
        }
    }

}


