using FirstWebApp.Dto;
using FirstWebApp.GenericResponse;
using FirstWebApp.IService;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;


namespace FirstWebApp.Controllers
{
    [Authorize]
    [ApiController]
    [Route("api/[controller]")]
    //this is primary contructor Dependency injection, we are injecting the IEmployeeService into the controller
    public class EmployeeController(IEmployeeService _service) : ControllerBase
    {
        [HttpGet("GetAllEmployees")]
        public async Task<IActionResult> GetAllEmployees()
        {
            try
            {
                var result = await _service.GetAllEmployees();
                if (result.Item2.Count == 0)
                {
                    return Ok(ResponseResult<List<EmployeeDto>>.Failure(200, "No employees found.", null));
                }
                return Ok(ResponseResult<List<EmployeeDto>>.Success(200, "Employees found.", result.Item2));
            }
            catch (Exception ex)
            {
                return StatusCode(500, ResponseResult<string>.Failure(500, ex.Message, null));
            }
        }
        [HttpPost("AddEmployee")]
        public async Task<IActionResult> AddEmployee([FromBody] EmployeeDto dto)
        {
            try
            {
                var result = await _service.RegisterEmployee(dto);
                if (result.Item1 == 0)
                {
                    return Conflict(ResponseResult<string>.Failure(409, result.Item2, null));
                }
                return Ok(ResponseResult<string>.Success(200, result.Item2, null));
            }
            catch (Exception)
            {
                return StatusCode(500, ResponseResult<string>.Failure(500, "An error occurred while processing your request.", null));
            }

        }
        [HttpPut("UpdateEmployee")]
        public async Task<IActionResult> UpdateEmployee([FromBody] UpdateEmployeeDto dto)
        {
            try
            {
                var result = await _service.UpdateEmployee(dto);
                if(result.Item1 == 0)
                {
                    return NotFound(ResponseResult<string>.Failure(404, result.Item2, null));
                }
                return Ok(ResponseResult<string>.Success(200, result.Item2, null));
            }
            catch(Exception )
            { 
                return StatusCode(500, ResponseResult<string>.Failure(500, "An error occurred while processing your request.", null));
            }
        }
        [HttpDelete("DeleteEmployee")]
        public async Task<IActionResult> DeleteEmployee(Guid id)
        {
            try
            {
                var result = await _service.DeleteEmployee(id);
                if (result.Item1 == 0)
                {
                    return NotFound(ResponseResult<string>.Failure(404, result.Item2, null));
                }
                return Ok(ResponseResult<string>.Success(200, result.Item2, null));
            }
            catch (Exception)
            {
                return StatusCode(500, ResponseResult<string>.Failure(500, "An error occurred while processing your request.", null));
            }
        }

        [HttpGet("GetEmployeeById/{id:Guid}")]
        public async Task<IActionResult> GetEmployeeById([FromRoute]Guid id)
        {
             try
             {
                var res = await _service.GetEmployeeById(id);
                if (res.Item1 == 0)
                {
                    return NotFound(ResponseResult<EmployeeDto>.Failure(404, "Employee not found", null));
                }
                return Ok(ResponseResult<EmployeeDto>.Success(200, "Employee found", res.Item2));
             }
             catch (Exception)
             {
                   return StatusCode(500, ResponseResult<string>.Failure(500, "An error occurred while processing your request.", null));
             }
        }
        
   }
}
