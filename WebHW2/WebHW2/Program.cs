using LibraryData;
using System.Net;

namespace WebHW2
{
    internal class Program
    {
       
        static void Main(string[] args)
        {
            char choice = ' ';
            char c = ' ';
            do
            {
                Console.WriteLine("1. Add Book ");
                Console.WriteLine("2. View All Books");
                Console.WriteLine("3. Add Member");
                Console.WriteLine("4. View All Members");
                Console.WriteLine("5. Issue Book to Member (Transaction)");
                Console.WriteLine("6. Return Book (Transaction)");
                Console.WriteLine("7. Export Books to JSON");
                Console.WriteLine("8. Import Books from JSON");
                Console.WriteLine("9. Exit");
                Console.WriteLine("Enter your choice: ");

                choice = char.Parse(Console.ReadLine());
                switch (choice)
                {
                    case '1':

                        Console.WriteLine("Enter book Title");
                        string name = Console.ReadLine();
                        Console.WriteLine("Enter  Author Name");
                        string auth= Console.ReadLine();
                        Console.WriteLine("Enter Stock");
                        int stk = int.Parse(Console.ReadLine());


                        Book book = new Book();
                        book.Title = name;
                        book.Author = auth;
                        book.Stock = stk;
                        BookRepository bookRepo = new BookRepository();
                        bookRepo.AddBook(book);
                        break;

                    case '2':

                        BookRepository bookRepo1 = new BookRepository();
                        List<Book> l = bookRepo1.GetAllBooks();
                        foreach (Book e in l)
                        {
                            Console.WriteLine($"Id: {e.BookId}, Title: {e.Title}, Stock: {e.Stock}");
                        }
                        break;

                    case '3':

                        
                        Console.WriteLine("Enter Name");
                        string memberName = Console.ReadLine();

                        Member mem = new Member();
                        mem.Name = memberName;
                       
                        MemberRepository memRepo = new MemberRepository();
                        memRepo.AddMember(mem);
                        break;

                    case '4':

                        MemberRepository memRepo1 = new MemberRepository();
                        List<Member> list = memRepo1.GetAllMembers();
                        foreach (Member e in list)
                        {
                            Console.WriteLine($"Id: {e.MemberId}, Name: {e.Name}");
                        }
                        break;
                        
                    case '5':
                        Console.WriteLine("Enter BookId to Issue");
                        int id = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter MemberId");
                        int memId = int.Parse(Console.ReadLine());
                        BookRepository bookRe = new BookRepository();
                        bool res = bookRe.IssueBook(id,memId);

                        if (res)
                        {
                            Console.WriteLine("Book issued successfully.");
                        }
                        else
                        {
                            Console.WriteLine("Book issued failed.");
                        }
                        break;

                    case '6':

                        Console.WriteLine("Enter IssueId to Return");
                        int id1 = int.Parse(Console.ReadLine());
                        BookRepository bookRep = new BookRepository();
                        bool result = bookRep.ReturnBook(id1);
                        if (result)
                        {
                            Console.WriteLine("Book returned successfully.");
                        }
                        else
                        {
                            Console.WriteLine("Book returned failed.");
                        }
                        break;

                    case '7':
              
                        BookRepository bookRepp = new BookRepository();
                        BackupHelper backup = new BackupHelper();

                        List<Book> books = bookRepp.GetAllBooks();

                        backup.AddToFile(books, "books.json");
                        break;

                    case '8':

                        BackupHelper back = new BackupHelper();
                        List<Book> backList= back.ReadFromFile("books.json");
                        foreach (Book e in backList)
                        {
                            Console.WriteLine($"Id: {e.BookId}, Title: {e.Title}, Stock: {e.Stock}");
                        }
                        break;

                    case '9':
                        Console.WriteLine("Exit");
                        break;

                    default:
                        Console.WriteLine("Invalid choice");
                        break;

                }
                Console.WriteLine("Do you want to take any choices again? y/n : ");
                c = char.Parse(Console.ReadLine());

            } while (c == 'Y' || c == 'y');
        }
    }
}
