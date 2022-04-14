#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

//Funktionen
void startGame();
void createBoard();
void printBoard();
int getPlayerInput();
int placeCoin();
void togglePlayer();
bool checkWin();
int settingsSpielModus();
int settingsSpielerAnfang();
char settingsColorPlayerOne();
char settingsColorPlayerTwo();

//Gewinnüberprüfungsfunktionen
int checkVertical();
int checkHorizontal();
int checkDia(); //Diagonale von Oben rechts nach unten links
bool check();

//Variablen
#define sizeX 7
#define sizeY 6

HANDLE hConsole;//Konsoleneinstellungen

int board[sizeX][sizeY];
int activPlayer = 1;
int playercolors[3] = {7, 68, 34};
int gvlAuswahlSpielModus = 0;
int gvlAuswahlAnfang = 0;
char gvlAuswahlFarbeSpieler2 = 0;
char gvlAuswahlFarbeSpieler1 = 0;

int main() {
    // Speileinstellung
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

void startGame(){
    // Beginn
    int count = 0;
    int maxcount = sizeX*sizeY;

    createBoard();
    printBoard();
    while(count < maxcount){
        count++;
        int x = getPlayerInput();
        int y = placeCoin(x);
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
}

void createBoard() {
    // Spielfeld wird befüllt
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            board[x][y] = 0;
        }
    }
}

void printBoard() {
    //clears Console
    system("cls");

    //Input Overview
    for (int x = 0; x < sizeX; x++) {
        printf("  %d ", x + 1);
    }
    printf("\n");


    //Oberer Rahmen
    SetConsoleTextAttribute(hConsole, 7);
    for (int z = 0; z < sizeX * 4 + 1; z++) {
        printf("-");
    }
    printf("\n");

    //Zahlenreihe + Unterer Rand
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            printf("|");
            //Colorchange
            SetConsoleTextAttribute(hConsole, playercolors[board[x][y]]);
            printf("   ");
            SetConsoleTextAttribute(hConsole, playercolors[0]);
        }
        printf("|\n");
        for (int z = 0; z < sizeX * 4 + 1; z++) {
            printf("-");
        }
        printf("\n");
    }
}

int getPlayerInput(){
    // In welche Spalte setzt der Spieler
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
    // Bis in welche Zeile fällt der Coin
    for(int y = sizeY-1; y >= 0; y--){
        if(board[x][y] == 0){
            board[x][y] = activPlayer;
            return y;
        }
    }
}

void togglePlayer(){
    // Wechseln zwischen Speiler 1 und Speiler 2
    activPlayer = activPlayer%2+1;
}
bool checkWin(){
    // Spielfeld wird durchgegangen und geschaut ob jemand gewonnen hat
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
    // Verticale gewinnerkennung
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
    // Horizontale gewinnerkennung
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
    // Diagonale gewinnerkennung
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
    // Überprüft ob die Spielfeldgröße eingehalten wird
    if (x < sizeX && x > -1){
        return true;
    }else{return false;} 
}
int rightInput(int oneOrTwo){
    // Richtiger Input wird überprüft
    if (oneOrTwo != 1 && oneOrTwo != 2){
        printf("Falsche eingabe\n");
        return 1;
    }else{return 0;}
}
int rightInputColor(char color){
    // Richtige Farbeauswahl wird überprüft
    if (color != 'r' && color != 'g' && color != 'b' && color != 'o'){
        printf("Falsche eingabe oder Farbe schon vergeben\n");
        return 1;
    }else{return 0;}
}
int settingsSpielModus(){
    // Spielmodus Einstellungen
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
    // Spielerfarbe 1
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
    // Spielerfarbe 2
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
    // Einstellung welcher spieler anfangen darf
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