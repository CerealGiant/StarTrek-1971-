#ifndef ENTERPRISE_H
#define ENTERPRISE_H
#define DEFAULTCOUNT 10;
#include "SpaceObjs.h"

//Enterprise is <*>(The Player)
class Enterprise: public SpaceObjects{
    private:
    int m_photoncount,m_photonpower;

    public:

    //Constructor to load default values.
    Enterprise(int mpc, int mpp) {
        SpaceObjects();
        m_photoncount = mpc;
        m_photonpower = mpp;
    }

    //Setters
    void setPhotonCount(int p) {
        m_photoncount = p;
    }
    void setPhotonPower(int pp) {
        m_photonpower = pp;
        //m_photonpower > shield strength of the enemy.
    }
    void setQuad(int x,int y) {
        m_quadx = x;
        m_quady = y;
    }
    void setSec(int x,int y) {
        m_secx = x;
        m_secy = y;
    }
    void setArmor(int a) {
        m_armor = a;
    }
    void setPulsePower(int pulse) {
        m_pulseattack = pulse;
    }

    void restocked() {
        m_photoncount = DEFAULTCOUNT;
    }


};
#endif