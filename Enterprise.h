#ifndef ENTERPRISE_H
#define ENTERPRISE_H
#define DEFAULTCOUNT 10;
#include "SpaceObjs.h"
#include <time.h>


//Enterprise is <*>(The Player)
class Enterprise: public SpaceObjects{
    private:
    int m_photoncount,m_photonpower;

    public:
    //Constructor to load default values.
    Enterprise();
    //Getters are handled by the Parent Class.
    //Setter????

};
#endif