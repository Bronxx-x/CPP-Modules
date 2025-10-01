
#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <exception>
#include <climits>


class Span {
    private:
        std::vector<int> numbers;
        unsigned int max_size;
        Span();
    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();

        template <typename iterator>
        void addNumbers(iterator begin, iterator end) {
            for (iterator it = begin; it != end; ++it) {
                if (numbers.size() >= max_size) {
                    throw std::out_of_range("Cannot add more numbers, span is full.");
                }
                numbers.push_back(*it);
            }
        }
};

#endif