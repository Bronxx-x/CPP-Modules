/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:40:33 by yousef            #+#    #+#             */
/*   Updated: 2025/09/22 15:50:27 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void printIntConst(const int &x) { std::cout << "const print: " << x << '\n'; }
void incInt(int &x) { x += 1; }

template <typename U>
void printTemplate(const U &x) { std::cout << "templ: " << x << '\n'; }

struct PrintStr {
    void operator()(const std::string &s) const { std::cout << "functor: " << s << '\n'; }
};

void printChar( char c) { std::cout << "char: " << c + '0' << '\n'; }

int main()
{
    void (*fptr)(char c);
    fptr = &printChar;
    int a[] = {1, 2, 3, 4};
    iter(a, 4, fptr);
    std::cout << "original a:\n";
    iter(a, 4, printTemplate<int>);     
    iter(a, 4, printIntConst);          
    iter(a, 4, incInt); 
    std::cout << "after incInt:\n";
    iter(a, 4, printTemplate<int>);

    const int ca[] = {10, 20, 30};
    std::cout << "const array ca:\n";
    iter(ca, 3, printIntConst);

    std::string s[] = {"one", "two", "three"};
    iter(s, 3, PrintStr());
    iter(s, 3, printTemplate<std::string>); 
    return 0;
}
