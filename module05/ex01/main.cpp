/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:18:30 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/20 08:37:27 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat paco("Paco", 51);
        Form taxForm("Tax Form", 50, 30);
        std::cout << paco << std::endl;
        std::cout << taxForm << std::endl;
        paco.signForm(taxForm);
        paco.incrementGrade();
        std::cout << paco << std::endl;
        paco.signForm(taxForm); 
        std::cout << taxForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form form1("Form1", 0, 30);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form form1("Form1", 50, -2);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form form2("Form1", 151, 30);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form form2("Form1", 50, 200);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}