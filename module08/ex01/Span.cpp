/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:16:30 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 17:44:08 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other) : _n(other._n), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _n = other._n;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _n) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() {
    if (_numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }
    std::vector<int> sorted_numbers = _numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    int min_span = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted_numbers.size(); ++i) {
        int span = sorted_numbers[i] - sorted_numbers[i - 1];
        if (span < min_span) {
            min_span = span;
        }
    }
    return min_span;
}

int Span::longestSpan() {
    if (_numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }
    int min_number = *std::min_element(_numbers.begin(), _numbers.end());
    int max_number = *std::max_element(_numbers.begin(), _numbers.end());
    return max_number - min_number;
}

void Span::fill_with_range_of_iterators(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) > static_cast<long>(_n - _numbers.size())) {
        throw SpanFullException();
    }
    _numbers.insert(_numbers.end(), begin, end);
}

const char *Span::SpanFullException::what() const throw() {
    return "Span is full. Cannot add more numbers.";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return "Not enough numbers to calculate a span.";
}