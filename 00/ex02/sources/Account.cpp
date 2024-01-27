#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account( void ) 
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_totalAmount = 0;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	_nbAccounts--;
	_totalAmount -= _amount;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t result = std::time(0);
	std::cout << "[" << result << "]";
}

int		Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int		Account::getTotalAmount( void )
{
	return _totalAmount;
}

int		Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << "total;" << _totalAmount << "deposits;" << _totalNbDeposits << "withdrawals;" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index;" << _accountIndex << ";amount;" << _amount << ";deposits;" << _nbDeposits << ";withdrawals;" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount < withdrawal)
		return false;
	else
	{
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		return true;
	}
}

int Account::checkAmount(void) const
{
	return _amount;
}

