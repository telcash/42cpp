/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:08:51 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/11 09:15:31 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _name = "Default_FragTrap";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed with default values." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed with parameterized values." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap " << _name << " copied." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap " << other._name << " assigned." << std::endl;
    if (this != &other) {
        this->ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructed." << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "FragTrap " << _name << " has no energy or hit points left to attack." << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}