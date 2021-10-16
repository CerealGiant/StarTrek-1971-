#include "IO.h"
#include "InputErrorCheck.h"
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
map<int ,string>Record;
string Rds[8][8] = {
  {"\0","\0","\0","\0","\0","\0","\0","\0"},
  {"\0","\0","\0","\0","\0","\0","\0","\0"},
  {"\0","\0","\0","\0","\0","\0","\0","\0"},
  {"\0","\0","\0","\0","\0","\0","\0","\0"},
  {"\0","\0","\0","\0","\0","\0","\0","\0"},
  {"\0","\0","\0","\0","\0","\0","\0","\0"},
  {"\0","\0","\0","\0","\0","\0","\0","\0"},
  {"\0","\0","\0","\0","\0","\0","\0","\0"}
};
string Records[10][17] = {
  {"-------------------------------------------------"},
  {"|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000" ,"|" ,"000" ,"|"},
  {"|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000" ,"|" ,"000" ,"|"},
  {"|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000" ,"|", "000" ,"|"},
  {"|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000" ,"|", "000" ,"|"},
  {"|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000" ,"|" ,"000" ,"|"},
  {"|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000" ,"|" ,"000" ,"|"},
  {"|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000" ,"|" ,"000" ,"|"},
  {"|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000", "|", "000" ,"|", "000" ,"|"},
  {"-------------------------------------------------"}            
};

string ss[10][26] = {
    {" - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - ","STARDATE ","FILLER"},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - ","CONDITION ","FILLER"},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - ","QUADRANT ","FILLER"},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - ","SECTOR ","FILLER"},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - ","ENERGY ","FILLER"},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - ","SHIELDS ","FILLER"},
    {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - ","PHOTONS ","FILLER"},
    {" - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "," - "," = "," - "},
};

//Starting Screen(ASCII Art & Options)
void start() {
  char *st = new char[500];

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
  cout<<"\n";
  //Error Checking Loop
  switch(inputCheck("PRESS 1 FOR INSTRUCTIONS. PRESS 2 TO BEGIN:",1,2)) {
    case 1:
    instructions();
    break;
    case 2:
    cout<<"\n\t\t\t\tSTAR TREK\n"<<endl;
    init();
    cout<<"THERE ARE "<<kilgons.size()<<" KILGONS TO DESTROY"<<" IN "<<player.getDuration()<<" STARDATES."<<"THERE ARE "<<starbases.size() <<" STARBASES.\n"<<endl;
    shortRangeScan();
    break;
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
  srand(time(0));
  int d = rand() % (30 + 1 - 12) + 12;
    player.setDuration(d); 
    for(int i =1;i < 9;i++) {
      for(int j = 1;j<9;j++) {
        int number = (i*10) + j;
        Record[number] = "NAN";
      }
    }
  //Creating & Initating the list of kilgons
  srand(time(NULL));
  int k = rand() % (25 + 1 - 8) + 8;
  srand(time(NULL));
  for(int i = 0; i < k;i++) {
    kilgon *a = new kilgon;
    kilgons.push_back(*a);
  }
  //TESTING: shows the positions(quadrant) as output to check against.
      // list<kilgon>::iterator ptr_3;
      // for(ptr_3 = kilgons.begin();ptr_3 != kilgons.end();ptr_3++) {
      //     cout << "KILGONS' X POS: " << ptr_3->returnQuadx() << endl;
      //     cout << "KILGONS' Y POS: " << ptr_3->returnQuady() << endl;
      // }

  //Creating & Initating the list of starbases(>!<)

  srand(time(NULL));
  int s = rand() % (5 + 1 - 1) + 1;
  srand(time(NULL));
  for(int i = 0; i < s;i++) {
    starbase *a = new starbase;
    starbases.push_back(*a);
  }
    //TESTING: shows the positions(quadrant) as output to check against.
      // list<starbase>::iterator ptr_1;
      // for(ptr_1 = starbases.begin();ptr_1 != starbases.end();ptr_1++) {
      //     cout << "STARBASES' X POS: " << ptr_1->returnQuadx() << endl;
      //     cout << "STARBASES' Y POS: " << ptr_1->returnQuady() << endl;
      // }

  //Creating & Initating the list of stars(*)

  srand(time(NULL));
  int st = rand() %  (200 + 1 - 100) + 100;
  srand(time(NULL));
  for(int i = 0; i < st;i++) {
    Star *a = new Star;
    stars.push_back(*a);
  }
    //TESTING: shows the positions(quadrant) as output to check against.
      // list<Star>::iterator ptr;
      // for(ptr = stars.begin();ptr != stars.end();ptr++) {
      //     cout << "STAR'S X POS: " << ptr->returnQuadx() << endl;
      //     cout << "STAR'S Y POS: " << ptr->returnQuady() << endl;
      //     cout<<"STAR'S COUNT: "<<stars.size() <<endl;
      // }

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
      cout<<"\n(!)KILGON PRESENT IN THIS AREA"<<endl;      
    }
  }
  if(player.getArmor() < 100 ) {
    cout<<"\t(!)SHIELD LEVELS DANGEROUSLY LOW"<<endl;
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
        player.setPhotonCount(10);
        continue;
      }
      ptr_2->LoadPos();
    }
  }

  
  string Quadrant = to_string(player.returnQuadx() ) + "," + to_string(player.returnQuady() );
  string Sector = to_string(player.returnSecx()) + "," + to_string( player.returnSecy() );
  ss[2][25] = to_string(player.getStarDate() );
  ss[3][25] = player.getCondition();
  ss[4][25] = Quadrant;
  ss[5][25] = Sector;
  ss[6][25] = to_string(player.getEnergy() );
  ss[7][25] = to_string(player.getArmor() );
  ss[8][25] = to_string(player.getPhotonCount() );
  
  
  //Updating the board with the latest current pos values obtained from .LoadPos() & other important values
  for(int i =0; i < 10;i++) {
    for(int j =0; j < 26;j++) {
      cout << ss[i][j];
    }
    cout << "\n";
  }

