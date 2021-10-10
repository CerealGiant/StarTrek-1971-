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

    int getPulse() {
    srand(time(NULL));
    m_pulseattack = rand() % (240 +1-60) + 60;
    return m_pulseattack;
    }
    int getArmor() {
        return m_armor;
    }
    void setArmor(int a) {
        m_armor = a;
    }
    void tempPos(int x, int y);

};
#endif