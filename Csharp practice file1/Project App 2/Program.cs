// See https://aka.ms/new-console-template for more information
using System;
using Csharp_practice_file1;

namespace Project_App_2;
internal class ExceptionDemo
{
    int c;

    internal void Division(int a, int b)
    {
        try
        {
            c = a / b;
            Console.WriteLine(c);
        }
        catch (ArithmeticException x)
        {
            Console.WriteLine(x.Message.ToString());
        }
    }
}
internal class Program 
{
    internal static void Main(string[] args)
    {
        //ExceptionDemo obj = new ExceptionDemo();
        //obj.Division(10, 0);
        //Console.ReadKey();
        CollectionSystem obj = new CollectionSystem();
        // obj.ArrayList();
        //obj.HashTable();
        obj.linkedlist();
        //Console.ReadLine();
    }
}