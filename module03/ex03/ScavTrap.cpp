/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:32:46 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/11 09:00:38 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() : ClapTrap()
{
    _name = "Default_ScavTrap";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed with default values." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed with parameterized values." << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap " << other._name << " assigned." << std::endl;
    if (this != &other)
    {
        this->ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " has no energy or hit points left to attack." << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode." << std::endl;
}