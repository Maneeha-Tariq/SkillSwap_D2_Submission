using Bussiness_Object;
using System.Runtime.Serialization;

using System.Text.Json;

namespace SerializeDeserialize
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Order obj = new Order();
            obj.OrderId = 101;
            obj.CustomerName = "Ali";
            obj.OrderDate = "24-09-2026";
            obj.ShippingAddress = "Pakistan";
            Product pr = new Product();
            pr.ProductId = 1;
            pr.Name = "Laptop";
            pr.Quantity = 1;
            pr.Price = 15000;
            Product pr1 = new Product();
            pr1.ProductId = 2;
            pr1.Name = "Mouse";
            pr1.Quantity = 2;
            pr1.Price = 5000;
            Product pr3 = new Product();
            pr3.ProductId = 3;
            pr3.Name = "Keyboard";
            pr3.Quantity = 1;
            pr3.Price = 2000;
            obj.Products = new List<Product>();
            obj.Products.Add(pr);
            //obj.Products.Add(pr1);
            obj.Products.Add(pr3);

            //string serStr = JsonSerializer.Serialize(obj);
            ////Console.WriteLine(serStr);
            //FileStream fs = new FileStream("Order.txt", FileMode.Create);
            //StreamWriter sw = new StreamWriter(fs);
            //sw.Write(serStr);
            //sw.Close();
            //FileStream fs1 = new FileStream("Order.txt", FileMode.Open);
            //StreamReader sr = new StreamReader(fs1);
            //string str = sr.ReadLine();
            //while (str != null)
            //{
            //    Console.WriteLine(str);
            //    str = sr.ReadLine();
            //}
            //sr.Close();
            obj.ShippingAddress = "Lahore Pakistan";
            pr1.Quantity = 3;
            obj.Products.Add(pr1);
            string serStr1 = JsonSerializer.Serialize(obj);
            FileStream fss = new FileStream("Order.txt", FileMode.Create);
            StreamWriter sw1 = new StreamWriter(fss);
            sw1.Write(serStr1);
            sw1.Close();
            Order o1 = JsonSerializer.Deserialize<Order>(serStr1);
            Console.WriteLine($"Id: {o1.OrderId}, Name:{o1.CustomerName}, Qtty: {o1.OrderDate},Address: {o1.ShippingAddress} ");
            foreach(Product p in o1.Products)
            {
                Console.WriteLine($"[Id: {p.ProductId}, Name: {p.Name}, Qtty: {p.Quantity}, Price: {p.Price}]");
            }
        }

        }
    }
