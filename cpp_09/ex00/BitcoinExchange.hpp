#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "colors.h"

#define DATABASE "./data.csv"

class BitcoinExchange {
    private :
        std::map< std::string , float >   _map;
        std::string _inputFile;
        BitcoinExchange( void );

    public :
        BitcoinExchange( std::string database );
        BitcoinExchange( const BitcoinExchange& other );
        ~BitcoinExchange( void ) ;
        BitcoinExchange& operator=( const BitcoinExchange& other );

        void readDB( void );
        void fillMap( std::string line );
        void error( std::string type );
        void readInputFile( void );
        void compareDates( std::string line );
        int checkDate( std::string date );
        int checkConnector( std::string connector );
        float checkValue( std::string value );
        int checkDay( std::string day );
        int checkMonth( std::string month );
        int checkYear( std::string year );
        int checkDateValidity( std::string year, std::string month , std::string day );
        void findDate( std::string date, float val );
        std::string decreaseDate( std::string date );
};