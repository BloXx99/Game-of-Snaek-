#include <iostream>
#include <conio.h> //To get getch() function
#include <algorithm>
#include <windows.h> //for "sleep" and console clearing functionalities.
#include <time.h>

#include "mapdrawer.hpp" //draw_map function import. 

using namespace std;

int main(){
    int field_width, field_height, game_speed;

    cout<<"--------------------------- KONRAD BLOCK PRESENTS -----------------------------"<<endl;
    Sleep(2000);
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"------------------------ G A M E     O F     S N A E K ------------------------"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl<<endl<<endl<<endl;

    cout<<"Choose your playing field size: WIDTH and HEIGHT (both accepted from 5 to 35)"<<endl;
    cout<<"WIDTH: ";
    cin>>field_width;

    while(field_width<5 || field_width>35){
        cout<<"Illegal width parameter. Please choose width between 5 and 35"<<endl;
        cin>>field_width;
    }
    cout<<"HEIGHT: ";
    cin>>field_height;
    while(field_height<5 || field_height>35){
        cout<<"Illegal height parameter. Please choose height between 5 and 35"<<endl;
        cin>>field_height;
    }
    cout<<endl<<"You chose "<<field_width<<" by "<<field_height<<" playing field"<<endl;
    Sleep(3000);
    system("cls");
    cout<<"Now, please choose your game speed (from 1 to 10)"<<endl;
    cin>>game_speed;
    while(game_speed<1 || game_speed>10){
        cout<<"Illegal game speed parameter. Please enter value between 1 and 10"<<endl;
        cin>>game_speed;
    }
    cout<<"You chose gamespeed of "<<game_speed<<endl;
    Sleep(2000);
    system("cls");
    cout<<"------------------------------ CONTROLS ------------------------"<<endl;
    cout<<"Use arrow keys to move your snake around."<<endl;
    Sleep(4000);
    system("cls");
    draw_map(game_speed,field_width,field_height);  // FUNCTION CONTAINING ACTUAL GAME LOOP AND DRAWING FUNCTIONS.

    

    return 0; 
}