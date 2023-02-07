#pragma once

// CXX17
// Variadic Expression
template <typename T>
T findTotal(T lastone) {
    return lastone;
}

template <typename T, typename ...p>
T findTotal(T head, p ...tail) { 
    // variyadic template list

    if (sizeof...(tail))
        head += findTotal(tail...);
    return head;
}

template <typename ...T>
auto sum(T ...p) {
    return (p + ...);
    // pack op ...
    // Unurary Left fold
}

template <typename ...T>
auto sum2(T ...p) {
    return (... + p);
    //      ... op pack
    // Uni Right Fold
}

template <typename ...list >
void Print(list ...args) {
    (std::cout << ... << args) << "\n";
  //    INIT   op ... op pack
    // Binary left fold
}

template <typename ... T>
auto minusOne(T ... p)
{
    return (p - ... - 0);
  //    pack op ... op INIT
    // Binary Right fold
}