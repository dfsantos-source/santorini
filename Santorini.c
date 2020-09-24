#include <stdio.h>


// minimization of global variables
// keeps track of prior player & AI position
// keeps track of game over status
int gameOver = 0;
int old_Px = -1;
int old_Py = -1;
char old_Pvalue = -1;
int old_Ax = -1;
int old_Ay = -1;
char old_Avalue = -1;

// traverses up from position (not including the position itself) and updates until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
// returns amount of spaces available from iterating
int updateUp(int row, int column, char p, int change, char state[6][6]) 
{
    int sum = 0;
    char bound;
    if (change == 1) //player is updating board
    {
        bound = '4'; 
    }
    else if (change == -1) //ai is updating board 
    {
        bound = '0';
    }
    int rowArr = row - 1;
    int columnArr = column - 1;
    char c;
    for (int i = row - 2; i >= 0; i--) //loop until boundary
    {
        c = state[i][columnArr]; // current element 
        if (c != p && c != bound) // update if current element is not boundary element and not edge
        {
            int d = (c - '0') + change;
            sum++;
            c = d + '0';
            state[i][columnArr] = c;
        }
        if (c == p) //stop updating if we reach the other builder's spot //stop updating if we reach the other builder's spot
        {
            break;
        }
    }
    return sum; 
}
// traverses down from position (not including the position itself) and updates until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
// returns amount of spaces available from iterating
int updateDown(int row, int column, char p, int change, char state[6][6])
{
    int sum = 0;
    char bound;
    if (change == 1) //player is updating board
    {
        bound = '4';
    }
    else if (change == -1) //ai is updating board
    {
        bound = '0';
    }
    int rowArr = row - 1;
    int columnArr = column - 1;

    char c;
    for (int i = rowArr + 1; i < 6; i++) // loop until boundary
    {
        c = state[i][columnArr]; // current element
        if (c != p && c != bound) // update if current element is not boundary element and not edge// update if current element is not boundary element and not edge
        {
            int d = (c - '0') + change;
            sum++;
            c = d + '0';
            state[i][columnArr] = c;
        }
        if (c == p) //stop updating if we reach the other builder's spot
        {
            break;
        }
    }
    return sum;
}
// traverses left from position (not including the position itself) and updates until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
// returns amount of spaces available from iterating
int updateLeft(int row, int column, char p, int change, char state[6][6]) 
{
    int sum = 0;
    char bound;
    if (change == 1) //player is updating board
    {
        bound = '4';
    }
    else if (change == -1) //ai is updating board
    {
        bound = '0';
    }
    int rowArr = row - 1;
    int columnArr = column - 1;

    char c;
    for (int i = columnArr - 1; i >= 0; i--) //loop until boundary
    {
        c = state[rowArr][i];
        if (c != p && c != bound) // update if current element is not boundary element and not edge
        {
            int d = (c - '0') + change;
            sum++;
            c = d + '0';
            state[rowArr][i] = c;
        }
        if (c == p) //stop updating if we reach the other builder's spot
        {
            break;
        }
    }
    return sum;
}
// traverses right from position (not including the position itself) and updates until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
// returns amount of spaces available from iterating
int updateRight(int row, int column, char p, int change, char state[6][6])
{
    int sum = 0;
    char bound;
    if (change == 1) //player is updating board
    {
        bound = '4';
    }
    else if (change == -1) //ai is updating board
    {
        bound = '0';
    }
    int rowArr = row - 1;
    int columnArr = column - 1;

    char c;
    for (int i = columnArr + 1; i < 6; i++) //loop until boundary
    {
        c = state[rowArr][i];
        if (c != p && c != bound)
        {
            int d = (c - '0') + change; // update if current element is not boundary element and not edge
            c = d + '0';
            sum++;
            state[rowArr][i] = c;
        }
        if (c == p) //stop updating if we reach the other builder's spot
        {
            break;
        }
    }
    return sum;
}
// traverses up right from position (not including the position itself) and updates until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
// returns amount of spaces available from iterating
int updateUpRight(int row, int column, char p, int change, char state[6][6]) 
{
    int sum = 0;
    char bound;
    if (change == 1) //player is updating board
    {
        bound = '4';
    }
    else if (change == -1) //ai is updating board
    {
        bound = '0';
    }
    int rowArr = row - 1;
    int columnArr = column - 1;

    char c;
    int count = 1;
    int maxDistance = -1;
    int up = 0;
    for (int i = row - 2; i >= 0; i--) // calculates spaces availble above
    {
        up++;
    }
    int right = 0;
    for (int i = columnArr + 1; i < 6; i++) // calculates spaces available to the right
    {
        right++;
    }
    if (row == 1 || column == 6) //position not accessible
    {
        return 0;
    }
    else
    {
        if (up > right) //we want the lower traversal value
        {
            maxDistance = right;
            for (int i = rowArr - 1; i >= rowArr - maxDistance; i--)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count++;
            }
        }
        else if (up < right)
        {
            maxDistance = up;
            for (int i = rowArr - 1; i >= rowArr - maxDistance; i--)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count++;
            }
        }
        else //both traversal values are the same
        {
            maxDistance = up;
            for (int i = rowArr - 1; i >= rowArr - maxDistance; i--)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count++;
            }
        }
    }
    return sum;
}
// traverses up left from position (not including the position itself) and updates until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
// returns amount of spaces available from iterating
int updateUpLeft(int row, int column, char p, int change, char state[6][6]) 
{
    int sum = 0;
    char bound;
    if (change == 1) //player is updating board
    {
        bound = '4';
    }
    else if (change == -1) //ai is updating board
    {
        bound = '0';
    }
    int rowArr = row - 1;
    int columnArr = column - 1;

    char c;
    int count = -1;
    int maxDistance = -1;
    int up = 0;
    for (int i = row - 2; i >= 0; i--) //calculates spaces available above
    {
        up++;
    }
    int left = 0;
    for (int i = columnArr - 1; i >= 0; i--) //calculates spaces available left
    {
        left++;
    }
    if (row == 1 || column == 1) //position not accessible
    {
        return 0;
    }
    else
    {
        if (up > left) //we want the lower traversal value
        {
            maxDistance = left;
            for (int i = rowArr - 1; i >= rowArr - maxDistance; i--)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count--;
            }
        }
        else if (up < left)
        {
            maxDistance = up;
            for (int i = rowArr - 1; i >= rowArr - maxDistance; i--)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count--;
            }
        }
        else //both traversal values are the same
        {
            maxDistance = up;
            for (int i = rowArr - 1; i >= rowArr - maxDistance; i--)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count--;
            }
        }
    }
    return sum;
}
// traverses down left from position (not including the position itself) and updates until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
// returns amount of spaces available from iterating
int updateDownLeft(int row, int column, char p, int change, char state[6][6]) 
{
    int sum = 0;
    char bound;
    if (change == 1) //player is updating board
    {
        bound = '4';
    }
    else if (change == -1) //ai is updating board
    {
        bound = '0';
    }
    int rowArr = row - 1;
    int columnArr = column - 1;

    char c;
    int count = -1;
    int maxDistance = -1;
    int down = 0;
    for (int i = rowArr + 1; i < 6; i++) // calculates available spaces downwards
    {
        down++;
    }
    int left = 0;
    for (int i = columnArr - 1; i >= 0; i--)  // calculates available spaces left
    {
        left++;
    }
    if (row == 6 || column == 1) //position not accessible
    {
        return 0;
    }
    else
    {
        if (down > left) //we want the lower traversal value
        {
            maxDistance = left;
            for (int i = rowArr + 1; i <= rowArr + maxDistance; i++)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count--;
            }
        }
        else if (down < left)
        {
            maxDistance = down;
            for (int i = rowArr + 1; i <= rowArr + maxDistance; i++)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count--;
            }
        }
        else //both traversal values are the same
        {
            maxDistance = down;
            for (int i = rowArr + 1; i <= rowArr + maxDistance; i++)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count--;
            }
        }
    }
    return sum;
}
// traverses down right from position (not including the position itself) and updates until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
// returns amount of spaces available from iterating
int updateDownRight(int row, int column, char p, int change, char state[6][6]) 
{
    int sum = 0;
    char bound;
    if (change == 1) //player is updating board
    {
        bound = '4';
    }
    else if (change == -1) //ai is updating board
    {
        bound = '0';
    }
    int rowArr = row - 1;
    int columnArr = column - 1;

    char c;
    int count = 1;
    int maxDistance = -1;
    int down = 0;
    for (int i = rowArr + 1; i < 6; i++) // calculates available spaces downwards
    {
        down++;
    }
    int right = 0;
    for (int i = columnArr + 1; i < 6; i++) // calculates available spaces right
    {
        right++;
    }
    if (row == 6 || column == 6) //position not accessible
    {
        return 0;
    }
    else
    {
        if (down > right) //we want the lower traversal value
        {
            maxDistance = right;
            for (int i = rowArr + 1; i <= rowArr + maxDistance; i++)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count++;
            }
        }
        else if (down < right)
        {
            maxDistance = down;
            for (int i = rowArr + 1; i <= rowArr + maxDistance; i++)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count++;
            }
        }
        else //both traversal values are the same
        {
            maxDistance = down;
            for (int i = rowArr + 1; i <= rowArr + maxDistance; i++)
            {
                c = state[i][columnArr + count];
                if (c != p && c != bound)
                {
                    int d = (c - '0') + change;
                    sum++;
                    c = d + '0';
                    state[i][columnArr + count] = c;
                }
                if (c == p) //stop updating if we reach the other builder's spot
                {
                    break;
                }
                count++;
            }
        }
    }
    return sum;
}
// traverses in every direction from position (not including the position itself) and UPDATES individual elements until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
void updateDirections(int posX, int posY, char p, int change, char state[6][6])
{
    updateUpLeft(posX, posY, p, change, state);
    updateUp(posX, posY, p, change, state);
    updateUpRight(posX, posY, p, change, state);
    updateLeft(posX, posY, p, change, state);
    updateRight(posX, posY, p, change, state);
    updateDownLeft(posX, posY, p, change, state);
    updateDown(posX, posY, p, change, state);
    updateDownRight(posX, posY, p, change, state);
}

