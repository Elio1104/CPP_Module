#include "PmergeMe.hpp"

PmergeMe::PmergeMe ( char **av ) : _unsorted( av ) {
    readInput();
    sort();
}

PmergeMe::PmergeMe( const PmergeMe &other ) : _unsorted( other._unsorted ) {
    *this = other;
    return;
}

PmergeMe::~PmergeMe( void ) {}

PmergeMe &PmergeMe::operator=( const PmergeMe &other ) {
    if (this != &other) {
        this->_unsorted = other._unsorted ;
    }
    return *this;
}

void PmergeMe::error(std::string type) {
	std::cout << FRED("Error: ") << type << std::endl;
	exit( 1 );
}

void PmergeMe::readInput() {
    int	i, j;

	i = 1;
	while (_unsorted[i])
	{
		j = 0;
		while (_unsorted[i][j])
		{
			if (isdigit(_unsorted[i][j]) == 0)
				error( "input isn't digit.");
			j++;
		}
		_vector.push_back(atoi(_unsorted[i]));
		_list.push_back(atoi(_unsorted[i]));
		i++;
	}
	printArray();
}

void PmergeMe::printArray() {
	int i = 1;
	std::cout << BOLD << FRED("Before:");
	while (_unsorted[i])
	{
		std::cout << " " << _unsorted[i];
		i++;
	}
	std::cout << std::endl;
}

void PmergeMe::printVector()
{
	std::vector<int>::iterator	it;

	std::cout << FCYN("---> Vector:") ;
	for (it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}


void PmergeMe::sort() {
    clock_t	start, finish;
	double	time_v;

	std::cout << BOLD << FRED("After:") << std::endl;
    start = clock();
	sortVector(0, _vector.size() - 1);
	finish = clock();
	time_v = ((double) (finish - start)) / CLOCKS_PER_SEC;
	printVector();

    std::cout << KYEL << "Time to process a range of " << _vector.size() << " elements with std::vector is: " << RST << std::fixed << time_v <<std::endl;
}

void PmergeMe::sortVector(int beg, int end) {
    if (end - beg > K)
	{
		int	mid = (beg + end) / 2;
		sortVector(beg, mid);
		sortVector(mid + 1, end);
		mergeVector(beg, mid, end);
	}
	else
		insertionVector(beg, end);
}

void PmergeMe::insertionVector(int beg, int end)
{
	for (int i = beg; i < end; i++)
	{
		int temp = _vector[i + 1];
		int	j = i + 1;
		while (j > beg && _vector[j - 1] > temp)
		{
			_vector[j] = _vector[j - 1];
			j--;
		}
		_vector[j] = temp;
	}
}

void PmergeMe::mergeVector(int beg, int mid, int end)
{
	int	n1 = mid - beg + 1;
	int	n2 = end - mid;
	int	right_i = 0;
	int	left_i = 0;

	std::vector<int> left(_vector.begin() + beg, _vector.begin() + mid + 1);
	std::vector<int> right(_vector.begin() + mid + 1, _vector.begin() + end + 1);

	for (int i = beg; i <= end; i++)
	{
		if (right_i == n2)
		{
			_vector[i] = left[left_i];
			left_i++;
		}
		else if (left_i == n1)
		{
			_vector[i] = right[right_i];
			right_i++;
		}
		else if (right[right_i] > left[left_i])
		{
			_vector[i] = left[left_i];
			left_i++;
		}
		else
		{
			_vector[i] = right[right_i];
			right_i++;
		}
	}
}

