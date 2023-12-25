/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:22:02 by bsengeze          #+#    #+#             */
/*   Updated: 2023/12/25 23:33:23 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();
  void addContact();
  void searchContact() const;

private:
  static const int MAX_CONTACTS = 8;
  Contact contacts[MAX_CONTACTS];
  int contactCount;
  int oldestContactIndex;
};

#endif
