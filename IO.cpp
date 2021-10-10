#include "IO.h"
//Global
#define EAST 1
#define NORTH_EAST 2
#define NORTH 3
#define NORTH_WEST 4
#define WEST 5
#define SOUTH_WEST 6
#define SOUTH 7
#define SOUTH_EAST 8

//Creating & Initialising the player(<*>)
Enterprise player;
list<kilgon> kilgons;
list<Star> stars;
list<starbase> starbases;
extern string ss[10][24] = {
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
    shortRangeScan();
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
  
  srand(time(NULL));
  int k = rand() % (20 + 1 - 5) + 5;
  srand(time(NULL));
  for(int i = 0; i < k;i++) {
    kilgon *a = new kilgon;
    kilgons.push_back(*a);
  }
      list<kilgon>::iterator ptr_3;
      for(ptr_3 = kilgons.begin();ptr_3 != kilgons.end();ptr_3++) {
          cout << "KILGONS' X POS: " << ptr_3->returnQuadx() << endl;
          cout << "KILGONS' Y POS: " << ptr_3->returnQuady() << endl;
      }

  //Creating & Initating the list of starbases(>!<)

  srand(time(NULL));
  int s = rand() % (5 + 1 - 1) + 1;
  srand(time(NULL));
  for(int i = 0; i < s;i++) {
    starbase *a = new starbase;
    starbases.push_back(*a);
  }
      list<starbase>::iterator ptr_1;
      for(ptr_1 = starbases.begin();ptr_1 != starbases.end();ptr_1++) {
          cout << "STARBASES' X POS: " << ptr_1->returnQuadx() << endl;
          cout << "STARBASES' Y POS: " << ptr_1->returnQuady() << endl;
      }

  //Creating & Initating the list of stars(*)
  
  srand(time(NULL));
  int st = rand() %  (20 + 1 - 8) + 8;
  srand(time(NULL));
  for(int i = 0; i < st;i++) {
    Star *a = new Star;
    stars.push_back(*a);
  }
      list<Star>::iterator ptr;
      for(ptr = stars.begin();ptr != stars.end();ptr++) {
          cout << "STAR'S X POS: " << ptr->returnQuadx() << endl;
          cout << "STAR'S Y POS: " << ptr->returnQuady() << endl;
      }

}


//Short Range Scan view.
void shortRangeScan() {
  player.LoadPos();

  //Loading the Stars in the quadrant.
  list<Star>::iterator ptr;
  for(ptr = stars.begin();ptr != stars.end();ptr++) {
    if( (ptr->returnQuadx() == player.returnQuadx() ) && ptr->returnQuady() == player.returnQuady() ) {
      //Same quadrant.
      ptr->LoadPos();
    }
  }

  //Loading the Kilgons in the quadrant.
  list<kilgon>::iterator ptr_1;
  for(ptr_1 = kilgons.begin();ptr_1 != kilgons.end();ptr_1++) {
    if( (ptr_1->returnQuadx() == player.returnQuadx() ) && ptr_1->returnQuady() == player.returnQuady() ) {
      //Same quadrant.
      ptr_1->LoadPos();
    }
  }

  //Loading the Starbases in the quadrant.
  list<starbase>::iterator ptr_2;
  for(ptr_2 = starbases.begin();ptr_2 != starbases.end();ptr_2++) {
    if( (ptr_2->returnQuadx() == player.returnQuadx() ) && ptr_2->returnQuady() == player.returnQuady() ) {
      //Same quadrant.
      ptr_2->LoadPos();
    }
  }


  //Updating the board with the latest current pos values obtained from .LoadPos()
  for(int i =0; i < 10;i++) {
    for(int j =0; j < 24;j++) {
      cout << ss[i][j];
    }
    cout << "\n";
  }

  cout << "\n\n---------STATS----------"<<endl;
  cout << "STARDATE" <<endl;
  cout << "CONDITION\t" << player.getCondition() <<endl;
  cout << "QUADRANT \t(" << player.returnQuadx() <<","<< player.returnQuady() <<")"<<endl;
  cout << "SECTOR   \t(" << player.returnSecx() <<","<< player.returnSecy() <<")"<<endl;
  cout << "ENERGY   \t"<<player.getEnergy() <<endl;
  cout << "SHIELDS  \t"<<player.getArmor() <<endl;
  cout << "PHOTONS  \t" <<player.getPhotonCount() << endl;
  cout << "---------STATS END---------"<<endl;
commands();
  
}

