/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:46:08 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/19 13:37:36 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal {
    protected:
     std::string type;
     Animal();
     Animal(const Animal& other);
    
    public:
     virtual ~Animal();
     Animal& operator=(const Animal& other);
     std::string getType() const;
     virtual void makeSound() const = 0;
};
#endif