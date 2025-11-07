/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:08:17 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/07 16:37:01 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook(void)
{
    this->_index = 0;
}

void Phonebook::add_contact(void)
{
    Contact contact;
    std::string input;

    input = "";
    while (input.empty())
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "First name cannot be empty." << std::endl;
        else
            contact.set_first_name(input);
    }
    input = "";
    while (input.empty())
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Last name cannot be empty." << std::endl;
        else
            contact.set_last_name(input);
    }
    input = "";
    while (input.empty())
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Nickname cannot be empty." << std::endl;
        else
            contact.set_nickname(input);
    }
    input = "";
    while (input.empty())
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Phone number cannot be empty." << std::endl;
        else if (!contact.isValidPhoneNumber(input))
        {
            std::cout << "Invalid phone number format." << std::endl;
            input = "";
        }
        else
            contact.set_phone_number(input);
    }
    input = "";
    while (input.empty())
    {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Darkest secret cannot be empty." << std::endl;
        else
            contact.set_darkest_secret(input);
    }
    this->_contacts[this->_index] = contact;
    if (this->_index == MAX_CONTACTS - 1)
        this->_index = 0;
    else
        this->_index++;
    std::cout << "Contact added successfully!" << std::endl;
}

void Phonebook::search_contact(void)
{
    std::string input;
    int index;

    this->display_contacts();
    std::cout << "Enter the index of the contact you want to see: ";
    std::getline(std::cin, input);
    if (input.empty() || input.length() > 1 || !isdigit(input[0]))
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    index = (int)(input[0] - '0');
    if (index < 0 || index >= MAX_CONTACTS)
        std::cout << "Invalid index." << std::endl;
    else if (this->_contacts[index].get_first_name() == "")
        std::cout << "Contact not found." << std::endl;
    else
        this->display_contact(index);
}

void Phonebook::display_contacts(void)
{
    Contact formatted_contact;
    int i;

    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    i = 0;
    while (i < MAX_CONTACTS)
    {
        if (this->_contacts[i].get_first_name() != "")
        {
            formatted_contact = Contact::formatContact(this->_contacts[i]);
            std::cout << "         " << (char)(i + '0') << "|"
                << formatted_contact.get_first_name() << "|" 
                << formatted_contact.get_last_name() << "|" 
                << formatted_contact.get_nickname()
                << std::endl;
        }
        i++;
    }
    std::cout << "-------------------------------------------" << std::endl << std::endl;
}

void Phonebook::display_contact(int index)
{
    std::cout << "First Name: " << this->_contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << this->_contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << this->_contacts[index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << this->_contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << this->_contacts[index].get_darkest_secret() << std::endl;
}


