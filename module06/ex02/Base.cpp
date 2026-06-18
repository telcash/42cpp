/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:58:26 by telcash           #+#    #+#             */
/*   Updated: 2026/06/18 22:17:28 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

Base *generate()
{
    std::srand(std::time(0));
    int random = std::rand() % 3;
    switch (random)
    {
        case 0:
            std::cout << "Generated type: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated type: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated type: C" << std::endl;
            return new C();
        default:
            return (NULL);
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    // Using a pointer inside this function is forbidden, so we will use dynamic_cast with references and catch exceptions
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception &e){}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception &e){}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception &e){}
    std::cout << "Unknown type" << std::endl;
}