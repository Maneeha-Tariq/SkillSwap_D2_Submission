using FirstWebApp.Entities;
using Microsoft.EntityFrameworkCore;

namespace FirstWebApp.Data
{
    public class AppDbContext: DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext>options):base(options)
        { 
        }
        public DbSet<User> Users { get; set; }
        public DbSet<Employee> Employees { get; set; }
        public DbSet<Manager> Manager { get; set; }
    }
}