commands();
  
}

//To handle and display the commands user can input & inputs
void commands() {

  switch(inputCheck("COMMAND: ",0,7) ) {
    case 0:
    while(player.getWarp() < 0) {
      cout<<"DAMAGE CONTROL REPORT: WARP ENGINES ARE DOWN!"<<endl;
    }    
    movement();
    break;
    case 1:
    while(player.getS() < 0) {
      cout<<"DAMAGE CONTROL REPORT: S.R SENSORS ARE DOWN!"<<endl;
    }
    shortRangeScan();
    break;
    case 2:
    while(player.getL() < 0) {
      cout<<"DAMAGE CONTROL REPORT: L.R SENSORS ARE DOWN!"<<endl;
    }    
    longScan();
    break;
    case 3:
    while(player.getPhaser() < 0) {
      cout<<"DAMAGE CONTROL REPORT: PHASER CONTROL IS DOWN!"<<endl;
    }    
    pulseAttk();
    break;
    case 4:
    while(player.getPhoton() < 0) {
      cout<<"DAMAGE CONTROL REPORT: PHOTON TUBES ARE DOWN!"<<endl;
    }    
    photonAttk();
    break;
    case 5:
    while(player.getShield() < 0) {
      cout<<"DAMAGE CONTROL REPORT: SHIELD CONTROL IS DOWN!"<<endl;
    }    
    shieldset();
    case 7:
    while(player.getComputer() < 0) {
      cout<<"DAMAGE CONTROL REPORT: COMPUTER IS DOWN!"<<endl;
    }    
    libraryComputer();
    break;
  }
}

