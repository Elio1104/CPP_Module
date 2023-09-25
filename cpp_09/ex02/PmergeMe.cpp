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
        if (atol(_unsorted[i]) > 2147483647)
            error("input is larger than max int.");
		_vector.push_back(atoi(_unsorted[i]));
		_deque.push_back(atoi(_unsorted[i]));
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
	double	time_v, time_l;

	std::cout << BOLD << FRED("After:") << std::endl;

    start = clock();
	sortVector(0, _vector.size() - 1);
	finish = clock();
	time_v = ((double) (finish - start)) / CLOCKS_PER_SEC;
	printVector();

    start = clock();
	sortDeque(0, _deque.size() - 1);
	finish = clock();
	time_l = ((double) (finish - start)) / CLOCKS_PER_SEC;
	printDeque();

    std::cout << KYEL << "Time to process a range of " << _vector.size() << " elements with std::vector is: " << RST << std::fixed << time_v <<std::endl;
    std::cout << KYEL << "Time to process a range of " << _deque.size() << " elements with std::deque is: " << RST << std::fixed << time_l <<std::endl;
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

void PmergeMe::printDeque()
{
	std::deque<int>::iterator	it;

	std::cout << FCYN("---> Deque:") ;
	for (it = _deque.begin(); it != _deque.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::sortDeque(int beg, int end) {
    if (end - beg > K)
	{
		int	mid = (beg + end) / 2;
		sortDeque(beg, mid);
		sortDeque(mid + 1, end);
		mergeDeque(beg, mid, end);
	}
	else
		insertionDeque(beg, end);
}

void PmergeMe::insertionDeque(int beg, int end)
{
	for (int i = beg; i < end; i++)
	{
		int temp = _deque[i + 1];
		int	j = i + 1;
		while (j > beg && _deque[j - 1] > temp)
		{
			_deque[j] = _deque[j - 1];
			j--;
		}
		_deque[j] = temp;
	}
}

void PmergeMe::mergeDeque(int beg, int mid, int end)
{
	int	n1 = mid - beg + 1;
	int	n2 = end - mid;
	int	right_i = 0;
	int	left_i = 0;

	std::deque<int> left(_deque.begin() + beg, _deque.begin() + mid + 1);
	std::deque<int> right(_deque.begin() + mid + 1, _deque.begin() + end + 1);

	for (int i = beg; i <= end; i++)
	{
		if (right_i == n2)
		{
			_deque[i] = left[left_i];
			left_i++;
		}
		else if (left_i == n1)
		{
			_deque[i] = right[right_i];
			right_i++;
		}
		else if (right[right_i] > left[left_i])
		{
			_deque[i] = left[left_i];
			left_i++;
		}
		else
		{
			_deque[i] = right[right_i];
			right_i++;
		}
	}
}
