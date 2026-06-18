/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:54:43 by carlossalaz       #+#    #+#             */
/*   Updated: 2026/06/18 18:29:19 by telcash          ###   ########.fr       */
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

void ShrubberyCreationForm::shrubberize() const
{
    const char *filename = (target + "_shrubbery").c_str();
    std::ofstream outfile(filename);
    if (!outfile)
    {
        std::cerr << "Error creating file: " << filename << std::endl;
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

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (canExecute(executor))
    {
        shrubberize();
    }
}
