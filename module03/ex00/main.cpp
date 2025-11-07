/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:42:56 by csalazar          #+#    #+#             */
/*   Updated: 2025/11/07 19:49:11 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("Clappy");

    clap1.attack("Target1");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    clap1.takeDamage(2);
    clap1.attack("Target2");
    clap1.attack("Target2");
    clap1.attack("Target2");
    clap1.attack("Target2");
    clap1.attack("Target2");
    clap1.attack("Target2");
    clap1.attack("Target2");
    clap1.attack("Target2");
    clap1.attack("Target2");
    clap1.takeDamage(10);

    return (0);
}