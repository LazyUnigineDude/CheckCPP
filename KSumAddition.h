// Check2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  OMAR JAVED: Time Started at 3:00PM March 16
//              Time Taken: 36 minutes
//              Got lost with char conversion then remembered the ASCII convert

#include <iostream>
#include <string>
#include <vector> // STACK

class KSumAddition {
public:
    KSumAddition() {}
    ~KSumAddition() {}

    std::string Calculate(std::string a, std::string b, int k) {

        //  CONSTRAINTS
        /*
            a and b are 0-9 and less than k
            Length: 0 << (a || b) << 100
            2 << k << 10

            No need to check for non number string char in a or b

            length between 2 : 10 restricts the other numbers
            so no need to check that too

            no need to check for exception error if lengths are different

            Using String and vector for Stacking Chars
        */
        std::string Answer = "";  // ANSWERS
        std::vector<int> RES;     // RESULT STACK


        int x = a.length(), y = b.length(), diff = abs(x - y), CarryOver = 0;


        // ADD 0 INFRONT TO REMOVE NULL EXCEPTIONS
        if (x > y) {
            std::string Extra;
            for (int i = 0; i < diff; i++) { Extra += "0"; }
            b = Extra + b;
        }
        else {
            std::string Extra;
            for (int i = 0; i < diff; i++) { Extra += "0"; }
            a = Extra + a;
        }



        // LOGIC
        for (int i = a.length() - 1; i >= 0; i--) {
            // ASCII LOGIC CONVERT TO INT
            int x = a[i] - '0' + b[i] - '0' + CarryOver;
            int DigitHolder = x % k;
            CarryOver = (x / k);

            /*
            // CHECK
            std::cout << a[i] << "     " << b[i] << "    ";
            std::cout << x << "       ";
            std::cout << DigitHolder << "    ";
            std::cout << CarryOver << " \n";*/

            // ADD TO STACK
            RES.push_back(DigitHolder);
        }
        // REMAINDER IF LEFT
        if (CarryOver > 0) { RES.push_back(CarryOver); }

        // APPEND STRING VIA STACK RANGE
        for (auto& i : RES) {
            Answer += RES.back() + '0';
            RES.pop_back();
        }


        // TIME COMPLEXITY   O(a.length)
        // SPACE COMPLEXITY  O(1)

        return Answer + "\n";
    }


    int Check()
    {
        std::cout << "Hello World!\n";


        std::cout << Calculate("0", "0", 2);
        std::cout << Calculate("11", "1", 2);
        std::cout << Calculate("12", "9", 10);
        std::cout << Calculate("9", "1", 10);
        std::cout << Calculate("264", "453", 7);
        std::cout << Calculate("888", "222", 9);
        std::cout << Calculate("584", "246", 9);
        std::cout << Calculate("315", "4541353", 6);
        std::cout << Calculate("842688", "257232", 9);
        std::cout << Calculate("5557384", "546", 9);
    }
};