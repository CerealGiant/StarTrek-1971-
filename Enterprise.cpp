#include "Enterprise.h"


 Enterprise:: Enterprise() {
    //Filling the values with the initial 1.
    SpaceObjects();
    m_condition = "GREEN";
    m_tempcondition = "GREEN";
    m_energy = 3000;
    srand(time(NULL));
    //Randomly generating INITIAL quad postions(x and y for the quad)
    int x = rand() % ( 8 + 1 - 1) + 1, y = rand() % ( 8 + 1 - 1) + 1;
    m_quadx = x,m_quady = y;

    //Randomly generating INITAL sector positions(c for column and r for row)
    int c = rand() % ( 8 + 1 - 1) + 1, r = rand() % ( 8 + 1 - 1) + 1;
    m_secx = c, m_secy = r;

    m_photoncount = 1;
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
