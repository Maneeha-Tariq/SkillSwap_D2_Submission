using System;
using System.Collections.Generic;
using System.Diagnostics.Metrics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class Inheritance
    {
        class Animal
        {
          

            internal Animal()
            {
                Console.WriteLine("Simple Animal constructor called.");
            }
           internal Animal(string name)
           {
               
                Console.WriteLine("Parametrized Animal constructor called.");
           }
           public  virtual void  Speak()
           {
             Console.WriteLine("Animal voice");
           }
        }

        class Dog : Animal
        {
            internal Dog()
            {
                Console.WriteLine("Dog constructor called.");
            }
            public virtual void Speak() 
            {
             Console.WriteLine(" Woof!");
            }
        }
        class octopus: Dog
        {
            internal octopus()
            {
                Console.WriteLine("octopus constructor called.");
            }
            public override void Speak()
            {
                Console.WriteLine("squawk!");
            }   
        }
        static void Main(string[] args)
        {
           Animal obj = new Dog();
           obj.Speak();
           Dog obj1 = new octopus();
           obj1.Speak();
        }

    }
}
