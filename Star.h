#ifndef STAR_H
#define STAR_H
#include "IO.h"
#include "SpaceObjs.h"

//Star is the *
class Star: public SpaceObjects{
    
    public:

    //Constructor to load default values.
    Star();
    void LoadPos();
    void tempPos(int x, int y);
    
};
#endif