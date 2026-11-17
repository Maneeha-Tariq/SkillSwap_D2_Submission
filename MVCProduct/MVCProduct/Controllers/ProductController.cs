using Microsoft.AspNetCore.Mvc;
using MVCProduct.Models;
using System.Diagnostics;
using MVCProduct.Repository;
namespace MVCProduct.Controllers
{
    public class ProductController : Controller
    {
        public async Task<IActionResult> Index()
        {
            ProductRepo p = new ProductRepo();
            List<Product>products = await p.getAllProducts();
            return View(products);
        }
       
        public async Task<IActionResult> Create(Product prod)
        {
            Console.WriteLine("NAME = " + prod.ProductName);
            Console.WriteLine("PRICE = " + prod.price);

            ProductRepo p = new ProductRepo();
            await p.AddProduct(prod);
            return View();
        }
    }
}
