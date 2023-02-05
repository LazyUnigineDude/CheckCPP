#pragma once
#include <vector>

struct vec2 {
    int x, y;
    vec2() = default;
    vec2(int x, int y) { this->x = x; this->y = y; }
};

std::vector<vec2> sort(int k, std::vector<vec2> posRes) {

    std::vector<vec2> ans;
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

std::vector<int> getFinalOrder(int k, std::vector<int> amount) {

    std::vector<int> res;
    std::vector<vec2> posRes;

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