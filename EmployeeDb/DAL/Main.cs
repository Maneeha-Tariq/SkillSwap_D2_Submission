using Business_Object;
using Microsoft.Data.SqlClient;
using ProductMain;
using System.Data;
using System.Data.Common;
namespace P_Main
{
    public class Program
    {
        internal static void Main(string[] args)
        {
            string choice = "";
            char c = ' ';
            do
            {
                Console.WriteLine("1. Add Product ");
                Console.WriteLine("2. View All Products");
                Console.WriteLine("3. View Product by Id");
                Console.WriteLine("4. Update Product");
                Console.WriteLine("5. Delete Product");
                Console.WriteLine("6. Search Products by Name");
                Console.WriteLine("7. Export Products to JSON ");
                Console.WriteLine("8. Import Products from JSON ");
                Console.WriteLine("9.Update Product Price(Disconnected Model");
                Console.WriteLine("10. Exit ");

                Console.WriteLine("Enter your choice: ");

                choice = Console.ReadLine();
                switch (choice)
                {
                    case "1":

                        Console.WriteLine("Enter name");
                        string name = Console.ReadLine();
                        Console.WriteLine("Enter price");
                        decimal p = decimal.Parse(Console.ReadLine());
                        Console.WriteLine("Enter Quantity");
                        int q = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter catogory");
                        string catog = Console.ReadLine();

                        Product prd = new Product();
                        prd.Name = name;
                        prd.Price = p;
                        prd.QuantityInStock = q;
                        prd.Category = catog;
                        ProductDal pdal = new ProductDal();
                        pdal.AddProduct(prd);
                        break;

                    case "2":

                        ProductDal p1 = new ProductDal();
                        List<Product> l = p1.GetAllProducts();
                        foreach (Product e in l)
                        {
                            Console.WriteLine($"Id: {e.ProductId}, Name: {e.Name}, Price: {e.Price},Quantity: {e.QuantityInStock}, Catagory: {e.Category}");
                        }
                        break;

                    case "3":

                        ProductDal p2 = new ProductDal();
                        Console.WriteLine("Enter Id to search: ");
                        int id = int.Parse(Console.ReadLine());
                        p2.GetProductById(id);
                        break;

                    case "4":

                        Console.WriteLine("Enter Id to update");
                        int _id = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter name");
                        string _name = Console.ReadLine();
                        Console.WriteLine("Enter price");
                        decimal _p = decimal.Parse(Console.ReadLine());
                        Console.WriteLine("Enter Quantity");
                        int _q = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter catogory");
                        string _catog = Console.ReadLine();
                        Product _prd = new Product();
                        _prd.ProductId = _id;
                        _prd.Name = _name;
                        _prd.QuantityInStock = _q;
                        _prd.Category = _catog;

                        ProductDal p3 = new ProductDal();
                        p3.updateProduct(_prd);
                        break;

                    case "5":

                        ProductDal p4 = new ProductDal();
                        Console.WriteLine("Enter Id to delete: ");
                        int i = int.Parse(Console.ReadLine());
                        p4.deleteProduct(i);
                        break;

                    case "6":
                        ProductDal p5 = new ProductDal();
                        Console.WriteLine("Enter Name to search");
                        string na = Console.ReadLine();
                        List<Product> list1 = p5.SearchProductsByName(na);
                        foreach (Product e in list1)
                        {
                            Console.WriteLine($"Name: {e.Name}, Price: {e.Price},Quantity: {e.QuantityInStock}, Catagory: {e.Category}");
                        }
                        break;
                    case "7":
                        ProductDal p6 = new ProductDal();
                        Console.WriteLine("Enter path");
                        string path = Console.ReadLine();
                        p6.ExportProductsToJson(path);
                        break;
                    case "8":
                        ProductDal p7 = new ProductDal();
                        Console.WriteLine("Enter path");
                        string path1 = Console.ReadLine();
                        p7.ImportProductsFromJson(path1);
                        break;
                    case "9":
                        ProductDal p8 = new ProductDal();
                        Console.WriteLine("Enter Id to update");
                        int pId = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter price to update");
                        decimal newPrice = decimal.Parse(Console.ReadLine());
                        SqlDataAdapter adpt = new SqlDataAdapter();
                        DataTable dt = p8.LoadProductsTable();
                        p8.UpdatePriceInTable(dt, adpt, pId, newPrice);
                        break;
                    case "10":
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