#include "Starbase.h"

starbase:: starbase() {

    //Filling the values with the initial 1.
    SpaceObjects();

    //Randomly generating INITIAL quad postions(x and y for the quad)
    int x = rand() % ( 8 + 1 - 1) + 1, y = rand() % ( 8 + 1 - 1) + 1;
    m_quadx = x,m_quady = y;

    //Randomly generating INITAL sector positions(c for column and r for row)
    int c = rand() % ( 8 + 1 - 1) + 1, r = rand() % ( 8 + 1 - 1) + 1;
    m_secx = c, m_secy = r;

}

void starbase:: LoadPos() {
  //Loading Position
  int editedx = 1 + ( (m_secx -1) * 3 );
  int editedy = m_secy;
  while( ss[editedy][editedx] != ">*<" && (ss[editedy][editedx] != " - " && ss[editedy][editedx] != ">!<") ) {
    srand(time(0));
    m_secx = rand() % (8 + 1 - 1) + 1;
    m_secy = rand() % (8 + 1 - 1) + 1;
    editedx = 1 + ( (m_secx -1) * 3 );
    editedy = m_secy;
  }
  if(ss[editedy][editedx] != ">*<") {
  ss[editedy][editedx] = ">!<";
  }
 

}

void starbase::docked() {
  int editedx = 1 + ( (m_secx -1) * 3 );
  int editedy = m_secy;
  ss[editedy][editedx] = ">*<";  
}
void starbase:: tempPos(int x, int y) {
  int editedx = 1 + ( (m_secx -1) * 3 );
  int editedy = m_secy;
  ss[editedy][editedx] = " - ";
} 