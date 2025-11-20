/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:08:27 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/20 10:34:46 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern intern;

    AForm *sF= intern.makeForm("shrubbery creation", "Home");
    if (sF)
    {
        Bureaucrat marvin("Marvin", 140);
        marvin.signForm(*sF);
        marvin.executeForm(*sF);
        delete sF;
    }

    AForm *rF = intern.makeForm("robotomy request", "Bender");
    if (rF)
    {
        Bureaucrat bob("Bob", 1);
        bob.signForm(*rF);
        bob.executeForm(*rF);
        delete rF;
    }

    AForm *pF = intern.makeForm("presidential pardon", "Charlie");
    if (pF)
    {
        Bureaucrat eve("Eve", 5);
        eve.signForm(*pF);
        eve.executeForm(*pF);
        delete pF;
    }

    AForm *uF = intern.makeForm("unknown form", "Target");
    if (uF)
    {
        delete uF;
    }

    return 0;
}