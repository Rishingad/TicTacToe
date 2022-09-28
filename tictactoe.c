#include <stdio.h>

int checkwin(char board[3][3])
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return 1;

    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return 1;

    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return 1;

    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return 1;

    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return 1;

    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return 1;

    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
             board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
        return 2;

    else
        return -1;
}

void moveforx(int choice, char board[3][3])
{
    int i, j;
    switch (choice)
    {
    case 1:
        board[0][0] = 'x';
        break;

    case 2:
        board[0][1] = 'x';
        break;

    case 3:
        board[0][2] = 'x';
        break;

    case 4:
        board[1][0] = 'x';
        break;

    case 5:
        board[1][1] = 'x';
        break;

    case 6:
        board[1][2] = 'x';
        break;

    case 7:
        board[2][0] = 'x';
        break;

    case 8:
        board[2][1] = 'x';
        break;

    case 9:
        board[2][2] = 'x';
        break;

    default:
        printf("Error! invalid choice");
    }
}

void movefor0(int choice, char board[3][3])
{
    int i, j;
    switch (choice)

    {
    case 1:
        board[0][0] = '0';
        break;

    case 2:
        board[0][1] = '0';
        break;

    case 3:
        board[0][2] = '0';
        break;

    case 4:
        board[1][0] = '0';
        break;

    case 5:
        board[1][1] = '0';
        break;

    case 6:
        board[1][2] = '0';
        break;

    case 7:
        board[2][0] = '0';
        break;

    case 8:
        board[2][1] = '0';
        break;

    case 9:
        board[2][2] = '0';
        break;

    default:
        printf("Error! invalid choice");
    }
}

void drawboard(char board[3][3]){
   
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);

    printf("_____|_____|___\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);

    printf("_____|_____|___\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);

    printf("     |     |     \n\n");
    
}

int main()
{
    int i, j, k;
    int choice;
    char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
     printf("\n\n\t\t\t\t\t\t\t\tTic Tac Toe\n\n");
     printf("\n\n\t\t\t 1)Players should enter their respective marks by entering the number assigned to the desired position \n\n\t\t\t 2)Players cannot pick positions already occupied by the other player\n\n\t\t\t 3)The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner\n\n\t\t\t 4)When all 9 squares are full, the game is over.\n\n\t\t\t 4)If no player has 3 marks in a row, the game ends in a tie.\n\n");
     printf("\t\t\t\t\t\t\tPlayer 1 (X)  -  Player 2 (O)\n\n");
    
    
    do
    {
        drawboard(board);
        printf("X's move: ");
        scanf("%d", &choice);
        moveforx(choice, board);
        k = checkwin(board);

        if (k == 1)
        { 
            drawboard(board);
            printf("Congratulations Player 1 , you are the winner");
            break;
        }
        else if (k == 2)
        {
            drawboard(board);
            printf("Game draw \n");
            printf("︶︿︶");
            break;
        }
        else if (k != 1)
            goto jump;

    jump:
        drawboard(board);
        printf("0's move: ");
        scanf("%d", &choice);
        movefor0(choice, board);
        k = checkwin(board);
        if (k == 1)
        {
            drawboard(board);
            printf("Congratulations Player 2 , you are the winner");
            break;
        }
    
        
    } while (k == -1);

    return 0;
}