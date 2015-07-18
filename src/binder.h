#ifndef BINDER
#define BINDER

// Interface Binder
class Binder
{
    virtual void AddLocalMusic() = 0;
    virtual bool GetPlayingState() = 0;
    virtual void SetVolume(int value) = 0;
};

#endif // BINDER

