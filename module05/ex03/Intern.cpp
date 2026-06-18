/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:15:24 by carlossalaz       #+#    #+#             */
/*   Updated: 2026/06/18 19:12:02 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(Intern::*formCreators[])(const std::string &) const = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Intern cannot create " << formName << " because it is unknown." << std::endl;
    return NULL;
}