#ifndef INPUTERRORCHECK_H
#define INPUTERRORCHECK_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
float inputCheck_F(string touser,int min, int max);

int inputCheck(string touser,int min, int max) {

    char *inpt = (char*) malloc(sizeof(char)*100);
    while(true) {

    int count = 0;
    cout<<touser;
    //Taking in user input
    fgets(inpt,sizeof(inpt),stdin);
    
    //Removing whitespace from user input
    inpt[strcspn(inpt, "\n")] = 0;

    //Checking whitespace-removed user input for any characters & numbers
    for(size_t i =0; i < strlen(inpt);i++) {
        if(!isdigit( inpt[i] ) ) {
            count++;
        }
    }
    //If a character is present, going back to the top of the loop else exit the loop;
    if(count > 0 ) {
        if(touser == "COMMAND: ") cout <<"0 = SET COURSE\n1 = SHORT RANGE SENSOR SCAN\n2 = LONG RANGE SENSOR SCAN\n3 = FIRE PHASERS\n4 = FIRE PHOTON TORPEDOES\n5 = SHIELD CONTROL\n6 = DAMAGE CONTROL REPORT\n7 = CALL ON LIBRARY COMPUTER\n\n"<<endl;
        else if(touser == "OPTION: ") cout <<"THE LIBRARY COMPUTER CONTAINS 3 OPTIONS:\n\nOPTION 0 = CUMULATIVE GALACTIC RECORD\nOPTION 1 = STATUS REPORT\nOPTION 2 = PHOTON TORPEDO TRAJECTORY DATA"<<endl;
        continue;
    }else {
        if(atoi(inpt) < min || atoi(inpt) > max ) {
        if(touser == "COMMAND: ") cout <<"0 = SET COURSE\n1 = SHORT RANGE SENSOR SCAN\n2 = LONG RANGE SENSOR SCAN\n3 = FIRE PHASERS\n4 = FIRE PHOTON TORPEDOES\n5 = SHIELD CONTROL\n6 = DAMAGE CONTROL REPORT\n7 = CALL ON LIBRARY COMPUTER\n\n"<<endl;
        else if(touser == "OPTION: ") cout <<"THE LIBRARY COMPUTER CONTAINS 3 OPTIONS:\n\nOPTION 0 = CUMULATIVE GALACTIC RECORD\nOPTION 1 = STATUS REPORT\nOPTION 2 = PHOTON TORPEDO TRAJECTORY DATA"<<endl;
        continue;            
        }else {
            break;
        } 
    }

    }
     return atoi(inpt);
}

float inputCheck_F(string touser,int min, int max) {
    
    char *inpt = (char*) malloc(sizeof(char)*100);
    int f = 0;
    while(true) {

    int count = 0;
    f = 0;
    cout<<touser;
    //Taking in user input
    fgets(inpt,sizeof(inpt),stdin);
    
    //Removing whitespace from user input
    inpt[strcspn(inpt, "\n")] = 0;

    //Checking whitespace-removed user input for any characters & numbers
    for(size_t i =0; i < strlen(inpt);i++) {
        if(!isdigit( inpt[i] ) ) {
            count++;
        }
        if(inpt[i] == '.' ) {
            count--;
            f++;
        }
    }
    //If a character is present, going back to the top of the loop else exit the loop;
    if(count > 0 ) {
        if(touser == "COMMAND: ") cout <<"0 = SET COURSE\n1 = SHORT RANGE SENSOR SCAN\n2 = LONG RANGE SENSOR SCAN\n3 = FIRE PHASERS\n4 = FIRE PHOTON TORPEDOES\n5 = SHIELD CONTROL\n6 = DAMAGE CONTROL REPORT\n7 = CALL ON LIBRARY COMPUTER\n\n"<<endl;
        else if(touser == "OPTION: ") cout <<"THE LIBRARY COMPUTER CONTAINS 3 OPTIONS:\n\nOPTION 0 = CUMULATIVE GALACTIC RECORD\nOPTION 1 = STATUS REPORT\nOPTION 2 = PHOTON TORPEDO TRAJECTORY DATA"<<endl;
        continue;
    }
else {
        //Input is a digit(0-9)
        if(atoi(inpt) < min || atoi(inpt) > max ) {
            //Input is not in the Range.
            if(touser == "COMMAND: ") cout <<"0 = SET COURSE\n1 = SHORT RANGE SENSOR SCAN\n2 = LONG RANGE SENSOR SCAN\n3 = FIRE PHASERS\n4 = FIRE PHOTON TORPEDOES\n5 = SHIELD CONTROL\n6 = DAMAGE CONTROL REPORT\n7 = CALL ON LIBRARY COMPUTER\n\n"<<endl;
            else if(touser == "OPTION: ") cout <<"THE LIBRARY COMPUTER CONTAINS 3 OPTIONS:\n\nOPTION 0 = CUMULATIVE GALACTIC RECORD\nOPTION 1 = STATUS REPORT\nOPTION 2 = PHOTON TORPEDO TRAJECTORY DATA"<<endl;
            continue;
        }else break;
    }

    }

    return stof(inpt);

}
#endif