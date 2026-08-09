// See https://aka.ms/new-console-template for more information
using System;
using Csharp_practice_file1;

class Program
{
    static int b = 20;
    int vari = 10;

    static void Main(string[] args)
    {
        //int a = Convert.ToInt32(Console.ReadLine());
        //int b = Convert.ToInt32(Console.ReadLine());
        //basicCalc obj = new basicCalc();
        //int c = obj.add(a, b);
        //Console.WriteLine(c);
        // --------------------------------------------------------------

        //Program obj = new Program();
        //Console.WriteLine($"a is {obj.vari}"); // string interpolation method 
        //Console.WriteLine("a is " + obj.vari + " "); // string concatenation method
        //Console.WriteLine("a is {0} and b is {1} ", obj.vari, b); // Placeholder method
        //Console.WriteLine(b);
        // ----------------------------------------------------------------------

        //For Swap Program
        int num1 = Convert.ToInt32(Console.ReadLine());
        int num2 = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Before Swap");

        Console.WriteLine("num1 = {0} ", num1);
        Console.WriteLine("num2 = {0} ", num2);

        SwapProgram obj = new SwapProgram();
        Console.WriteLine("After Swap");
        obj.swap(ref num1, ref num2);
        Console.WriteLine("num1 = {0} ", num1);
        Console.WriteLine("num2 = {0} ", num2);

        //Console.Write("Enter radius: ");
        //double r = Convert.ToDouble(Console.ReadLine());
        //AreaCircle obj1 = new AreaCircle(r);
        //obj1.area();

        //CompoundInterest ob = new CompoundInterest(10000,1,2,0.10);
        //ob.interest();




    }
}
