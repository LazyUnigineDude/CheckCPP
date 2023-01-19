#include <iostream>
#include <vector>

using namespace std;

struct vec2 {
    int x, y;
    vec2() = default;
    vec2(int x, int y) { this->x = x; this->y = y; }
};

vector<vec2> sort(int k, vector<vec2> posRes) {

    vector<vec2> ans;
    for (int i = 0; i < posRes.size(); i++) {

        if (posRes[i].y <= k)
            ans.push_back(posRes[i]);
        else {
            vec2 _x;
            _x.x = posRes[i].x;
            _x.y = posRes[i].y - k;
            posRes.erase(posRes.begin() + i);
            posRes.push_back(_x);
          return sort(k, posRes);
        }
    }
    return ans;
}

vector<int> getFinalOrder(int k, vector<int> amount) {

    vector<int> res;
    vector<vec2> posRes;

    for (int i = 0; i < amount.size(); i++) {
        vec2 _x;
        _x.x = i + 1;
        _x.y = amount[i];
        posRes.push_back(_x);
    }

    posRes = sort(k, posRes);
    for (auto& i : posRes) {
        res.push_back(i.x);
    }
    return res;
}

//template <typename T>
//T findTotal(T lastone) {
//    return lastone;
//}
//
//template <typename T, typename ...p>
//T findTotal(T head, p ...tail) { // fold expressions
//
//    if (sizeof...(tail))
//        head += findTotal(tail...);
//    return head;
//}
//
//int main() {
//    double total = findTotal(2.17, 3.0, 4.5, 3.14);
//    std::cout << total;
//}

//using func_ptrs = void(*)();
//
//void fx(), fy(), fz();
//
//func_ptrs functions[3] = { fx, fy, fz };
//void x() {
//    for (int i = 0; i < 3; i++)
//    {
//        functions[i]();
//    }
//}

class V { public: ~V() { std::cout << "V\n"; } };
class E { public: ~E() { std::cout << "E\n"; } };
class T : V { public: ~T() { std::cout << "T\n"; } private: E e; };


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

     


    return 0x14;
}

int main() {

    // T Trusc;
    //vector<vector<string>> paths = { {"London", "New York"} ,{"New York", "Lima"},{"Lima", "Sao Paulo" }};
    vector<vector<int>> grids = { {0,0,1,1},{1,0,1,0},{1,1,0,0} };
    std::cout << matrixScore(grids);
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