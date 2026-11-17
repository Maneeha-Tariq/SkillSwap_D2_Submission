using System.ComponentModel.DataAnnotations;

namespace FirstWebApp.Dto
{
    public class UpdateProfiledto
    {
        [Key]
        public string? Name { get; set; }
        public string ? oldEmail { get; set; }
        public string? newEmail { get; set; }
    }
}
