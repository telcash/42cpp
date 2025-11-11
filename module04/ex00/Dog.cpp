/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:52:04 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/11 10:08:12 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructed." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Dog assigned." << std::endl;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog barks." << std::endl;
}