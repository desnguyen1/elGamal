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
    uint1024_t primeNum, alpha, x, privateKey;

    //get public key (p, alpha, x) and private key (a)
    generateKeys(primeNum, alpha, x, privateKey);
    cout<<"\nGenerating public and private key based off of desired key size in bits.....";

    //obtain A's public key
    cout<<"\nGetting the public key.....";
    //get message to decrypt from user



    return 0;
}
//TODO: if errors, check the string return type in decToBinary
