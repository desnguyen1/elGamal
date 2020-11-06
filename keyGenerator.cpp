#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <math.h>

#include "algorithms.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using boost::multiprecision::uint1024_t;

int getKeySize(){
    int size;
    do{
        cout<<"\nKey size (bit size) options: 64, 128, 256, and 512";
        cout<<"\nEnter the desired key size: ";
        cin>>size;
    }while(size != 64 && size != 128 && size != 256 && size != 512);
    return size;
}

//generate a large random prime p based off of desire key size
uint1024_t generatePrime(int key_size){
    uint1024_t lowerBound, upperBound, range, prime=0;
    bool isPrime;

    lowerBound = (uint1024_t)pow(2, key_size-1);
    upperBound = (uint1024_t)pow(2, key_size);
    range = upperBound - lowerBound;


    while(!isPrime){
        prime = rand() % lowerBound + range;
        //to find a value with the desired number of bits, we find a number n between 2^(b-1) ≤ n ≤ 2^b

        //check primality of random number
        isPrime = millerRabinPrimalityTest(prime, 10);
        //cout<<"\nNot prime";
    }


    cout<<"\nprime number is: "<<prime;
    return prime;
}

//generate alpha given alpha is in [1,prime-1]
uint1024_t generateAlpha(uint1024_t prime){
    uint1024_t alpha;
    alpha = 1 + rand() % prime;
    //cout<<"\nalpha: "<<alpha;
    return alpha;
}


void generateKeys(uint1024_t& p, uint1024_t& alpha, uint1024_t& x, uint1024_t& privateKey){
    int key_size;
    uint1024_t a;

    //get key size from user
    key_size = getKeySize();

    //getting public keys = (p, alpha, x (where x is a^alpha (mod p))
    //getting prime number
    p = generatePrime(key_size);
    //getting alpha (generator)
    alpha = generateAlpha(p);
    //getting x
    //generate a random integer 'a' given 1 ≤ a ≤ p-2;
    a = 1 + rand() % p-2;
    //computing x using modular exponentiation
    x = square_and_multiply(alpha, a, p);

    //private key
    //cout<<"\na: "<<a;
    privateKey = a;

}
