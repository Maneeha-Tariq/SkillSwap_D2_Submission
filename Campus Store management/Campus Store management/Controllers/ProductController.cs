using Microsoft.AspNetCore.Mvc;
using System.Runtime.ConstrainedExecution;
using Campus_Store_management.Models;
using Campus_Store_management.Models.ViewModel;
namespace Campus_Store_management.Controllers
{
    public class ProductController : Controller
    {
        private static DashboardViewModel d = new DashboardViewModel();
        [HttpGet]
        public IActionResult Index()
        {
           
            return View(d.product); 
        }
        [HttpGet]
        public IActionResult Create()
        {
            return View();
        }
        [HttpPost]
        public IActionResult Create(Product prd)
        {
            if (!ModelState.IsValid)
            {
                return View("Create", prd);
            }

            d.product.Add(prd);

            TempData["success"] = "Product Added successfully";
            return RedirectToAction("Index");
        }
    }
}
