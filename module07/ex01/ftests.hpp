/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftests.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 12:35:05 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 12:37:26 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTESTS_HPP
#define FTESTS_HPP

#include <iostream>

template <typename T>
void print(const T &element)
{
    std::cout << element << std::endl;
}

template <typename T>
void increment(T &element)
{
    ++element;
}

template <typename T>
void doubleValue(T &element)
{
    element *= 2;
}

template <typename T>
void printWithSpace(const T &element)
{
    std::cout << element << " ";
}

template <typename T>
void assignDefault(T &element)
{
    element = T();
}

#endif
