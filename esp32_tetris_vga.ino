#include <fabgl.h>
#include <Arduino.h>

// ---------------- VGA SETUP ----------------
fabgl::VGA16Controller DisplayController;
fabgl::Canvas canvas(&DisplayController);

// ---------------- GAME CONSTANTS ----------------
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BLOCK_SIZE 12

#define BTN_LEFT   32
#define BTN_RIGHT  33
#define BTN_ROTATE 25
#define BTN_DOWN   26

// ---------------- GAME STATE ----------------
int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};
int score = 0;

struct Piece {
  int shape[4][4];
  int x, y;
};

Piece currentPiece;

// ---------------- TETRIS SHAPES ----------------
int tetrominoes[7][4][4] = {
  {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}}, // I
  {{1,1},{1,1}},                           // O
  {{0,1,0},{1,1,1},{0,0,0}},               // T
  {{0,1,1},{1,1,0},{0,0,0}},               // S
  {{1,1,0},{0,1,1},{0,0,0}},               // Z
  {{1,0,0},{1,1,1},{0,0,0}},               // J
  {{0,0,1},{1,1,1},{0,0,0}}                // L
};

// ---------------- FUNCTION DECLARATIONS ----------------
void spawnPiece();
bool checkCollision(int nx, int ny, int shape[4][4]);
void placePiece();
void clearLines();
void rotatePiece();
void drawBoard();
void drawPiece();

// ---------------- SETUP ----------------
void setup() {
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_ROTATE, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);

  DisplayController.begin();
  DisplayController.setResolution(VGA_640x480_60Hz);
  canvas.setBrushColor(Color::Black);
  canvas.clear();

  randomSeed(analogRead(0));
  spawnPiece();
}

// ---------------- MAIN LOOP ----------------
void loop() {
  if (!digitalRead(BTN_LEFT))  currentPiece.x--;
  if (!digitalRead(BTN_RIGHT)) currentPiece.x++;
  if (!digitalRead(BTN_ROTATE)) rotatePiece();
  if (!digitalRead(BTN_DOWN)) currentPiece.y++;

  if (checkCollision(currentPiece.x, currentPiece.y, currentPiece.shape)) {
    currentPiece.y--;
    placePiece();
    clearLines();
    spawnPiece();
  }

  canvas.clear();
  drawBoard();
  drawPiece();

  canvas.drawText(400, 20, "Score:", Color::White);
  canvas.drawText(400, 40, String(score).c_str(), Color::White);

  delay(300);
}

// ---------------- GAME LOGIC ----------------
void spawnPiece() {
  int r = random(0, 7);
  memcpy(currentPiece.shape, tetrominoes[r], sizeof(currentPiece.shape));
  currentPiece.x = BOARD_WIDTH / 2 - 2;
  currentPiece.y = 0;
}

bool checkCollision(int nx, int ny, int shape[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (shape[i][j]) {
        int x = nx + j;
        int y = ny + i;
        if (x < 0 || x >= BOARD_WIDTH || y >= BOARD_HEIGHT) return true;
        if (y >= 0 && board[y][x]) return true;
      }
    }
  }
  return false;
}

void placePiece() {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (currentPiece.shape[i][j])
        board[currentPiece.y + i][currentPiece.x + j] = 1;
}

void clearLines() {
  for (int i = BOARD_HEIGHT - 1; i >= 0; i--) {
    bool full = true;
    for (int j = 0; j < BOARD_WIDTH; j++)
      if (!board[i][j]) full = false;

    if (full) {
      score += 100;
      for (int k = i; k > 0; k--)
        memcpy(board[k], board[k - 1], sizeof(board[k]));
    }
  }
}

void rotatePiece() {
  int temp[4][4];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      temp[j][3 - i] = currentPiece.shape[i][j];

  if (!checkCollision(currentPiece.x, currentPiece.y, temp))
    memcpy(currentPiece.shape, temp, sizeof(temp));
}

// ---------------- DRAWING ----------------
void drawBoard() {
  for (int i = 0; i < BOARD_HEIGHT; i++)
    for (int j = 0; j < BOARD_WIDTH; j++)
      if (board[i][j])
        canvas.fillRectangle(
          j * BLOCK_SIZE,
          i * BLOCK_SIZE,
          (j + 1) * BLOCK_SIZE,
          (i + 1) * BLOCK_SIZE,
          Color::Green
        );
}

void drawPiece() {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (currentPiece.shape[i][j])
        canvas.fillRectangle(
          (currentPiece.x + j) * BLOCK_SIZE,
          (currentPiece.y + i) * BLOCK_SIZE,
          (currentPiece.x + j + 1) * BLOCK_SIZE,
          (currentPiece.y + i + 1) * BLOCK_SIZE,
          Color::Red
        );
}
