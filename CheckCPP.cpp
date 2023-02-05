#include <iostream>
#include "Multithreading.h"

using namespace std;

using func_ptrs = void(*)();
void fx(), fy(), fz();

func_ptrs functions[3] = { fx, fy, fz };
void x() {
    for (int i = 0; i < 3; i++)
    {
        functions[i]();
    }
}




#include <unordered_set>
std::string destCity(vector<vector<string>>& paths) {
    std::unordered_set<std::string> left;

    for (auto &i: paths) {  left.insert(i[0]); }
    for (auto &i: paths) {  if (!left.count(i[1])) return i[1]; }
    return "";
}

//      0   0   1   1       1   1   0   0       1   1   1   0       1   1   1   1
//      1   0   1   0       1   0   1   0       1   0   0   0       1   0   0   1
//      1   1   0   0       1   1   0   0       1   1   1   0       1   1   1   1

int matrixScore(vector<vector<int>>& grid) {

    // Change All rows so the first is always one
    // then manage columns

    return 0x14;
}


int main() {

    //vector<vector<string>> paths = { {"London", "New York"} ,{"New York", "Lima"},{"Lima", "Sao Paulo" }};
  //  vector<vector<int>> grids = { {0,0,1,1},{1,0,1,0},{1,1,0,0} };
  //  std::cout << matrixScore(grids);

}


//
//int main() {
//
// //   vector<int> amount = { 2,5,1 };
// //   vector<int> res = getFinalOrder(2, amount);
//
//	//for (auto& i : res)
//	//{
//	//	std::cout << i << "\n";
//	//}
//
//    double d = 8.83;
//    int i = static_cast<int>(d);
//    std::cout << i;
//
//	return 0;
//}