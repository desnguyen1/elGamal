#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using boost::multiprecision::uint1024_t;

//string -> int
//turns the letter into a number where A = 10, B = 11, a = 42, b = 43
string stringToInt(string message) {
    string output = "";
    int num;
    for (int i = 0; i < message.length(); i++) {
        //set space to 99
        if(message[i] == ' '){
            num = 99;
            //cout<<"\nspace";
        }
        else {
            //otherwise A = 65
            num = (int) message[i] - 55;
        }
        output += std::to_string(num);
        //cout<<"\nnum: "<<num;
        //cout<<"\nout: "<<output;
    }

    return output;
}

string intToString(uint1024_t decryptedMessage){
    string output="";
    char letter;
    int num;
    while(decryptedMessage > 0){
        num = ((int)decryptedMessage % 100) + 55;
        decryptedMessage /= 100;
        cout<<"\nnum: "<<num;
        letter = char(num);
        cout<<"\nletter: "<<letter;
        output += std::to_string(char(letter));
    }
    return output;
}

//decimal -> binary
string decToBinary(uint1024_t n){
    uint1024_t r;
    string binary ="";

    if(n == 0){
        binary += '0';
    }
    else{
        while(n>0){
            r = n % 2;
            n /= 2;
            if(r==1)
                binary += '1';
            else
                binary += '0';
        }
        reverse(binary.begin(), binary.end());
    }
    return binary;
}

//modular exponentiation
//output: a^k(mod n)
uint1024_t square_and_multiply(uint1024_t a, uint1024_t k, uint1024_t n){
    uint1024_t b, A;
    string binaryRep;

    //first, k must be in binary
    binaryRep = decToBinary(k);

    //reverse bits to get correct order of k
    reverse(binaryRep.begin(), binaryRep.end());

    //starting modular exponentiation
    b = 1;

    //return 1 if power is 0
    if(binaryRep == "0"){
        return b;
    }
    else{
        A = a;
        if(binaryRep[0] == '1')
            b = A;
        for(int i=1; i<binaryRep.length(); i++){
            A = pow(A, 2);
            A = A % n;
            if(binaryRep[i] == '1')
                b = (A*b)%n;
        }

        return b;
    }
}

//returns true if number is prime
bool millerRabinPrimalityTest(uint1024_t randomNum, int t){
    uint1024_t num, r = 1;
    uint1024_t a, y;
    int s=0;

    //step 1: finding 'r' and 's'
    //write n-1 = 2^s * r
    num = randomNum - 1;
    while(num != 1){
        if(num % 2 == 0){
            num /= 2;
            s++;
        }
        else{
            r *= num;
            num /= num;
        }
    }

    //step 2: primality test
    for(int i = 0; i<t; i++){
        //choose a random 'a' given 2 ≤ a ≤ n-2
        //this doesnt include n-3 number in random int, e.g., if n = 27, we will get a random a from [2,25]
        a = 2+rand() % randomNum-3;

        //compute y = a^r mod n
        y = square_and_multiply(a, r, randomNum);

    if(y != 1 && y != randomNum-1){
        int j = 1;
        while( j<= s-1 && y != randomNum-1){
            y = square_and_multiply(y, 2, randomNum);
            if(y==1) {
                return false; //randomNum is composite
            }
            j++;
        }
        if(y != randomNum-1)
            return false;//composite
    }

    }
    //cout<<"\n"<<(uint1024_t)pow(2,s) * r <<" = 2^"<<s<<" * "<<r;
    return true;
}