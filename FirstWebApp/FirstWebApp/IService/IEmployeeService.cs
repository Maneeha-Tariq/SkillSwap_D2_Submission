using FirstWebApp.Dto;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace FirstWebApp.IService
{
    public interface IEmployeeService
    {
        Task<Tuple<int, List<EmployeeDto>>> GetAllEmployees();
        Task<Tuple<int, string>> RegisterEmployee(EmployeeDto dto);
        Task<Tuple<int, string>> UpdateEmployee(UpdateEmployeeDto dto);
        Task<Tuple<int, string>> DeleteEmployee(Guid id);
        Task<Tuple<int,EmployeeDto>> GetEmployeeById(Guid id);  
    }
}
