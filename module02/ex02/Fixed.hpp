/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:11:41 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/07 10:14:13 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <ostream>

class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed &operator++();        
    Fixed operator++(int);       
    Fixed &operator--();        
    Fixed operator--(int);       
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif