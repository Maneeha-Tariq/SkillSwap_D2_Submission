#ifndef KEYS_H
#define KEYS_H
namespace Keys
{
    const int UP = 72;   // Windows: 224,72 | Linux: \033[A
    const int DOWN = 80;   // Windows: 224,80 | Linux: \033[B
    const int LEFT = 75;   // Windows: 224,75 | Linux: \033[D
    const int RIGHT = 77;   // Windows: 224,77 | Linux: \033[C
    const int ARROW_PREFIX = 224;
    //const int 
    // Common special keys
    const int ESC = 27;
    const int ENTER = 13;
    const int SPACE = 32;
    const int BACKSPACE = 8;
    const int TAB = 9;

    // Function keys (F1-F12) Windows codes
    const int F1 = 59;
    const int F2 = 60;
    const int F3 = 61;
    const int F4 = 62;
    const int F5 = 63;
    const int F6 = 64;
    const int F7 = 65;
    const int F8 = 66;
    const int F9 = 67;
    const int F10 = 68;
    const int F11 = 133; // optional mapping
    const int F12 = 134; // optional mapping

}
#endif // !KEYS_H
