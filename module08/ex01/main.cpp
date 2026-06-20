/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:44:42 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 17:55:42 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

void spans(Span &sp) {
    try {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void fill_vector_with_random_numbers(std::vector<int> &vec, int count) {
    std::srand(time(0));
    for (int i = 0; i < count; ++i) {
        vec.push_back(std::rand() % 10000000);
    }
}

void print_vector_to_file(const std::vector<int> &vec, const std::string &filename) {
    std::ofstream outfile(filename.c_str());
    if (!outfile) {
        std::cerr << "Error creating file: " << filename << std::endl;
        return;
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        outfile << vec[i] << std::endl;
    }
    outfile.close();
}

int main() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    spans(sp);

    Span largeSpan(10000);
    std::vector<int> numbers;
    fill_vector_with_random_numbers(numbers, 10000);
    std::sort(numbers.begin(), numbers.end());
    print_vector_to_file(numbers, "numbers.txt");
    largeSpan.fill_with_range_of_iterators(numbers.begin(), numbers.end());
    spans(largeSpan);
    return 0;
}