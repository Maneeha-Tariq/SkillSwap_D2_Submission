
using DapperPractice.Models;
using DapperPractice.Models.Interface;
using Microsoft.AspNetCore.Mvc;

namespace DapperPractice.Controllers
{
    public class StudentController : Controller
    {
        private readonly IStudentRepository _repo;

        public StudentController(IStudentRepository repo)
        {
            _repo = repo;
        }

        // GET ALL
        public IActionResult GetAll()
        {
            var students = _repo.GetAllStudents();
            return View(students);
        }

        // GET BY ID
        public IActionResult GetById(int id)
        {
            var student = _repo.GetStudentById(id);
            return View(student);
        }

        // ADD
        [HttpGet]
        public IActionResult Add()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Add(Student student)
        {
            _repo.AddStudent(student);
            return RedirectToAction("GetAll");
        }

        // UPDATE
        [HttpGet]
        public IActionResult Update(int id)
        {
            var student = _repo.GetStudentById(id);
            return View(student);
        }

        [HttpPost]
        public IActionResult Update(Student student)
        {
            _repo.UpdateStudent(student);
            return RedirectToAction("GetAll");
        }

        // DELETE
        [HttpGet]
        public IActionResult Delete(int id)
        {
            var student = _repo.GetStudentById(id);
            return View(student);
        }

        // POST: Confirm Delete
        [HttpPost, ActionName("Delete")]
        public IActionResult DeleteConfirmed(int id)
        {
            _repo.DeleteStudent(id);
            return RedirectToAction("GetAll");
        }
    }
}
