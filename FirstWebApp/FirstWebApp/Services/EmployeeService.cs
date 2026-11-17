using FirstWebApp.Data;
using FirstWebApp.Dto;
using FirstWebApp.IService;
using FirstWebApp.Entities;
using Microsoft.EntityFrameworkCore;
namespace FirstWebApp.Services
{
    public class EmployeeService(AppDbContext _context) : IEmployeeService
    {
       public async Task<Tuple<int, List<EmployeeDto>>> GetAllEmployees()
       {
            try
            {
                var res = await _context.Employees.AsNoTracking().Select(x => new EmployeeDto
                {
                    Id = x.Id,
                    Name = x.Name,
                    CreateDate = x.CreateDate,
                    LastModifiedDate = x.LastModifiedDate,
                    DOB = x.DOB,
                    Position = x.Position,
                    Department = x.Department,
                    EmailAddress = x.EmailAddress
                }).ToListAsync();
                return new Tuple<int, List<EmployeeDto>>(1, res);
            }
            catch (Exception ex)
            {
                return new Tuple<int, List<EmployeeDto>>(0, new List<EmployeeDto>());
            }

       }
        public async Task<Tuple<int,string>> RegisterEmployee(EmployeeDto dto)
        {
            try
            {
                var exists = await _context.Employees.AnyAsync(x => x.EmailAddress == dto.EmailAddress);
                if(exists)
                {
                    return new Tuple<int,string>(0, "Employee with this email already exists");
                }
                var newEmployee = new Employee
                {
                    Id = Guid.NewGuid(),
                    Name = dto.Name,
                    CreateDate = DateTime.Now,
                    LastModifiedDate = DateTime.Now,
                    DOB = dto.DOB,
                    Position = dto.Position,
                    Department = dto.Department,
                    EmailAddress = dto.EmailAddress
                };
                await _context.Employees.AddAsync(newEmployee);
                await _context.SaveChangesAsync();
                return new Tuple<int, string>(1, "Employee registered successfully");

            }
            catch(Exception )
            {
                return new Tuple<int, string>(2, "Error occured while registering Employee");
            }
        }
        public async Task<Tuple<int, string>> UpdateEmployee(UpdateEmployeeDto dto)
        {
            try
            {
                if(dto == null)
                {
                    return new Tuple<int, string>(0, "Invalid Employee data");  
                }
                var exists = await _context.Employees.FirstOrDefaultAsync(x => x.EmailAddress == dto.OldEmailAddress);
                if (exists == null)
                {
                    return new Tuple<int, string>(0, "Employee with this email doesnot exist,Please Register first");
                }
                
                if(dto.NewEmailAddress != null && dto.NewEmailAddress != dto.OldEmailAddress)
                        exists.EmailAddress = dto.NewEmailAddress;
                

                exists.Name = string.IsNullOrWhiteSpace(dto.Name) ? exists.Name : dto.Name;
                exists.DOB = dto.DOB ?? exists.DOB;
                exists.Position = string.IsNullOrWhiteSpace(dto.Position) ? exists.Position : dto.Position;
                exists.Department = string.IsNullOrWhiteSpace(dto.Department) ? exists.Department : dto.Department;
                exists.LastModifiedDate = DateTime.Now;

                await _context.SaveChangesAsync();
                return new Tuple<int, string>(1, "Employee Updated successfully");

            }
            catch (Exception)
            {
                return new Tuple<int, string>(2, "Error occured while updating Employee");
            }
        }
        public async Task<Tuple<int,string>> DeleteEmployee(Guid id)
        {
            try
            {
                var exists = await _context.Employees.FirstOrDefaultAsync(x => x.Id == id);
                if(exists == null)
                {
                    return new Tuple<int, string>(0, "Employee with this Id doesnot exist");
                }
                _context.Employees.Remove(exists);
                await _context.SaveChangesAsync();
                return new Tuple<int, string>(1, "Employee Deleted successfully");

            }
            catch(Exception) 
            {

                return new Tuple<int, string>(2, "Error occured while Deleting Employee");
            }
        }
        public async  Task<Tuple<int, EmployeeDto>> GetEmployeeById(Guid id)
        {
            try
            {
                var exists = await _context.Employees.AsNoTracking().
                    Select(e => new EmployeeDto
                    {
                        Id = e.Id,
                        Name = e.Name,
                        CreateDate = e.CreateDate,
                        LastModifiedDate = e.LastModifiedDate,
                        DOB = e.DOB,
                        Position = e.Position,
                        Department = e.Department,
                        EmailAddress = e.EmailAddress
                    }).FirstOrDefaultAsync(x=> x.Id==id);
                        
                if (exists==null)
                {
                    return new Tuple<int, EmployeeDto>(0, new EmployeeDto());
                }
                return new Tuple<int, EmployeeDto>(1, exists);
            }
            catch(Exception)
            {
                return new Tuple<int, EmployeeDto>(2, new EmployeeDto());
            }
        }
    }
}
