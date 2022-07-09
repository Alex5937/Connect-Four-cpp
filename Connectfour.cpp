#include <iostream>
#include <windows.h>

using namespace std;

class Playerinfo{

public:

    string name;
    char character[20];
    //char name[15];
    //char character[1];
    void set_default_character(char default_character[20]);
    void set_default_name(string default_name);
};

void Playerinfo::set_default_character(char default_character[20]){

    character[0] = default_character[0];
}

void Playerinfo::set_default_name(string default_name){

    name = default_name;
}

    char a[20]={'X'};
    char b[20]={'O'};

    Playerinfo Player_1; //Player1 info
    Playerinfo Player_2; //Player2 info
    int Choose; //input Choose
    char board[7][8];  //board size

    int turn = 1; //Player's turn
    int DropChoice;
    int check_condition;
    int win = 0, full = 0; //Conditions
    int trueWidth = 6, trueLength = 7; // Connect Four size

void Win(char player);
void Full(char player);
void Check_Condition();
void Update_Board(char player);
void Display_Board();
void Default_Board();
void Choose1();
void Choose2(); 
void Choose3(); 
int Play_Again();
void Main_menu();

int main()
{

    Player_1.set_default_character(a);    //default Charater of Player1
    Player_2.set_default_character(b);    //default Charater of Player2

    Player_1.set_default_name("Player1");    //default Name of Player1
    Player_2.set_default_name("Player2");    //default Name of Player2

    Main_menu();

    return 0;
}

/*void GoBack(string Back){  //Go back to before main menu

    if(Back == "q"){
        Main_menu();
    }

   
}*/

void Choose1(){ //Change Playre Names

    cout << "\n";
    cout << "Please Enter Player1's name : " ;
    cin >> Player_1.name;
    //GoBack(Player_1.name);
    cout << "Please Enter Player2's name : " ;
    cin >> Player_2.name;
    //GoBack(Player_2.name);

    if (Player_1.name == Player_2.name){

            cout << "Wrong Input! The Names cannot be same! Please try again!" << endl;
            Choose1();
    }

    Main_menu();
}

void Choose2(){ //Change Playre Characters

    char a[20], b[20]; // temp character
    cout << "\n";
    cout << "Please Enter Player1's Charater : " ;
    cin >> a ;
    //GoBack(Player_1.character);
    cout << "Please Enter Player2's Charater : " ;
    cin >> b ;


    //GoBack(Player_2.character);
    if (a[0] == b[0]){

        cout << "Wrong Input! The Charaters cannot be same! Please try again!" << endl;
        Choose2();
   }

    if ((strlen(a) >1 ) || (strlen(b) >1 )){

        cout << "Wrong Input! There should one charater of each Player! Please try again!" << endl;
        Choose2();
   }


    Player_1.set_default_character(a);
    Player_2.set_default_character(b); 

    Main_menu();
    

}

void Choose3(){ //Game start

    if (turn == 1){

        Display_Board();

    }

    if (win != 1 && full != 7){
    
        do
        {   
            full = 0; //reset

            if(turn % 2 == 1){
                cout << Player_1.name << "'s Turn. ";
            }
            else if (turn % 2 == 0){
                cout << Player_2.name << "'s Turn. ";
            }
                cout << "Please enter a number between 1 and 7: ";
                cin  >> DropChoice;

            while ( board[1][DropChoice] == Player_1.character[0] || board[1][DropChoice] == Player_2.character[0] )
            {
                cout << "That row is full, please enter a new row: ";
                cin  >> DropChoice;
            }

        }while ( DropChoice < 1 || DropChoice > 7 ); //Keep input until input is correct

        //Update board
        if(turn % 2 == 1){
            Update_Board(Player_1.character[0]);
        }

        else if (turn % 2 == 0){
            Update_Board(Player_2.character[0]);
        }
        
        Display_Board();

        //Check which players win
        Check_Condition();
        turn++;
        
        //cout << full;
        Choose3();
        
        
    }

}

void Display_Board(){
    
    int x, y;
	
	for(x = 1; x <= trueWidth; x++) //print out layout; /*******/
	{
		cout << "|";
		for(y = 1; y <= trueLength; y++)
		{
			if(board[x][y] != Player_1.character[0] && board[x][y] != Player_2.character[0])
				board[x][y] = ' ';

			cout << " " << board[x][y];
			
		}

		cout << " " << "|" << endl;
	}

        cout << "  1 2 3 4 5 6 7  " << endl;    //mark the column

}

