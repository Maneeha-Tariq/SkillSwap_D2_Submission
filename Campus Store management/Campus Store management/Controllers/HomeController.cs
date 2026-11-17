using Campus_Store_management.Models;
using Campus_Store_management.Models.ViewModel;
using Microsoft.AspNetCore.Mvc;

using System.Diagnostics;

namespace Campus_Store_management.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            DashboardViewModel d = new DashboardViewModel();
            return View(d);
        }
    }
}
