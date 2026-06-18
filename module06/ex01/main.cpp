/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:38:39 by telcash           #+#    #+#             */
/*   Updated: 2026/06/18 21:51:05 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data* originalData = new Data();
    std::cout << "Original Data: Name = " << originalData->getName() << ", Value = " << originalData->getValue() << std::endl;
    std::cout << "Original Data Address: " << originalData << std::endl;
    
    uintptr_t serializedData = Serializer::serialize(originalData);
    std::cout << "Serialized Data (uintptr_t): " << serializedData << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized Data: Name = " << deserializedData->getName() << ", Value = " << deserializedData->getValue() << std::endl;
    std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
    delete originalData;
    return 0;
}