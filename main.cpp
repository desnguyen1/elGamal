#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

#include "keyGenerator.h"
#include "algorithms.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using boost::multiprecision::uint1024_t;

int main() {
    int key_size;
    uint1024_t primeNum;

    //get key size from user
    key_size = getKeySize();

    //get random prime number based off of desired key size
    primeNum = generateLargePrime(key_size);

    bool test;
    test = millerRabinPrimalityTest(29, 10);
    cout<<"\ntest: "<<test;


    return 0;
}
//TODO: if errors, check the string return type in decToBinary