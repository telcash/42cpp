/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:52:04 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/19 13:36:36 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
    Dog::brain = new Brain();
    std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(const Dog &other) {
    Dog::brain = new Brain(*(other.brain));
    std::cout << "Dog copy constructed." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        *(this->brain) = *(other.brain);
        std::cout << "Dog assigned." << std::endl;
    }
    return *this;
}

Dog::~Dog() {
    delete Dog::brain;
    std::cout << "Dog destructed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog barks." << std::endl;
}

void Dog::setIdea(int index, const std::string &idea) {
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return this->brain->getIdea(index);
}