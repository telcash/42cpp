/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:09:45 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/06 20:43:27 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

#define HORDE_SIZE 5

int main() {
    int i;
    Zombie* horde = zombieHorde(HORDE_SIZE, "Zombie");
    i = 0;
    while (i < HORDE_SIZE) {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return 0;
}