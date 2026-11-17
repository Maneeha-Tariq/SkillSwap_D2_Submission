using System.ComponentModel.DataAnnotations;

namespace FirstWebApp.Dto
{
    public class RegsiterDto
    {
        [Key]
        public string? Name { get; set; }   
        public string? Password { get; set; }
        public string? Email { get; set; }
    }
}
