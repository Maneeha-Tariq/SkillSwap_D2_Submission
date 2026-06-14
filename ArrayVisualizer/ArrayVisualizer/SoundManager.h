#ifndef SOUND_MANAGER
#define SOUND_MANAGER

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class SoundManager {
public:
    static void play(const wchar_t* file,bool loop=true) 
    {
        if(loop)
            PlaySoundW(file, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        else
            PlaySoundW(file, NULL, SND_FILENAME | SND_ASYNC );
    }
    static void stop()
    {
        PlaySoundW(NULL,0,0);
    }
};

#endif
