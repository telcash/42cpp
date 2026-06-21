/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:28:00 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 22:28:00 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

static double elapsedMicroseconds(clock_t start, clock_t end)
{
    return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

static void validateSameResult(const std::vector<int> &vectorValues,
                               const std::deque<int> &dequeValues)
{
    if (vectorValues.size() != dequeValues.size())
        throw std::runtime_error("Error");
    for (size_t i = 0; i < vectorValues.size(); ++i)
    {
        if (vectorValues[i] != dequeValues[i])
            throw std::runtime_error("Error");
    }
}

int main(int argc, char **argv)
{
    try
    {
        std::vector<int> input = PmergeMe::parse(argc, argv);
        std::vector<int> vectorValues;
        std::deque<int> dequeValues;
        clock_t start;
        clock_t end;
        double vectorTime;
        double dequeTime;

        PmergeMe::printSequence("Before:", input);

        start = std::clock();
        vectorValues = input;
        PmergeMe::sortVector(vectorValues);
        end = std::clock();
        vectorTime = elapsedMicroseconds(start, end);

        start = std::clock();
        dequeValues.assign(input.begin(), input.end());
        PmergeMe::sortDeque(dequeValues);
        end = std::clock();
        dequeTime = elapsedMicroseconds(start, end);

        validateSameResult(vectorValues, dequeValues);
        PmergeMe::printSequence("After:", vectorValues);

        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << input.size()
                  << " elements with std::vector : " << vectorTime << " us"
                  << std::endl;
        std::cout << "Time to process a range of " << input.size()
                  << " elements with std::deque : " << dequeTime << " us"
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
