#ifndef KILGON_H
#define KILGON_H
#include "SpaceObjs.h"

//Enemy is the +++(Kilgon)
class kilgon: public SpaceObjects{
    private:
    int m_earmor;

    public:
    //Constructor
    kilgon(int m_earmor) {
        SpaceObjects();
        m_earmor = 0;
    }
    
    //Setter
    void setArmor(int a) {
        m_earmor = a;
    }
    void setPulsePower(int pp) {
        m_pulseattack = pp;
    }
    

};
#endif