//To handle and display the commands user can input & inputs
void commands() {
  int input;
  cout << "COMMAND: ";
  //The commands range from 0-9.
  scanf("%d",&input);
  switch(input) {
    case 0:
    movement();
    break;
    case 1:
    shortRangeScan();
    break;
    case 2:
    longScan();
    break;
    case 5:
    shieldset();
    break;
  }
}

//To control the movement of the player
void movement() {

  int course;
  float warp_factor;
  
  //Course input
  cout << "Course[1-9]: ";
  scanf("%d",&course);

  //Warp Factor input
  cout << "Warp Factor[0-8]: ";
  scanf("%f",&warp_factor);


    int move = warp_factor / 0.125;
    switch(course) {
      case EAST:
      player.tempPos(player.returnSecx(),player.returnSecy() );
      if( (player.returnSecx() + (1*move)) > 8 ) {
        int value = (player.returnSecx() + (1*move));
        int count = 0;
        while(value >= 8) {
          value = value - 8;
          count++;
        }
        if( (player.returnQuadx() + (1*count)) > 8 ) {
          cout << "X: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setQuadx(player.returnQuadx() );
          player.setSecx(player.returnSecx() );
        }else {
        player.setQuadx(player.returnQuadx() + (1*count) );
        player.setSecx(value);
        }

      }else {
      player.setSecx( player.returnSecx() + (1*move) );
      }
      break;

      case NORTH_EAST:
      player.tempPos(player.returnSecx(),player.returnSecy() );
      if( (player.returnSecx() + (1*move)) > 8 ) {
        int value = (player.returnSecx() + (1*move));
        int count = 0;
        while(value >= 8) {
          value = value - 8;
          count++;
        }
        if( (player.returnQuadx() + (1*count)) > 8 ) {
          cout << "X: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setQuadx(player.returnQuadx() );
          player.setSecx(player.returnSecx() );
        }else {
        player.setQuadx(player.returnQuadx() + (1*count) );
        player.setSecx(value);
        }
      }else {
      player.setSecx( player.returnSecx() + (1*move) );
      }

      if((player.returnSecy() - (1*move) ) < 1 ) {
        int value = player.returnSecy() - (1*move);
        int count = 0;
        while(value <= 0) {
          value = value + 8;
          count++;
        }
        if(player.returnQuady() - (1*count) < 1) {
          cout << "Y: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
         player.setSecy(player.returnSecy() );
         player.setQuady(player.returnQuady() );
        }else {
        player.setQuady(player.returnQuady() - (1*count) );
        player.setSecy(value);

        }

      }else {
      player.setSecy(player.returnSecy() - (1*move) );
      }

      break;

      case NORTH:
      player.tempPos(player.returnSecx(),player.returnSecy() );
      if((player.returnSecy() - (1*move) ) < 1) {
        int value = player.returnSecy() - (1*move);
        int count = 0;
        while(value <= 0) {
          value = value + 8;
          count++;
        }
        if(player.returnQuady() - (1*count) < 1 ) {
         cout << "Y: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
         player.setSecy(player.returnSecy() );
         player.setQuady(player.returnQuady() );          
        }else {
        player.setQuady(player.returnQuady() - (1*count) );
        player.setSecy(value);
        }

      }else {
      player.setSecy(player.returnSecy() - (1*move) );
      }

      break;
    

      case NORTH_WEST:
      player.tempPos(player.returnSecx(),player.returnSecy() );
      if( (player.returnSecx() - (1*move)) < 1 ) {
        int value = player.returnSecx() - (1*move);
        int count = 0;
        while(value <= 0) {
          value = value + 8;
          count++;
        }
        if((player.returnQuadx() - (1*count) ) < 1 ) {
          cout << "X: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setSecx(player.returnSecx() );
          player.setQuadx(player.returnQuadx() );
        }else {
        player.setQuadx(player.returnQuadx() - (1*count) );
        player.setSecx(value);
        }
      }else {
      player.setSecx(player.returnSecx() - (1*move) );
      }

      if((player.returnSecy() - (1*move)) < 1 ) {
        int value = player.returnSecy() - (1*move);
        int count = 0;
        while(value <= 0 ) {
          value = value + 8;
          count++;
        }
        if((player.returnQuady() - (1*count)) < 1 ) {
          cout << "Y: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setSecy(player.returnSecy() );
          player.setQuady(player.returnQuady() );
        }else {
          player.setQuady(player.returnQuady() - (1*count) );
          player.setSecy(value);
        }
      }else {
      player.setSecy(player.returnSecy() - (1*move) );
      }

      break;

      case WEST:
      player.tempPos(player.returnSecx(),player.returnSecy() );
      if((player.returnSecx() - (1*move)) < 1 ) {
        int value = player.returnSecx() - (1*move);
        int count = 0;
        while(value <= 0) {
          value = value + 8;
          count++;
        }
        if( (player.returnQuadx() - (1*count)) < 1) {
          cout << "X: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setQuadx(player.returnQuadx() );
          player.setSecx(player.returnSecx() );
        }else {
          player.setQuadx(player.returnQuadx() - (1*count));
          player.setSecx(value);
        }
      }else {
      player.setSecx(player.returnSecx() - (1*move) );
      }

      break;

      case SOUTH_WEST:
      player.tempPos(player.returnSecx(),player.returnSecy() );
      if(player.returnSecx() - (1*move) < 1) {
        int value = player.returnSecx() - (1*move);
        int count = 0;
        while(value <= 0) {
          value = value + 8;
          count++;
        }
        if(player.returnQuadx() - (1*count) < 1) {
          cout << "X: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setQuadx(player.returnQuadx() );
          player.setSecx(player.returnSecx() ); 
        }else {
          player.setQuadx(player.returnQuadx() - (1*count) );
          player.setSecx(value);
        }
      }else {
      player.setSecx(player.returnSecx() - (1*move) );
      }
      if(player.returnSecy() + (1*move) > 8) {
        int value = player.returnSecy() + (1*move);
        int count = 0;
        while(value >= 8) {
          value = value - 8;
          count++;
        }
        if(player.returnQuady() + (1*count) > 8) {
          cout <<"Y: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setSecy(player.returnSecy() );
          player.setQuady(player.returnQuady() );
        }else {
          player.setQuady(player.returnQuady() + (1*count) );
          player.setSecy(value);
        }
      }else {
      player.setSecy(player.returnSecy() + (1*move) );
      }

      break;

      case SOUTH:
      player.tempPos(player.returnSecx(),player.returnSecy() );
      if(player.returnSecy() + (1*move) > 8) {
        int value = player.returnSecy() + (1*move);
        int count = 0;
        while(value >= 8) {
          value = value - 8;
          count++;
        }
        if(player.returnQuady() + (1*count) > 8) {
          cout <<"Y: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setSecy(player.returnSecy() );
          player.setQuady(player.returnQuady() );
        }else {
          player.setSecy(value);
          player.setQuady(player.returnQuady() + (1*count) );
        }
      }else {
      player.setSecy(player.returnSecy() + (1*move) );
      }

      break;

      case SOUTH_EAST:
      player.tempPos(player.returnSecx(),player.returnSecy() );
      if(player.returnSecx() + (1*move) > 8) {
        int value = player.returnSecx() + (1*move);
        int count = 0;
        while(value >= 8) {
          value = value - 8;
          count++;
        }
        if(player.returnQuadx() + (1*count) > 8) {
          cout << "X: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setSecx(player.returnSecx() );
          player.setQuadx(player.returnQuadx() );
        }else {
          player.setSecx(value);
          player.setQuadx(player.returnQuadx() + (1*count) );
        }
      }else {
      player.setSecx(player.returnSecx() + (1*move) );
      }
      if(player.returnSecy() + (1*move) > 8) {
        int value = player.returnSecy() + (1*move);
        int count = 0;
        while(value >= 8) {
          value = value - 8;
          count++;
        }
        if(player.returnQuady() + (1*count) > 8 ) {
          cout<<"Y: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
          player.setSecy(player.returnSecy() );
          player.setQuady(player.returnQuady() );
        }else {
          player.setQuady(player.returnQuady() + (1*count) );
          player.setSecy(value);
        }
      }else {
      player.setSecy(player.returnSecy() + (1*move) );
      }

      break;

    }

commands();

}

