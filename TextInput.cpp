#include "TextInput.h"

void start() {
  int inpt;
  FILE *fp;
  char *st = new char[500];
  fp = fopen("trek.txt","r");
  if(fp == NULL) {
    printf("Error!");
    exit(1);
  }
  while( (fgets(st,sizeof(string),fp)) != NULL) {
    cout << st;
  } 
  fclose(fp);
  
  cout << "PRESS 1 FOR TUTORIAL. PRESS 2 TO BEGIN:\t";
  switch(fgetc(stdin) ) {
    case '1':
    //Instructions
    case '2':
    //Game
  }


}