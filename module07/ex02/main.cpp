/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 13:54:03 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 14:14:38 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

template <typename T>
void printArray(const std::string &name, const Array<T> &array)
{
    std::cout << name << " size: " << array.size() << std::endl;
    for (unsigned int i = 0; i < array.size(); ++i)
        std::cout << name << "[" << i << "] = " << array[i] << std::endl;
}

void testEmptyArray()
{
    std::cout << "--- Empty array ---" << std::endl;
    Array<int> empty;

    std::cout << "empty size: " << empty.size() << std::endl;
    try {
        std::cout << empty[0] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "empty[0] exception: " << e.what() << std::endl;
    }
}

void testDefaultInitialization()
{
    std::cout << std::endl << "--- Default initialization ---" << std::endl;
    Array<int> numbers(5);
    Array<std::string> words(3);

    printArray("numbers", numbers);
    printArray("words", words);
}

void testSubscriptAndBounds()
{
    std::cout << std::endl << "--- Subscript and bounds ---" << std::endl;
    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); ++i)
        numbers[i] = i * 10;
    printArray("numbers", numbers);

    try {
        std::cout << "numbers[5] = " << numbers[5] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "numbers[5] exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "numbers[100] = " << numbers[100] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "numbers[100] exception: " << e.what() << std::endl;
    }
}

void testCopyConstructor()
{
    std::cout << std::endl << "--- Copy constructor deep copy ---" << std::endl;
    Array<int> original(3);

    original[0] = 7;
    original[1] = 14;
    original[2] = 21;

    Array<int> copy(original);
    original[0] = 100;
    copy[1] = 200;

    printArray("original", original);
    printArray("copy", copy);
}

void testAssignmentOperator()
{
    std::cout << std::endl << "--- Assignment operator deep copy ---" << std::endl;
    Array<std::string> source(2);
    Array<std::string> assigned(4);

    source[0] = "alpha";
    source[1] = "beta";

    assigned[0] = "old";
    assigned[1] = "values";
    assigned[2] = "will";
    assigned[3] = "go";

    assigned = source;
    source[0] = "changed source";
    assigned[1] = "changed assigned";

    printArray("source", source);
    printArray("assigned", assigned);
}

void testConstAccessAndSize()
{
    std::cout << std::endl << "--- Const access and const size() ---" << std::endl;
    Array<int> numbers(2);

    numbers[0] = 42;
    numbers[1] = 84;

    const Array<int> constNumbers(numbers);

    std::cout << "constNumbers size: " << constNumbers.size() << std::endl;
    std::cout << "constNumbers[0] = " << constNumbers[0] << std::endl;
    std::cout << "constNumbers[1] = " << constNumbers[1] << std::endl;

    try {
        std::cout << "constNumbers[2] = " << constNumbers[2] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "constNumbers[2] exception: " << e.what() << std::endl;
    }
}

int main()
{
    testEmptyArray();
    testDefaultInitialization();
    testSubscriptAndBounds();
    testCopyConstructor();
    testAssignmentOperator();
    testConstAccessAndSize();

    return 0;
}
