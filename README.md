# Project Battleship

## Description

This is a Battleship CLI game with a lot of move validators. All these functions make it easy to play. Get ready and set your ships! Your opponent waits for you. All the rules about setting your ship and shooting opponent you will find after typing `-h` flag whenever you want. 

This project is a documentation of my learning process about the C language. You can find here some operations with binary files, a lot of pointers, structures, use of quick sort and much more. I used [CRT library](https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx) to find out if there are no memory leaks. I tried to make it as clean as possible.

If you can see some drama, some obvious bug or some bad habit tell me! I would be very glad if you do. It is all about learning.

## Used characters as fields

```
'	- you do not know yet what it is
~	- water field
#	- a ship or its part
X	- killed ship
```

## How to build and run it?

1. Clone this repository.
2. Add all files from the `app` folder to the empty project in your IDE and compile it as `*.c` files.
3. Have fun time while playing!

Use these flags:
- `-h` or `--help` to get help with flags
- `-l` or `--load` to load previously saved game
- `-s` or `--highScores` to print high scores
- none just to run the game

## Points counting

Here is how points are counted:
```c
int countPoints(GameBoard* gameBoard) {
	const int MAX_NUMBER_OF_TURNS = boardSize * boardSize;
	const int MIN_NUMBER_OF_TURNS = numberOfShips;
	
	return MAX_NUMBER_OF_TURNS + MIN_NUMBER_OF_TURNS - gameBoard->numberOfTurns;
}
```

## Here is how the game looks like

![screenshot](https://raw.githubusercontent.com/franpog859/battleship/master/doc/screenshot.png)