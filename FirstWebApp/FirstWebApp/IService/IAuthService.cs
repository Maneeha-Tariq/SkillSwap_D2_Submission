using FirstWebApp.Dto;
using FirstWebApp.Entities;

namespace FirstWebApp.IService
{
    public interface IAuthService
    {
        Task<Tuple<int, TokenDto>> LoginUser(LoginDto dto);
        Task<Tuple<int, string>> RegisterUser(RegsiterDto dto);
        Task<Tuple<int, string>> UpdateUserProfile(UpdateProfiledto dto);
    }
}
