#include <stdio.h>

// Function to draw the Tic-Tac-Toe board
void drawBoard(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;

    return 0;
}

int main() {
    char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
    int currentPlayer = 1;
    int moves = 0;
    int choice;
    int row, column;

    while (1) {
        drawBoard(board);
        currentPlayer = (currentPlayer % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", currentPlayer);
        scanf("%d", &choice);

        row = --choice / 3;
        column = choice % 3;

        if (board[row][column] == choice + '0') {
            board[row][column] = (currentPlayer == 1) ? 'X' : 'O';
            moves++;

            if (checkWin(board, (currentPlayer == 1) ? 'X' : 'O')) {
                printf("Congratulations! Player %d wins!\n", currentPlayer);
                drawBoard(board);
                break;
            }

            if (moves == 9) {
                printf("It's a draw!\n");
                drawBoard(board);
                break;
            }
        }
        else {
            printf("Invalid move! Try again.\n");
        }

        currentPlayer++;
    }

    return 0;
}
