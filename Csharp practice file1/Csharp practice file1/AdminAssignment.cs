using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class AdminAssignment
    {
        int id;
        string name;
        public int Id
        {
            get
            {
                return id;
            }
        }
        public string Name
        {
            get
            {
                return name;
            }
        }
        internal void Accept(int id,string name)
        {
            this.id = id;
            this.name = name;
        }
        internal void Display()
        {
            Console.WriteLine("AdminId = {0}, AdminName = {1}", id, name);
        }

    }
    internal class Manager: AdminAssignment
    {
        float salary;
        public float Salary
        {
            get
            {
                return salary;
            }
        }
        internal void Accept1(float salary)
        {
            this.salary = salary;
        }
        internal void Display1()
        {
            Console.WriteLine("ManagerId = {0} , ManagerName = {1}, ManagerSalary = {2}", Id, Name, salary);
        }
    }
    internal class Employee: Manager
    {
        float incentive;
        internal void Accept2(float incentive)
        {
            this.incentive = incentive;
        }
        internal void Display2()
        {
            Console.WriteLine("EmployeeId = {0} , EmployeeName = {1} , EmployeeSalary = {2} , EmployeeIncentive = {3} ", Id, Name,Salary,incentive);
        }
    }
    internal class  AMain
    {
        internal static void Main(string[] args)
        {
            Employee obj = new Employee();
            obj.Accept(101, "John");
            obj.Accept1(50000);
            obj.Accept2(6000);
            obj.Display2();
            Console.WriteLine(obj.GetType());
          
        }
    }
}
