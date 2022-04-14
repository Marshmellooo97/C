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
int settingsSpielModus();
int settingsSpielerAnfang();
char settingsColorPlayerOne();
char settingsColorPlayerTwo();
int randomGenerator();
int pcPlayer();

//Gewinnüberprüfungsfunktionen
int checkVertical();
int checkHorizontal();
int checkDia(); //Diagonale von Oben rechts nach unten links
bool check();


//Variablen
#define sizeX 7
#define sizeY 6
#if 0
enum {
    leer = 0,
    spieler1 = 1,
    spieler2 = 2,
};
#endif
HANDLE hConsole;//Konsoleneinstellungen

int board[sizeX][sizeY];
int activPlayer = 1;
int playercolors[3] = {7, 68, 34};
int gvlAuswahlSpielModus = 0;
int gvlAuswahlAnfang = 0;
char gvlAuswahlFarbeSpieler2 = 0;
char gvlAuswahlFarbeSpieler1 = 0;

int main(){
    int setting = 1;
    if (setting){
        gvlAuswahlSpielModus = settingsSpielModus();
        gvlAuswahlAnfang = settingsSpielerAnfang();
        gvlAuswahlFarbeSpieler1 = settingsColorPlayerOne();
        gvlAuswahlFarbeSpieler2 = settingsColorPlayerTwo();
        activPlayer = gvlAuswahlAnfang;
    }
    setting = 0;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    startGame();
    getchar();
    return 0;
}
int pcPlayer(){
    int pcInput = 8;
    int xPcRandom = 0;
    int yPcRandom = 0;
    int activPlayerlast = activPlayer;
    for (int test = 1; test < 3; test++){
        activPlayer = test;
        for (xPcRandom = 0; xPcRandom < sizeX; xPcRandom++){
            yPcRandom = placeCoin(xPcRandom);
            if (yPcRandom == 8){
                break;
            }
            if (checkWin()){
                board[xPcRandom][yPcRandom] = 0;
                pcInput = xPcRandom;
                break;
            }
            board[xPcRandom][yPcRandom] = 0;
        }
    }
    if (pcInput == 8){
        pcInput = randomGenerator();
    }
    activPlayer = activPlayerlast;
    return pcInput; 
}
int randomGenerator(){
    int pcInput = 0;
    int run = 1;
    while(run){
        pcInput = rand() % 7;
        if (board[pcInput][0] == 0){
            run = 0;
        }
    }
    return pcInput;
}
int rightInput(int oneOrTwo){
    if (oneOrTwo != 1 && oneOrTwo != 2){
        printf("Falsche eingabe\n");
        return 1;
    }else{return 0;}
}
int rightInputColor(char color){
    if (color != 'r' && color != 'g' && color != 'b' && color != 'o'){
        printf("Falsche eingabe oder Farbe schon vergeben\n");
        return 1;
    }else{return 0;}
}
int settingsSpielModus(){
    int rightInputWhile = 1;
    char auswahlSpielModusInput = 'a';
    int auswahlSpielModus = 0;
    while(rightInputWhile){
        printf("Spielmodus: \n1 = Spieler gegen Spieler\n2 = Spieler gegen PC\n");
        scanf("%c", &auswahlSpielModusInput);
        auswahlSpielModus = ("%d",auswahlSpielModusInput) - 48;
        while ((getchar()) != '\n');
        rightInputWhile = rightInput(auswahlSpielModus);
    }
    return auswahlSpielModus;
}
char settingsColorPlayerOne(){
    int rightInputWhile = 1;
    char auswahlFarbeSpieler1Input = 'a';
    int auswahlFarbeSpieler1 = 0;
    while(rightInputWhile){
        printf("Spielerfarbe Player 1: \nr = rot\ng = grün\nb = blau\no = orange\n");
        scanf("%c", &auswahlFarbeSpieler1Input);
        while ((getchar()) != '\n');
        rightInputWhile = rightInputColor(auswahlFarbeSpieler1Input);
    }
    return auswahlFarbeSpieler1Input;
}
char settingsColorPlayerTwo(){
    int rightInputWhile = 1;
    char auswahlFarbeSpieler2Input = 'a';
    int auswahlFarbeSpieler2 = 0;
    while(rightInputWhile){
        printf("Spielerfarbe Player 2: \nr = rot\ng = grün\nb = blau\no = orange\n");
        scanf("%c", &auswahlFarbeSpieler2Input);
        while ((getchar()) != '\n');
        rightInputWhile = rightInputColor(auswahlFarbeSpieler2Input);
        if (!rightInputWhile){
            rightInputWhile = gvlAuswahlFarbeSpieler1 == auswahlFarbeSpieler2Input ;
            if (rightInputWhile) printf("Farbe bereits vergeben!\n");
        }
    }
    return auswahlFarbeSpieler2Input;
}
int settingsSpielerAnfang() {
    int rightInputWhile = 1;
    char auswahlAnfangInput = 'a';
    int auswahlAnfang = 0;
    while(rightInputWhile){
        printf("Welcher Spieler soll anfangen: \n2 = Spieler 1\n1 = Spieler2 oder PC\n");
        scanf("%c", &auswahlAnfangInput);
        auswahlAnfang = ("%d",auswahlAnfangInput) - 48;
        while ((getchar()) != '\n');
        rightInputWhile = rightInput(auswahlAnfang);
    }
    return auswahlAnfang;
}
void startGame(){
    int count = 0;
    int maxcount = sizeX*sizeY;
    createBoard();
    printBoard();
    while(count < maxcount){
        int x = 0;
        int y = 0;
        count++;
        if (gvlAuswahlSpielModus == 2 && activPlayer == 1){
            x = pcPlayer();
            y = placeCoin(x);
        }else{
            x = getPlayerInput();
            y = placeCoin(x);
        }
        printBoard();
        bool won = checkWin();
        if(won){
            if (activPlayer == 1){
                printf("Spieler 2 oder PC hat gewonnen.");
                break;
            }
            if (activPlayer == 2){
                printf("Spieler 1 hat gewonnen.");
                break;
            }
        }
        togglePlayer();
    }
    if(count == maxcount){
        printf("Unentschieden.\n");
    }
    //printBoard(); 
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
    return 8;
}
void togglePlayer(){
    activPlayer = activPlayer%2+1;
}
bool checkWin(){
    int activPlayerlast = activPlayer;
    for (int test = 1; test < 3; test++){
        activPlayer = test;
        int win = 0;
        win += checkVertical();
        win += checkHorizontal();
        win += checkDia();
        if(win > 0){
            activPlayer = activPlayerlast;
            return true;
        }
    }
    activPlayer = activPlayerlast;
    return false;
}
int checkVertical(){
    int win = 0;
    for (int x = 0; x < sizeX; x++) {
        win = 0;
        for (int y = 0; y < sizeY; y++) {
            if (board[x][y] == activPlayer){win++;}
            if (board[x][y] != activPlayer){win = 0;}
            if (win == 4){return 1;}
        }
    }
    return 0;
}
int checkHorizontal(){
    int win = 0;
    for (int y = 0; y < sizeY; y++) {
        win = 0;
        for (int x = 0; x < sizeX; x++) {
            if (board[x][y] == activPlayer){win++;}
            if (board[x][y] != activPlayer){win = 0;}
            if (win == 4){return 1;}
        }
    }
    return 0;
}
int checkDia(){
    int win1 = 0;
    int win2 = 0;
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            win1 = win2 = 0;
            if (board[x][y] == activPlayer){
                for (int xi = 0; xi < 4; xi++){
                    if (board[x + xi][y + xi] == activPlayer && check(x + xi)){
                        win1++;}
                    if (board[x + xi][y + xi] != activPlayer && check(x + xi)){
                        win1 = 0;}
                    if (board[x - xi][y + xi] == activPlayer && check(x - xi)){
                        win2++;}
                    if (board[x - xi][y + xi] != activPlayer && check(x - xi)){
                        win2 = 0;}
                    if (win1 == 4 || win2 == 4){return 1;}
                }
            }   
        }
    }
    return 0;
}
bool check(int x){
    if (x < sizeX && x > -1){
        return true;
    }else{return false;} 
}