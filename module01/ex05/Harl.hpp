/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:04:05 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/06 22:09:45 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>

class Harl {
   public:
    Harl();
    ~Harl();
    void complain(std::string level);

   private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};
#endif