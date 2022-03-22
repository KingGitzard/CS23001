#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-2.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }

    bigint bi1;
    bigint bi2;
    char c = ' ';
 
    while(in >> bi1 && in >> bi2){ 
        std::cout << "FIRST BIGINT: " << bi1 << std::endl;
        std::cout << "SECOND BIGINT: " << bi2 << std::endl;


        bigint result = bi1 * bi2;
        std::cout << "SUM OF BIGINTS: " << result << std::endl;
        c = '0';
        std::cout << std::endl;
    }
	in.close();
	return 0;
}
