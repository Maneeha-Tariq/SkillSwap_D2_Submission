using System.ComponentModel.DataAnnotations;

namespace FirstWebApp.Entities
{
    public class User
    {
        [Key]
        public Guid Id { get; set; } = Guid.NewGuid();
        public string? UserName { get; set; }
        public string? Password { get; set; }
        public string? Email { get; set; } 

    }
}
