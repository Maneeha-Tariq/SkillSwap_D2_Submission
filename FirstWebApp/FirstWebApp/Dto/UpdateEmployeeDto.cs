namespace FirstWebApp.Dto
{
    public class UpdateEmployeeDto
    {
        public Guid Id { get; set; }
        public string? Name { get; set; }
        public DateTime? CreateDate { get; set; }
        public DateTime? LastModifiedDate { get; set; }
        public DateOnly? DOB { get; set; }
        public string? Position { get; set; }
        public string? Department { get; set; }
        public string? OldEmailAddress { get; set; }
        public string? NewEmailAddress { get; set; }

    }
}
