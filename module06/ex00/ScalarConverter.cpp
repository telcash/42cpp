/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:43:12 by telcash           #+#    #+#             */
/*   Updated: 2026/04/26 10:56:24 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other; 
    return *this; 
}
ScalarConverter::~ScalarConverter() {}

enum Type { CHAR, INT, FLOAT, DOUBLE, NOT_A_NUMBER, INF, NOT_VALID };

void ScalarConverter::convert(const std::string &literal) {
    Type type;
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    long intValue = 0;
    double parsedValue = 0.0;
    char *end = NULL;
    std::size_t start = 0;
    std::size_t dotPos = std::string::npos;
    bool valid = true;
    bool charImpossible = false;
    bool intImpossible = false;
    bool floatImpossible = false;

    if (literal == "nan" || literal == "nanf")
        type = NOT_A_NUMBER;
    else if (literal == "inf" || literal == "+inf" || literal == "-inf"
        || literal == "inff" || literal == "+inff" || literal == "-inff")
        type = INF;
    else if (literal.length() == 1 && std::isprint(static_cast<unsigned char>(literal[0])) && !std::isdigit(static_cast<unsigned char>(literal[0])))
        type = CHAR;
    else
    {
        if (literal.empty())
            type = NOT_VALID;
        else
        {
            if (literal[0] == '+' || literal[0] == '-')
                start = 1;
            if (start == literal.length())
                valid = false;
            dotPos = literal.find('.', start);
            if (valid && literal[literal.length() - 1] == 'f')
            {
                if (dotPos == std::string::npos || dotPos == start
                    || dotPos == literal.length() - 2)
                    valid = false;
                else
                {
                    for (std::size_t idx = start; idx < literal.length() - 1; ++idx)
                    {
                        if (idx == dotPos)
                            continue;
                        if (!std::isdigit(static_cast<unsigned char>(literal[idx])))
                        {
                            valid = false;
                            break;
                        }
                    }
                }
                type = valid ? FLOAT : NOT_VALID;
            }
            else if (valid && dotPos != std::string::npos)
            {
                if (dotPos == start || dotPos == literal.length() - 1)
                    valid = false;
                else
                {
                    for (std::size_t idx = start; idx < literal.length(); ++idx)
                    {
                        if (idx == dotPos)
                            continue;
                        if (!std::isdigit(static_cast<unsigned char>(literal[idx])))
                        {
                            valid = false;
                            break;
                        }
                    }
                }
                type = valid ? DOUBLE : NOT_VALID;
            }
            else
            {
                for (std::size_t idx = start; idx < literal.length(); ++idx)
                {
                    if (!std::isdigit(static_cast<unsigned char>(literal[idx])))
                    {
                        valid = false;
                        break;
                    }
                }
                type = valid ? INT : NOT_VALID;
            }
        }
    }
    try {
        switch (type) {
            case CHAR:
                c = literal[0];
                i = static_cast<int>(c);
                f = static_cast<float>(c);
                d = static_cast<double>(c);
                break;
            case INT:
                errno = 0;
                intValue = std::strtol(literal.c_str(), &end, 10);
                if (errno == ERANGE || *end != '\0'
                    || intValue < std::numeric_limits<int>::min()
                    || intValue > std::numeric_limits<int>::max())
                {
                    std::cout << "char: impossible" << std::endl;
                    std::cout << "int: impossible" << std::endl;
                    std::cout << "float: impossible" << std::endl;
                    std::cout << "double: impossible" << std::endl;
                    return;
                }
                i = static_cast<int>(intValue);
                c = static_cast<char>(i);
                f = static_cast<float>(i);
                d = static_cast<double>(i);
                break;
            case FLOAT:
                errno = 0;
                parsedValue = std::strtod(literal.c_str(), &end);
                if (errno == ERANGE || (*end != 'f' && *end != '\0')
                    || ((*end == 'f') && *(end + 1) != '\0'))
                    floatImpossible = true;
                if (!floatImpossible
                    && (parsedValue > std::numeric_limits<float>::max()
                    || parsedValue < -std::numeric_limits<float>::max()))
                    floatImpossible = true;
                d = parsedValue;
                if (!floatImpossible)
                    f = static_cast<float>(d);
                break;
            case DOUBLE:
                errno = 0;
                parsedValue = std::strtod(literal.c_str(), &end);
                if (errno == ERANGE || *end != '\0')
                {
                    std::cout << "char: impossible" << std::endl;
                    std::cout << "int: impossible" << std::endl;
                    std::cout << "float: impossible" << std::endl;
                    std::cout << "double: impossible" << std::endl;
                    return;
                }
                d = parsedValue;
                if (d > std::numeric_limits<float>::max()
                    || d < -std::numeric_limits<float>::max())
                    floatImpossible = true;
                else
                    f = static_cast<float>(d);
                break;
            case NOT_A_NUMBER:
                f = std::numeric_limits<float>::quiet_NaN();
                d = std::numeric_limits<double>::quiet_NaN();
                break;
            case INF:
                f = (literal[0] == '-') ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
                d = (literal[0] == '-') ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
                break;
            case NOT_VALID:
            default:
                std::cerr << "Error: Invalid literal" << std::endl;
                return;
        }
        if (type == FLOAT || type == DOUBLE)
        {
            if (std::isnan(d) || std::isinf(d)
                || d > std::numeric_limits<int>::max()
                || d < std::numeric_limits<int>::min())
                intImpossible = true;
            else
                i = static_cast<int>(d);
            if (std::isnan(d) || std::isinf(d)
                || d < 0 || d > 127)
                charImpossible = true;
            else
                c = static_cast<char>(d);
        }
        if (type == NOT_A_NUMBER || type == INF) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        } else {
            if (charImpossible)
                std::cout << "char: impossible" << std::endl;
            else if (std::isprint(static_cast<unsigned char>(c)))
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
            if (intImpossible)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << i << std::endl;
        }
        if (floatImpossible)
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
