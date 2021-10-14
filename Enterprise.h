#ifndef ENTERPRISE_H
#define ENTERPRISE_H
#define DEFAULTCOUNT 10;
#include "SpaceObjs.h"
#include <time.h>
#include "IO.h"

//Enterprise is <*>(The Player)
class Enterprise: public SpaceObjects{
    protected:
    int m_photoncount,m_photonpower,m_energy,m_pulseattack,m_initialstardate,m_duration,m_stardate,warp_e,s_sensor,l_sensor,p_ctrl,p_tubes,damage_ctrl,shield_ctrl,computer;
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
    //warp_e,s_snsor,l_sensor,p_ctrl,p_tubes,damage_ctrl,shield_ctrl,computer
    void doAdd() {
        if(warp_e < 0) {
            warp_e++;
        }else if(s_sensor < 0) {
            s_sensor++;
        }else if(l_sensor < 0) {
            l_sensor++;
        }else if(p_ctrl < 0) {
            p_ctrl++;
        }else if(p_tubes < 0) {
            p_tubes++;
        }else if(damage_ctrl < 0) {
            damage_ctrl++;
        }else if(shield_ctrl < 0) {
            shield_ctrl++;
        }else if(computer < 0) {
            computer++;
        }
    }
    
    void damaged() {
        if( (m_stardate - m_initialstardate) % 6 == 0 && m_initialstardate != m_stardate ) {
            srand(time(0));
            int damage = rand() % (3 + 1 - 1) + 1;
            switch(damage) {
                case 1:
                //Damage Control
                damage_ctrl = -2;
                cout<< "DAMAGE CONTROL REPORT: DAMAGE CONTROL DAMAGED!"<<endl;
                break;
                case 2:
                computer = -2;
                cout<< "DAMAGE CONTROL REPORT: COMPUTER DAMAGED!"<<endl;
                break;
                case 3:
                shield_ctrl = -2;
                cout<< "DAMAGE CONTROL REPORT: SHIELD CONTROL DAMAGED!"<<endl;
                break;
            }
        }else if( (m_stardate - m_initialstardate) % 10 == 0 && m_initialstardate != m_stardate ) {
            srand(time(0));
            int damage = rand() % (5 + 1 - 1) + 1;
            switch(damage) {
                case 1:
                //Warp Engine
                warp_e = -2;
                cout<< "DAMAGE CONTROL REPORT: WARP ENGINE DAMAGED!"<<endl;
                break;
                case 2:
                s_sensor = -2;
                cout<< "DAMAGE CONTROL REPORT: SHORT RANGE SENSORS DAMAGED!"<<endl;
                break;
                case 3:
                l_sensor = -2;
                cout<< "DAMAGE CONTROL REPORT: LONG RANGE SENSORS DAMAGED!"<<endl;
                break;
                case 4:
                p_ctrl = -2;
                cout<< "DAMAGE CONTROL REPORT: PHASER CONTROL DAMAGED!"<<endl;
                break;
                case 5:
                p_tubes = -2;
                cout<< "DAMAGE CONTROL REPORT: PHOTON TUBES CONTROL!"<<endl;
                break;
            }
        }
    }
    
    int getWarp() {
        return warp_e;
    }
    int getssensor() {
        return s_sensor;
    }
    int getlsensor() {
        return l_sensor;
    }
    int getpctrl() {
        return p_ctrl;
    }
    int getptubes() {
        return p_tubes;
    }
    int returndamage() {
        return damage_ctrl;
    }
    int returnshield() {
        return shield_ctrl;
    }
    int getComputer() {
        return computer;
    }
    void setWarp(int w) {
        warp_e = w;
    }
    void setssensor(int s) {
        s_sensor = s;
    }
    void setlsensor(int l) {
        l_sensor = l; 
    }
    void setpctrl(int p) {
        p_ctrl = p;
    }
    void setptubes(int pt) {
        p_tubes = pt;
    }
    void setdamage(int d) {
        damage_ctrl = d;
    }
    void setshield(int s) {
        shield_ctrl = s;
    }
    void setComputer(int c) {
        computer = c;
    }

};
#endif