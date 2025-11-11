/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:42:56 by csalazar          #+#    #+#             */
/*   Updated: 2025/11/11 09:15:31 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    ScavTrap scav("Scavvy");
    scav.attack("Target2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    FragTrap frag("Fraggy");
    frag.attack("Target3");
    frag.takeDamage(15);
    frag.beRepaired(5);
    frag.highFivesGuys();

    return 0;
}