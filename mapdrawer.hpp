#include <iostream>
#include <conio.h> //To get getch() function
#include <algorithm>
#include <windows.h> //for "sleep" and console clearing functionalities.

using namespace std;

void draw_map(int gamespeed,int width,int height){
    char field[height][width];
    int snakeX, snakeY, foodX,foodY;

    //We're going to mark particular cell status with characters.
    //e - cell is empty  f - cell is occupied by food  s - cell is occupied by snake.
    //Then, map drawer will draw appropriate symbol on each cell. (Whitespace for e, 'X' for food, 'O' for snake)

    for (int i = 0; i < height; i++){

        for (int j = 0; j < width; j++)
        {
            field[i][j] = 'e';             
        }
        
    }

    for(int i = 0; i<width+1; i++){
        cout<<"--";               // TOP FRAME
    }
    cout<<endl;

    for (int i = 0; i<height; i++){
        cout<<"|";

        for(int j =0; j<width;j++){
            cout<<"  ";
        }
        cout<<"|"<<endl;
    }

    for(int i = 0; i<width+1; i++){
        cout<<"--";               // BOTTOM FRAME
    }


}