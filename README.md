# **Connectfour**

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
