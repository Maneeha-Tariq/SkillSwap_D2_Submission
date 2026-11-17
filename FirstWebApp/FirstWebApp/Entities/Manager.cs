using System.ComponentModel.DataAnnotations;

namespace FirstWebApp.Entities
{
    public class Manager
    {
        [Key]
        public Guid M_Id { get; set; } = Guid.NewGuid();
        public string?name { get; set; }    
        public string? M_email { get; set; }
    }
}