void shieldset() {
  int shield_temp = player.getArmor();
  int shield;
  while(true) {
  cout << "SET ENERGY GOING TO SHIELD: ";
  scanf("%d",&shield);
  if(shield > player.getEnergy() ) {
    cout<<"NOT POSSIBLE.(ENERGY TOO LOW)"<<endl;
    continue;
  }else if(player.getArmor() >= shield) {
    cout<<"SET ENERGY HIGHER THAN PREVIOUS ONE."<<endl;
    continue;
  }else {
    break;
  }
  }
  player.setArmor(shield);
  player.setEnergy(player.getEnergy() - (shield-shield_temp) );
  commands();
}

void longScan() {

  cout<<"LONG RANGE SENSOR SCAN FOR QUADRANT "<<player.returnQuadx()<<" , "<<player.returnQuady()<<endl;
  string longResults[5][7] = {
    {"-------------------"},
    {"|",longView(-1,-1),"|", longView(0,-1), "|", longView(1,-1), "|"},
    {"|",longView(-1,0),"|", longView(0,0), "|", longView(1,0), "|"},
    {"|",longView(-1,1),"|", longView(0,1), "|", longView(1,1), "|"},
    {"-------------------"}
  };
  for(int i =0; i < 5;i++) {
    for(int j =0;j < 7;j++) {
      cout << longResults[i][j];
    }
    cout << "\n";
  }
  commands();
}

