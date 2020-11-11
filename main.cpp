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

//function declaration
uint1024_t concatTwoNums(uint1024_t num1, uint1024_t num2);

//outputs a concatenation of two numbers so 10 + 12 = 1012
uint1024_t concatTwoNums(uint1024_t num1, uint1024_t num2){
    uint1024_t times=1;
    if(num2 == 0){
        return num1*1;
    }
    while(times <= num2){
        times *= 10;
    }

    return num1*times + num2;
}

int main() {
    uint1024_t primeNum, alpha, x, privateKey;
    uint1024_t gamma, delta;
    uint1024_t m, message_int, decryptedBlock, leftover, nextBlock;
    string message, decrypted_message="", str_decryptedBlock;
    int messageBlock=1;

    //get message to decrypt from user
    cout<<"\nEnter message to decrypt: ";
    getline(cin, message);

    //turning message into a number (A = 10, B = 11, a = 42)
    message = stringToInt(message);

    //turning string into int for computation
    std::stringstream ss;
    ss<<message;
    ss>>m;

    //get public key (p, alpha, x) and private key (a)
    generateKeys(primeNum, alpha, x, privateKey);
    cout<<"\nGenerating public and private key based off of desired key size in bits.....";

    //obtain A's public key
    cout<<"\nGetting the public key.....";
    cout<<"\nPublic Key published: ("<<primeNum<<", "<<alpha<<", "<<x<<")";

<<<<<<< HEAD

    //checking size of message
    if(m>primeNum-1){
        cout<<"\nbigger than prime number";
        return 0;
    }
=======
    while(messageBlock>0){
        //otherwise nextBlock will continue to add on previously decrypted letters
        nextBlock = 0;
        //need to separate into blocks because if m >primeNum-1
        if(m>primeNum-1)
            messageBlock++;

        //creating blocks of m if needed
        while(m>primeNum-1){
            leftover = m % 100;
            nextBlock = concatTwoNums(leftover, nextBlock);
            m/=100;
            cout<<"\nm: "<<m;
            cout<<"\nnextBlock: "<<nextBlock;
        }
>>>>>>> messages

        //starting encryption
        //will output ciphertext of c = (gamma, delta)
        encryption(m, primeNum, x, alpha, gamma, delta);

        //starting decryption
        decryptedBlock = decryption(privateKey, primeNum, gamma, delta);
        str_decryptedBlock = intToString(decryptedBlock);
        decrypted_message += str_decryptedBlock;

        cout << "\ndecrypted block: " << decryptedBlock;

        m = nextBlock;
        messageBlock--;

    }
    //convert back to letters
    cout << "\ndecrypted message: " << decrypted_message;


    return 0;
}
//TODO: print ciphertext