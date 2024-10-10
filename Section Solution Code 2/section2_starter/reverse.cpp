/*
 * Author: Rosman R Cariño
 * CS106B Section Handout Test Harness: Section 8
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
#include "SimpleTest.h"
#include "lexicon.h"
#include "error.h"
using namespace std;

/*
 * Container Classes Review (Code Writing)
 * --------------------------------------------------------
 * Write a function that is given a Map<string, int> that associates
 * string values with integers and produces a Map<int, Set<string>>
 * that’s essentially the reverse mapping, associating each integer
 * value with the set of strings that map to it. (This is an old job
 * interview question from 2010.)
 */
/**
 * @brief reverseMapV1: Using the Unified Approach
 * @param map
 * @return
 */
Map<int, Set<string>> reverseMapV1(Map<string, int>& map) {
    Map<int, Set<string>> result;
    for (string oldKey : map) {
        if (!result.containsKey(map[oldKey])) {
            result[map[oldKey]] = {};
        }
        result[map[oldKey]].add(oldKey);
    }
    return result;
}
/**
 * @brief reverseMapV2: Using If/Else Approach
 * @param map
 * @return
 */
Map<int, Set<string>> reverseMapV2(Map<string, int>& map) {
    Map<int, Set<string>> result;
    for (string oldKey : map) {
        if (result.containsKey(map[oldKey])) {
            result[map[oldKey]].add(oldKey);
        } else {
            result[map[oldKey]] = {oldKey};
        }
    }
    return result;
}
/**
 * @brief reverseMapV3: Optimal Version taking advantage of Stanford Library
 *                  Documentation. If a key is not a map, then it will auto
 *                  initialize it.
 * @param map
 * @return result
 */
Map<int, Set<string>> reverseMapV3(Map<string, int>& map) {
    Map<int, Set<string>> result;
    for (string oldKey : map) {
        result[map[oldKey]].add(oldKey);
    }
    return result;
}


PROVIDED_TEST("Simple Tests for Reversing Map") {
    Map<string, int> map = {{"foo", 4}, {"bar", 4}, {"baz", 3}};
    Map<int, Set<string>> reversed = reverseMap(map);
    Map<int, Set<string>> soln = {{4, {"bar", "foo"}}, {3, {"baz"}}};

    EXPECT_EQUAL(reversed, soln);

    map = {};
    reversed = reverseMapV3(map);
    soln = {};
    EXPECT_EQUAL(reversed, soln);
}

PROVIDED_TEST("Simple Tests for Reversing Map") {


    Map<string, int> map = {{"Michael", 100}, {"Pam", 500},
                            {"Dwight", 500}, {"Kelly", 1000}
                            };



    Map<int, Set<string>> reversed = reverseMap(map);



    Map<int, Set<string>> soln = {{100, {"Michael"}},
                                  {500, {"Pam", "Dwight"}},
                                  {1000, {"Kelly"}}
                                };

    EXPECT_EQUAL(reversed, soln);

    map = {};
    reversed = reverseMapV3(map);
    soln = {};
    EXPECT_EQUAL(reversed, soln);
}
