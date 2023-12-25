/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 03:41:55 by bsengeze          #+#    #+#             */
/*   Updated: 2023/12/25 03:42:04 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else {
    std::string inputString;
    for (int i = 1; i < argc; ++i) {
      inputString += argv[i];
      if (i < argc - 1) {
        inputString += " ";
      }
    }

    for (size_t i = 0; i < inputString.length(); ++i) {
      inputString[i] = std::toupper(inputString[i]);
    }

    std::cout << inputString << std::endl;
  }
  return 0;
}
