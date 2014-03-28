#include "string-utils.h"
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

using namespace strutl;

bool testRemoveMult() {
    string s = removec("aabbaacccaaddd", "bcd");
    if(s != "aaaaaa") { return false; }

    return true;
}

bool testRemoveC() {
    string s = removec("abaca","a");
    if(s != "bc") { return false; }

    return true;
}

bool testStrip() {
    string strippedStr = strip("aabbcc","ac");
    if(strippedStr != "bb") { return false; }

    return true;
}

bool testRStripEmptyString() {
    string strippedStr = rstrip("","c");
    if(strippedStr != "") { return false; }

    return true;
}

bool testRStripEmptyChars() {
    string strippedStr = rstrip("aabbcc","");
    if(strippedStr != "aabbcc") { return false; }

    return true;
}

bool testRStripAll() {
    string strippedStr = rstrip("aabbcc","abc");
    if(strippedStr != "") { return false; }

    return true;
}

bool testRStrip() {
    string strippedStr = rstrip("aabbcc","c");
    if(strippedStr != "aabb") { return false; }

    return true;
}

bool testLStrip() {
    string strippedStr = lstrip("aaabbcc","a");
    if(strippedStr != "bbcc") { return false; }

    return true;
}

bool testLStripEmtpyString() {
    string strippedStr = lstrip("","a");
    if(strippedStr.length() != 0) { return false; }

    return true;
}

bool testLStripEmptyChars() {
    string strippedStr = lstrip("aaabbcc","");
    if(strippedStr != "aaabbcc") { return false; }
    
    return true;
}

bool testLStripDefaultValue() {
    string strippedStr = lstrip("  aaabbcc");
    if(strippedStr != "aaabbcc") { return false; }

    return true;
}

bool testLStripAll() {
    string strippedStr = lstrip("aaaaa","a");
    if(strippedStr != "") { return false; }

    return true;
}

bool testSeparatorNotFound() {
    vector<string> splitStr = split("ABCDE", ":");
    if(splitStr.size() != 1) { return false; }
    if(splitStr[0] != "ABCDE") { return false; }
    
    return true;
}

bool testSplit() {
    vector<string> splitStr = split("A:B:C", ":");
    if(splitStr.size() != 3) { return false; }
    if(splitStr[0] != "A") { return false; }
    if(splitStr[1] != "B") { return false; }
    if(splitStr[2] != "C") { return false; }

    return true;
}

bool testEmptyString() {
    vector<string> splitStr = split("", ":");
    if(splitStr.size() != 0) { return false; }

    return true;
}

bool testEmptySeparator() {
    vector<string> splitStr = split("A:B:C");
    if(splitStr.size() != 5) { return false; }
    if(splitStr[0] != "A") { return false; }
    if(splitStr[1] != ":") { return false; }
    if(splitStr[2] != "B") { return false; }
    if(splitStr[3] != ":") { return false; }
    if(splitStr[4] != "C") { return false; }

    return true;
}

void test(const std::string name, bool passed) {
    if(passed) {
        cout << "[Passed] " << name << endl;
    }
    else {
        cout << "[Failed] " << name << endl;
    }
}

int main() {
    test("Split: Simple Case", testSplit());
    test("Split: Empty String", testEmptyString());
    test("Split: Emtpy Separator", testEmptySeparator());
    test("Split: Separator not found", testSeparatorNotFound());
    test("Left Strip: Simple Case", testLStrip());
    test("Left Strip: Empty String", testLStripEmtpyString());
    test("Left Strip: Empty Strip chars", testLStripEmptyChars());
    test("Left Strip: Default parameter value", testLStripDefaultValue());
    test("Left Strip: Strip All", testLStripAll());
    test("Right Strip: Simple Case", testRStrip());
    test("Right Strip: Empty String", testRStripEmptyString());
    test("Right Strip: Empty Strip chars", testRStripEmptyChars());
    test("Right Strip: Strip All", testRStripAll());
    test("Strip: Simple Case", testStrip());
    test("Remove Char: Simple Case", testRemoveC());
    test("Remove Char: Multiple Chars", testRemoveMult());
}
