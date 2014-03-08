#include "string-utils.h"
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

using namespace strutl;

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
}
