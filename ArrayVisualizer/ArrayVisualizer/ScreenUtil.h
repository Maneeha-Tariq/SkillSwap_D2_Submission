#ifndef SCREEN_UTIL_H
#define SCREEN_UTIL_H
#include <string>
using namespace std;
namespace screenUtil
{
    const string CLEAR_SCREEN = "\033[2J";  
    const string CLEAR_SCREEN_UP = "\033[1J";  
    const string CLEAR_SCREEN_DOWN = "\033[0J";  

    const string NEWLINE = "\033[1B";
    const string CURSOR_HOME = "\033[H";         
    const string SAVE_CURSOR = "\033[s";          
    const string ROLLBACK_CURSOR = "\033[u";
}
#endif // !SCREEN_UTIL_H
