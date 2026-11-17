using Cookie.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace Cookie.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult SetCookie()
        {
            if (!HttpContext.Request.Cookies.ContainsKey("Username"))
            {
                CookieOptions option = new CookieOptions();
                option.Expires = DateTime.Now.AddDays(3);
                HttpContext.Response.Cookies.Append("Username", "Maneeha", option);
                ViewBag.found = "Cookie created successfully";
            }
            else
            {
                ViewBag.found = "Cookie already found";
            }
            return View();
        }

        public IActionResult ReadCookie()
        {
            if (HttpContext.Request.Cookies.ContainsKey("Username"))
            {
                string cookie = HttpContext.Request.Cookies["Username"];
                ViewBag.cook = $"Cookie contains {cookie}";
            }
            else
            {
                ViewBag.cook = "Cookie not found please create it first";
            }
            return View();
        }
        public IActionResult DeleteCookie()
        {
            if (HttpContext.Request.Cookies.ContainsKey("Username"))
            {
                HttpContext.Response.Cookies.Delete("Username");
                ViewBag.cook = $"Cookie deleted successfully";
            }
            else
            {
                ViewBag.cook = "Cookie not found please create it first";
            }
            return View();
        }


    }
}
