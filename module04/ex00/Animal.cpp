/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:48:16 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/11 10:10:28 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructed with default type." << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal constructed with type: " << type << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copy constructed with type: " << type << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Animal assigned with type: " << type << std::endl;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructed with type: " << type << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Animal makes sound." << std::endl;
}