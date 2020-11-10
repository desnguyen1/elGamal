#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <sstream>

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
    string message, decrypted_message;

    //get message to decrypt from user
    cout<<"\nEnter message to decrypt: ";
    getline(cin, message);

    //turning message into a number (A = 10, B = 11, a = 42)
    message = stringToInt(message);
    cout<<"\nMessage in string form: "<<message;

    //turning string into int for computation
    //TODO: check that number is within range of p-1 or we have to do blocks of m
    //TODO: fix, ss is not taking in huge numbers ?? not sure
    std::stringstream ss;
    ss<<message;
    ss>>m;

    //get public key (p, alpha, x) and private key (a)
    generateKeys(primeNum, alpha, x, privateKey);
    cout<<"\nGenerating public and private key based off of desired key size in bits.....";

    //obtain A's public key
    cout<<"\nGetting the public key.....";
    cout<<"\nPublic Key published: ("<<primeNum<<", "<<alpha<<", "<<x<<")";


    //checking size of message
    if(m>primeNum-1){
        cout<<"\nbigger than prime number";
        return 0;
    }

    //starting encryption
    //will output ciphertext of c = (gamma, delta)
    encryption(m, primeNum, x, alpha, gamma, delta);

    //starting decryption
    decrypted_m = decryption(privateKey, primeNum, gamma, delta);

    cout<<"\ndecrypted m: "<<decrypted_m;

    //convert back to letters
    decrypted_message = intToString(decrypted_m);
    cout<<"\ndecrypted message: "<<decrypted_message;


    return 0;
}
//TODO: implement srand() instead of rand()
//TODO: fix 512 bits or take it out
//TODO: print ciphertext