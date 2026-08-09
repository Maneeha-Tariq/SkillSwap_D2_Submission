using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_practice_file1
{
    internal class Username_Password
    {
        string firstname;
        string lastname;
        public Username_Password(string f,string l)
        {
            firstname = f;
            lastname = l;
        }
        public void checkCredentials(string username,string password)
        {
            if(username == firstname && password == lastname)
            {
                Console.WriteLine("Username and Password are VALID");
            }
            else if(username == firstname&& password!= lastname)
            {
                Console.WriteLine("INVALID password");
            }
            else if(username != firstname && password == lastname)
            {
                Console.WriteLine("INVALID username");
            }
            else
            {
                Console.WriteLine("INVALID username and password");
            }
        }
        static void Main(string[] args)
        {
            Username_Password obj = new Username_Password("Maneeha", "Tariq");
            obj.checkCredentials("Maneeh", "Tariq");
        }
    }
}
