using Microsoft.AspNetCore.Mvc;
using DI_with_Partial_View.Models;

namespace DI_with_Partial_View.Controllers
{
    public class StudentController : Controller
    {
        private readonly IStudentRepository studentRepository;
        public StudentController(IStudentRepository studentRepository)
        {
            this.studentRepository = studentRepository;
        }
        public IActionResult Index()
        {
            List<Student> std = studentRepository.GetAllStudents();

            return View(std);
        }

        [HttpGet]
        public IActionResult Create()
        {
            return View();
        }
        [HttpPost]
        public IActionResult Create(Student student)
        {
            studentRepository.AddStudent(student);
            return RedirectToAction("Index");
        }
    }
}
