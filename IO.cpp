#include "IO.h"
//Global

//Creating & Initialising the player(<*>)
Enterprise player;
list<kilgon> kilgons;
list<Star> stars;
string ss[10][24] = {
    {" - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
    {" - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "},
};

//Starting Screen(ASCII Art & Options)
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
  for(long unsigned int i =0; i < sizeof(ptr);i++) {
    if(ptr[i] >= 33) {
      count++;
    }
  }
  if(number == 1 && count == 0) {
    instructions();
    break;
  }else if(number == 2 && count == 0) {
    init();
    break;
  }else {
    count = 0;
    continue;
  }

}

}

//Displays the game instructions in order.
void instructions() {
  char *cont = new char(1);
  FILE *fp;
  char *str = new char[sizeof(char)*500];
  fp = fopen("Instructions.txt","r");
  if(fp == NULL) {
    printf("Error!");
    exit(1);
  }
  while( (fgets(str,sizeof(str),fp)) != NULL) {
    printf("%s",str);
  } 
  cout <<"\n Press anything to continue....";
  fgets(cont,sizeof(cont),stdin);
  cout <<"\n\n";
  fp = fopen("Instructions(2).txt","r");
  if(fp == NULL) {
    printf("Error!");
    exit(1);
  }
  while( (fgets(str,sizeof(str),fp)) != NULL) {
    printf("%s",str);
  } 
  fclose(fp);
  cout <<"\n Press anything to continue....";
  fgets(cont,sizeof(cont),stdin);
}

//Initalising the Enterprise,Kilgons,Stars and Starbases
void init() {

  //Creating & Initating the list of kilgons
  
  srand(time(0));
  int k = rand() % (20 + 1 - 5) + 5;
  srand(time(0));
  for(int i = 0; i < k;i++) {
    kilgon *a = new kilgon;
    kilgons.push_back(*a);
  }

  //Creating & Initating the list of starbases(>!<)
  list<starbase> starbases;
  srand(time(0));
  int s = rand() % (5 + 1 - 1) + 1;
  srand(time(0));
  for(int i = 0; i < s;i++) {
    starbase *a = new starbase;
    starbases.push_back(*a);
  }

  //Creating & Initating the list of stars(*)
  
  srand(time(0));
  int st = rand() %  (15 + 1 - 8) + 8;
  cout << "ST: " << st << endl;
  srand(time(0));
  for(int i = 0; i < st;i++) {
    Star *a = new Star;
    stars.push_back(*a);
  }
    // list<Star>::iterator ptr;
    // for(ptr = stars.begin();ptr != stars.end();ptr++) {
    //     cout << "KILGONS' X POS: " << ptr->returnQuadx() << endl;
    //     cout << "KILGONS' Y POS: " << ptr->returnQuady() << endl;
    // }

}

//Short Range Scan view.
void shortRangeScan() {

  int player_x = player.returnSecx();//Column
  int player_y = player.returnSecy();//Row
  int editedx = 1 + ( (player_x -1) * 3 );
  int editedy = player_y;
  ss[editedy][editedx] = "<*>";
  cout << "X: " << player_x << endl;
  cout << "Y: " << player_y << endl;
  cout << "EX: " << editedx << endl;
  cout << "EY: " << editedy << endl;
  for(int i =0; i < 10;i++) {
    for(int j =0; j < 24;j++) {
      cout << ss[i][j];
    }
    cout << "\n";
  }
  cout << "\n\n---------STATS----------"<<endl;
  cout << "STARDATE" <<endl;
  cout << "CONDITION" <<endl;
  cout << "QUADRANT" <<endl;
  cout << "SECTOR" <<endl;
  cout << "ENERGY" <<endl;
  cout << "SHIELDS" <<endl;
  cout << "PHOTON TORPEDOS" <<endl;
  cout << "---------STATS END---------"<<endl;
}