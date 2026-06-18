/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 22:10:49 by telcash           #+#    #+#             */
/*   Updated: 2026/06/18 22:11:53 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base *base = generate();
    std::cout << "Identifying using pointer: ";
    identify(base);
    std::cout << "Identifying using reference: ";
    identify(*base);
    delete base;
    return 0;
}