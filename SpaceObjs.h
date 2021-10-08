#ifndef SPACEOBJS_H
#define SPACEOBJS_H
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class SpaceObjects {
    protected:
    int m_secx, m_secy,m_quadx,m_quady,m_armor,m_pulseattack;
    
    public:

    //Constructor to set their default values.
    SpaceObjects() {
        m_secx = 1, m_secy = 1, m_quadx = 1, m_quady = 1,m_armor = 0, m_pulseattack = 0;
    }
    //Overloaded Constructor to store randomly generated values.
    SpaceObjects(int secx,int secy, int quadx, int quady, int armor,int pulseattack) {
        m_secx = secx, m_secy = secy, m_quadx = quadx, m_quady = quady,m_armor = armor, m_pulseattack = pulseattack;
    }
    

};
#endif