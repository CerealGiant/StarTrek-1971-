#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "SpaceObjs.h"
#include "Enterprise.h"
#include "Kilgon.h"
#include "Star.h"
#include "Starbase.h"
#include <list>
using namespace std;

void start();
void instructions(); 
void init();
extern list<kilgon> kilgons;
#endif