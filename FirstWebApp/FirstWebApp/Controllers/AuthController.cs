using FirstWebApp.Dto;
using FirstWebApp.GenericResponse;
using FirstWebApp.IService;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System.Reflection.Metadata.Ecma335;

namespace FirstWebApp.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class AuthController : ControllerBase
    {
        private readonly IAuthService _authService;
        public AuthController(IAuthService authService)
        {
            _authService = authService;
        }
        [HttpPost("login")]
        public async Task<IActionResult> Login([FromBody]LoginDto dto)
        {
            try
            {
                var result = await _authService.LoginUser(dto);
                if (result.Item1 == 0)
                {
                    return NotFound(ResponseResult<TokenDto>.Failure(404,result.Item2.Message,null));
                }
                if (result.Item1 == 1)
                {
                    return Unauthorized(ResponseResult<TokenDto>.Failure(401,result.Item2.Message,null));
                }
                return Ok(ResponseResult<TokenDto>.Success(200, result.Item2.Message, result.Item2));
            } 
            catch(Exception)
            {
                return StatusCode(500, "An error occurred while processing your request.");
            }
           
        }
        [HttpPost("register")]
        public async Task<IActionResult> Register([FromBody] RegsiterDto dto)
        {
            try
            {
                var result = await _authService.RegisterUser(dto);
                if (result.Item1 == 0)
                {
                    return Conflict(ResponseResult<string>.Failure(409, result.Item2, null));
                }
               
                return Created("",ResponseResult<string>.Success(201, result.Item2, null));
            }
            catch (Exception)
            {
                return StatusCode(500, "An error occurred while processing your request.");
            }
        }
        [HttpPut("update_profile")]
        public async Task<IActionResult> UpdateProfile([FromBody] UpdateProfiledto dto)
        {
            try
            {
                var result = await _authService.UpdateUserProfile(dto);
                if(result.Item1==0)
                {
                    return Conflict(ResponseResult<string>.Failure(409, result.Item2, null));
                }
                if(result.Item1 == 1)
                {
                    return NotFound(ResponseResult<string>.Failure(404, result.Item2, null));
                }
                return Ok(ResponseResult<string>.Success(200, result.Item2, null));
            }
            catch(Exception)
            {
                return StatusCode(500, "An error occurred while processing your request.");
            }
        }
    }
}
