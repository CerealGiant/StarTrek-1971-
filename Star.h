#ifndef STAR_H
#define STAR_H

#include "SpaceObjs.h"

//Star is the *
class Star: public SpaceObjects{
    
    public:

    //Constructor to load default values.
    Star() {
        SpaceObjects();
    }

    //Setters
    void setQuad(int x,int y) {
        m_quadx = x;
        m_quady = y;
    }
    void setSec(int x,int y) {
        m_secx = x;
        m_secy = y;
    }


};
#endif