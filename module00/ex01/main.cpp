/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:13:00 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/24 09:55:56 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

int main(void)
{
    Phonebook phonebook;
    std::string command;
    std::cout << "Welcome to the Phonebook!" << std::endl;
    while (true)
    {;
        std::cout << std::endl << "Available commands: ADD, SEARCH, EXIT" << std::endl;
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