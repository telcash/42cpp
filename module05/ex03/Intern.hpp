/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:14:28 by carlossalaz       #+#    #+#             */
/*   Updated: 2026/06/18 19:12:02 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include <string>

class Intern
{
private:
    AForm *createShrubberyCreationForm(const std::string &target) const;
    AForm *createRobotomyRequestForm(const std::string &target) const;
    AForm *createPresidentialPardonForm(const std::string &target) const;
public:
    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern &operator=(const Intern &other);
    AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif