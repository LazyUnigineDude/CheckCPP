#pragma once
#include <string>
#include <unordered_set>

std::string destCity(std::vector<std::vector<std::string>>& paths) {
    std::unordered_set<std::string> left;

    for (auto& i : paths) { left.insert(i[0]); }
    for (auto& i : paths) { if (!left.count(i[1])) return i[1]; }
    return "";
}

//vector<vector<string>> paths = { {"London", "New York"} ,{"New York", "Lima"},{"Lima", "Sao Paulo" }};