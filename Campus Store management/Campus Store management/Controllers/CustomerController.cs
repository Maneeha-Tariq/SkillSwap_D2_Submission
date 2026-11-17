using Campus_Store_management.Models;
using Campus_Store_management.Models.ViewModel;
using Microsoft.AspNetCore.Mvc;

namespace Campus_Store_management.Controllers
{
    public class CustomerController : Controller
    {
        public IActionResult Index()
        {
            DashboardViewModel d = new DashboardViewModel();
            return View(d.customer);
        }
    }
}
