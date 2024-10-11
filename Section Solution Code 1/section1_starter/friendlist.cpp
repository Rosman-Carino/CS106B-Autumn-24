/*
 * CS106B Section Handout Test Harness: Section 1
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "map.h"
#include "vector.h"
#include "set.h"
#include "filelib.h"
#include "strlib.h"
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
using namespace std;

/*
 * Friend List (Code Write)
 * ----------------------------------
 * Write a function named friendList that takes in a file name and reads
 * friend relationships from a file and writes them to a Map.
 * friendList should return the populated Map. Friendships are bi-directional.
 * The file contains one friend relationship per line, with names separated
 * by a single space. You do not have to worry about malformed entries.
 */

Map<string, Set<string>> friendListReference(string filename){
    // Step 1: Read the file and populate it into a Vector of lines
    ifstream in;
    Vector<string> lines;
    if (openFile(in, filename)) { // openFile is similar to Python's open()
        lines = readLines(in);
    }
    // Step 2 Declare our Map where
    // Key: Person, Value: Set of Friends(string)
    Map<string, Set<string>> friendsMap;

    // Step 3: Iterate through 'lines;
    for (string line : lines) {
        // Need to call stringSplit() to tokenize each string by the
        // delimiter/seperator which is a space " "
        Vector<string> people = stringSplit(line, " ");
        string person1 = people[0];
        string person2 = people[1];
        // We are getting a reference to the address of the friendsMap
        // This not is for folks that have taken CS106A. We teach them this
        // when dealing with an ADT as their value.
        Set<string> &person1Friends = friendsMap[person1];
        Set<string> &person2Friends = friendsMap[person2];
        person1Friends.add(person2);
        person2Friends.add(person1);
    }
    return friendsMap;
}


Map<string, Set<string>> friendsListV1(string filename){
    // Step 1: Read the file and populate it into a Vector of lines
    ifstream in;
    Vector<string> lines;
    if (openFile(in, filename)) { // openFile is similar to Python's open()
        lines = readLines(in);
    }
    // Step 2 Declare our Map where
    // Key: Person, Value: Set of Friends(string)
    Map<string, Set<string>> friendsMap;

    // Step 3: Iterate through 'lines;
    for (string line : lines) {
        // Need to call stringSplit() to tokenize each string by the
        // delimiter/seperator which is a space " "
        Vector<string> people = stringSplit(line, " ");
        string person1 = people[0];
        string person2 = people[1];

        // Add each person to the map - Using the Unified Approach
        if (!friendsMap.containsKey(person1)) {
            friendsMap[person1] = {};
        }
        if (!friendsMap.containsKey(person2)) {
            friendsMap[person2] = {};
        }

        // Add the person to each person's respective friend's set.
        // Recall Sets do not allow for duplicates
        friendsMap[person1].add(person2);
        friendsMap[person2].add(person1);
    }
    return friendsMap;
}





///* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("provided test case from handout for friendList") {
    Map<string, Set<string>> soln;
    soln["Abby"] = {"Barney", "Clyde"};
    soln["Barney"] = {"Abby"};
    soln["Clyde"] = {"Abby"};
    EXPECT_EQUAL(soln, friendsListV1("res/buddies.txt"));
}

