/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:55:17 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 16:04:47 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>


// Example usage of easyfind with c++ 98 containers
int main() {

    std::vector<int> vec;
    // Fill the vector with some values
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found value at index: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 15);
        std::cout << "Found value at index: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> lst;
    for (int i = 0; i < 10; ++i) {
        lst.push_back(i);
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 7);
        std::cout << "Found value at index: " << std::distance(lst.begin(), it) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found value at index: " << std::distance(lst.begin(), it) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    std::deque<int> deq;
    for (int i = 0; i < 10; ++i) {
        deq.push_back(i);
    }

    try {
        std::deque<int>::iterator it = easyfind(deq, 4);
        std::cout << "Found value at index: " << std::distance(deq.begin(), it) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(deq, 15);
        std::cout << "Found value at index: " << std::distance(deq.begin(), it) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
