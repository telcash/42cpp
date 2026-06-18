/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:17:43 by telcash           #+#    #+#             */
/*   Updated: 2026/06/18 21:42:00 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP
#include <string>

class Data
{
    private:
        std::string name;
        int value;
    public:
        Data();
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();
        const std::string& getName() const;
        int getValue() const;
};

#endif