//To control the movement of the player
void movement() {

    int tempsecx = player.returnSecx();
    int tempsecy = player.returnSecy();  
    int tempquadx = player.returnQuadx(); 
    int tempquady = player.returnQuady();    
    int course;
    float warp_factor;
    
    //Course input
    course = inputCheck("COURSE(1-8): ",1,8);
  
  
    //Warp Factor input
    warp_factor = inputCheck_F("WARP FACTOR(0-8): ",0,8);
  
  
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
           if(value == 0){
             value = 8;
             count-=1;
         }
          if( (player.returnQuadx() + (1*count)) > 8 ) {
            cout << "X: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
            player.setQuadx(player.returnQuadx() );
            player.setSecx(player.returnSecx() );
          }else {
          player.setQuadx(player.returnQuadx() + (1*count) );
          player.setSecx(value);
        player.Add();
          player.setStarDate(player.getStarDate() + 1);
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
           if(value == 0) {
             value = 8;
             count-=1;
           }
          if( (player.returnQuadx() + (1*count)) > 8 ) {
            cout << "X: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
            player.setQuadx(player.returnQuadx() );
            player.setSecx(player.returnSecx() );
          }else {
          player.setQuadx(player.returnQuadx() + (1*count) );
          player.setSecx(value);
        player.Add();
          player.setStarDate(player.getStarDate() + 1);
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
        player.Add();
          player.setStarDate(player.getStarDate() + 1);
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
        player.Add();
          player.setStarDate(player.getStarDate() + 1);
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
        player.Add();
          player.setStarDate(player.getStarDate() + 1);
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
  
            player.Add();
            player.setStarDate(player.getStarDate() + 1);
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
  
            player.Add();
            player.setStarDate(player.getStarDate() + 1);
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
  
            player.Add();
            player.setStarDate(player.getStarDate() + 1);
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
           if(value == 0) {
             value = 8;
             count-=1;
           }
          if(player.returnQuady() + (1*count) > 8) {
            cout <<"Y: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
            player.setSecy(player.returnSecy() );
            player.setQuady(player.returnQuady() );
          }else {
            player.setQuady(player.returnQuady() + (1*count) );
            player.setSecy(value);
  
            player.Add();
            player.setStarDate(player.getStarDate() + 1);
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
           if(value == 0) {
             value = 8;
             count-=1;
           }
          if(player.returnQuady() + (1*count) > 8) {
            cout <<"Y: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
            player.setSecy(player.returnSecy() );
            player.setQuady(player.returnQuady() );
          }else {
            player.setSecy(value);
            player.setQuady(player.returnQuady() + (1*count) );
  
            player.Add();
            player.setStarDate(player.getStarDate() + 1);
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
           if(value == 0) {
               value = 8;
               count-=1;
             }
          if(player.returnQuadx() + (1*count) > 8) {
            cout << "X: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
            player.setSecx(player.returnSecx() );
            player.setQuadx(player.returnQuadx() );
          }else {
            player.setSecx(value);
            player.setQuadx(player.returnQuadx() + (1*count) );
  
            player.Add();
            player.setStarDate(player.getStarDate() + 1);
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
           if(value == 0) {
               value = 8;
               count-=1;
             }
          if(player.returnQuady() + (1*count) > 8 ) {
            cout<<"Y: TOO FAR OUT OF THE GALAXY!(UNDEFINED)"<<endl;
            player.setSecy(player.returnSecy() );
            player.setQuady(player.returnQuady() );
          }else {
            player.setQuady(player.returnQuady() + (1*count) );
            player.setSecy(value);
            player.Add();
            player.setStarDate(player.getStarDate() + 1);
          }
        }else {
        player.setSecy(player.returnSecy() + (1*move) );
        }
  
        break;
  
  
      }
  
        if(player.getStarDate() - player.getIStarDate() == player.getDuration() ) {
          cout<<"IT IS NOW "<<player.getStarDate()<<". THERE ARE "<<kilgons.size() <<" LEFT."<<endl;
          cout<<"\t\tENTERPRISE WAS UNSUCCESSFUL IN DESTROYING ALL KILGONS IN THE GALAXY.GAME OVER"<<endl;
          exit(1);
        }
        
     list<Star>::iterator ptr;
     for(ptr = stars.begin();ptr != stars.end();ptr++) {
       if( (ptr->returnQuadx() == player.returnQuadx() ) && ptr->returnQuady() == player.returnQuady()  ) {
         //Same Quadrant as player
         if(ptr->returnSecx() == player.returnSecx() && ptr->returnSecy() == player.returnSecy() ) {
           cout<<"YOU CANT NAVIGATE INTO STARS SILLY!!"<<endl;
           player.setQuadx(tempquadx);
           player.setQuady(tempquady);
           player.setSecx(tempsecx);
           player.setSecy(tempsecy);
          if(player.getArmor() - 10 > 0) {
            player.setArmor(player.getArmor() - 10);
          }else {
            cout<<"ENTERPRISE WAS DESTROYED!! GAME OVER!"<<endl;
            exit(1);
          }
         }
         
       }
     }  
            
     list<kilgon>::iterator ptr1;
     for(ptr1 = kilgons.begin();ptr1 != kilgons.end();ptr1++) {
       if( (ptr1->returnQuadx() == player.returnQuadx() ) && ptr1->returnQuady() == player.returnQuady()  ) {
         //Same Quadrant as player
         if(ptr1->returnSecx() == player.returnSecx() && ptr1->returnSecy() == player.returnSecy() ) {
           cout<<"YOU DONT NAVIGATE INTO KILGONS SILLY!! YOU DESTROY THEM!"<<endl;
           player.setQuadx(tempquadx);
           player.setQuady(tempquady);
           player.setSecx(tempsecx);
           player.setSecy(tempsecy);
          if(player.getArmor() - 50 > 0) {
            player.setArmor(player.getArmor() - 50);
          }else {
            cout<<"ENTERPRISE WAS DESTROYED!! GAME OVER!"<<endl;
            exit(1);
          }         
         }
         
       }
     } 
  
int random = 0;
list<kilgon>::iterator ptr2;
for(ptr2 = kilgons.begin();ptr2 != kilgons.end();ptr2++) {
  if( (ptr2->returnQuadx() == player.returnQuadx() ) && ptr2->returnQuady() == player.returnQuady()  ) {
    //Same Quadrant as player
    srand(time(NULL));
    random = rand() % (100 + 1 - 50) + 50;
    if(player.getArmor() - random > 0) {
        cout<<"KILGON HIT ENTERPRISE WITH "<<random<<" NUMBER OF UNITS"<<endl;
        player.setArmor(player.getArmor() - random);
    }else {
      cout<<"ARMOR: "<<player.getArmor()<<endl;
      cout<<"RANDOM "<<random<<endl;
        cout<<"ENTERPRISE HAS BEEN DESTROYED! GAME OVER!!" <<endl;
        exit(1);
    }
  }
}  
    player.Destroy();
    
    commands();
    
    }

//To set shield strength.
void shieldset() {
  int shield = inputCheck("SET ENERGY GOING TO SHIELD: ",player.getArmor() ,player.getEnergy() );
  player.setArmor(shield);
  player.setEnergy(3000 - shield);
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
  for(int i = -1; i < 2;i++) {
    for(int j = -1; j < 2;j++) {
      int number = ((player.returnQuadx() + i) * 10) + (player.returnQuady() + j);
      Record[number] = longView(i,j); 
    }
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
  int enemy,p;
  list<kilgon>::iterator ptr_1;
  for(ptr_1 = kilgons.begin();ptr_1 != kilgons.end();ptr_1++) {
    if( (ptr_1->returnQuadx() == player.returnQuadx() ) && ptr_1->returnQuady() == player.returnQuady() ) {
      while(player.getArmor() >= 0 && ptr_1->getArmor() > 0 ) {
      cout<<"TARGET ACQUIRED! ATTACKING....\n";
      int inpt = inputCheck("ENTER ENERGY TO BE USED: ",0,player.getEnergy() );
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

  int count = 11,temp_count = 11;
  switch(inputCheck("OPTION: ",0,2) ) {
    
    //Cumulative Record
    case 0:
    //Load the values into the map
    for(int i = 1;i < 9;i++) {
      for(int j = 1; j < 17;j+=2) {
        Records[i][j] = Record[count];
        if(count < 80) {
          count+=10;
        }else {
          count = temp_count + 1;
          temp_count = count;
        }
      }
    }
    //Records[1][14] = "DOG";
    cout<<"COMPUTER RECORD OF GALAXY FOR QUADRANT "<<player.returnQuadx()<<","<<player.returnQuady()<<endl;
    for(int i =0; i < 10;i++) {
      for(int j =0; j < 17;j++) {
        cout<<Records[i][j];
      }
      cout<<"\n";
    }
    commands();
    break;
    //Status Report
    case 1:
    cout<<"*********STATUS REPORT*********"<<endl;
    cout<<"NUMBER OF KILGONS LEFT: "<<kilgons.size()<<endl;
    cout<<"STARDATES LEFT:"<<player.getDuration() - (player.getStarDate() - player.getIStarDate() ) <<endl;
    cout<<"NUMBER OF STARBASES: "<<starbases.size()<<endl;
    cout<<"*******************************"<<endl;
    commands();
    break;

    //Calculator + Trajectory detector.
    case 2:
    list<kilgon>::iterator ptr_1;
    int x_diff,y_diff;
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
  

  switch(inputCheck("TO USE CALCULATOR PRESS 1 or 0 to exit: ",0,1) ) {
    case 0:
    commands();
    break;

    case 1:
    //Calculator
    int x1,y1,x2,y2,diff_x,diff_y;
    float dist;
    x2 = inputCheck("INPUT THE X COORDINATE OF ENTERPRISE: ",1,8); 
    y2 = inputCheck("INPUT THE Y COORDINATE OF ENTERPRISE: ",1,8);
    x1 = inputCheck("INPUT THE X COORDINATE OF KILGON: ",1,8);
    y1 = inputCheck("INPUT THE Y COORDINATE OF KILGON: ",1,8);
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
  if(player.getPhotonCount() == 0) {
    cout<<"NO MORE PHOTONS LEFT!!"<<endl;
    commands();
  }
  traj = inputCheck("COMPUTER INITIALISED. ENTER TRAJECTORY[1-8]: ",1,8);

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
        }

      }else {
        cout << "MISSED KILGON!!"<<endl;
        player.setPhotonCount(player.getPhotonCount() - 1);        
      }
      break;                                                                   
    }
    if(kilgons.size() == 0) {
      cout<<"ALL THE KILGONS HAVE BEEN DESTROYED!! GAME OVER "<<".THE STARDATE NOW IS "<<player.getStarDate()<<".AND YOU WON IN "<<player.getStarDate()-player.getIStarDate()<<" STARDATES."<<endl;
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
  }


}

void damageControl() {
  cout<<"\n\nDAMAGE CONTROL\t\t\t\tSTATE OF REPAIR"<<endl;
  cout<<"WARP ENGINES\t\t\t\t"<<player.getWarp()<<endl;
  cout<<"S.R SENSORS\t\t\t\t"<<player.getS()<<endl;
  cout<<"L.R SENSORS\t\t\t\t"<<player.getL()<<endl;
  cout<<"PHASER CNTRL\t\t\t\t"<<player.getPhaser()<<endl;
  cout<<"PHOTON TUBES\t\t\t\t"<<player.getPhoton()<<endl;
  cout<<"DAMAGE CNTRL\t\t\t\t"<<player.getDamage()<<endl;
  cout<<"SHIELD CNTRL\t\t\t\t"<<player.getShield()<<endl;
  cout<<"COMPUTER\t\t\t\t"<<player.getComputer()<<endl;
}