//
//  string-utils.h
//
//  A simple string manipulation library for C++
//  Author: Adam Harbin

#include <vector>
#include <string>

namespace strutl {
    
    // Splits the given string into a vector of strings breaking by the
    // separator parameter.  If the separator is the empty string (default
    // value), then the string is split into its component characters
    std::vector<std::string> split(std::string strToSplit, std::string separator = "");

    // Strips characters from the beginning of the given string belonging to the
    // charsToStrip parameter (default space)
    std::string lstrip(std::string, std::string charsToStrip = " ");
    
    // Strips characters from the end of the given string belonging to the
    // charsToStrip parameter (default space)
    std::string rstrip(std::string, std::string charsToStrip = " ");

    // Strips characters from both the beginning and end of the string as 
    // in lstrip/rstrip
    std::string strip(std::string, std::string charsToStrip = " ");

    // Removes all instances of the given characters from a string
    std::string removec(std::string, std::string charsToRemove = " ");
}
