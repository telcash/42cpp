/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:43:44 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 21:33:05 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <data_file>" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    try
    {
        exchange.readDatabase("data.csv");
        exchange.processData(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}