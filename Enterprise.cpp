#include "Enterprise.h"


 Enterprise:: Enterprise() {
    srand(time(0));
    //Filling the values with the initial 1.
    SpaceObjects();
    
    //Randomly generating INITIAL quad postions(x and y for the quad)
    int x = rand() % ( 8 + 1 - 1) + 1, y = rand() % ( 8 + 1 - 1) + 1;
    m_quadx = x,m_quady = y;

    //Randomly generating INITAL sector positions(c for column and r for row)
    int c = rand() % ( 8 + 1 - 1) + 1, r = rand() % ( 8 + 1 - 1) + 1;
    m_secx = c, m_secy = r;

    m_photoncount = DEFAULTCOUNT;
    m_photonpower = 0;
    //m_photonpower > shield strength of the enemy.
}