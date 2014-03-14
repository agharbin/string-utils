//
// string-utils.cpp
//
// A simple string manipulation library for C++
// Author: Adam Harbin

#include "string-utils.h"

using std::string;
using std::vector;

namespace strutl {
    vector<string> split(string strToSplit, string separator){
        vector<string> result;
        size_t separatorPos = 0;
        size_t substrBeginPos = 0;
        size_t sizeOfSeparator = separator.length();

        if(strToSplit.length() != 0) {
            if(separator.length() != 0) {
                // Non-empty separator
                separatorPos = strToSplit.find(separator, 0);

                while(separatorPos != string::npos) {
                    // Add substring to vector
                    result.push_back(strToSplit.substr(substrBeginPos,
                                                       separatorPos - substrBeginPos));

                    // Find next substring
                    substrBeginPos = separatorPos + sizeOfSeparator;
                    separatorPos = strToSplit.find(separator, substrBeginPos);
                }
                // Add last segment of the string
                result.push_back(strToSplit.substr(substrBeginPos, string::npos));
            }
            else {
                // Emtpy separator
                for(int i = 0; i < strToSplit.length(); i++){
                    result.push_back(strToSplit.substr(i, 1));
                }
            }
        }
        return result;
    }

    string lstrip(string strToStrip, string charsToStrip) {
        string result;
        size_t stripEndPos = strToStrip.find_first_not_of(charsToStrip);
        if(stripEndPos != string::npos) {
            result = strToStrip.substr(stripEndPos);
        }
        return result;
    }

    string rstrip(string strToStrip, string charsToStrip) {
        string result;
        size_t stripBeginPos = strToStrip.find_last_not_of(charsToStrip);
        if(stripBeginPos != string::npos){
            result = strToStrip.substr(0,stripBeginPos+1);
        }

        return result;
    }

    string strip(string strToStrip, string charsToStrip){
        return rstrip(lstrip(strToStrip,charsToStrip),charsToStrip);
    }
}
