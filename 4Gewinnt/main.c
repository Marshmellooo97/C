#include <stdio.h>
#include <windows.h>
#include <stdbool.h>


//Methoden
void startGame();
void createBoard();
int getPlayerInput();
int placeCoin();
void printBoard();
bool checkWin();
void togglePlayer();

//Gewinnüberprüfungsfunktionen
int checkVertical();
int checkHorizontal();
int checkOlUr(); //Diagonale von Oben rechts nach unten links
int checkUlOr(); //Diagonale von Unten links nach oben rechts

//Variablen
#define sizeX 7
#define sizeY 6

HANDLE hConsole;//Konsoleneinstellungen

int board[sizeX][sizeY];
int activPlayer = 1;
int playercolors[3] = {7, 68, 34};

int main(){
    printf("test\n");
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    startGame();
    getchar();
    return 0;
}

void startGame(){
    int count = 0;
    int maxcount = sizeX*sizeY;

    createBoard();
    printBoard();
    while(count < maxcount){
        count++;
        int x = getPlayerInput();
        int y = placeCoin(x);
        printBoard();
        bool won = checkWin(x,y);
        if(won){
            printf("Du hast gewonnen.");
            break;
        }
        togglePlayer();
    }
    if(count == maxcount){
        printf("Unentschieden.\n");
    }
}

void createBoard(){
    for(int x = 0; x < sizeX; x++){
        for(int y = 0; y < sizeY; y++){
            board[x][y] = 0;
        }
    }
}

void printBoard(){

    /*
    218: ┌  191: ┐
    192: └  217: ┘

    193: ┴
    194: ┬

    195: ├
    180: ┤
    179: │
    196: ─
    197: ┼
    */

    //clears Console
    system("cls");

    //Input Overview
    for(int x = 0; x < sizeX; x++){
        printf("  %d ", x+1);
    }
    printf("\n");


    //Oberer Rahmen
    SetConsoleTextAttribute(hConsole, playercolors[0]);
    printf("%c",218);
    for(int z = 1; z < sizeX*4; z++){
        if(z%4==0){printf("%c",194);}
        else{printf("%c",196);}
    }
    printf("%c\n",191);

    //Zahlenreihe + Unterer Rand
    for(int y = 0; y < sizeY; y++){
        for(int x = 0; x < sizeX; x++){
            printf("%c",179);
            //Colorchange
            SetConsoleTextAttribute(hConsole, playercolors[board[x][y]]);
            printf("   ");
            SetConsoleTextAttribute(hConsole, playercolors[0]);
        }
        printf("%c\n",179);

        //prints Horizonatal lines
        int sign = 197;
        int corner1 = 195;
        int corner2 = 180;
        if(y == sizeY-1){
            sign = 193;
            corner1 = 192;
            corner2 = 217;
        }

        printf("%c", corner1);
        for(int z = 1; z < sizeX*4; z++){
            if(z%4==0){printf("%c",sign);}
            else{printf("%c",196);}
        }
        printf("%c\n",corner2);
    }
}

int getPlayerInput(){
    char input = 'a';
    int posX = 0;
    while(true){
        printf("Wohin willst du setzen: ");
        scanf("%c", &input);
        posX = ("%d",input)-49; //verhindert Absturz bei char Input; 0 ≙ 48

        //clears Input Buffer
        while ((getchar()) != '\n');

        //Falsche Eingaben
        if(posX < 0 || posX >= sizeX){
            printf("Ungültige Eingabe.\n");
            continue;
        }
        if(board[posX][0] == 0){
            return posX;
        }
        printf("Ungültige Eingabe.\n");
    }

}

int placeCoin(int x){
    for(int y = sizeY-1; y >= 0; y--){
        if(board[x][y] == 0){
            board[x][y] = activPlayer;
            return y;
        }
    }
}

void togglePlayer(){
    activPlayer = activPlayer%2+1;
}

bool checkWin(int x, int y){
    int wins = 0;
    wins += checkVertical(x,y);
    wins += checkHorizontal(x,y);
    wins += checkOlUr(x,y);
    wins += checkUlOr(x,y);

    if(wins > 0){
        return true;
    }

    return false;
}

int checkVertical(int x, int y){
    int count = 0;
    for(int arry = y; arry < sizeY; arry++){
        if(board[x][arry] == activPlayer){
            count++;
            if(count == 4){
                return 1;
            }
        }
        else{count = 0;}
    }
    return 0;
}

int checkHorizontal(int x, int y){
    int count = 0;
    for(int arrx = 0; arrx < sizeX; arrx++){
        if(board[arrx][y] == activPlayer){
            count++;
            if(count == 4){
                return 1;
            }
        }
        else{count = 0;}
    }
    return 0;
}

int checkOlUr(int x, int y){
    int count = 0;

    //Maximale Verscheibung nach oben rechts
    int arrx = (x >= y)?x-y:0;
    int arry = (x >= y)?0:y-x;

    //Maxima Unten rechts
    int differenz = abs(x-y);
    int maxx = (x >= y)?sizeX:sizeX-differenz;
    //int maxy = (x >= y)?sizeY-differenz:sizeY;

    while(arrx < maxx){
        if(board[arrx][arry] == activPlayer){
            count++;
            if(count == 4){
                return 1;
            }
        }
        else{count = 0;}
        arrx++;
        arry++;
    }
    return 0;
}

int checkUlOr(int x, int y){
    int count = 0;

    int arrx = x;
    int arry = y;

    while(arrx > 0 && arry < sizeY){
        arrx--;
        arry++;
    }
    while(arrx < sizeX && arry > 0){
        if(board[arrx][arry] == activPlayer){
            count++;
            if(count == 4){
                return 1;
            }
        }
        else{count = 0;}
        arrx++;
        arry--;
    }
    return 0;
}
