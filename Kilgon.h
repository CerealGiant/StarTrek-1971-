#ifndef KILGON_H
#define KILGON_H
#include "SpaceObjs.h"
#include "IO.h"
//Enemy is the +++(Kilgon)
class kilgon: public SpaceObjects{
    private:

    public:
    //Constructor
    kilgon();
    //Getter
    int getQuadx() {
        return m_quadx;
    }
    int getQuady() {
        return m_quady;
    }
    void LoadPos();

};
#endif