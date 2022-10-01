#pragma once
#include <map>
#include <string>

class RansomNote
{
public:
    bool canConstructRansomNote(std::string Sample, std::string Result) {

        // loop through sample and get a map count

        //      abcdef      ab cd ef
        //      aace        a  c  e

        std::map<char, int> CharMap;

        for (char& c : Sample)
        {
            CharMap[c]++;
        }

        //for loop through result
        // if theres a space ignore it
        // if we dont have enough return false
        // else true
        for (char& c : Result) {        // a 1       a 0

            if (c == ' ') { continue; }
            // if
            CharMap[c]--;
            if (CharMap[c] > 0) { return false; }
        }

        return true;
    }
};

