/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:00:51 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/24 09:39:35 by carlossalaz      ###   ########.fr       */
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
        Contact formatContact(Contact contact);
    public:
        Phonebook();
        void add_contact();
        void search_contact();
        void display_contacts();
        void display_contact(int index);
};

#endif