// traverses in every direction from position (not including the position itself) and CALCULATES total score until boundary or P in the way
// [p] is boundary to check for 
// [change] is amount to update each element by (either 1 or -1)
// [state] is the game state
int calculateScore(int row, int column, char p, char state[6][6])
{
    int sum = 0;
    int upValue = updateUp(row, column, p, 0, state);
    int downValue = updateDown(row, column, p, 0, state);
    int leftValue = updateLeft(row, column, p, 0, state);
    int rightValue = updateRight(row, column, p, 0, state);
    int upRightValue = updateUpRight(row, column, p, 0, state);
    int upLeftValue = updateUpLeft(row, column, p, 0, state);
    int downLeftValue = updateDownLeft(row, column, p, 0, state);
    int downRightValue = updateDownRight(row, column, p, 0, state);
    sum = upValue + downValue + leftValue + rightValue + upRightValue + upLeftValue + downLeftValue + downRightValue;
    return sum;
}


// prints game state
void printGameState(char state[6][6])
{
    printf("  %c %c %c %c %c %c\n", '1', '2', '3', '4', '5', '6');

    for (int i = 0; i < 6; i++)
    {
        char temp = i + 1 + '0';
        printf("%c ", temp);
        for (int j = 0; j < 6; j++)
        {
            printf("%c ", state[i][j]);
        }
        printf("\n");
    }
}

