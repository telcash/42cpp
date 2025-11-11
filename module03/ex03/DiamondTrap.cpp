/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:19:43 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/11 09:37:18 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap() {
    _name = "Default_DiamondTrap";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " constructed with default values." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(), FragTrap() {
    _name = name;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " constructed with parameterized values." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ScavTrap(other), FragTrap(other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "DiamondTrap " << _name << " copied." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DiamondTrap " << other._name << " assigned." << std::endl;
    if (this != &other) {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructed." << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}