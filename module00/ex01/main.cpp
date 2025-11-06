/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:13:00 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/06 17:08:51 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

int main(void)
{
    Phonebook phonebook;
    std::string command;

    std::cout << std::endl << "Welcome to the Phonebook!" << std::endl << std::endl;
    while (true)
    {
        std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    std::cout << "Exiting Phonebook. Goodbye!" << std::endl;
    return (0);
}