// initializes game state for processing
void initialzeGameState(char state[6][6])
{
    int row = -1;
    int column = -1;
    printf("Enter [row column]\n");
    while ((row < 1 || row > 6 || column < 1 || column > 6) || //row is invalid && column is invalid
           (row < 1 || row > 6 || column < 1 || column > 6) || //row is valid && column is invalid
           (row < 1 || row > 6 || column < 1 || column > 6))   //row is invalid && column is valid
    {
        scanf("%i %i", &row, &column);
        if ((row < 1 || row > 6 || column < 1 || column > 6) || //row is invalid && column is invalid
            (row < 1 || row > 6 || column < 1 || column > 6) || //row is valid && column is invalid
            (row < 1 || row > 6 || column < 1 || column > 6))   //row is invalid && column is valid
        {
            printf("Not valid. Must be between 1-6. Must be in the format: [2 4]\n");
        }
    }
    printf("Player chose row: %i column: %i\n", row, column);
    char playerPosValue = state[row - 1][column - 1];
    state[row - 1][column - 1] = 'P';

    // ai picks a spot
    int pRow = row - 1;
    int pColumn = column - 1;
    //initialze all available adjacent points from 'P'
    int topLeft = 0; // 0 = invalid, 1 = vaid
    int aX = -1;     //top left
    int aY = -1;

    int top = 0;
    int bX = -1; // top
    int bY = -1;

    int topRight = 0;
    int cX = -1; // top right
    int cY = -1;

    int left = 0;
    int dX = -1; // left
    int dY = -1;

    int right = 0;
    int eX = -1; //right
    int eY = -1;

    int bottomLeft = 0;
    int fX = -1; // bottom left
    int fY = -1;

    int bottom = 0;
    int gX = -1; // bottom
    int gY = -1;

    int bottomRight = 0;
    int hX = -1; // bottom right
    int hY = -1;

    //0 - topleft
    //1 - top
    //2 - top right
    //3 - left
    //4 - right
    //5 - bottom left
    //6 - bottom
    //7 - bottom right
    int neighbors[8] = {//boolean table consisting of neighbors that are available or not, 0 = invalid, 1= valid
                        0, 0, 0,
                        0, 0,
                        0, 0, 0};

    if (updateUpLeft(row, column, 'P', 0, state) != 0) // 'top left' adjacent spot available
    {

        neighbors[0] = 1;
        aX = row - 1;
        aY = column - 1;
    }
    if (updateUp(row, column, 'P', 0, state) != 0) // 'top' adjacent spot available
    {

        neighbors[1] = 1;
        bX = row + 1;
        bY = column;
    }
    if (updateUpRight(row, column, 'P', 0, state) != 0) // 'top right' adjacent spot available
    {

        neighbors[2] = 1;
        cX = row - 1;
        cY = column + 1;
    }
    if (updateLeft(row, column, 'P', 0, state) != 0) // 'left' adjacent spot available
    {

        neighbors[3] = 1;
        dX = row;
        dY = column - 1;
    }
    if (updateRight(row, column, 'P', 0, state) != 0) // 'right' adjacent spot available
    {

        neighbors[4] = 1;
        eX = row;
        eY = column + 1;
    }
    if (updateDownLeft(row, column, 'P', 0, state) != 0) // 'bottom left' adjacent spot available
    {

        neighbors[5] = 1;
        fX = row + 1;
        fY = column - 1;
    }
    if (updateDown(row, column, 'P', 0, state) != 0) // 'botttom' adjacent spot available
    {

        neighbors[6] = 1;
        gX = row + 1;
        gY = column;
    }
    if (updateDownRight(row, column, 'P', 0, state) != 0) // 'botttom right' adjacent spot available
    {

        neighbors[7] = 1;
        hX = row + 1;
        hY = column + 1;
    }

    
    //find maximum score for all of the available points
    int values[8] =
        {

            calculateScore(aX, aY, 'P', state),
            calculateScore(bX, bY, 'P', state),
            calculateScore(cX, cY, 'P', state),
            calculateScore(dX, dY, 'P', state),
            calculateScore(eX, eY, 'P', state),
            calculateScore(fX, fY, 'P', state),
            calculateScore(gX, gY, 'P', state),
            calculateScore(hX, hY, 'P', state)};

    //array for coordinates of adjacent/available points
    int xCords[8] =
        {
            aX,
            bX,
            cX,
            dX,
            eX,
            fX,
            gX,
            hX};
    int yCords[8] =
        {
            aY,
            bY,
            cY,
            dY,
            eY,
            fY,
            gY,
            hY};
    int max = -1000000;

    //find max score of out of all adjacent 
    for (int i = 0; i < 8; i++)
    {
        if (neighbors[i] == 1 && values[i] > max)
        {
            max = values[i];
        }
    }

    //set AI position 
    int ai_positionX;
    int ai_positionY;
    for (int i = 0; i < 8; i++)
    {
        if (values[i] == max)
        {
            ai_positionX = xCords[i];
            ai_positionY = yCords[i];
        }
    }
    printf("AI chose row: %i column: %i\n", ai_positionX, ai_positionY);
    char ai_position_value = state[ai_positionX][ai_positionY];
    state[ai_positionX - 1][ai_positionY - 1] = 'A';
    printGameState(state); // print game state with 'A' and 'P'

    state[row - 1][column - 1] = playerPosValue; //p leaves, ai stays

    printf("Initialized Game.\n");
    printf("--------------------------------\n");

    //update old player and old ai values
    old_Px = row; 
    old_Py = column;
    old_Pvalue = playerPosValue;
    old_Ax = ai_positionX;
    old_Ay = ai_positionY;
    old_Avalue = ai_position_value;
}



