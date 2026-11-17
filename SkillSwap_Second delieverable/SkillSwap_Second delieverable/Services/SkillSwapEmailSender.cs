
using Microsoft.AspNetCore.Identity.UI.Services;

namespace SkillSwap_Second_delieverable.Services
{
    public class SkillSwapEmailSender : IEmailSender
    {
        public Task SendEmailAsync(string email, string subject, string htmlMessage)
        {
            return Task.CompletedTask;
        }
    }
}
