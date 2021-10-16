#include "Enterprise.h"


 Enterprise:: Enterprise() {
    //Filling the values with the initial 1.
    SpaceObjects();
    m_condition = "GREEN";
    m_tempcondition = "GREEN";
    m_energy = 3000;
    m_warp = 0,m_ssensors = 0,m_lsensors = 0,m_phasers = 0,m_photons = 0,m_damage = 0,m_shield = 0,m_computer = 0;
    srand(time(NULL));
    //Randomly generating INITIAL quad postions(x and y for the quad)
    int x = rand() % ( 8 + 1 - 1) + 1, y = rand() % ( 8 + 1 - 1) + 1;
    m_quadx = x,m_quady = y;
    m_stardate = rand() % (4000 + 1 - 2000) + 2000;
    m_initialstardate = m_stardate;

    //Randomly generating INITAL sector positions(c for column and r for row)
    int c = rand() % ( 8 + 1 - 1) + 1, r = rand() % ( 8 + 1 - 1) + 1;
    m_secx = c, m_secy = r;

    m_photoncount = 10;
    m_photonpower = 0;
    //m_photonpower > shield strength of the enemy.

    //Randomly generating the pulse attack value
    int p = rand() % (220 +1-60) + 60;
    m_pulseattack = p;
}

void Enterprise:: LoadPos() {
  //Loading Position
  int editedx = 1 + ( (m_secx -1) * 3 );
  int editedy = m_secy;
  if(ss[editedy][editedx] != ">*<") {
    ss[editedy][editedx] = "<*>";
  }

}

void Enterprise:: tempPos(int x, int y) {
  int editedx = 1 + ( (x -1) * 3 );
  int editedy = y;
  ss[editedy][editedx] = " - ";
}

void Enterprise:: Add() {
  if(m_warp < 0) {
    m_warp++;
  }
  if(m_ssensors < 0) {
    m_ssensors++;
  }  
  if(m_lsensors < 0) {
    m_lsensors++;
  }
  if(m_phasers < 0) {
    m_phasers++;
  }
  if(m_photons < 0) {
    m_photons++;
  }
  if(m_damage < 0) {
    m_damage++;
  }
  if(m_shield < 0) {
    m_shield++;
  }
  if(m_computer < 0) {
    m_computer++;
  }          
}
void Enterprise:: Destroy() {
  if(m_stardate - m_initialstardate % 6 == 0 && m_stardate - m_initialstardate != 0) {
    srand(time(0));
    int random = rand() % (3 + 1 - 1) + 1;
    switch(random) {
      case 1:
      //Damage Control
      cout<<"DAMAGE CONTROL REPORT: DAMAGE CONTROL IS DOWN!"<<endl;
      m_damage = -2;
      break;
      case 2:
      cout<<"DAMAGE CONTROL REPORT: SHIELD CONTROL IS DOWN!"<<endl;
      m_shield = -2;
      break;
      case 3:
      cout<<"DAMAGE CONTROL REPORT: COMPUTER IS DOWN!"<<endl;
      m_computer = -2;
      break;
    }
  }else if(m_stardate - m_initialstardate % 10 == 0 && m_stardate - m_initialstardate != 0) {
    srand(time(0));
    int random = rand() % (5 + 1 - 1) + 1;
    switch(random) {
        case 1:
        //Warp Engines
        cout<<"DAMAGE CONTROL REPORT: WARP ENGINES ARE DOWN!"<<endl;
        m_warp = -2;
        break;
        case 2:
        cout<<"DAMAGE CONTROL REPORT: S.R SENSORS ARE DOWN!"<<endl;
        m_ssensors = -2;
        break;
        case 3:
        cout<<"DAMAGE CONTROL REPORT: L.R SENSORS ARE DOWN!"<<endl;
        m_lsensors = -2;
        break;
        case 4:
        cout<<"DAMAGE CONTROL REPORT: PHASER CONTROL IS DOWN!"<<endl;
        m_phasers = -2;
        break;
        case 5:
        cout<<"DAMAGE CONTROL REPORT: PHOTON CONTROL IS DOWN!"<<endl;
        m_photons = -2;
        break;
    }
  }
}
