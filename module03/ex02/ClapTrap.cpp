/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:54:59 by csalazar          #+#    #+#             */
/*   Updated: 2025/11/11 09:00:38 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed with default values." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed with parameterized values." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) 
{
    std::cout << "ClapTrap " << _name << " copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap " << other._name << " assigned." << std::endl;   
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= amount) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and is now destroyed!" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage, remaining hit points: " << _hitPoints << "." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points, total hit points: " << _hitPoints << "." << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to be repaired." << std::endl;
    }
}