void Default_Board(){
    
    int x, y;
	
	for(x = 1; x <= trueWidth; x++){ //print out layout; |*******|

		for(y = 1; y <= trueLength; y++){
		
				board[x][y] = ' ';

		}
	}
}

void Update_Board(char player){
    
    int out = 0;
    int width = 6;

	do 
	{
		if ( board[width][DropChoice] != Player_1.character[0] && board[width][DropChoice] != Player_2.character[0] )   //Check any cherker placed from row 1 t0 6
		{
			board[width][DropChoice] = player;  //Place checker
			out = 1; 
		}
		else
		--width;    // Check next row
	}while (  out != 1 );   //Keep check until placed checker
}

void Win(char Player){

    char Checker;
    Checker = Player;

	for( int i = 6; i >= 1; --i )
	{
		
		for( int j = 7; j >= 1; --j )
		{
			//diagoanl
			if( board[i][j] == Checker     &&  
				board[i-1][j-1] == Checker &&
				board[i-2][j-2] == Checker &&
				board[i-3][j-3] == Checker )
			{
				win = 1;
			}

            if( board[i][j] == Checker     &&
				board[i-1][j+1] == Checker &&
				board[i-2][j+2] == Checker &&
				board[i-3][j+3] == Checker )
			{
				win = 1;
            }

            //horizontal
			if( board[i][j] == Checker   &&
				board[i][j-1] == Checker &&
				board[i][j-2] == Checker &&
				board[i][j-3] == Checker )
			{
				win = 1;
			}
					
			if( board[i][j] == Checker   &&
				board[i-1][j] == Checker &&
				board[i-2][j] == Checker &&
				board[i-3][j] == Checker )
			{	
				win = 1;
			}
					
			//vertical			
			if ( board[i][j] == Checker   &&
				 board[i][j+1] == Checker &&
				 board[i][j+2] == Checker &&
				 board[i][j+3] == Checker )
			{
				win = 1;
			}
		}
		
	}
}

void Full(){

    for ( int x = 1; x <= 7; ++x )
	{
		if ( board[1][x] != ' ' )
			++full;
	}

}

void Check_Condition(){

    Full();
    if(full == 7){
        cout <<"Game Over!!! Draw!!!" << endl;
        Play_Again();   //Ask Continues
    }

    if(turn % 2 == 1){
        Win(Player_1.character[0]);
        if ( win == 1){
            cout << Player_1.name << " wins." << endl;
            Play_Again();   //Ask Continues
       } 

                
    }

    else if (turn % 2 == 0){
        Win(Player_2.character[0]);
       if ( win == 1){
            cout << Player_1.name << " wins." << endl;
            Play_Again();   //Ask Continues
       }
        
    }
}

int Play_Again(){
    char Continues;
   
    do{
        cout << "Continues??? (Y/N) : ";
        cin >> Continues;

        if (Continues == 'Y'){

            Main_menu();
        }

        else if (Continues == 'N'){

        cout << "Thank you for playing!!!" << endl;
        break;
        }
 
    }while (Continues != 'Y' || Continues != 'N');

    return 0;
}

void Main_menu(){ // Main menu

    win = 0, full = 0, turn = 1, board[7][8] ={};  //Reset
    Default_Board();   //Reset

    cout << "\n";
    cout << "Welcome to my Connect Four!!! " << endl;
    cout << "1. Change Player Names, Please Enter 1." << endl;
    cout << "   Now are " << Player_1.name << " and " << Player_2.name << "." << endl;
    cout << "2. Change Player Characters, Please Enter 2." << endl;
    cout << "   Now are " << Player_1.name << " : " << Player_1.character <<" and " << Player_2.name << " : " << Player_2.character << "." << endl;
    cout << "3. Start Game!" << endl;
    cout << "Enter your Choose : ";
    cin >> Choose;

    switch (Choose){

        case 1: Choose1(); break;
        case 2: Choose2(); break;
        case 3: Choose3(); break;
        default: {
            cout << "\n";
            cout << "Wrong Input! Please try again!" << endl;
            cout << "\n";
            Sleep(500); 
            Main_menu();
            break;
            }
    }
}   

