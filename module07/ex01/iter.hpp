/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 22:32:57 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 12:38:05 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T *array, const size_t length, F func)
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

#endif