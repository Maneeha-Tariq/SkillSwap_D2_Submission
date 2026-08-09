using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_App_2
{

    internal class FileD
    {
        public string path = "AccountDetails.txt";
        internal void CreateFile()
        {
            if (!File.Exists(path))
            {
                File.Create(path).Close();
                Console.WriteLine("File Created Successfully");
            }
            else
            {
                Console.WriteLine("File already exists");
            }
        }
        internal void WriteToFile(int Acc, string name, double balance)
        {
            using (StreamWriter sw = new StreamWriter(path, true))
            {
                sw.WriteLine("-------------------------------------");
                sw.WriteLine("Account number is : " + Acc);
                sw.WriteLine("Account Holder Name is: " + name);
                sw.WriteLine("CurrentBalance is: " + balance);
                sw.WriteLine("-------------------------------------");
                sw.WriteLine();
            }
        }

    }
}
