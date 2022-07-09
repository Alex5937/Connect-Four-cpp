# **Connectfour**

## **Introduce**

> Connect-Four is a tic-tac-toe-like two-player game in which players alternately place pieces on a vertical board 7 columns across and 6 rows high. Each player uses pieces of a particular color (commonly black and red, or sometimes yellow and red), and the object is to be the first to obtain four pieces in a horizontal, vertical, or diagonal line. Because the board is vertical, pieces inserted in a given column always drop to the lowest unoccupied row of that column. As soon as a column contains 6 pieces, it is full and no other piece can be placed in the column.

## **Rundown**

>1. Decide which player starts.
>2. Change Player name or charater.  
>3. Players will alternate turn after playing a checker.
>4. On your turn, drop one of your checkers down any of the slots in the top of the grid.
>5. Players alternates until one player gets 4 checkers of his color in a row horizontally, vertically or diagonally.

```mermaid
graph TD
A[Input charater] --> B[Check position]
    B --> |win=1| D[win]
    B --> |full=7| E[draw]
    B --> |else| F[Place checker]
    G(Process)
