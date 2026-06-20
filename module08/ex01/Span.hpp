/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:09:33 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 17:26:13 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>

class Span {
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void fill_with_range_of_iterators(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    private:
        unsigned int _n;
        std::vector<int> _numbers;
    
    class SpanFullException : public std::exception {
        public:
            virtual const char *what() const throw();
    };

    class NotEnoughNumbersException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
};

#endif