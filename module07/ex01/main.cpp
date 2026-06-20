/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 11:04:08 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 12:38:27 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "ftests.hpp"
#include <iostream>
#include <string>

void printConstInt(const int &element)
{
    std::cout << element << " ";
}

void addTen(int &element)
{
    element += 10;
}

void printConstString(const std::string &element)
{
    std::cout << element << " ";
}

void addQuestionMark(std::string &element)
{
    element += "?";
}

void printConstDouble(const double &element)
{
    std::cout << element << " ";
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    const size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Int array with template print:" << std::endl;
    iter(intArray, intArrayLength, print<int>);
    std::cout << std::endl;

    std::cout << "Int array with non-template const print:" << std::endl;
    iter(intArray, intArrayLength, printConstInt);
    std::cout << std::endl << std::endl;

    iter(intArray, intArrayLength, increment<int>);
    std::cout << "Int array after template increment:" << std::endl;
    iter(intArray, intArrayLength, printWithSpace<int>);
    std::cout << std::endl;

    iter(intArray, intArrayLength, addTen);
    std::cout << "Int array after non-template addTen:" << std::endl;
    iter(intArray, intArrayLength, printWithSpace<int>);
    std::cout << std::endl << std::endl;

    const int constIntArray[] = {10, 20, 30};
    const size_t constIntArrayLength = sizeof(constIntArray) / sizeof(constIntArray[0]);

    std::cout << "Const int array with template print:" << std::endl;
    iter(constIntArray, constIntArrayLength, print<int>);
    std::cout << std::endl;

    std::cout << "Const int array with non-template const print:" << std::endl;
    iter(constIntArray, constIntArrayLength, printConstInt);
    std::cout << std::endl << std::endl;

    double doubleArray[] = {1.5, 2.5, 3.5};
    const size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Double array with non-template const print:" << std::endl;
    iter(doubleArray, doubleArrayLength, printConstDouble);
    std::cout << std::endl;

    iter(doubleArray, doubleArrayLength, doubleValue<double>);
    std::cout << "Double array after template doubleValue:" << std::endl;
    iter(doubleArray, doubleArrayLength, printWithSpace<double>);
    std::cout << std::endl << std::endl;

    std::string strArray[] = {"hello", "iter", "templates"};
    const size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array with template print:" << std::endl;
    iter(strArray, strArrayLength, print<std::string>);
    std::cout << std::endl;

    std::cout << "String array with non-template const print:" << std::endl;
    iter(strArray, strArrayLength, printConstString);
    std::cout << std::endl << std::endl;

    iter(strArray, strArrayLength, addQuestionMark);
    std::cout << "String array after non-template addQuestionMark:" << std::endl;
    iter(strArray, strArrayLength, printWithSpace<std::string>);
    std::cout << std::endl << std::endl;

    const std::string constStrArray[] = {"const", "string", "array"};
    const size_t constStrArrayLength = sizeof(constStrArray) / sizeof(constStrArray[0]);

    std::cout << "Const string array with template print:" << std::endl;
    iter(constStrArray, constStrArrayLength, print<std::string>);
    std::cout << std::endl;

    iter(intArray, intArrayLength, assignDefault<int>);
    std::cout << "Int array after template assignDefault:" << std::endl;
    iter(intArray, intArrayLength, printWithSpace<int>);
    std::cout << std::endl;

    return 0;
}
