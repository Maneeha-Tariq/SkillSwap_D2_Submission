using System;
using System.Collections.Generic;
using Business_Objects;
using _DAL;

namespace ExecutionPoint
{
    internal class BookMain
    {
        static void Main(string[] args)
        {
            Book book = new Book();
            book.ID = 1;
            book.Name = "The Great Gatsby";
            book.Title = "A Novel";
            book.Author = "F. Scott Fitzgerald";
            BookDAL dal = new BookDAL();
            dal.AddBook(book);

            List<Book> books = dal.ReadBook();
            foreach(Book b in books)
            {
                Console.WriteLine($"{b.ID}, {b.Name}, {b.Title}, {b.Author}");
            }


        }
    }
}



