#ifndef ENTERPRISE_H
#define ENTERPRISE_H
#define DEFAULTCOUNT 10;
#include "SpaceObjs.h"
#include <time.h>
#include "IO.h"

//Enterprise is <*>(The Player)
class Enterprise: public SpaceObjects{
    private:
    int m_photoncount,m_photonpower,m_energy,m_pulseattack;
    string m_condition;

    public:
    //Constructor to load default values.
    Enterprise();
    void LoadPos();
    //Getters are handled by the Parent Class.
    //Setter????
    void setSecx(int x) {
        m_secx = x;
    }
    void setSecy(int y) {
        m_secy = y;
    }
    void tempPos(int x, int y);
    
    void setQuadx(int x) {
        m_quadx =x;
    }
    void setQuady(int y) {
        m_quady = y;
    }
    void setCondition(string c) {
        m_condition = c;
    }
    string getCondition() {
        return m_condition;
    }
    int getArmor() {
        return m_armor;
    }
    void setEnergy(int e) {
        m_energy = e;
    }
    int getEnergy() {
        return m_energy;
    }
    int getPhotonCount() {
        return m_photoncount;
    }
    void setPhotonCount(int p) {
        m_photoncount = p;
    }
    void setArmor(int a) {
        m_armor = a;
    }
    int getPulse() {
        while(m_pulseattack > m_energy) {
            srand(time(NULL));
            m_pulseattack = rand() % (220 +1-60) + 60;
        }
        return m_pulseattack;
    }
};
#endif