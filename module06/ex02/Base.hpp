/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:52:49 by telcash           #+#    #+#             */
/*   Updated: 2026/06/18 22:14:35 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        virtual ~Base();
};

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif