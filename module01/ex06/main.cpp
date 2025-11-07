/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:23:14 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/07 08:30:02 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    harl.complain("DEBUG");
    std::cout << " *************************** " << std::endl;
    harl.complain("INFO");
    std::cout << " *************************** " << std::endl;
    harl.complain("WARNING");
    std::cout << " *************************** " << std::endl;
    harl.complain("ERROR");
    std::cout << " *************************** " << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}