#include <iostream>
#include "colors.h"
#include <deque>
#include <vector>
#include <time.h>

class PmergeMe {
    private :
        static const int K = 5;
        char **_unsorted;
        std::deque<int> _deque;
        std::vector<int> _vector;

    public :
        PmergeMe( char **av );
        PmergeMe( const PmergeMe& other );
        ~PmergeMe( void ) ;
        PmergeMe& operator=( const PmergeMe& other );

        void error(std::string type);
        void readInput();
        void printArray();
        void sort();
        void sortVector(int beg, int end);
        void printVector();
        void insertionVector(int beg, int end);
        void mergeVector(int beg, int mid, int end);
        void sortDeque(int beg, int end);
        void printDeque();
        void insertionDeque(int beg, int end);
        void mergeDeque(int beg, int mid, int end);
};