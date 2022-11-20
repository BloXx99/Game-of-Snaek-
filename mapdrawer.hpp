#include <iostream>
#include <conio.h> //To get getch() function
#include <algorithm>
#include <windows.h> //for "sleep" and console clearing functionalities.
#include <time.h>

using namespace std;

void draw_map(int gamespeed,int width,int height){
    char field[height][width];
    char positionY_history[10000];
    char positionX_history[10000];   // Extremely unelegant, but working solution to track previous positon. To be changed in the future. 
    string direction;
    int snakeX, snakeY, foodX, foodY, snake_length, moves, key;
    bool alive = true;
    moves = 0;
    snake_length = 3;

    //We're going to mark particular cell status with characters.
    //e - cell is empty  f - cell is occupied by food  s - cell is occupied by snake.
    //Then, map drawer will draw appropriate symbol on each cell. (Whitespace for e, 'X' for food, 'O' for snake)

    for (int i = 0; i < height; i++){

        for (int j = 0; j < width; j++)
        {
            field[i][j] = 'e';          //INITIALIZE ARRAY WITH 'e' SYMBOLS          
        }
        
    }


    srand(time(NULL));
    snakeX = rand()%width;
    snakeY = rand()%height;
    field[snakeY][snakeX] = 's';
    

    do{
        foodX = rand()%width;
        foodY = rand()%height;
    }
    while(field[foodY][foodX]!='e');

    field[foodY][foodX] = 'f';

    direction = "left";
    while(alive){  // ---------------------- GAME LOOP START ----------------------
        
        
        field[foodY][foodX] = 'f';
        positionY_history[moves] = snakeY;
        positionX_history[moves] = snakeX; 
        moves++;
    
        system("cls");
        for(int i = 0; i<width+1; i++){
        cout<<"--";               // TOP FRAME
    }
    cout<<endl;

    for (int i = 0; i<height; i++){
        cout<<"|";

        for(int j =0; j<width;j++){
            if (field[i][j] == 'e'){cout<<"  ";}
            if (field[i][j] == 's'){cout<<" O";}            //DRAWING ACTUAL MAP CONTENT
            if (field[i][j] == 'f'){cout<<" X";}
        }
        cout<<"|"<<endl;
    }

    for(int i = 0; i<width+1; i++){
        cout<<"--";               // BOTTOM FRAME
    }
    

    Sleep(1000/gamespeed);
    if(kbhit()){
        key = getch();
        if (key == 224 || key == 0){key+=getch();}
        if(key == 224 + 72) {direction = "up";}
        if(key == 224 + 80) {direction = "down";}
        if(key == 224 + 75) {direction = "left";}
        if(key == 224 + 77) {direction = "right";}
    }

    if(direction == "up"){snakeY--;}
    if(direction =="down"){snakeY++;}           //CONTROLLING SNAKE DIRECTION
    if(direction == "left"){snakeX--;}
    if(direction == "right"){snakeX++;}
    
    if(field[snakeY][snakeX] == 'f'){  // FOOD COLLISION CHECK
        snake_length++;

        do{
        foodX = (rand()% width-5)+3;
        foodY = (rand()% height-5)+3;  // AVOIDING PROBLEMATIC FOOD GENERATION AT FIELD BORDER
    }
    while(field[foodY][foodX]!='e');
    }
    else {field[positionY_history[moves-snake_length]][positionX_history[moves-snake_length]] = 'e';}

    if(field[snakeY][snakeX] == 's'){alive=false;}

    if (snakeX == width){snakeX = 0;}
    if (snakeX == 0){snakeX = width;}
    if (snakeY == height){snakeY = 1;}          //FRAME COLLISION CONTROL
    if (snakeY == 0){snakeY = height;}

    field[snakeY][snakeX] = 's';
    
    


    

    
    
    
    

    
    



    }// ---------------------- GAME LOOP END ----------------------
    system("cls");
    
    cout<<"------------------------------ GAME OVER ------------------------------"<<endl;
    cout<<"You've reached length of: "<<snake_length<<endl;
    cout<<"Thanks for playing!"<<endl;
    Sleep(10000);

}