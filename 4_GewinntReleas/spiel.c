#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>  //Zufallszahlen
#include <windows.h> //Konsoleneinstellungen

// Funktionen
void createBoard();
int getPlayerInput();
int placeCoin();
void printBoard();
bool checkWin();
void togglePlayer();

void setPlayerName();
int setPlayerColor();
void printColors(); // Dartsellung von Farben für setPlayerColor
void chooseGameMode();

void settingPvP();
void settingBot();
void settingHrd(); // PvP mit der selben Farbe

void startGameBot();
void startGamePvP();

int botMove();

void clearInput();
void easterEgg();
void stringToLower();

int randomGenerator();
int placeCoinWithoutAnimation();

// Gewinnüberprüfungsfunktionen
int checkVertical();
int checkHorizontal();
int checkOlUr(); // Diagonale von Oben rechts nach unten links
int checkUlOr(); // Diagonale von Unten links nach oben rechts

// Variablen
#define sizeX 7
#define sizeY 6
#define nameLenght 32

HANDLE hConsole; // Konsoleneinstellungen

int board[sizeX][sizeY];
int activPlayer = 1;
int playercolors[3] = {7, 68, 68};
char playerNames[2][nameLenght + 1]; //+1 Für Abbruchzeichen, dass am Ende des
                                     // Strings benötigt wird

int main() {
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  chooseGameMode();
  getchar();
  return 0;
}

void chooseGameMode() {
  char input;
  int value = 0;
  printf("Herzlich Wilkommen zu Vier Gewinnt.\n");
  printf("Waehle nun einen dieser Spielmodi aus.\n");
  printf("1: Player vs Player\n2: Player vs KI\n3: Hardcore\n");
  while (value > 3 || value < 1) {
    printf("Waehle nun einen der Spielmodi aus (1-3):");
    scanf("%c", &input);
    clearInput();
    value = ("%d", input) - 48;
  }

  // Erst settings dann Spielstart
  switch (value) {
  case 1:
    settingPvP();
    startGamePvP();
    break;
  case 2:
    settingBot();
    startGameBot();
    break;
  case 3:
    settingHrd();
    startGamePvP();
    break;
  }
}

void settingPvP() {
  setPlayerName(1);
  setPlayerName(2);
  playercolors[1] = setPlayerColor(1);
  playercolors[2] = setPlayerColor(2);
  easterEgg();
}

void settingBot() {
  setPlayerName(1);
  playercolors[1] = setPlayerColor(1);
  if (playercolors[1] == 68) {
    playercolors[2] = 17;
  }
  easterEgg();
  strcpy(playerNames[1], "Glados");
}

void settingHrd() {
  // predefined playercolors
  setPlayerName(1);
  setPlayerName(2);
  easterEgg();
}

void setPlayerName(int player) {
  printf("Name fuer Spieler%d bitte eingeben: ", player);
  char currentChar = ' ';
  bool overflow = true;
  for (int x = 0; x < nameLenght; x++) {
    scanf("%c", &currentChar);
    if (currentChar == '\n') {
      overflow = false;
      break;
    }
    playerNames[player - 1][x] = currentChar;
  }
  if (overflow) {
    clearInput();
  }
}

int setPlayerColor(int player) {
  printf("%s\nWaehle nun einer dieser Farben aus:\n", playerNames[player - 1]);
  printf("1: Blau  ");
  printColors(17);
  printf("2: Gruen ");
  printColors(34);
  printf("3: Cyan  ");
  printColors(51);
  printf("4: Rot   ");
  printColors(68);
  printf("5: Lila  ");
  printColors(80);
  printf("6: Gelb  ");
  printColors(96);
  printf("7: Weiss ");
  printColors(112);
  printf("8: Grau  ");
  printColors(128);

  char number;
  int value;
  while (true) {
    printf("Gebe nun die passende Zahl ein: ");
    scanf("%c", &number);
    clearInput();
    value = ("%d", number) - 48; // 1 entspricht 1 nach ascii umwandlung
    if (value >= 1 && value <= 8) {
      switch (value) {
      case 1:
        return 17;
      case 2:
        return 34;
      case 3:
        return 51;
      case 4:
        return 68;
      case 5:
        return 80;
      case 6:
        return 96;
      case 7:
        return 112;
      case 8:
        return 128;
      }
    }
  }
}

