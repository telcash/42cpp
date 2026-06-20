/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 13:01:55 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 14:03:41 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

template <typename T>
class Array {
    private:
        unsigned int _size;
        T* _array;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        const Array<T>& operator=(const Array<T>& other);
        const T& operator[](unsigned int index) const;
        T& operator[](unsigned int index);
        unsigned int size() const;
        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif