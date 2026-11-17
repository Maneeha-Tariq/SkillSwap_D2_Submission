using FirstMvCProject.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using FirstMvCProject.Repositories;

namespace FirstMvCProject.Controllers
{
    public class StudentController: Controller
    {
        public IActionResult Index()
        {
            StudentRepository repo = new StudentRepository();
            List<Student> students = repo.ViewAllStudent();
            return View(students);
        }
       
        public IActionResult Create(Student student)
        {
            StudentRepository repo = new StudentRepository();
            repo.AddStudent(student);
            return View();
        }
        public IActionResult Edit(Student student)
        {
            StudentRepository repo = new StudentRepository();
            repo.UpdateStudent(student.StudentId, student);
            return View();
        }
        public IActionResult Delete(int id)
        { 
            StudentRepository repo = new StudentRepository();
            repo.DeleteStudent(id);
            return View();
        }
    }
}
