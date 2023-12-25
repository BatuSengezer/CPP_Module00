/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:21:45 by bsengeze          #+#    #+#             */
/*   Updated: 2023/12/25 02:25:05 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
  PhoneBook phoneBook;
  std::string command;

  while (true) {
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);

    if (command == "EXIT")
      break;
    else if (command == "ADD")
      phoneBook.addContact();
    else if (command == "SEARCH")
      phoneBook.searchContact();
    else
      std::cout << "Invalid command. Valid commands are ADD, SEARCH, and EXIT "
                << std::endl;
  }
  return 0;
}
