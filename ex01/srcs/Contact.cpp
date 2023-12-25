/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:21:31 by bsengeze          #+#    #+#             */
/*   Updated: 2023/12/25 23:34:46 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
    : firstName(""), lastName(""), nickname(""), phoneNumber(""),
      darkestSecret("") {}

Contact::~Contact() {}

void Contact::setDetails() {
  firstName = getInput("Enter First Name: ");
  lastName = getInput("Enter Last Name: ");
  nickname = getInput("Enter Nickname: ");
  phoneNumber = getInput("Enter Phone Number: ");
  darkestSecret = getInput("Enter Darkest Secret: ");
}

std::string Contact::getInput(const std::string &prompt) {
  std::string input;
  do {
    std::cout << prompt;
    std::getline(std::cin, input);
    if (input.empty()) {
      std::cout << "This field cannot be empty. Please enter a value."
                << std::endl;
    }
  } while (input.empty());
  return input;
}

void Contact::displaySummary(int index) const {
  std::cout << std::setw(10) << index << "|";
  std::cout << std::setw(10)
            << (firstName.length() > 10 ? firstName.substr(0, 9) + "."
                                        : firstName)
            << "|";
  std::cout << std::setw(10)
            << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName)
            << "|";
  std::cout << std::setw(10)
            << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname)
            << std::endl;
}

void Contact::displayDetails() const {
  std::cout << "First Name: " << firstName << std::endl;
  std::cout << "Last Name: " << lastName << std::endl;
  std::cout << "Nickname: " << nickname << std::endl;
  std::cout << "Phone Number: " << phoneNumber << std::endl;
  std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
