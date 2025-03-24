#include <Wire.h>
#include <Arduino.h>
#include "ht1632.h"
#include <avr/pgmspace.h>
#include <TimerOne.h>

#define GRID_SIZE 8
int grid[GRID_SIZE][GRID_SIZE];
int k = 0;
int x = 0;
int y = 0;
int utils = 0;
int lastX = 0;
int lastY = 0;
int playerColor;
int player = 0;
bool validation = false; // Corrected syntax

#define BUTTON 2
#define POTEN A0

int* getTableau();

#define MAXCOUP 20
typedef struct {
  byte x;
  byte y;
  // Add other attributes if necessary
} T_coupPossible;

typedef struct {
  T_coupPossible coups[MAXCOUP];
  byte nbCoups;
} tabCoupsPossibles;

typedef struct {
  T_coupPossible coups[MAXCOUP];
  byte x;
  byte y;
  byte nbrPrises;
} T_coupsPossibles;



void fnPeriodique();

void add(int x, int y, bool player) {
  playerColor = player ? RED : GREEN;
  ht1632_plot((2 * x) + 8, 2 * y, playerColor);
  ht1632_plot((2 * x) + 9, 2 * y, playerColor);
  ht1632_plot((2 * x) + 8, (2 * y) + 1, playerColor);
  ht1632_plot((2 * x) + 9, (2 * y) + 1, playerColor);
}

void initializeGrid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = -1;
    }
  }
  grid[3][3] = 0;
  grid[4][4] = 0;
  grid[3][4] = 1;
  grid[4][3] = 1;
}

void displayGrid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j] != -1) {
        add(i, j, grid[i][j]);
      }
    }
  }
}

void setup() {
  ht1632_setup();
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
  Wire.begin();
  setup7Seg();
  cls();
  pinMode(POTEN, INPUT);


  Timer1.initialize(25000);
  Timer1.attachInterrupt(fnPeriodique);

  initializeGrid();
  displayGrid();
}

void loop() {
  x ++; // Corrected variable name
  if (x == 8) { // Corrected variable name
    x = 0;
    y++;
    if (player == 0){
      player = 1;
    }
    else{
      player = 0;
    }
  }
  if (y > 7) {
    y = 0;
  }

  if (validation) {
    int val = analogRead(POTEN);  // lit la valeur actuelle du potentiomètre

    Serial.println(val);
    grid[x][y] = player;
    Serial.println(grid[x][y]);
    Serial.println(x);
    Serial.println(y);
    displayGrid();
    if (y==5){
        validation = false;
    }
  }
}

void fnPeriodique() {
  static bool lastButtonState = HIGH;
  bool currentButtonState = digitalRead(BUTTON);

  if (currentButtonState == LOW && lastButtonState == HIGH) {
    validation = true; // Set the flag to change direction
    Serial.println("knf");
  }

  lastButtonState = currentButtonState;
}
