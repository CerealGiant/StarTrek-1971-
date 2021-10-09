#include "IO.h"

void start() {
  char* inpt = new char[sizeof(char)*100],*ptr,*st = new char[500];

  //Opening trek.txt & Printing the ASCII Art
  FILE *fp;
  fp = fopen("trek.txt","r");
  if(fp == NULL) {
    printf("Error!");
    exit(1);
  }
  while( (fgets(st,sizeof(string),fp)) != NULL) {
    cout << st;
  } 
  fclose(fp);
  
  //Error Checking Loop
  while(true) {

  cout << "\n\nPRESS 1 FOR TUTORIAL. PRESS 2 TO BEGIN:";
  fgets(inpt,sizeof(inpt),stdin);
  int number = strtol(inpt,&ptr,10);
  int count = 0 ;
  for(int i =0; i < sizeof(ptr);i++) {
    if(ptr[i] >= 33) {
      count++;
    }
  }
  if(number == 1 && count == 0) {
    instructions();
    break;
  }else if(number == 2 && count == 0) {
    break;
  }else {
    count = 0;
    continue;
  }

}

}

void instructions() {
  char *cont = new char(1);
  cout << " ";
  cout <<"\n Press anything to continue to game.";
  fgets(cont,sizeof(cont),stdin);
  //Call game functions next......
}