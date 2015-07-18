#ifndef COMMANDER
#define COMMANDER

// Commander
class Commander
{
    virtual void AddLocalMusic() = 0;
    virtual bool GetPlayingState() = 0;
    virtual void SetVolume(int value) = 0;
};
#endif // COMMANDER

