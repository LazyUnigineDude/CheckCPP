#pragma once

// CXX17
// Variadic Expression
template <typename T>
T findTotal(T lastone) {
    return lastone;
}

template <typename T, typename ...p>
T findTotal(T head, p ...tail) { // fold expressions

    if (sizeof...(tail))
        head += findTotal(tail...);
    return head;
}