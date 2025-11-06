/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:54:38 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/06 20:03:27 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int main()
{
    randomChump("Zombie 1");
    randomChump("Zombie 2");

    Zombie* zombie3 = newZombie("Heap Zombie");
    zombie3->announce();
    randomChump("Zombie 4");
    delete zombie3;

    return 0;
}