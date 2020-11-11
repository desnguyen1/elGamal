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
    string message, message_substr, decrypted_message="", str_decryptedBlock;
    int messageBlock=1, messageCount = 1;

    cout<<"\n|============Welcome to the ElGamal Encryption Scheme Simulator============|";

    //get message to decrypt from user
    cout<<"\nNote: this program does not take in any other character outside of the alphabet, otherwise it will cause errors";
    cout<<"\nEnter message to decrypt: ";
    getline(cin, message);

    //turning message into a number (A = 10, B = 11, a = 42)
    message = letterToInt(message);


    //get public key (p, alpha, x) and private key (a)
    generateKeys(primeNum, alpha, x, privateKey);
    cout << "\nGenerating public and private key based off of desired key size in bits....." << endl;

    //obtain A's public key
    cout << "\nGetting the public key.....";
    cout << "\nPublic Key published: (" << primeNum << ", " << alpha << ", " << x << ")" << endl;

    cout<<"\n===========================================================================================================";

    //need to split up message to fit in a 1024 bit variable if it is a long message
    //1024 bits have 309 digits
    while(messageCount > 0) {
        messageBlock =1;
        if (message.length() >= 309) {
            message_substr = message.substr(0, 308);
            //cout<<"\nsize of message: "<<message.length();
            message = message.erase(0, 308);
            messageCount++;
            //cout<<"\nmessage count: "<<messageCount;
        } else {
            message_substr = message;
        }
        //turing string of numbers into an integer
        std::stringstream ss;
        ss << message_substr;
        ss >> m;


        while (messageBlock > 0) {
            //otherwise nextBlock will continue to add on previously decrypted letters
            nextBlock = 0;
            //need to separate into blocks because if m >primeNum-1
            if (m > primeNum - 1)
                messageBlock++;

            //creating blocks of m if needed
            while (m > primeNum - 1) {
                leftover = m % 100;
                nextBlock = concatTwoNums(leftover, nextBlock);
                m /= 100;
                //cout<<"\nm: "<<m;
                //cout<<"\nnextBlock: "<<nextBlock;
            }

            //starting encryption
            //will output ciphertext of c = (gamma, delta)
            encryption(m, primeNum, x, alpha, gamma, delta);

            cout << "\nCiphertext for each block of m: (" << gamma << ", " << delta << ")";

            //starting decryption
            decryptedBlock = decryption(privateKey, primeNum, gamma, delta);
            str_decryptedBlock = intToLetter(decryptedBlock);
            decrypted_message += str_decryptedBlock;

            //cout << "\ndecrypted block: " << decryptedBlock;

            m = nextBlock;
            messageBlock--;

        }
        messageCount--;
    }
    cout<<"\n===========================================================================================================";
    //convert back to letters
    cout << "\n\nDecrypted message: " << decrypted_message;


    return 0;
}
