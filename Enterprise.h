#ifndef ENTERPRISE_H
#define ENTERPRISE_H
#define DEFAULTCOUNT 10;
#include "SpaceObjs.h"
#include <time.h>
#include "IO.h"

//Enterprise is <*>(The Player)
class Enterprise: public SpaceObjects{
    protected:
    int m_photoncount,m_photonpower,m_energy,m_pulseattack,m_initialstardate,m_duration,m_stardate,m_warp,m_ssensors,m_lsensors,m_phasers,m_photons,m_damage,m_shield,m_computer;
    string m_condition,m_tempcondition;

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
    void setTempCond(string t) {
        m_tempcondition = t;
    }
    string getTempCond() {
        return m_tempcondition;
    }

     int getStarDate() {
         return m_stardate;
     }
     void setStarDate(int s) {
         m_stardate = s;
    }
    void setDuration(int d) {
        m_duration = d;
    }
    int getDuration() {
        return m_duration;
    }
    int getIStarDate() {
        return m_initialstardate;
    }
    int getWarp() {
        return m_warp;
    }
    int getS() {
        return m_ssensors;
    }
    int getL() {
        return m_lsensors;
    }
    int getPhaser() {
        return m_phasers;
    }
    int getPhoton() {
        return m_photons;
    }
    int getDamage() {
        return m_damage;
    }
    int getShield() {
        return m_shield;
    }             
    int getComputer() {
        return m_computer;
    }
    void Destroy();
    void Add();
};
#endif