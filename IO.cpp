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
//map<int ,string>Records;


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
  //Character to take in input on the instructions screen
  char *cont = new char(1);
  //Opening file that contains the instructions(1)
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
  //Opening file that contains the instructions(1)
  fp = fopen("Instructions(2).txt","r");
  if(fp == NULL) {
    printf("Error!");
    exit(1);
  }
  while( (fgets(str,sizeof(str),fp)) != NULL) {
    printf("%s",str);
  } 
  fclose(fp);
  //End of instructions
  cout <<"\n Press anything to continue....";
  fgets(cont,sizeof(cont),stdin);
}

//Initalising the Enterprise,Kilgons,Stars and Starbases
void init() {

  //Creating & Initating the list of kilgons
  srand(time(NULL));
  int k = 1;
  srand(time(NULL));
  for(int i = 0; i < k;i++) {
    kilgon *a = new kilgon;
    kilgons.push_back(*a);
  }
  //TESTING: shows the positions(quadrant) as output to check against.
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
    //TESTING: shows the positions(quadrant) as output to check against.
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
    //TESTING: shows the positions(quadrant) as output to check against.
      list<Star>::iterator ptr;
      for(ptr = stars.begin();ptr != stars.end();ptr++) {
          cout << "STAR'S X POS: " << ptr->returnQuadx() << endl;
          cout << "STAR'S Y POS: " << ptr->returnQuady() << endl;
      }

}


