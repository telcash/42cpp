/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:08:17 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/24 10:01:14 by carlossalaz      ###   ########.fr       */
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
    index = std::stoi(input);
    if (index < 0 || index >= MAX_CONTACTS - 1)
        std::cout << "Invalid index." << std::endl;
    else if (this->_contacts[index].get_first_name() == "")
        std::cout << "Contact not found." << std::endl;
    else
        this->display_contact(index);
}

void Phonebook::display_contacts(void)
{
    Contact formatted_contact;
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        if (this->_contacts[i].get_first_name() != "")
        {
            formatted_contact = this->formatContact(this->_contacts[i]);
            std::cout << "         " << std::to_string(i) << "|"
                << formatted_contact.get_first_name() << "|" 
                << formatted_contact.get_last_name() << "|" 
                << formatted_contact.get_nickname()
                << std::endl;
        }
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

Contact Phonebook::formatContact(Contact contact)
{
    Contact formatted_contact;
    std::string first_name = contact.get_first_name();
    std::string last_name = contact.get_last_name();
    std::string nickname = contact.get_nickname();
    std::string phone_number = contact.get_phone_number();

    if (first_name.length() > 10)
        first_name = first_name.substr(0, 9) + ".";
    else if (first_name.length() < 10)
        first_name = std::string(10 - first_name.length(), ' ') + first_name;
    if (last_name.length() > 10)
        last_name = last_name.substr(0, 9) + ".";
    else if (last_name.length() < 10)
        last_name = std::string(10 - last_name.length(), ' ') + last_name;
    if (nickname.length() > 10)
        nickname = nickname.substr(0, 9) + ".";
    else if (nickname.length() < 10)
        nickname = std::string(10 - nickname.length(), ' ') + nickname;
    if (phone_number.length() > 10)
        phone_number = phone_number.substr(0, 9) + ".";

    formatted_contact.set_first_name(first_name);
    formatted_contact.set_last_name(last_name);
    formatted_contact.set_nickname(nickname);
    return formatted_contact;
}