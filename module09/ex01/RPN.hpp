/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:08:00 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 22:08:00 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN
{
    private:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        static bool _isOperator(const std::string &token);
        static bool _isNumber(const std::string &token);
        static long _applyOperator(long left, long right, char op);

    public:
        static long evaluate(const std::string &expression);
};

#endif
