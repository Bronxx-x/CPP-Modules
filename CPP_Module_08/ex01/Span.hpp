
#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <exception>

class Span {
    private:
        std::vector<int> numbers;
        unsigned int max_size;
    public:
        Span(unsigned int n);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
};

#endif