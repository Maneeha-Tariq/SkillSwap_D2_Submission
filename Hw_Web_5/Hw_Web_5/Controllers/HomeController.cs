using Hw_Web_5.Models;
using Hw_Web_5.ViewModels;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace Hw_Web_5.Controllers
{
    public class HomeController : Controller
    {
        public  List<Author> authors = new List<Author>
        {
            new Author { Id = 1, Name = "Ali", Country = "Pakistan" },
            new Author { Id = 2, Name = "Ahmed", Country = "India" }
        };
        public static List<Book> books = new List<Book>
        {
            new Book { Id = 1, Title = "C# Basics", Price = 500, AuthorId = 1 },
            new Book { Id = 2, Title = "ASP.NET", Price = 800, AuthorId = 1 },
            new Book { Id = 3, Title = "Java", Price = 600, AuthorId = 2 }
        };
        public IActionResult Index()
        {
            HomeViewModel vm = new HomeViewModel();
            
            vm.Authors = authors;
            vm.Books = new List<BookCardViewModel>();
            foreach (var b in books)
            {
                var author = vm.Authors.FirstOrDefault(a => a.Id == b.AuthorId);
                if(author!=null)
                {
                    BookCardViewModel bookCard = new BookCardViewModel();
                    bookCard.Id = b.Id;
                    bookCard.Title = b.Title;
                    bookCard.Price = b.Price;
                    bookCard.AuthorName = author.Name;
                    vm.Books.Add(bookCard);
                }
            }
            return View(vm);
        }
        public  IActionResult About()
        {
            return View();
        }
        public IActionResult Contact()
        {
            return View();
        }
        [HttpPost]
        public IActionResult AddAuthor(string name,string country)
        {
            int newId = authors.Count > 0 ? authors.Max(a => a.Id) + 1 : 1;
            Author author = new Author
            {
                Id= newId,
                Name = name,
                Country = country
            };
            authors.Add(author);
            return RedirectToAction("Index");
        }
        [HttpPost]
        public IActionResult AddBook(string title,decimal price,int authorId)
        {
            if (string.IsNullOrWhiteSpace(title))
            {
                return RedirectToAction("Index");
            }

            int newId = books.Count > 0 ? books.Max(b => b.Id) + 1 : 1;
            Book b = new Book
            {
                Id = newId,
                Title = title,
                Price = price,
                AuthorId = authorId
            };
            books.Add(b);
            return RedirectToAction("Index");
        }
        [HttpPost]
        public IActionResult RemoveBook(int id)
        {
            Book book = books.FirstOrDefault(b => b.Id == id);

            if (book != null)
            {
                books.Remove(book);
            }

            return RedirectToAction("Index");
        }


    }
}
