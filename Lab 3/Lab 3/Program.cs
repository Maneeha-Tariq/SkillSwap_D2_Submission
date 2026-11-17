
using Microsoft.Data.SqlClient;
using LabLibrary;
using System.Diagnostics;


namespace Lab_3
{
    internal class Program
    {
        static async Task MethodA()
        {
            Console.WriteLine("Start A");
            await Task.Delay(3000);
            Console.WriteLine("Finish A");
        }
        static async Task MethodB()
        {
            Console.WriteLine("Start B");
            await Task.Delay(2000);
            Console.WriteLine("Finish B");
        }
        static async Task MethodC()
        {
            Console.WriteLine("Start C");
            await Task.Delay(1000);
            Console.WriteLine("Finish C");
        }
        static async Task Main(string[] args)
        {
         var timer = Stopwatch.StartNew();
            //asynchronous + concurrent
            Task tA = MethodA();
            Task tb = MethodB();
            Task tC = MethodC();
            await Task.WhenAll(tA, tb, tC);

            // executes the asynchronous operations sequentially, but it does not block the thread while waiting.
            //await MethodA();
            //await MethodB();
            //await MethodC();


            Console.WriteLine($"Total time : {timer.ElapsedMilliseconds} ms");
        }
    }
}
