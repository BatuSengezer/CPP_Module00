/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:31:41 by bsengeze          #+#    #+#             */
/*   Updated: 2023/12/25 18:51:33 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
  std::time_t now = std::time(0);
  std::tm *ltm = std::localtime(&now);

  std::cout << "[" << 1900 + ltm->tm_year << (1 + ltm->tm_mon < 10 ? "0" : "")
            << 1 + ltm->tm_mon << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
            << "_" << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
            << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
            << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "] ";
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
}

void Account::makeDeposit(int deposit) {
  _nbDeposits++;
  _totalNbDeposits++;
  _amount += deposit;
  _totalAmount += deposit;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit
            << ";deposit:" << deposit << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  if (_amount < withdrawal) {
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";withdrawal:refused" << std::endl;
    return false;
  }
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal
            << ";withdrawal:" << withdrawal << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