void printColors(int color) {
  SetConsoleTextAttribute(hConsole, color);
  printf("   \n");
  SetConsoleTextAttribute(hConsole, 7);
}

void startGamePvP() {
  while (true) {
    int count = 0;
    int maxcount = sizeX * sizeY;

    createBoard();
    printBoard();
    while (count < maxcount) {
      count++;
      int x = getPlayerInput();
      int y = placeCoin(x);
      printBoard();
      bool won = checkWin(x, y);
      if (won) {
        printf("%s hat gewonnen.\n", playerNames[activPlayer - 1]);
        break;
      }
      togglePlayer();
    }
    if (count == maxcount) {
      printf("Unentschieden.\n");
    }

    printf("Moechtest du/ihr nochmal spielen? (y/n):");
    char stop = 'y';
    scanf("%c", &stop);
    if (tolower(stop) == 'n') {
      break;
    }
    clearInput();
  }
}

void startGameBot() {
  while (true) {
    int count = 0;
    int maxcount = sizeX * sizeY;

    createBoard();
    printBoard();
    while (count < maxcount) {
      count++;

      int x = 0;
      if (activPlayer == 1) {
        x = getPlayerInput();
      } else {
        x = botMove();
      }

      int y = placeCoin(x);
      printBoard();
      bool won = checkWin(x, y);
      if (won) {
        printf("%s hat gewonnen.\n", playerNames[activPlayer - 1]);
        break;
      }
      togglePlayer();
    }
    if (count == maxcount) {
      printf("Unentschieden.\n");
    }

    printf("Moechtest du/ihr nochmal spielen? (y/n):");
    char stop = 'y';
    scanf("%c", &stop);
    if (tolower(stop) == 'n') {
      break;
    }
    clearInput();
  }
}

void clearInput() {
  while ((getchar()) != '\n')
    ;
}

void createBoard() {
  for (int x = 0; x < sizeX; x++) {
    for (int y = 0; y < sizeY; y++) {
      board[x][y] = 0;
    }
  }
}

void printBoard() {
  // clears Console
  system("cls");

  // Input Overview
  for (int x = 0; x < sizeX; x++) {
    printf("  %d ", x + 1);
  }
  printf("\n");

  // Oberer Rahmen
  SetConsoleTextAttribute(hConsole, playercolors[0]);
  printf("%c", 218);
  for (int z = 1; z < sizeX * 4; z++) {
    if (z % 4 == 0) {
      printf("%c", 194);
    } else {
      printf("%c", 196);
    }
  }
  printf("%c\n", 191);

  // Zahlenreihe + Unterer Rand
  for (int y = 0; y < sizeY; y++) {
    for (int x = 0; x < sizeX; x++) {
      printf("%c", 179);
      // Colorchange
      SetConsoleTextAttribute(hConsole, playercolors[board[x][y]]);
      printf("   ");
      SetConsoleTextAttribute(hConsole, playercolors[0]);
    }
    printf("%c\n", 179);

    // prints Horizonatal lines
    int sign = 197;
    int corner1 = 195;
    int corner2 = 180;
    if (y == sizeY - 1) {
      sign = 193;
      corner1 = 192;
      corner2 = 217;
    }

    printf("%c", corner1);
    for (int z = 1; z < sizeX * 4; z++) {
      if (z % 4 == 0) {
        printf("%c", sign);
      } else {
        printf("%c", 196);
      }
    }
    printf("%c\n", corner2);
  }
}

int getPlayerInput() {
  char input = 'a';
  int posX = 0;
  while (true) {
    printf("%s ist dran.\n", playerNames[activPlayer - 1]);
    printf("Wohin moechtest du setzen: ");
    scanf("%c", &input);
    posX = ("%d", input) - 49; // verhindert Absturz bei char Input; 0 ≙ 48

    // clears Input Buffer
    clearInput();

    // Falsche Eingaben
    if (posX < 0 || posX >= sizeX) {
      printf("Ungueltige Eingabe.\n");
      continue;
    }
    if (board[posX][0] == 0) {
      return posX;
    }
    printf("Ungueltige Eingabe.\n");
  }
}

int placeCoin(int x) {
  for (int y = 0; y < sizeY; y++) {
    board[x][y] = activPlayer;
    printBoard();
    // sleep(1);
    if (board[x][y + 1] != 0) {
      return y;
    }
    board[x][y] = 0;
  }
  board[x][sizeY - 1] = activPlayer;
  return sizeY - 1;
}

