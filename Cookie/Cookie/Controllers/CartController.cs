using Cookie.Models;
using Microsoft.AspNetCore.Mvc;

namespace Cookie.Controllers
{
    public class CartController : Controller
    {
        public IActionResult Index()
        {
            List<Product> products = new List<Product>
            {
                new Product { Id = 1, Name = "Keyboard", Price = 2500 },
                new Product { Id = 2, Name = "Mouse", Price = 1200 }
            };

            ViewBag.Products = products;

            string? cart = HttpContext.Request.Cookies["Cart"];

            ViewBag.Cart = cart;

            return View();
        }

        public IActionResult AddToCart(string name)
        {
            string? cart = HttpContext.Request.Cookies["Cart"];

            if (cart == null)
            {
                cart = name;
            }
            else
            {
                cart = cart + "," + name;
            }

            CookieOptions options = new CookieOptions();
            options.Expires = DateTime.Now.AddDays(3);

            HttpContext.Response.Cookies.Append("Cart", cart, options);

            return RedirectToAction("Index");
        }
    }

}