// returns 0 -> game is not over
// returns 1 -> game is over, player wins
// returns 2 -> game is over, AI wins
void isGameOver(char state[6][6])
{
    //loop through checking 10 with level 4
    //loop through checking  10 with level 0
    int sum4 = 0;
    int sum0 = 0;
    for (int i = 0; i < 6; i++) // loop through the game board
    {
        for (int j = 0; j < 6; j++)
        {
            if (state[i][j] == '4')
            {
                sum4++;
            }
            if (state[i][j] == '0')
            {
                sum0++;
            }
        }
    }
    if (sum4 >= 10) 
    {
        gameOver = 1; //game over
    }
    else if (sum0 >= 10)
    { 
        gameOver = 2; //game over
    }
    else
    {
        gameOver = 0; //game not over
    }
    printf("Player Score: %i\n", sum4);
    printf("AI Score: %i\n", sum0);
}

void updateGameState(char state[6][6])
{
    int row = -1;
    int column = -1;
    printf("Enter [row column]\n");
    while ((row < 1 || row > 6 || column < 1 || column > 6) || // row is invalid && column is invalid
           (row < 1 || row > 6 || column < 1 || column > 6) || // row is valid && column is invalid
           (row < 1 || row > 6 || column < 1 || column > 6) || // row is invalid && column is valid
           (row == old_Px && column == old_Py) ||            // spot is already taken by player
           (row == old_Ax && column == old_Ay) ||            // spot is already taken by AI
           ((row > old_Px + 1) || (row < old_Px - 1)) ||
           ((column < old_Py - 1) || (column > old_Py + 1)))    // spot is not adjacent
    {
        scanf("%i %i", &row, &column);
        if ((row < 1 || row > 6 || column < 1 || column > 6) || // row is invalid && column is invalid
            (row < 1 || row > 6 || column < 1 || column > 6) || // row is valid && column is invalid
            (row < 1 || row > 6 || column < 1 || column > 6) || // row is invalid && column is valid
            (row == old_Px && column == old_Py) ||           // spot is already taken by player
            (row == old_Ax && column == old_Ay) ||           // spot is already taken by AI
            ((row > old_Px + 1) || (row < old_Px - 1)) ||
            ((column < old_Py - 1) || (column > old_Py + 1)))   // spot is not adjacent
        {
            printf("Not valid. Must be between 1-6. Must be in the format: [2 4] Must not be previous builder spot.\n");
        }
    }
    printf("Player chose row: %i column: %i\n", row, column);
    int playerPosValue = state[row - 1][column - 1];
    state[row - 1][column - 1] = 'P';
    updateDirections(row, column, 'A', 1, state); // update board (Player turn)
    printf("Player updates board. \n");
    printGameState(state);
    isGameOver(state);
    if (gameOver == 1 || gameOver == 2) // check if game is over
    {
        return;
    }

    //remove old A from gameboard
    state[old_Ax - 1][old_Ay - 1] = old_Avalue;

    // ai picks a spot
    int pRow = row - 1;
    int pColumn = column - 1;
    //get all available adjacent points from 'A'
    int topLeft = 0; // 0 = invalid, 1 = vaid
    int aX = -1;     //top left
    int aY = -1;

    int top = 0;
    int bX = -1; // top
    int bY = -1;

    int topRight = 0;
    int cX = -1; // top right
    int cY = -1;

    int left = 0;
    int dX = -1; // left
    int dY = -1;

    int right = 0;
    int eX = -1; //right
    int eY = -1;

    int bottomLeft = 0;
    int fX = -1; // bottom left
    int fY = -1;

    int bottom = 0;
    int gX = -1; // bottom
    int gY = -1;

    int bottomRight = 0;
    int hX = -1; // bottom right
    int hY = -1;

    //0 - topleft
    //1 - top
    //2 - top right
    //3 - left
    //4 - right
    //5 - bottom left
    //6 - bottom
    //7 - bottom right
    int neighbors[8] = {//boolean table consisting of neighbors that are available or not, 0 = invalid, 1= valid
                        0, 0, 0,
                        0, 0,
                        0, 0, 0};

    if (updateUpLeft(old_Ax, old_Ay,'P', 0, state) != 0) // 'top left' adjacent spot available
    {

        neighbors[0] = 1;
        aX = old_Ax - 1;
        aY = old_Ay - 1;
    }
    if (updateUp(old_Ax, old_Ay, 'P', 0, state) != 0) // 'top' adjacent spot available
    {

        neighbors[1] = 1;
        bX = old_Ax + 1;
        bY = old_Ay;
    }
    if (updateUpRight(old_Ax, old_Ay, 'P', 0, state) != 0) // 'top right' adjacent spot available
    {

        neighbors[2] = 1;
        cX = old_Ax - 1;
        cY = old_Ay + 1;
    }
    if (updateLeft(old_Ax, old_Ay, 'P', 0, state) != 0) // 'left' adjacent spot available
    {

        neighbors[3] = 1;
        dX = old_Ax;
        dY = old_Ay - 1;
    }
    if (updateRight(old_Ax, old_Ay, 'P', 0, state) != 0) // 'right' adjacent spot available
    {

        neighbors[4] = 1;
        eX = old_Ax;
        eY = old_Ay + 1;
    }
    if (updateDownLeft(old_Ax, old_Ay, 'P', 0, state) != 0) // 'bottom left' adjacent spot available
    {

        neighbors[5] = 1;
        fX = old_Ax + 1;
        fY = old_Ay - 1;
    }
    if (updateDown(old_Ax, old_Ay, 'P', 0, state) != 0) // 'botttom' adjacent spot available
    {

        neighbors[6] = 1;
        gX = old_Ax + 1;
        gY = old_Ay;
    }
    if (updateDownRight(old_Ax, old_Ay, 'P', 0, state) != 0) // 'botttom right' adjacent spot available
    {

        neighbors[7] = 1;
        hX = old_Ax + 1;
        hY = old_Ay + 1;
    }

    int values[8] =
        {
            calculateScore(aX, aY, 'P', state),
            calculateScore(bX, bY, 'P', state),
            calculateScore(cX, cY, 'P', state),
            calculateScore(dX, dY, 'P', state),
            calculateScore(eX, eY, 'P', state),
            calculateScore(fX, fY, 'P', state),
            calculateScore(gX, gY, 'P', state),
            calculateScore(hX, hY, 'P', state)};

    //coordinates for adjact points from A
    int xCords[8] =
        {
            aX,
            bX,
            cX,
            dX,
            eX,
            fX,
            gX,
            hX};
    int yCords[8] =
        {
            aY,
            bY,
            cY,
            dY,
            eY,
            fY,
            gY,
            hY};

    // calculate max amount of "coverage" for each individual spot, and pick the one that can deduct the most spots
    int max = -1000000;
    for (int i = 0; i < 8; i++)
    {
        if (neighbors[i] == 1 && values[i] > max)
        {
            max = values[i];
        }
    }

    // variables for new AI position
    int ai_positionX;
    int ai_positionY;
    for (int i = 0; i < 8; i++)
    {
        if (values[i] == max)
        {
            ai_positionX = xCords[i];   //set AI position
            ai_positionY = yCords[i];
        }
    }
    printf("AI chose row: %i column: %i\n", ai_positionX, ai_positionY);
    char ai_position_value = state[ai_positionX - 1][ai_positionY - 1];
    state[ai_positionX - 1][ai_positionY - 1] = 'A';    //put AI on the gameboard
    updateDirections(ai_positionX, ai_positionY, 'P', -1, state);
    printf("AI updates board. \n");

    printGameState(state); 
    isGameOver(state);
    if (gameOver == 1 || gameOver == 2)
    {
        return;
    }
    printf("--------------------------------\n");

    state[row - 1][column - 1] = playerPosValue;    //remove player from gameboard

    //update old coordinates
    old_Px = row; 
    old_Py = column;
    old_Pvalue = playerPosValue;
    old_Ax = ai_positionX;
    old_Ay = ai_positionY;
    old_Avalue = ai_position_value;
}

int main()
{
    char gameBoard[6][6];
    for (int i=0; i<6; i++) 
    {
        for (int j=0;j<6;j++)
        {
            gameBoard[i][j] = '2';
        }
    }
    initialzeGameState(gameBoard);
    printf("Begin Game.\n");
    while (gameOver == 0) //0 -- game is not over, 1 - player wins, 2 - ai wins
    {
        updateGameState(gameBoard);
    }
    if (gameOver == 1)
    {
        printf("Player wins!");
    }
    else if (gameOver == 2)
    {
        printf("AI wins!");
    }
}