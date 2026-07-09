#include "Account.hpp"
#include <ctime>
#include <iostream>

Account::Account() : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0){};

Account::~Account(){};

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) 
{
    return (_totalNbWithdrawals);
}

// void	Account::displayAccountsInfos( void )
// {
//     std::string output;
//     output = []
// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

// }

void    Account::makeDeposit( int deposit )
{
    
}


void	Account::_displayTimestamp( void )
{
    time_t timestamp;
    char output[50];
    struct tm * datetime;

    time(&timestamp);
    datetime = localtime(&timestamp);

    strftime(output, 50, "[%G%m%d_%H%M%S]", datetime);
    std::cout << output << "\n";
}



