/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:54:43 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/20 10:11:06 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }

    std::ofstream outfile(target + "_shrubbery");
    if (!outfile)
    {
        std::cerr << "Error creating file: " << target + "_shrubbery" << std::endl;
        return;
    }

    outfile << "            *\n"
               "           /|\\\n"
               "          /*|*\\\n"
               "         /*/|\\*\\\n"
               "        /O//|\\\\O\\\n"
               "       /*/O/|\\O\\*\\\n"
               "      /X/O//|\\\\X\\O\\\n"
               "     /O/*/X/|\\X\\*\\O\\\n"
               "    /*/O/X//|\\\\X\\O\\*\\\n"
               "   /O/X/*/O/|\\O\\*\\X\\O\\\n"
               "           |X|\n"
               "           |X|\n"
               "           |X|\n"
               "         =======\n";
    outfile.close();
}
