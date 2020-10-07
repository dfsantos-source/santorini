
# Santorini
Board game Santorini created in C for second year course C coding course.

## Video Link
https://youtu.be/cVoETrJT9x4

## Game Overview

1. Initialize: Player picks a valid point, AI picks a point, gameboard is not updated
2. Player picks a valid spot, updates the board in all directions if nothing in the way, print board, print score, check if game is over
3. AI picks a spot, updates, updates the board in all directions if nothing in the way, print board, print score, check if game is over
4. Rinse and Repeat

## Update Board Overview

Methods:
int updateUpLeft()
int updateUpRight()
int updateUp()
int updateLeft()
int updateRight()
int updateDownLeft()
int updateDown()
int updateDownRight()

These methods find the available spaces for each directional. 
They may also update the spaces along the way.
We can utilize these methods for both player and AI.

## Calculate Score Overview

We calculate all available adjacent spots from an initial point.
We use Update Board methods but we don't update, just find amount of available spots for each direction.

## AI Overview

1) Find every available adjacent point from A
2) Store all available adjacent points in an int array, where 0 is not available, 1 is available
2) Loop through array of available points and calculate the amount of spaces reached in each direction for each adjacent point
3) Find adjacent spoint that can "reach" the most amount of spaces (ie. deduct the most spots)
4) Pick AI as that point
