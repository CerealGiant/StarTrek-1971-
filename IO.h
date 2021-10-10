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
#include <map>
using namespace std;

void start();
void instructions(); 
void init();
void shortRangeScan();
void movement();
void commands();
void shieldset();
void longScan();
void test();
void pulseAttk();
string longView(int x, int y);
extern string ss[10][24];
#endif