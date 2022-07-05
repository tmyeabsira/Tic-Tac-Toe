/*
A simple tic tac toe game 

functionalities include 
    displaying the game board
    getting input from the user
    checking if the user’s input is valid or not 
    place user’s input on the board
    check if the game is over or not
    display the winner's user name with a congratulation message

Group Members:
    Yeabsira Tesfaye
    Naol Girma
    Muaz Mohammed 
    Tadiyos Tesfaye 
    Mikias Gebreslassie 
*/

#include <iostream>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variables
string p1,p2;
int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Function to show the current status of the gaming board


void display_board(){

    //Render Game Board LAYOUT

    cout<<p1<<" [X]\t "<<p2<<" [O]"<<endl;
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"     |     |     \n";
}

//Function to get the player input and update the board

void player_turn(){
    go:
    if(turn == 'X'){
        cout<<p1<<"'s turn : ";
    }
    else if(turn == 'O'){
        cout<<p2<<"'s turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            //check whether the input is valid
            while(cin.fail() || (choice < 1 || choice >9)){ 
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<"Invalid Move\n";
                goto go;
            }
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        //if input position already filled
        cout<<"Box already filled! Please choose another!!\n\n";
    }
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{
    cout<<"T I C K -- T A C -- T O E -- G A M E";
    cout<<"\nFOR 2 PLAYERS\n";
    cout<<"Enter the first player's name: "<<endl;
    cin>>p1;
    cout<<"Enter the seccond player's name: "<<endl;
    cin>>p2;
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    display_board();
    //to check who won
    if(turn == 'X' && draw == false){
        cout<<"\nCongratulations! "<<p2<<" has won the game"<<endl;
    }
    else if(turn == 'O' && draw == false){
        cout<<"\nCongratulations! "<<p1<<" has won the game"<<endl;
    }
    else
        cout<<"\nGAME DRAW!!!\n";
} 
