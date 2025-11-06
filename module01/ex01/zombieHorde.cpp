/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:11:07 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/06 20:34:12 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name) {
    int i;

    if (N <= 0)
        return NULL;
    Zombie* horde = new Zombie[N];
    i = 0;
    while (i < N) {
        horde[i].setName(name);
        i++;
    }
    return horde;
}