/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:00:51 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/06 17:57:14 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

#ifndef MAX_CONTACTS
# define MAX_CONTACTS 8
#endif

class Phonebook
{
    private:
        Contact _contacts[MAX_CONTACTS];
        int _index;
        std::string formatField(std::string field);
    public:
        Phonebook();
        void add_contact();
        void search_contact();
        void display_contacts();
        void display_contact(int index);
};

#endif