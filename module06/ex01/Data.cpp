/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:37:20 by telcash           #+#    #+#             */
/*   Updated: 2026/06/18 21:42:00 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : name("Default"), value(0) {}
Data::Data(const Data& other) : name(other.name), value(other.value) {}
Data& Data::operator=(const Data& other) {
    if (this != &other) {
        this->name = other.name;
        this->value = other.value;
    }
    return *this;
}
Data::~Data() {}

const std::string& Data::getName() const {
    return name;
}

int Data::getValue() const {
    return value;
}