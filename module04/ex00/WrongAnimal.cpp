/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:18:49 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/11 10:21:31 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructed with default type." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "WrongAnimal constructed with type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
    std::cout << "WrongAnimal copy constructed with type: " << type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        type = other.type;
        std::cout << "WrongAnimal assigned with type: " << type << std::endl;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructed with type: " << type << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes sound." << std::endl;
}