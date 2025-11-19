/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:54:28 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/19 13:36:36 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
    Cat::brain = new Brain();
    std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(const Cat &other) {
    Cat::brain = new Brain(*(other.brain));
    std::cout << "Cat copy constructed." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        *(this->brain) = *(other.brain);
        std::cout << "Cat assigned." << std::endl;
    }
    return *this;
}

Cat::~Cat() {
    delete Cat::brain;
    std::cout << "Cat destructed." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat meows." << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return this->brain->getIdea(index);
}