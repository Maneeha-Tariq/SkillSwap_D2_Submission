using Business_Object;
using EmployeeDAL;

namespace EmployeeMain
{
    public class EmployeeMain
    {
        static void Main(string[] args)
        {
            Employeedal ed = new Employeedal();
            Console.WriteLine(" ========== Employee Management System ==========");

            char choice = ' ';
            char c = ' ';
            do
            {
                Console.WriteLine("1. Add Employee ");
                Console.WriteLine("2. View All Employees");
                Console.WriteLine("3. Search Employee");
                Console.WriteLine("4. Update Employee");
                Console.WriteLine("5. Delete Employee");
                Console.WriteLine("6. Exit");
                Console.WriteLine("Enter your choice: ");

                choice = char.Parse(Console.ReadLine());
                switch (choice)
                {
                    case '1':
                        Employee emp = new Employee();
                        Console.WriteLine("Enter Name: ");
                        emp.Name = Console.ReadLine();
                        Console.WriteLine("Enter Department: ");
                        emp.Dept = Console.ReadLine();
                        Console.WriteLine("Enter Salary: ");
                        emp._Salary = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter Email: ");
                        emp.Email = Console.ReadLine();
                        ed.AddEmployee(emp);
                        break;
                    case '2':
                        List<Employee> l = ed.ViewAllEmployees();
                        foreach (Employee e in l)
                        {
                            Console.WriteLine($"Id: {e.Id}, Name: {e.Name}, Dept: {e.Dept}, Salary: {e._Salary},Email: {e.Email}");
                        }
                        break;
                    case '3':
                        Console.WriteLine("Enter Id to search: ");
                        int id = int.Parse(Console.ReadLine());
                        ed.SearchEmployee(id);
                        break;
                    case '4':
                        Employee emp1 = new Employee();
                        Console.WriteLine("Enter Id to update record: ");
                        emp1.Id = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter Name: ");
                        emp1.Name = Console.ReadLine();
                        Console.WriteLine("Enter Department: ");
                        emp1.Dept = Console.ReadLine();
                        Console.WriteLine("Enter Salary: ");
                        emp1._Salary = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter Email: ");
                        emp1.Email = Console.ReadLine();
                        ed.UpdateEmployee(emp1);
                        break;
                    case '5':
                        Console.WriteLine("Enter Id to delete: ");
                        int i = int.Parse(Console.ReadLine());
                        ed.DeleteEmployee(i);
                        break;
                    case '6':
                        Console.WriteLine("Exit");
                        return;
                    default:
                        Console.WriteLine("Invalid choice");
                        break;

                }
                Console.WriteLine("Do you want to take any choices again? y/n : ");
                c = char.Parse(Console.ReadLine());

            } while (c == 'Y' || c == 'y');

            
        }

    }
}
