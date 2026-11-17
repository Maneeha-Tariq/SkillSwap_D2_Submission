using System.ComponentModel.DataAnnotations;

namespace FirstWebApp.Dto
{
    public class LoginDto
    {
        [Key]
        public string? Password{ get; set; }
        public string? Email { get; set; }
    }
}
