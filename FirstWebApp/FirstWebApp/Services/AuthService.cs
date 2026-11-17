using FirstWebApp.Data;
using FirstWebApp.Dto;
using FirstWebApp.Entities;
using FirstWebApp.IService;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Security.Claims;
using System.Text;

namespace FirstWebApp.Services
{
    public class AuthService : IAuthService
    {
        public readonly AppDbContext _context;
        public AuthService(AppDbContext context)
        {
            _context = context;
        }
        public async Task<Tuple<int,TokenDto>> LoginUser(LoginDto dto)
        {
            try
            {
                var _existingUser = await _context.Users.FirstOrDefaultAsync(x=> x.Email == dto.Email);
                TokenDto dtoken = new TokenDto();
                if (_existingUser == null)
                {
                    dtoken.Token = null;
                    dtoken.Message = "This User Not Exist, Please Login";
                    return new Tuple<int,   TokenDto>(0, dtoken);
                }
                var hasher = new PasswordHasher<User>();
                var result = hasher.VerifyHashedPassword(_existingUser, _existingUser.Password, dto.Password);
              
                if (result == PasswordVerificationResult.Failed)
                {
                    dtoken.Token = null;
                    dtoken.Message = "Password is Incorrect";
                    return new Tuple<int, TokenDto>(1, dtoken);
                }
                var token = GenerateJwtToken(_existingUser);
               
                dtoken.Token = token;
                dtoken.Message = "Login Sucessfully";
                return new Tuple<int, TokenDto>(2, dtoken);
            }
            catch(Exception)
            {
                TokenDto dtoken = new TokenDto();
                dtoken.Token = null;
                dtoken.Message = "Something Went Wrong";
                return new Tuple<int, TokenDto>(3, dtoken);
            }
        }
        private string GenerateJwtToken(User user)
        {
            var claims = new[]
            {
                new Claim(ClaimTypes.Name, user.UserName),
                new Claim(ClaimTypes.Email, user.Email),
                new Claim(ClaimTypes.NameIdentifier, user.Id.ToString())
            };
            var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes("ccV&PUp[HRbOpA+uDQ_P*[%^Ll(rjQ<xr4?+ABBH=jc"));
            var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);
            var token = new JwtSecurityToken(
                issuer: "maneeha-client",
                audience: "maneeha-backend",
                claims: claims,
                expires: DateTime.Now.AddMinutes(30),
                signingCredentials: creds
            );

            return new JwtSecurityTokenHandler().WriteToken(token);
        }
        public async Task<Tuple<int,string>> RegisterUser(RegsiterDto dto)
        {
            try
            {
                //Any asnyn return boolean if data exists then true otherwise false
                var _existingUser = await _context.Users.AnyAsync(x => x.Email == dto.Email);
                if(_existingUser)
                {
                    return new Tuple<int, string>(0, "This User Already Exist,Please Login");
                }
                var hasher = new PasswordHasher<User>();
               
                var user = new User
                {
                    Email = dto.Email,
                    UserName = dto.Name
                };
                user.Password =  hasher.HashPassword(user, dto.Password);

                _context.Users.Add(user);
                await _context.SaveChangesAsync();
                return new Tuple<int,string>(1, "User Registered Sucessfully");
            }
            catch(Exception)
            {
                return new Tuple<int, string>(2, "Something Went Wrong");
            }
        }
        public async Task<Tuple<int, string>> UpdateUserProfile(UpdateProfiledto dto)
        {
            try
            {   
                if (dto.newEmail != null)
                {
                    var _emailExists = await _context.Users.AnyAsync(x => x.Email == dto.newEmail && x.Email != dto.oldEmail);
                    if (_emailExists)
                    {
                        return new Tuple<int, string>(0, "This Email Already Exist, Please Try Another Email");
                    }
                }
                var _existingUser = await _context.Users.FirstOrDefaultAsync(x => x.Email == dto.oldEmail);

                if (_existingUser == null)
                {
                    return new Tuple<int, string>(1, "This User Not Exist, Please Register the User");
                }
                _existingUser.UserName = dto.Name;
                if (dto.newEmail != null)
                {
                    _existingUser.Email = dto.newEmail;
                }
                await _context.SaveChangesAsync();
                return new Tuple<int, string>(2, "User Profile Updated Successfully");
            }
            catch (Exception)
            {
                return new Tuple<int, string>(3, "Something went wrong");
            }
        }
    }
}
