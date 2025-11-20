/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:08:27 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/20 09:48:53 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {

    Bureaucrat marvin("Marvin", 140);
    Bureaucrat ford("Ford", 45);
    Bureaucrat zaphod("Zaphod", 1);
    ShrubberyCreationForm sF("Home");
    RobotomyRequestForm rF("Tricia");
    PresidentialPardonForm pF("Arthur");

    try {
        marvin.signForm(sF);
        marvin.executeForm(sF); //error
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        ford.executeForm(sF);
        ford.executeForm(rF); //error
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        ford.signForm(rF);
        ford.executeForm(rF);
        ford.signForm(pF); //error
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        zaphod.signForm(pF);
        zaphod.executeForm(pF);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}