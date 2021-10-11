#ifndef STARBASE_H
#define STARBASE_H
#include "SpaceObjs.h"
#include "IO.h"
//Starbase is the  >!<
class starbase: public SpaceObjects{
    protected:

    public:
    //Constructor
    starbase();
    void LoadPos();
    void tempPos(int x,int y);
    void docked();
    

};
#endif