using CookieExamPractice.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using System.Text.Json;

namespace CookieExamPractice.Controllers
{
    public class ExamController : Controller
    {
        string s = "Preferences";
        [HttpPost]
        public IActionResult SavePreferences(string subject,string examMode,int duration)
        {
            List<ExamPreference> list = new List<ExamPreference>();
            if (HttpContext.Request.Cookies[s]!=null)
            {
                string? cook = HttpContext.Request.Cookies[s];
                list = JsonSerializer.Deserialize<List<ExamPreference>>(cook)?? new List<ExamPreference>();
            }
            ExamPreference ?prefer = list.FirstOrDefault(x => x.Subject == subject);
            if(prefer!=null)
            {
                prefer.ExamMode = examMode;
                prefer.Duration = duration;
            }
            else
            {
                list.Add( new ExamPreference
                {
                    Subject = subject,
                    ExamMode = examMode,
                    Duration = duration,
                });
            }
            CookieOptions options = new CookieOptions();
            options.Expires = DateTime.Now.AddDays(5);
            options.HttpOnly = true;
            HttpContext.Response.Cookies.Append(s, JsonSerializer.Serialize(list), options);

            return RedirectToAction("ShowPreferences");
        }

        public IActionResult ShowPreferences()
        {
            List<ExamPreference> list = new List<ExamPreference>();

            if (HttpContext.Request.Cookies[s] != null)
            {
                string ?cook = HttpContext.Request.Cookies[s];
                list = JsonSerializer.Deserialize<List<ExamPreference>>(cook) ?? new List<ExamPreference>() ;
            }
            ExamPreferenceViewModel viewModel = new ExamPreferenceViewModel();
            viewModel.Plist = list;
            viewModel.Count = list.Count;


            return View(viewModel);
        }

        public IActionResult RemovePreferences(string subject)
        {
            List<ExamPreference> list = new List<ExamPreference>();

            if (HttpContext.Request.Cookies[s] != null)
            {
                string? cook = HttpContext.Request.Cookies[s];
                list = JsonSerializer.Deserialize<List<ExamPreference>>(cook)?? new List<ExamPreference>();
            }
            ExamPreference ?prefer = list.FirstOrDefault(x => x.Subject == subject);
            if (prefer != null)
            {
                list.Remove(prefer);
            }

            CookieOptions options = new CookieOptions();
            options.Expires = DateTime.Now.AddDays(5);
            options.HttpOnly = true;
            HttpContext.Response.Cookies.Append(s, JsonSerializer.Serialize(list), options);
            return RedirectToAction("ShowPreferences");
        }
        public IActionResult Delete()
        {
            if (HttpContext.Request.Cookies[s] != null)
            {
                HttpContext.Response.Cookies.Delete(s);
            }
            return RedirectToAction("ShowPreferences");
        }
    }
}
