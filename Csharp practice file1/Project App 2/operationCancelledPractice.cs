using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_App_2
{
    internal class operationCancelledPractice
    {
        internal static async Task Main(string[] args)
        {
            CancellationTokenSource cts = new CancellationTokenSource();
            Task worker = Task.Run(() =>
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!cts.Token.IsCancellationRequested)
                    {
                        Console.WriteLine($"Worker {i}");
                        Thread.Sleep(200);
                    }
                    else
                    {
                        cts.Token.ThrowIfCancellationRequested();
                    }
                }
            },cts.Token);
            Thread.Sleep(800);
            cts.Cancel();
            //try
            //{
            //  await worker;
            //}
            //catch (Exception ex)
            //{
            //    Console.WriteLine(ex.GetType().Name);

            //}
        }
    }
}
