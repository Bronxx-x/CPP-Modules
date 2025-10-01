
#include "Span.hpp"


Span::Span() : max_size(0) {}
Span::Span(unsigned int n) : max_size(n) {}
Span::Span(const Span& other) : numbers(other.numbers), max_size(other.max_size) {}
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers = other.numbers;
        max_size = other.max_size;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int n) {
    if (numbers.size() >= max_size) {
        throw std::out_of_range("Cannot add more numbers, span is full.");
    }
    numbers.push_back(n);
}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    std::vector<int> sorted_numbers = numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    int min_span = INT_MAX;
    for (size_t i = 1; i < sorted_numbers.size(); ++i) {
        int span = sorted_numbers[i] - sorted_numbers[i - 1];
        if (span < min_span) {
            min_span = span;
        }
    }
    return min_span;
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    int min_num = *std::min_element(numbers.begin(), numbers.end());
    int max_num = *std::max_element(numbers.begin(), numbers.end());
    return max_num - min_num;
}