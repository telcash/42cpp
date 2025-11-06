/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 22:54:25 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/06 18:15:18 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::set_first_name(std::string first_name) {
    this->_first_name = first_name;
}

void Contact::set_last_name(std::string last_name) {
    this->_last_name = last_name;
}

void Contact::set_nickname(std::string nickname) {
    this->_nickname = nickname;
}

void Contact::set_phone_number(std::string phone_number) {
    this->_phone_number = phone_number;
}

void Contact::set_darkest_secret(std::string darkest_secret) {
    this->_darkest_secret = darkest_secret;
}

std::string Contact::get_first_name() const {
    return this->_first_name;
}

std::string Contact::get_last_name() const {
    return this->_last_name;
}

std::string Contact::get_nickname() const {
    return this->_nickname;
}

std::string Contact::get_phone_number() const {
    return this->_phone_number;
}

std::string Contact::get_darkest_secret() const {
    return this->_darkest_secret;
}

bool Contact::isValidPhoneNumber(const std::string &pn) const {
    size_t i = 0;

    if (pn.empty())
        return false;
    if(pn[0] == '+')
    {
        if (pn.size() == 1)
            return false;
        i = 1;
    }
    while (i < pn.size())
    {
        if (!isdigit(pn[i]))
            return false;
        i++;
    }
    return true;
}

static std::string formatField(std::string field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else if (field.length() < 10)
        return std::string(10 - field.length(), ' ') + field;
    return field;
}

Contact Contact::formatContact(Contact contact)
{
    Contact formatted_contact;
    std::string first_name = contact.get_first_name();
    std::string last_name = contact.get_last_name();
    std::string nickname = contact.get_nickname();
    std::string phone_number = contact.get_phone_number();

    first_name = formatField(first_name);
    last_name = formatField(last_name);
    nickname = formatField(nickname);
    phone_number = formatField(phone_number);
    formatted_contact.set_first_name(first_name);
    formatted_contact.set_last_name(last_name);
    formatted_contact.set_nickname(nickname);
    formatted_contact.set_phone_number(phone_number);
    return formatted_contact;
}