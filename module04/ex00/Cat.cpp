/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:54:28 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/11 10:08:46 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructed." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Cat assigned." << std::endl;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructed." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat meows." << std::endl;
}