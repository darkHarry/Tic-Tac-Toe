#include <stdio.h>

struct Move
{
  int score, choice;
};

int gameOver (char *board)
{
  int i = 0, s = 0;
  for (i = 0; i < 9; i++)
    if (board[i] != '.')
      s++;

  if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X' || board[3] == 'X' && board[4] == 'X' && board[5] == 'X' ||
      board[6] == 'X' && board[7] == 'X' && board[8] == 'X' || board[0] == 'X' && board[3] == 'X' && board[6] == 'X' ||
      board[1] == 'X' && board[4] == 'X' && board[7] == 'X' || board[2] == 'X' && board[5] == 'X' && board[8] == 'X' ||
      board[0] == 'X' && board[4] == 'X' && board[8] == 'X' || board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
      return 2;
  if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O' || board[3] == 'O' && board[4] == 'O' && board[5] == 'O' ||
      board[6] == 'O' && board[7] == 'O' && board[8] == 'O' || board[0] == 'O' && board[3] == 'O' && board[6] == 'O' ||
      board[1] == 'O' && board[4] == 'O' && board[7] == 'O' || board[2] == 'O' && board[5] == 'O' && board[8] == 'O' ||
      board[0] == 'O' && board[4] == 'O' && board[8] == 'O' || board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
      return 1;

  if (s == 9)
      return -1;  //Draw Condition

  return 0; //nothing happens
}

void move (char *board, char c)
{
  int n;
  do
  {
    printf("Enter Pos: ");
    scanf("%d", &n);
  }while (n < 1 || n > 9 || board[n-1] != '.');
  board[n-1] = c;
}

void printBoard (char *board)
{
  printf("\n%c %c %c", board[0], board[1], board[2]);
  printf("\n%c %c %c", board[3], board[4], board[5]);
  printf("\n%c %c %c\n", board[6], board[7], board[8]);
}

struct Move AImove (char *board, int player, int depth)
{
  struct Move move;
  move.choice = 0;
  depth++;
  if (gameOver(board) == 1)
  {
    move.score = depth-10;
    return move;
  }
  if (gameOver(board) == 2)
  {
    move.score = 10-depth;
    return move;
  }
  if (gameOver(board) == -1)
  {
    move.score = 0;
    return move;
  }
  char b[9];
  int i = 0, n = 0, j = 0;
  for (i = 0; i < 9; i++)
  {
    if (board[i] == '.')
      n++;
    b[i] = board[i];
  }
  struct Move m[n];
  for (i = 0; i < 9; i++)
  {
    if (b[i] == '.')
    {
      struct Move t;
      b[i] = player;
      m[j].choice = i;
      if (player == 'X')
        t = AImove(b, 'O', depth);
      else
        t = AImove(b, 'X', depth);
      m[j++].score = t.score;
      b[i] = '.';
    }
  }

  if (player == 'X')
  {
    int max = -11, maxIndex = -1;
    for (i = 0; i < n; i++)
      if (m[i].score > max)
        max = m[i].score, maxIndex = i;
    return m[maxIndex];
  }
  else
  {
    int min = 11, minIndex = -1;
    for (i = 0; i < n; i++)
      if (m[i].score < min)
        min = m[i].score, minIndex = i;
    return m[minIndex];
  }
}

int main()
{
  char board[9];
  struct Move m;
  int i = 0, check;
  while (i < 9)
    board[i++] = '.';
  char p1 = 'O';
  char p2 = 'X';
  i = 0;
  printBoard(board);
  while (1)
  {
    if (i%2 == 0)
      move(board, 'O');
    else
    {
      m = AImove(board, 'X', 0);
      board[m.choice] = 'X';
    }
    printBoard(board);
    check = gameOver(board);
    if (check == 1 || check == 2 || check == -1)
      break;
    i++;
  }
  if (check == 1)
    printf("O Wins\n");
  else if (check == 2)
    printf("X Wins\n");
  else
    printf("Draw\n");
  return 0;
}
