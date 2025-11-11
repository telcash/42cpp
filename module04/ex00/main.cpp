/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:54:59 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/11 10:29:57 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;

const WrongAnimal* wrongMeta = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();
std::cout << wrongCat->getType() << " " << std::endl;
wrongCat->makeSound(); //will output the WrongAnimal sound!
wrongMeta->makeSound();
delete wrongMeta;
delete wrongCat;
return 0;
}