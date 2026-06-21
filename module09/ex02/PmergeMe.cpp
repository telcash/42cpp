/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:28:00 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 22:28:00 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}
PmergeMe::~PmergeMe() {}

int PmergeMe::_parsePositiveInt(const std::string &value)
{
    char *end = NULL;
    long number;

    if (value.empty())
        throw std::runtime_error("Error");
    for (size_t i = 0; i < value.length(); ++i)
    {
        if (value[i] < '0' || value[i] > '9')
            throw std::runtime_error("Error");
    }
    errno = 0;
    number = std::strtol(value.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || number <= 0 || number > INT_MAX)
        throw std::runtime_error("Error");
    return static_cast<int>(number);
}

std::vector<int> PmergeMe::parse(int argc, char **argv)
{
    std::vector<int> values;

    if (argc < 2)
        throw std::runtime_error("Error");
    values.reserve(argc - 1);
    for (int i = 1; i < argc; ++i)
        values.push_back(_parsePositiveInt(argv[i]));
    return values;
}

std::vector<int> PmergeMe::_buildJacobsthalOrderVector(size_t size)
{
    std::vector<int> order;
    size_t previous;
    size_t current;
    size_t next;

    if (size == 0)
        return order;
    order.push_back(0);
    previous = 1;
    current = 3;
    while (previous < size)
    {
        next = current;
        if (next > size)
            next = size;
        for (size_t i = next; i > previous; --i)
            order.push_back(static_cast<int>(i - 1));
        next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return order;
}

std::deque<int> PmergeMe::_buildJacobsthalOrderDeque(size_t size)
{
    std::deque<int> order;
    size_t previous;
    size_t current;
    size_t next;

    if (size == 0)
        return order;
    order.push_back(0);
    previous = 1;
    current = 3;
    while (previous < size)
    {
        next = current;
        if (next > size)
            next = size;
        for (size_t i = next; i > previous; --i)
            order.push_back(static_cast<int>(i - 1));
        next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return order;
}

size_t PmergeMe::_lowerBoundVector(const std::vector<int> &values, int value)
{
    size_t first = 0;
    size_t count = values.size();

    while (count > 0)
    {
        size_t step = count / 2;
        size_t mid = first + step;

        if (values[mid] < value)
        {
            first = mid + 1;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first;
}

size_t PmergeMe::_lowerBoundDeque(const std::deque<int> &values, int value)
{
    size_t first = 0;
    size_t count = values.size();

    while (count > 0)
    {
        size_t step = count / 2;
        size_t mid = first + step;

        if (values[mid] < value)
        {
            first = mid + 1;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first;
}

size_t PmergeMe::_lowerBoundVectorPairs(const std::vector<VectorPair> &values,
                                        const VectorPair &value)
{
    size_t first = 0;
    size_t count = values.size();

    while (count > 0)
    {
        size_t step = count / 2;
        size_t mid = first + step;

        if (values[mid].big < value.big)
        {
            first = mid + 1;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first;
}

size_t PmergeMe::_lowerBoundDequePairs(const std::deque<DequePair> &values,
                                       const DequePair &value)
{
    size_t first = 0;
    size_t count = values.size();

    while (count > 0)
    {
        size_t step = count / 2;
        size_t mid = first + step;

        if (values[mid].big < value.big)
        {
            first = mid + 1;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first;
}

void PmergeMe::_sortVectorPairs(std::vector<VectorPair> &values)
{
    std::vector<VectorPair> winners;
    std::vector<VectorPair> losers;
    std::vector<int> order;
    bool hasOdd = values.size() % 2 != 0;
    VectorPair odd;

    if (values.size() < 2)
        return;
    if (hasOdd)
        odd = values[values.size() - 1];
    winners.reserve(values.size() / 2 + 1);
    losers.reserve(values.size() / 2);
    for (size_t i = 0; i + 1 < values.size(); i += 2)
    {
        if (values[i].big <= values[i + 1].big)
        {
            losers.push_back(values[i]);
            winners.push_back(values[i + 1]);
        }
        else
        {
            losers.push_back(values[i + 1]);
            winners.push_back(values[i]);
        }
    }
    _sortVectorPairs(winners);
    order = _buildJacobsthalOrderVector(losers.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        VectorPair value = losers[order[i]];
        winners.insert(winners.begin() + _lowerBoundVectorPairs(winners, value), value);
    }
    if (hasOdd)
        winners.insert(winners.begin() + _lowerBoundVectorPairs(winners, odd), odd);
    values = winners;
}

void PmergeMe::_sortDequePairs(std::deque<DequePair> &values)
{
    std::deque<DequePair> winners;
    std::deque<DequePair> losers;
    std::deque<int> order;
    bool hasOdd = values.size() % 2 != 0;
    DequePair odd;

    if (values.size() < 2)
        return;
    if (hasOdd)
        odd = values[values.size() - 1];
    for (size_t i = 0; i + 1 < values.size(); i += 2)
    {
        if (values[i].big <= values[i + 1].big)
        {
            losers.push_back(values[i]);
            winners.push_back(values[i + 1]);
        }
        else
        {
            losers.push_back(values[i + 1]);
            winners.push_back(values[i]);
        }
    }
    _sortDequePairs(winners);
    order = _buildJacobsthalOrderDeque(losers.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        DequePair value = losers[order[i]];
        winners.insert(winners.begin() + _lowerBoundDequePairs(winners, value), value);
    }
    if (hasOdd)
        winners.insert(winners.begin() + _lowerBoundDequePairs(winners, odd), odd);
    values = winners;
}

void PmergeMe::sortVector(std::vector<int> &values)
{
    std::vector<VectorPair> pairs;
    std::vector<int> mainChain;
    std::vector<int> pend;
    std::vector<int> order;
    bool hasOdd = values.size() % 2 != 0;
    int odd = 0;

    if (values.size() < 2)
        return;
    if (hasOdd)
        odd = values[values.size() - 1];
    pairs.reserve(values.size() / 2);
    for (size_t i = 0; i + 1 < values.size(); i += 2)
    {
        VectorPair pair;

        if (values[i] <= values[i + 1])
        {
            pair.small = values[i];
            pair.big = values[i + 1];
        }
        else
        {
            pair.small = values[i + 1];
            pair.big = values[i];
        }
        pairs.push_back(pair);
    }
    _sortVectorPairs(pairs);
    mainChain.reserve(values.size());
    pend.reserve(pairs.size() + 1);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].big);
        pend.push_back(pairs[i].small);
    }
    if (hasOdd)
        pend.push_back(odd);
    order = _buildJacobsthalOrderVector(pend.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        int value = pend[order[i]];
        mainChain.insert(mainChain.begin() + _lowerBoundVector(mainChain, value), value);
    }
    values = mainChain;
}

void PmergeMe::sortDeque(std::deque<int> &values)
{
    std::deque<DequePair> pairs;
    std::deque<int> mainChain;
    std::deque<int> pend;
    std::deque<int> order;
    bool hasOdd = values.size() % 2 != 0;
    int odd = 0;

    if (values.size() < 2)
        return;
    if (hasOdd)
        odd = values[values.size() - 1];
    for (size_t i = 0; i + 1 < values.size(); i += 2)
    {
        DequePair pair;

        if (values[i] <= values[i + 1])
        {
            pair.small = values[i];
            pair.big = values[i + 1];
        }
        else
        {
            pair.small = values[i + 1];
            pair.big = values[i];
        }
        pairs.push_back(pair);
    }
    _sortDequePairs(pairs);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].big);
        pend.push_back(pairs[i].small);
    }
    if (hasOdd)
        pend.push_back(odd);
    order = _buildJacobsthalOrderDeque(pend.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        int value = pend[order[i]];
        mainChain.insert(mainChain.begin() + _lowerBoundDeque(mainChain, value), value);
    }
    values = mainChain;
}

void PmergeMe::printSequence(const std::string &label,
                             const std::vector<int> &values)
{
    std::cout << label;
    for (size_t i = 0; i < values.size(); ++i)
        std::cout << " " << values[i];
    std::cout << std::endl;
}
