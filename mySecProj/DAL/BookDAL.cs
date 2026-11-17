using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Business_Objects;

namespace DAL
{
    public class BookDAL
    {
        public void AddBook(Book book)
        {
            StreamWriter sw = new StreamWriter("book.txt", true);
            string str = $"{book.ID},{book.Name},{book.Title},{book.Author}";
            sw.WriteLine(str);
            sw.Close();
        }
        public List<Book> ReadBook()
        {
            StreamReader sr = new StreamReader("book.txt");
            string line = sr.ReadLine();
            List<Book> books = new List<Book>();
            while (line!=null)
            {
                string[] arr = line.Split(',');
                Book b = new Book();
                b.ID = int.Parse(arr[0]);
                b.Name = arr[1];
                b.Title = arr[2];
                b.Author = arr[3];
                books.Add(b);
                line = sr.ReadLine();
            }
            return books;
        }
    }
}
