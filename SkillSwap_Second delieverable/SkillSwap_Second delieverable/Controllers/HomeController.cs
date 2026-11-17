using Microsoft.AspNetCore.Mvc;
using SkillSwap_Second_delieverable.Models;
using System.Diagnostics;

namespace SkillSwap_Second_delieverable.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
        public IActionResult Login()
        {
            return View();
        }
        public IActionResult Signup()
        {
            return View();
        }
    }
}