void togglePlayer() { activPlayer = activPlayer % 2 + 1; }

bool checkWin(int x, int y) {
  int wins = 0;
  wins += checkVertical(x, y);
  wins += checkHorizontal(x, y);
  wins += checkOlUr(x, y);
  wins += checkUlOr(x, y);

  if (wins > 0) {
    return true;
  }

  return false;
}

int checkVertical(int x, int y) {
  int count = 0;
  for (int arry = y; arry < sizeY; arry++) {
    if (board[x][arry] == activPlayer) {
      count++;
      if (count == 4) {
        return 1;
      }
    } else {
      count = 0;
    }
  }
  return 0;
}

int checkHorizontal(int x, int y) {
  int count = 0;
  for (int arrx = 0; arrx < sizeX; arrx++) {
    if (board[arrx][y] == activPlayer) {
      count++;
      if (count == 4) {
        return 1;
      }
    } else {
      count = 0;
    }
  }
  return 0;
}

int checkOlUr(int x, int y) {
  int count = 0;

  // Maximale Verscheibung nach oben rechts
  int arrx = (x >= y) ? x - y : 0;
  int arry = (x >= y) ? 0 : y - x;

  // Maxima Unten rechts
  int differenz = abs(x - y);
  int maxx = (x >= y) ? sizeX : sizeX - differenz;
  // int maxy = (x >= y)?sizeY-differenz:sizeY;

  while (arrx < maxx) {
    if (board[arrx][arry] == activPlayer) {
      count++;
      if (count == 4) {
        return 1;
      }
    } else {
      count = 0;
    }
    arrx++;
    arry++;
  }
  return 0;
}

int checkUlOr(int x, int y) {
  int count = 0;

  int arrx = x;
  int arry = y;

  while (arrx > 0 && arry < sizeY) {
    arrx--;
    arry++;
  }
  while (arrx < sizeX && arry > 0) {
    if (board[arrx][arry] == activPlayer) {
      count++;
      if (count == 4) {
        return 1;
      }
    } else {
      count = 0;
    }
    arrx++;
    arry--;
  }
  return 0;
}

void easterEgg() {
  char baseName[32];

  for (int i = 0; i < 2; i++) {
    strcpy(baseName, playerNames[i]);
    stringToLower(baseName);
    printf("Worked %s\n", baseName);
    if (!strcmp(baseName, "batman")) {
      strcpy(playerNames[i], "Bruce Wayne");
    }
    if (!strcmp(baseName, "spider man") || !strcmp(baseName, "spider-man")) {
      strcpy(playerNames[i], "Peter Parker");
    }
  }
}

void stringToLower(char arr[]) {
  for (int i = 0; i < strlen(arr); i++) {
    if (arr[i] == '\0') {
      break;
    }
    arr[i] = tolower(arr[i]);
  }
}

int botMove() {
  int pcInput = 8;
  int xPcRandom = 0;
  int yPcRandom = 0;
  int activPlayerlast = activPlayer;
  for (int test = 1; test < 3; test++) {
    activPlayer = test;
    for (xPcRandom = 0; xPcRandom < sizeX; xPcRandom++) {
      yPcRandom = placeCoinWithoutAnimation(xPcRandom);
      if (yPcRandom == 8) {
        break;
      }
      if (checkWin(xPcRandom, yPcRandom)) {
        board[xPcRandom][yPcRandom] = 0;
        pcInput = xPcRandom;
        break;
      }
      board[xPcRandom][yPcRandom] = 0;
    }
  }
  if (pcInput == 8) {
    pcInput = randomGenerator();
  }
  activPlayer = activPlayerlast;
  return pcInput;
}
int randomGenerator() {
  int pcInput = 0;
  int run = 1;
  while (run) {
    pcInput = rand() % 7;
    if (board[pcInput][0] == 0) {
      run = 0;
    }
  }
  return pcInput;
}

int placeCoinWithoutAnimation(int x) {
  for (int y = 0; y < sizeY; y++) {
    board[x][y] = activPlayer;
    if (board[x][y + 1] != 0) {
      return y;
    }
    board[x][y] = 0;
  }
  board[x][sizeY - 1] = activPlayer;
  return sizeY - 1;
}