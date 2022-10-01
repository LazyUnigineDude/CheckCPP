#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <bitset>

std::pair<size_t, size_t> Next_Empty(std::vector<std::vector<char>>& Storage,
    size_t R, size_t C);
  int Get_Cell(int R, int C);

class SudokuChallenge
{
public:
    SudokuChallenge() {}
    ~SudokuChallenge() {}

    std::vector<std::vector<char>> Get_File_Name();
    std::vector<std::vector<char>> Get_Value_From_Text(std::string FileName);
    void Visualize_Sudoku(std::vector<std::vector<char>> Storage);
    static bool Solve_Recursion(std::vector<std::vector<char>>& Storage,
        size_t R, size_t C,
        std::array<std::bitset<9>, 9>& Rows,
        std::array<std::bitset<9>, 9>& Cols,
        std::array<std::bitset<9>, 9>& Cell);


    void Show_Solved_Sudoku(std::vector<std::vector<char>>& Storage);
    void Solve_Sudoku(std::vector<std::vector<char>>& Storage);
    void MainLoop(std::vector<std::vector<char>> Storage, char c);

};

// FILESYSTEM
//===========================================================================
std::vector<std::vector<char>> SudokuChallenge::Get_File_Name() {
    std::string TextName;
    std::cout << "Hi! Simple Sudoku Solver.\n\n\n";
    std::cout << "Sample text name is \"SudokuSample.txt\" or \"SudokuSample2.txt\" or \"SudokuSample3.txt\" \n";
    std::cout << "There should be no spaces between the numbers and 9 numbers in sequences. 0 for blanks\n\n\nEnter FileName: ";
    std::cin >> TextName;

    return Get_Value_From_Text(TextName);
}

std::vector<std::vector<char>> SudokuChallenge::Get_Value_From_Text(std::string FileName) {
    std::vector<std::vector<char>> File;

    std::fstream TextFile;
    std::string line;
    std::vector<char> _c;
    TextFile.open(FileName, std::ios::in);

    if (TextFile.is_open()) {
        while (std::getline(TextFile, line)) {
            for (const char& c : line) {

                if (isdigit(c)) {

                    if (c == '0') { _c.push_back('.'); }
                    else _c.push_back(c);
                    //std::cout << c << " ";
                }
            }
            //std::cout << "\n";
            File.push_back(_c);
            _c.clear();
        }
        TextFile.close();
    }

    else { std::cout << "File Does Not Exist, Try Again\n\n\n\n"; system("cls"); Get_File_Name(); }

    return File;
}


// SUDOKU STUFF
//=======================================================================
void SudokuChallenge::Visualize_Sudoku(const std::vector<std::vector<char>> Storage) {
    system("cls");

    std::cout << "Your Sudoku:  \n\n\n\n\n";

    for (auto& V : Storage) {
        for (const char& c : V)
        {
            if (c == '0') { std::cout << "  . "; }
            else std::cout << c << "  ";
        }
        std::cout << "\n";
    }

}
// Cell Get
int Get_Cell(int R, int C) { return (R / 3) * 3 + C / 3; }


void SudokuChallenge::Solve_Sudoku(std::vector<std::vector<char>>& Storage) {

    //Bit Manipulate
    std::array<std::bitset<9>, 9> Rows; Rows.fill(0);
    std::array<std::bitset<9>, 9> Cols; Cols.fill(0);
    std::array<std::bitset<9>, 9> Cell; Cell.fill(0);

    for (int x = 0; x < 9; ++x) // SET DIGIT MANIP
    {
        for (int y = 0; y < 9; ++y)
        {
            char digit = Storage[x][y];
            if (digit != '.') {

                size_t Digit = digit - '1';

                Rows[x].set(Digit);
                Cols[y].set(Digit);
                size_t _Cell = Get_Cell(x, y);
                Cell[_Cell].set(Digit);
                // WORKS
              // std::cout << x / 2 << " " << y << "  " << _Cell << "          ";
              //std::cout << Rows[x/2] << "  " << Cols[y] << "  " << Cell[_Cell] ;
            }
            //std::cout << "\n";
        }
        // std::cout << "\n";
    }
    //RECURSION ITERATE

    Solve_Recursion(Storage, 0, 0, Rows, Cols, Cell);
}

bool SudokuChallenge::Solve_Recursion(std::vector<std::vector<char>>& Storage,
    const size_t R, const size_t C,
    std::array<std::bitset<9>, 9>& Rows,
    std::array<std::bitset<9>, 9>& Cols,
    std::array<std::bitset<9>, 9>& Cell) {

    //CHECK         WORKS
    auto Cell_ = Next_Empty(Storage, R, C);
    //std::cout << Cell_.first << "    " << Cell_.second;
    //system("pause");


    if (Cell_.first == 9) { return true; }

    int __Cell = Get_Cell(Cell_.first, Cell_.second);

    // SOLVE BIT MANIPULATION
    std::bitset<9> Contain = Rows[Cell_.first] | Cols[Cell_.second] | Cell[__Cell];
    if (Contain.all()) { return false; }


    for (size_t i = 0; i < 9; ++i)
    {

        if (!Contain[i]) {
            // Use Cell Check to CHANGE
            Storage[Cell_.first][Cell_.second] = static_cast<char>(i + '1');
            Rows[Cell_.first].set(i);
            Cols[Cell_.second].set(i);
            Cell[__Cell].set(i);

            // RECURSION
            if (Solve_Recursion(Storage, Cell_.first, Cell_.second, Rows, Cols, Cell)) { return true; }

            //UNDO CHANGE if false
            Rows[Cell_.first].reset(i);
            Cols[Cell_.second].reset(i);
            Cell[__Cell].reset(i);

        }
    }

    // IF ALL GUESS FAILS RESET TO 0
    Storage[Cell_.first][Cell_.second] = '.';
    return false;

}

size_t returnR(size_t R, size_t C) { return R + (C + 1) / 9; }
size_t returnC(size_t C) { return (C + 1) % 9; }

std::pair<size_t, size_t> Next_Empty(std::vector<std::vector<char>>& Storage,
    size_t R, size_t C) {
    // FIND NEXT EMPTY
    while (R != 9) {

        if (Storage[R][C] == '.') {
            return { R,C };
        }
        R = returnR(R, C);
        C = returnC(C);
    }

    return { 9,0 };
}



//====================================================================
void SudokuChallenge::Show_Solved_Sudoku(std::vector<std::vector<char>>& Storage) {
    system("pause");
    system("cls");

    std::cout << "Your Sudoku Solved:  \n\n\n\n\n";

    for (auto& V : Storage) {
        for (const char& c : V)
        {
            std::cout << c << "  ";
        }
        std::cout << "\n";
    }

}

void SudokuChallenge::MainLoop(std::vector<std::vector<char>> Storage, char c) {

    bool isQuit = false;

    do {
        std::cout << "\n\n\nPress S to Solve\nQ to Quit\nF for NewFile\n\n\n";
        std::cin >> c;

        if (c == 'S' || c == 's') {
            std::cout << "Solving the Sudoku...Please Wait.\n";
            Solve_Sudoku(Storage);
            Show_Solved_Sudoku(Storage);
            system("pause");
        }

        else if (c == 'F' || c == 'f') {
            system("cls");
            Storage = Get_File_Name();
            Visualize_Sudoku(Storage);
        }

        else if (c == 'Q' || c == 'q') { isQuit = !isQuit; }

        else { std::cout << "Please Enter Again.\n\n\n"; }

    } while (!isQuit);
}