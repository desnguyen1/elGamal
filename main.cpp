#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

#include "keyGenerator.h"
#include "algorithms.h"
#include "elGamal.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using boost::multiprecision::uint1024_t;

int main() {
    uint1024_t primeNum, alpha, x, privateKey;
    uint1024_t gamma, delta;
    uint1024_t m, decrypted_m;

    //get public key (p, alpha, x) and private key (a)
    generateKeys(primeNum, alpha, x, privateKey);
    cout<<"\nGenerating public and private key based off of desired key size in bits.....";

    //obtain A's public key
    cout<<"\nGetting the public key.....";
    cout<<"\nPublic Key published: ("<<primeNum<<", "<<alpha<<", "<<x<<")";

    //get message to decrypt from user
    cout<<"\nMessage in integer form: ";
    cin>>m;

    //starting encryption
    //will output ciphertext of c = (gamma, delta)
    encryption(m, primeNum, x, alpha, gamma, delta);

    //starting decryption
    decrypted_m = decryption(privateKey, primeNum, gamma, delta);

    cout<<"\ndecrypted m: "<<decrypted_m;


    return 0;
}
//TODO: if errors, check the string return type in decToBinary
//TODO: fix message part, this was done to test functionality
//TODO: implement srand() instead of rand()
//TODO: fix encryption/decryption