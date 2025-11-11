/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:20:24 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/11 10:21:31 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructed." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        std::cout << "WrongCat assigned." << std::endl;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructed." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat makes sound." << std::endl;
}