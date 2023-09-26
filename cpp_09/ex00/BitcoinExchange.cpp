#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange ( std::string inputFile ) : _inputFile( inputFile ) {
    readDB();
    readInputFile();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) : _inputFile( other._inputFile ) {
    readDB();
}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other ) {
    if (this != &other) {
        this->_inputFile = other._inputFile ;
        readDB();
    }
    return *this;
}

void BitcoinExchange::readDB( void ) {
    std::ifstream   data( DATABASE );
    std::string     line;
    
    if ( data.fail() )
        error( "Opening data.csv file." );
    getline( data, line );
    while ( !data.eof() ) {
        getline( data, line );
        fillMap( line );
    }
    data.close() ;
}

void BitcoinExchange::fillMap( std::string line ) {
    std::stringstream   s( line );
    std::string         date, rate;

    getline( s, date, ',' );
    getline( s, rate );
    _map[ date ] = atof( rate.c_str() );
}

void BitcoinExchange::error(std::string type)
{
	std::cout << FRED("Error: ") << type << std::endl;
	exit( 1 );
}

void BitcoinExchange::readInputFile( void ) {
    std::ifstream   input( _inputFile.c_str() ) ;
    std::string     line ;

    if ( input.fail() )
        error( "Invalid input file. ");
    getline( input , line );
    if ( line.compare( "date | value" ) != 0 )
        error( "Invalid input format." );
    while ( getline( input, line ) )
        compareDates( line );
    input.close();
}

void BitcoinExchange::compareDates( std::string line ) {
    std::stringstream   s(line);
    std::string         date, connector, value;

    s >> date >> connector >> value ;
    
    if ( checkDate( date ) )
        return ;
    if ( checkConnector( connector ) )
        return ;
    float val = checkValue( value ) ;
    if ( val == -1 )
        return ;
    
    findDate(date, val);
}

int BitcoinExchange::checkDate( std::string date ) {
    std::stringstream   s(date);
    std::string         year, month, day;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << FRED("Error: Bad input => ") << date << std::endl;
		return (-1);
	}
    getline(s, year, '-');
    getline(s, month, '-');
    getline(s, day);
    if ( checkYear( year ) )
        return -1;
    if ( checkMonth( month ) )
        return -1;
    if ( checkDay( day ) )
        return -1;
    if ( checkDateValidity( year, month, day ) )
        return -1;
    return 0;
}
int BitcoinExchange::checkDateValidity(std::string year, std::string month, std::string day) {
    int y = atoi(year.c_str());
    int m = atoi(month.c_str());
    int d = atoi(day.c_str());

    bool isLeapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear) {
        daysInMonth[2] = 29;
    }

    if (m < 1 || m > 12) {
        std::cout << FRED("Error: Month out of range => ") << month << std::endl;
        return (-1);
    }

    if (d < 1 || d > daysInMonth[m]) {
        std::cout << FRED("Error: Day out of range for month => ") << day << std::endl;
        return (-1);
    }

    if ( d == 1 && y == 2009 && m == 1) {
        std::cout << FRED("Error: Date out of range => ") << year << "-" << month << "-" << day << std::endl;
        return (-1);
    }


    return (0);
}

int BitcoinExchange::checkYear( std::string year ) {
    int	y = atoi(year.c_str());

	if (y < 2009)
	{
		std::cout << FRED("Error: Year out of range => ") << year << std::endl;
		return (-1);
	}
	return (0);
}

int BitcoinExchange::checkMonth( std::string month ) {
    int	m = atoi(month.c_str());

	if (m > 12 || m < 1)
	{
		std::cout << FRED("Error: Month out of range => ") << month << std::endl;
		return (-1);
	}
	return (0);
}

int BitcoinExchange::checkDay( std::string day ) {
    int	d = atoi(day.c_str());

	if (d > 31 || d < 1)
	{
		std::cout << FRED("Error: Day out of range => ") << day << std::endl;
		return (-1);
	}
	return (0);
}

int BitcoinExchange::checkConnector( std::string connector ) {
    if ( connector.compare("|") != 0 ) {
        std::cout << FRED( "Error : Bad connector." ) << std::endl;
        return ( -1 ) ;
    }
    return 0 ;
}

float BitcoinExchange::checkValue( std::string value ) {
    if ( value.size() == 0 ) {
        std::cout << FRED( "Error : No value found." ) << std::endl;
        return ( -1 ) ;
    }
    float val = atof( value.c_str() );
    if (val == 0 && value.find("0") != 0) {
        std::cout << FRED( "Error : Not digit." ) << std::endl;
        return ( -1 ) ;
    }
    if ( value.find( "-" ) == 0 ) {
        std::cout << FRED( "Error : Not a positive number." ) << std::endl;
        return ( -1 ) ;
    }
    if ( val > 1000 ) {
        std::cout << FRED( "Error : Too large a number." ) << std::endl;
        return ( -1 ) ;
    }
    return val;
}

void BitcoinExchange::findDate( std::string date, float val ) {
    if ( _map.find(date) != _map.end() )
	{
		float result = val * _map[date];
		std::cout << date << FBLU(" => ") << std::fixed << std::setprecision(2) << val << FBLU(" = ") << result << std::endl;
		return ;
	}
	else
	{
		date = decreaseDate(date);
		findDate(date, val);
	}
}

std::string BitcoinExchange::decreaseDate( std::string date ) {
    std::stringstream   s( date );
    std::string         year, month, day;

    getline(s, year, '-');
    getline(s, month, '-');
    getline(s, day);
    int y = atoi(year.c_str());
    int m = atoi(month.c_str());
    int d = atoi(day.c_str());
    if (d > 1)
		d--;
	else if (m > 1)
	{
		d = 31;
		m--;
	}
	else
	{
		d = 31;
		m = 12;
		y--;
	}
    std::stringstream conc;
    conc << y << '-' << std::setw(2) << std::setfill('0') << m << '-' << std::setw(2) << std::setfill('0') << d;
    date = conc.str();
    return( date );
}