//Short Range Scan view.
void shortRangeScan() {
  //Resetting the view to default to prevent double loading of the elements.
  for(int i =1;i < 9;i++) {
    for(int j =0;j < 24;j++) {
      ss[i][j] = " - ";
    }
  }
  //Setting initial condition of the player
  player.setCondition("GREEN");

  //Loading position of the player.
  player.LoadPos();

  //Loading the Stars in the quadrant.
  list<Star>::iterator ptr;
  for(ptr = stars.begin();ptr != stars.end();ptr++) {
    if( (ptr->returnQuadx() == player.returnQuadx() ) && ptr->returnQuady() == player.returnQuady()  ) {
      //Same Quadrant as player
      ptr->LoadPos();
    }
  }  

  //Loading the Kilgons in the quadrant.
  list<kilgon>::iterator ptr_1;
  for(ptr_1 = kilgons.begin();ptr_1 != kilgons.end();ptr_1++) {
    if((ptr_1->returnQuadx() == player.returnQuadx() ) && ptr_1->returnQuady() == player.returnQuady() ) {
      //Same quadrant as player
      ptr_1->LoadPos();
      if(player.getCondition() != "DOCKED") {//If player is docked in the Starbase)
      player.setCondition("RED");
      player.setTempCond("RED");
      }      
    }
  }

  //Loading the Starbases in the quadrant.
  list<starbase>::iterator ptr_2;
  for(ptr_2 = starbases.begin();ptr_2 != starbases.end();ptr_2++) {
    if( (ptr_2->returnQuadx() == player.returnQuadx() ) && ptr_2->returnQuady() == player.returnQuady()  ) {
      if(ptr_2->returnSecx() == player.returnSecx() && ptr_2->returnSecy() == player.returnSecy() ) {
        player.setCondition("DOCKED");
        cout << "SHIELDS DROPPED FOR DOCKING PURPOSES\n"<<endl;
        ptr_2->docked();
        player.setArmor(0);
        player.setEnergy(3000);
        continue;
      }
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
  while(input < 0 || input > 7 ) {
    cout <<"0 = SET COURSE\n1 = SHORT RANGE SENSOR SCAN\n2 = LONG RANGE SENSOR SCAN\n3 = FIRE PHASERS\n4 = FIRE PHOTON TORPEDOES\n5 = SHIELD CONTROL\n6 = DAMAGE CONTROL REPORT\n7 = CALL ON LIBRARY COMPUTER\n\n"<<endl;
    cout << "COMMAND: ";
    scanf("%d",&input);
  }
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
    case 3:
    pulseAttk();
    break;
    case 4:
    photonAttk();
    break;
    case 5:
    shieldset();
    case 7:
    libraryComputer();
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

    //move = number of 1/8th part of quadrants moved.
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
        // if(value == 0){
        //   value = 8;
        //   count-=1;
        // }
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
        // if(value == 0) {
        //   value = 8;
        //   count-=1;
        // }
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
        // if(value == 8) {
        //   value = 1;
        //   count+=1;
        // }
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
        // if(value == 8) {
        //   value = 1;
        //   count+=1;
        // }
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
        // if(value == 8) {
        //   value = 1;
        //   count+=1;
        // }
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
        // if(value == 8) {
        //   value = 1;
        //   count+=1;
        // }
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
        // if(value == 8) {
        //   value = 1;
        //   count+=1;
        // }
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
        // if(value == 8) {
        //   value = 1;
        //   count+=1;
        // }
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
        // if(value == 0) {
        //   value = 8;
        //   count-=1;
        // }
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
        // if(value == 0) {
        //   value = 8;
        //   count-=1;
        // }
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
        // if(value == 0) {
        //     value = 8;
        //     count-=1;
        //   }
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
        // if(value == 0) {
        //     value = 8;
        //     count-=1;
        //   }
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

      // list<starbase>::iterator ptr_a;
      // for(ptr_a = starbases.begin();ptr_a != starbases.end();ptr_a++) {
      // if( (ptr_a->returnQuadx() == player.returnQuadx() ) && ptr_a->returnQuady() == player.returnQuady() ) {
      //   //Same quadrant.
      // if( (ptr_a->returnSecx() == player.returnSecx() ) && ptr_a->returnSecy() == player.returnSecy() ){
      //     //Same Sector
      //     player.setTempCond(player.getCondition() );
      //     player.setCondition("DOCKED");
      //     cout << "SHIELDS DROPPED FOR DOCKING PURPOSES\n"<<endl;
      //     int editedx = 1 + ( (ptr_a->returnSecx() -1) * 3 );
      //     int editedy = ptr_a->returnSecy();
      //     ss[editedy][editedx] = ">*<";
      //     player.setArmor(0);
      //     player.setEnergy(3000);
      //    }else {
      //      int editedx = 1 + ( (ptr_a->returnSecx() -1) * 3 );
      //      int editedy = ptr_a->returnSecy();
      //      ss[editedy][editedx] = ">!<";
      //      player.setCondition(player.getTempCond() );
      //  }  

      // }

      // } 
commands();

}
//To set shield strength.
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

void pulseAttk() {
  int inpt,enemy,p;
  list<kilgon>::iterator ptr_1;
  for(ptr_1 = kilgons.begin();ptr_1 != kilgons.end();ptr_1++) {
    if( (ptr_1->returnQuadx() == player.returnQuadx() ) && ptr_1->returnQuady() == player.returnQuady() ) {
      while(player.getArmor() >= 0 && ptr_1->getArmor() > 0 ) {
      cout << "TARGET ACQUIRED! ATTACKING...."<<endl;
      cout <<"ENTER ENERGY TO BE USED: ";
      scanf("%d",&inpt);
      p = player.getPulse();
      while(p > inpt) {
        srand(time(0));
        p = rand() % (inpt + 1 - 0) + 0;
      }
      player.setEnergy(player.getEnergy() - inpt);
      enemy = ptr_1->getPulse();
      player.setArmor(player.getArmor() - enemy);
      ptr_1->setArmor(ptr_1->getArmor() - p);
      if(ptr_1->getArmor() > 0 || player.getArmor() > 0) {
      cout <<"ENTERPRISE HIT TARGET WITH "<<p<<"UNITS("<<player.getArmor()<<"SHIELD LEFT)"<<endl;
      cout <<"KILGON HIT ENTERPRISE WITH "<<enemy<<"UNITS("<<ptr_1->getArmor()<<"ENERGY LEFT)"<<endl;
      }
      }
      if(ptr_1->getArmor() <= 0) {
        //Enemy has been killed.
        ptr_1->tempPos(ptr_1->returnSecx(),ptr_1->returnSecy() );          
        kilgons.erase(ptr_1);  
        cout << "*********KILGON HAS BEEN KILLED*********"<<endl;
        if(kilgons.size() == 0) {
        cout<<"ALL THE KILGONS HAVE BEEN DESTROYED! GAME OVER"<<endl;
        exit(1);
        }else {
          commands();
        }

      }
      if(player.getArmor() <= 0) {
        cout<<"*******ENTERPRISE HAS BEEN DESTROYED!! GAME OVER*******"<<endl;
        exit(1);
      }

    }
  }
      cout << "KILGONS NOT DETECTED!"<<endl;
      commands();
}

void libraryComputer() {
  cout<<"OPTION: ";
  int inpt;
  scanf("%d",&inpt);
  while(inpt < 0 || inpt > 2) {
    cout <<"THE LIBRARY COMPUTER CONTAINS 3 OPTIONS:\n\n"<<endl;
    cout<<"OPTION 0 = CUMULATIVE GALACTIC RECORD"<<endl;
    cout<<"OPTION 1 = STATUS REPORT"<<endl;
    cout<<"OPTION 2 = PHOTON TORPEDO TRAJECTORY DATA"<<endl;
    cout<<"OPTION: ";
    scanf("%d",&inpt);   
  }
  switch(inpt) {

    //Cumulative Record
    case 0:
    cout<<"COMPUTER RECORD OF GALAXY FOR QUADRANT "<<player.returnQuadx()<<","<<player.returnQuady()<<endl;
    break;
    //Status Report
    case 1:
    cout<<"*********STATUS REPORT*********"<<endl;
    cout<<"NUMBER OF KILGONS LEFT: "<<kilgons.size()<<endl;
    cout<<"STARDATES:"<<endl;
    cout<<"NUMBER OF STARBASES: "<<starbases.size()<<endl;
    cout<<"*******************************"<<endl;
    commands();
    break;

    //Calculator + Trajectory detector.
    case 2:
    list<kilgon>::iterator ptr_1;
    int x_diff,y_diff,input;
    for(ptr_1 = kilgons.begin();ptr_1 != kilgons.end();ptr_1++){
      if( (ptr_1->returnQuadx() == player.returnQuadx() ) && ptr_1->returnQuady() == player.returnQuady() ){
        //Kilgon present in current quadrant 
        x_diff = ptr_1->returnSecx() - player.returnSecx();
        y_diff = ptr_1->returnSecy() - player.returnSecy();
        if(x_diff > 0 && y_diff == 0) {
          //East
          cout <<"TRAJECTORY: "<<EAST<<endl;
        }else if(x_diff > 0 && y_diff < 0) {
          //North-East
          cout <<"TRAJECTORY: "<<NORTH_EAST<<endl;
        }else if(x_diff == 0 && y_diff < 0) {
          //North
          cout<<"TRAJECTORY: "<<NORTH<<endl;
        }else if(x_diff < 0 && y_diff < 0) {
          //North-West
          cout<<"TRAJECTORY: "<<NORTH_WEST<<endl;
        }else if(x_diff < 0 && y_diff == 0) {
          cout<<"TRAJECTORY: "<<WEST<<endl;
        }else if(x_diff < 0 && y_diff > 0) {
          cout<<"TRAJECTORY: "<<SOUTH_WEST<<endl;
        }else if(x_diff == 0 && y_diff > 0) {
          cout<<"TRAJECTORY: "<<SOUTH<<endl;
        }else if(x_diff > 0 && y_diff > 0) {
          cout<<"TRAJECTORY: "<<SOUTH_EAST<<endl;
        }
    }
  }
  cout <<"TO USE CALCULATOR PRESS 1 or 0 to exit: ";
  scanf("%d",&input);
  while(input < 0 || input > 1) {
    cout <<"TO USE CALCULATOR PRESS 1 or 0 to exit: ";
    scanf("%d",&input);  
  }
  switch(input) {
    case 0:
    commands();
    break;
    case 1:
    //Calculator
    int x1,y1,x2,y2,diff_x,diff_y;
    float dist;
    cout <<"INPUT THE COORDINATES OF ENTERPRISE: ";
    scanf("%d %d",&x1,&y1);
    cout <<"INPUT THE COORDINATES OF ENEMY SHIP: ";
    scanf("%d %d",&x2,&y2);
    diff_x = x2 - x1;
    diff_y = y2 - y1;
    dist = sqrt( (diff_x*diff_x) + (diff_y*diff_y) );
    cout <<"DISTANCE BETWEEN THE BOTH ARE: "<<dist<<"UNITS."<<endl;
    commands();
  }
  break;

}
}

void photonAttk() {
  int traj,photonx = player.returnSecx(),photony = player.returnSecy();
  cout << "COMPUTER INITIALISED. ENTER TRAJECTORY[1-8]: ";
  scanf("%d",&traj);
  list<kilgon>::iterator ptr_1;
  for(ptr_1 = kilgons.begin();ptr_1 != kilgons.end();ptr_1++) {
  if( (ptr_1->returnQuadx() == player.returnQuadx() ) && ptr_1->returnQuady() == player.returnQuady() ) {
    //Kilgon is present in the current quadrant.
    cout<<"PHOTON PATH:\n"<<endl;
    switch(traj) {
      case EAST:
      while(photonx < ptr_1->returnSecx() && photonx != 8 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photonx++;
      }
      if(photonx == ptr_1->returnSecx() && photony == ptr_1->returnSecy() ) {
        //Kilgon killed.
        if(player.getPhotonCount() > 0) {
        player.setPhotonCount(player.getPhotonCount() - 1);
        ptr_1->tempPos(ptr_1->returnSecx(),ptr_1->returnSecy() );          
        kilgons.erase(ptr_1);  
        cout <<"KILGON SUCCESSFULLY HIT!"<<endl;
        }else {
          cout<<"NO MORE PHOTONS. ATTACK FAILED!"<<endl;
        }

      }else {
        cout << "MISSED KILGON!!"<<endl;
        player.setPhotonCount(player.getPhotonCount() - 1);
      }
      break;

      case NORTH_EAST:
      while(photonx < ptr_1->returnSecx() && photonx != 8 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photonx++;        
      }
      while(photony > ptr_1->returnSecy() && photony != 0 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photony--;        
      }      
      if(photonx == ptr_1->returnSecx() && photony == ptr_1->returnSecy() ) {
        //Kilgon killed.
        if(player.getPhotonCount() > 0) {
        player.setPhotonCount(player.getPhotonCount() - 1);
        ptr_1->tempPos(ptr_1->returnSecx(),ptr_1->returnSecy() );          
        kilgons.erase(ptr_1);  
        cout <<"KILGON SUCCESSFULLY HIT!"<<endl;
        }else {
          cout<<"NO MORE PHOTONS. ATTACK FAILED!"<<endl;
        }
      }else {
        cout << "MISSED KILGON!!"<<endl;
        player.setPhotonCount(player.getPhotonCount() - 1);        
      }
      break;
      case NORTH:
      while(photony > ptr_1->returnSecy() && photony != 0 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photony--;        
      } 
      if(photonx == ptr_1->returnSecx() && photony == ptr_1->returnSecy() ) {
        //Kilgon killed.
        if(player.getPhotonCount() > 0) {
        player.setPhotonCount(player.getPhotonCount() - 1);
        ptr_1->tempPos(ptr_1->returnSecx(),ptr_1->returnSecy() );          
        kilgons.erase(ptr_1);  
        cout <<"KILGON SUCCESSFULLY HIT!"<<endl;
        }else {
          cout<<"NO MORE PHOTONS. ATTACK FAILED!"<<endl;
        }
      }else {
        cout << "MISSED KILGON!!"<<endl;
        player.setPhotonCount(player.getPhotonCount() - 1);        
      }
      break; 

      case NORTH_WEST:
      while(photonx > ptr_1->returnSecx() && photonx != 0 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photonx--;        
      }      
      while(photony > ptr_1->returnSecy() && photony != 0 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photony--;        
      }
      if(photonx == ptr_1->returnSecx() && photony == ptr_1->returnSecy() ) {
        //Kilgon killed.
        if(player.getPhotonCount() > 0) {
        player.setPhotonCount(player.getPhotonCount() - 1);
        ptr_1->tempPos(ptr_1->returnSecx(),ptr_1->returnSecy() );          
        kilgons.erase(ptr_1);  
        cout <<"KILGON SUCCESSFULLY HIT!"<<endl;
        }else {
          cout<<"NO MORE PHOTONS. ATTACK FAILED!"<<endl;
        }
      }else {
        cout << "MISSED KILGON!!"<<endl;
        player.setPhotonCount(player.getPhotonCount() - 1);        
      }
      break;

      case WEST:
      while(photonx > ptr_1->returnSecx() && photonx != 0 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photonx--;        
      }
      if(photonx == ptr_1->returnSecx() && photony == ptr_1->returnSecy() ) {
        //Kilgon killed.
        if(player.getPhotonCount() > 0) {
        player.setPhotonCount(player.getPhotonCount() - 1);
        ptr_1->tempPos(ptr_1->returnSecx(),ptr_1->returnSecy() );          
        kilgons.erase(ptr_1);  
        cout <<"KILGON SUCCESSFULLY HIT!"<<endl;
        }else {
          cout<<"NO MORE PHOTONS. ATTACK FAILED!"<<endl;
        }
      }else {
        cout << "MISSED KILGON!!"<<endl;
        player.setPhotonCount(player.getPhotonCount() - 1);        
      }
      break;

      case SOUTH_WEST:
      while(photonx > ptr_1->returnSecx() && photonx != 0 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photonx--;        
      }
      while(photony < ptr_1->returnSecy() && photony != 8 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photony++;        
      }
      if(photonx == ptr_1->returnSecx() && photony == ptr_1->returnSecy() ) {
        //Kilgon killed.
        if(player.getPhotonCount() > 0) {
        player.setPhotonCount(player.getPhotonCount() - 1);
        ptr_1->tempPos(ptr_1->returnSecx(),ptr_1->returnSecy() );          
        kilgons.erase(ptr_1);  
        cout <<"KILGON SUCCESSFULLY HIT!"<<endl;
        }else {
          cout<<"NO MORE PHOTONS. ATTACK FAILED!"<<endl;
        }
      }else {
        cout << "MISSED KILGON!!"<<endl;
        player.setPhotonCount(player.getPhotonCount() - 1);        
      }
      break;

      case SOUTH:
      while(photony < ptr_1->returnSecy() && photony != 8 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photony++;        
      }
      if(photonx == ptr_1->returnSecx() && photony == ptr_1->returnSecy() ) {
        //Kilgon killed.
        if(player.getPhotonCount() > 0) {
        player.setPhotonCount(player.getPhotonCount() - 1);
        ptr_1->tempPos(ptr_1->returnSecx(),ptr_1->returnSecy() );          
        kilgons.erase(ptr_1);  
        cout <<"KILGON SUCCESSFULLY HIT!"<<endl;
        }else {
          cout<<"NO MORE PHOTONS. ATTACK FAILED!"<<endl;
        }
      }else {
        cout << "MISSED KILGON!!"<<endl;
        player.setPhotonCount(player.getPhotonCount() - 1);        
      }
      break;

      case SOUTH_EAST:
      while(photony < ptr_1->returnSecy() && photony != 8 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photony++;        
      }
      while(photonx < ptr_1->returnSecx() && photonx != 8 ) {
        cout<<"("<<photonx<<","<<photony<<")"<<endl;
        photonx++;        
      }
      if(photonx == ptr_1->returnSecx() && photony == ptr_1->returnSecy() ) {
        //Kilgon killed.
        if(player.getPhotonCount() > 0) {
        player.setPhotonCount(player.getPhotonCount() - 1);
        ptr_1->tempPos(ptr_1->returnSecx(),ptr_1->returnSecy() );          
        kilgons.erase(ptr_1);  
        cout <<"KILGON SUCCESSFULLY HIT!"<<endl;
        }else {
          cout<<"NO MORE PHOTONS. ATTACK FAILED!"<<endl;
        }
      }else {
        cout << "MISSED KILGON!!"<<endl;
        player.setPhotonCount(player.getPhotonCount() - 1);        
      }
      break;                                                                   
    }
    if(kilgons.size() == 0) {
      cout<<"ALL THE KILGONS HAVE BEEN DESTROYED!! GAME OVER"<<endl;
      exit(1);
    }else {
    commands();
    }

  }

  }
  if(player.getPhotonCount() > 0) {
  cout<<"NO KILGON DETECTED! PHOTON WASTED!"<<endl;
  player.setPhotonCount(player.getPhotonCount() - 1);
  commands();
  }else {
    cout<<"NO PHOTONS & NO KILGON DETECTED!"<<endl;
    commands();
  }


}


