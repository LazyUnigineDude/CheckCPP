#pragma once

// Variadic Expressions
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

// Repeat till final overloaded Function for ... types