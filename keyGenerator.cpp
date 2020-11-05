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
uint1024_t generateLargePrime(int key_size){
    uint1024_t lowerBound, upperBound, range, largePrime=0;
    bool isPrime;

    lowerBound = (uint1024_t)pow(2, key_size-1);
    upperBound = (uint1024_t)pow(2, key_size);
    range = upperBound - lowerBound;

    while(!isPrime){
        largePrime = rand() % lowerBound + range;
        //to find a value with the desired number of bits, we find a number n between 2^(b-1) ≤ n ≤ 2^b

        //check primality of random number
        isPrime = millerRabinPrimalityTest(largePrime, 10);
        cout<<"\nNot prime";
    }


    cout<<"prime number is: "<<largePrime;
    return largePrime;
}

//TODO: fix t