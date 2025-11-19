/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:54:59 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/19 13:52:16 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    const int size = 4;
    Animal *animals[size];

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound();
    }

    Dog *testDog = new Dog();
    testDog->setIdea(3, "Chase the cat");
    Dog assignDog = *testDog;
    std::cout << "Copied Dog Idea[3]: " << assignDog.getIdea(3) << std::endl;
    delete testDog;

    Cat *testCat = new Cat();
    testCat->setIdea(5, "Climb the tree");
    Cat copyCat(*testCat);
    std::cout << "Copied Cat Idea[5]: " << copyCat.getIdea(5) << std::endl;
    delete testCat;

    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }

    return 0;
}