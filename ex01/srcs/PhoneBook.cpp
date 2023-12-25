/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:24:15 by bsengeze          #+#    #+#             */
/*   Updated: 2023/12/25 23:34:59 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
  if (contactCount < MAX_CONTACTS) {
    contacts[contactCount++].setDetails();
  } else {
    contacts[oldestContactIndex++].setDetails();
    if (oldestContactIndex >= MAX_CONTACTS) {
      oldestContactIndex = 0;
    }
  }
}

void PhoneBook::searchContact() const {
  if (contactCount == 0) {
    std::cout << "No contacts in phonebook." << std::endl;
    return;
  }

  std::cout << std::setw(10) << "Index|" << std::setw(10) << "First Name|"
            << std::setw(10) << "Last Name|" << std::setw(10) << "Nickname"
            << std::endl;
  for (int i = 0; i < contactCount; ++i) {
    contacts[i].displaySummary(i);
  }

  int index;
  bool isValidInput;
  std::cout << "Enter the index of the contact to view: ";

  do {
    std::cin >> index;
    isValidInput = true;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. ";
      isValidInput = false;
    } else {
      std::cin.ignore();
      if (index < 0 || index >= contactCount) {
        std::cout << "Invalid index. ";
        isValidInput = false;
      }
    }

    if (!isValidInput) {
      std::cout << "Please enter a valid index: " << std::flush;
    }

  } while (!isValidInput);

  contacts[index].displayDetails();
}