void test() {
  cout << "ENTERPRISE'S X POS: " << player.returnQuadx() << endl;
  cout << "ENTERPRISE'S Y POS: " << player.returnQuady() << endl;
}

string longView(int x,int y) {


  int count = 0;
  list<Star>::iterator ptr;
  for(ptr = stars.begin();ptr != stars.end();ptr++ ) {
    if(ptr->returnQuadx() == player.returnQuadx()+x ) {
      if(ptr->returnQuady() == player.returnQuady()+y ) {
        //Same quadrant
        count++;
      }
    }
  }
  int count_1 = 0;
  list<kilgon>::iterator ptr_1;
    for(ptr_1 = kilgons.begin();ptr_1 != kilgons.end();ptr_1++ ) {
    if(ptr_1->returnQuadx() == player.returnQuadx()+x ) {
      if(ptr_1->returnQuady() == player.returnQuady()+y ) {
        //Same quadrant
        count_1++;
      }
    }
  }

  int count_2 = 0;
  list<starbase>::iterator ptr_2;
    for(ptr_2 = starbases.begin();ptr_2 != starbases.end();ptr_2++ ) {
    if(ptr_2->returnQuadx() == player.returnQuadx()+x ) {
      if(ptr_2->returnQuady() == player.returnQuady()+y ) {
        //Same quadrant
        count_2++;
      }
    }
  }
 int result = count + (count_2*10) + (count_1*100);
  if(result == 0) {
    return "000";
  }else if(result < 10) {
    return "00" + to_string(result);
  }else if(result < 100) {
    return "0" + to_string(result);
  }else {
    return to_string(result);
  }
  
}