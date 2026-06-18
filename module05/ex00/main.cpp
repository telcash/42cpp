/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:56:52 by csalazar          #+#    #+#             */
/*   Updated: 2026/06/18 16:57:26 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat d;
        std::cout << d << std::endl;
    } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat e("John Doe", 42);
        std::cout << e << std::endl;
        Bureaucrat f("Jane Smith", 100);
        std::cout << "Before assignment:" << std::endl;
        std::cout << f << std::endl;
        f = e;
        std::cout << "After assignment:" << std::endl;
        std::cout << f << std::endl;
        Bureaucrat g(e);
        std::cout << g << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat b1("Boss", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Newbie", 149);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("BHigh", 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("BLow", 151);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}