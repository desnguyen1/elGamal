#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using boost::multiprecision::uint1024_t;

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
    
}