#ifndef STARBASE_H
#define STARBASE_H
#include "SpaceObjs.h"

//Starbase is the  >!<
class starbase: public SpaceObjects{
    private:

    public:
    //Constructor
    starbase() {
        SpaceObjects();
    }
    //Setter
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