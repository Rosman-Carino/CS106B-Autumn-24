/*
 * Author: Rosman R Cariño
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "SimpleTest.h"
#include "grid.h"
#include "gridlocation.h"
#include "hashmap.h"
using namespace std;

/*
 * waysToEscape (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named countWaysToEscape​ that returns the 
 * total number of ways to escape a maze, if we can only move south
 * and east at any position in the maze. The input is a grid of booleans
 * representing a maze, and a gridLocation representing where we are
 * starting from.
 */



int countWaysToEscapeV1(Grid<bool>& maze, GridLocation location) {
    // Base Case: Failure 1 -> Current Location is Out-of-Bounds
    if (!maze.inBounds(location)) {
        return 0;
    }

    // Base Case : Failure 2 -> Current Location is a Wall
    if (!maze[location]) {
        return 0;
    }

    // Base: Success - At the Exit
    if (location == GridLocation{maze.numRows() - 1,
                                 maze.numCols() -1}) {
        return 1;
    }

    // Recursive Calls: What choices can I make? South & East are my choices.
    int south = countWaysToEscapeV1(maze, {location.row + 1,
                                         location.col});
    int east = countWaysToEscapeV1(maze, {location.row,
                                        location.col + 1});
    int total = south + east; // Aggregate both choices
    return total;
}


int countWaysToEscapeV2(Grid<bool>& maze, GridLocation location) {
    // Base Case: Failure 1 -> Current Location is Out-of-Bounds
    // or  Failure 2 -> Current Location is a Wall
    if (!maze.inBounds(location) ||
        !maze[location]) return 0;

    // Base: Success - At the Exit
    if (location == GridLocation{maze.numRows() - 1,
                                 maze.numCols() -1}) {
        return 1;
    }

    // Recursive Calls: What choices can I make? South & East are my choices.
    int south = countWaysToEscapeV1(maze, {location.row + 1,
                                           location.col});
    int east = countWaysToEscapeV1(maze, {location.row,
                                          location.col + 1});
    int total = south + east; // Aggregate both choices
    return total;
}




/* * * * * Provided Tests Below This Point * * * * */
PROVIDED_TEST("Test ways to escape") {
    Grid<bool> maze = {{true, true, true}, {true, true, true}};
    EXPECT_EQUAL(countWaysToEscapeV2(maze, {0,0}), 3);

    maze = {{true, true, true}, {true, true, false}};
    EXPECT_EQUAL(countWaysToEscapeV2(maze, {0,0}), 0);

    maze = {{true, true, true}, {true, false, true}};
    EXPECT_EQUAL(countWaysToEscapeV2(maze, {0,0}), 1);

    maze = {{true, true, true}, {false, true, true}};
    EXPECT_EQUAL(countWaysToEscapeV2(maze, {0,0}), 2);

    Grid<bool> longMaze {
        {true, true, true, true},
        {true, true, true, true},
        {true, true, true, true},
        {true, true, true, true}
    };
    EXPECT_EQUAL(countWaysToEscapeV2(longMaze, {0,0}), 20);

    Grid<bool> simpleMaze {
        {true, true, false},
        {true, true, true}
    };
    EXPECT_EQUAL(countWaysToEscapeV2(simpleMaze, {0,0}), 2);

}


