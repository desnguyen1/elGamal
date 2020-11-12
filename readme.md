# ElGamal Asymmetric Encryption Scheme
Destiny Nguyen

Z: 23397389

Assignment - 03: ElGamal Asymmetric Encryption/Decryption 

## How to Run the Program
This zip folder will already include an executable file named `elGamalHW`

Go inside the project folder, e.g., if the project folder is placed in Desktop: `cd Desktop/elGamalHW` then go into the `build` folder so file path would be similar to `Desktop/elGamalHW/build` 

Then run the following command

`./elGamalHW`

## File Contents
main.cpp
> Contains the general code to run the program and includes a function called `concatTwoNums()` which will concatenate two integers, e.g., 10 and 22 = 1022.

elGamal.cpp
> This file contains the functions `encryption()` and `decryption()` for encrypting and decrypting the user's message.

keyGenerator.cpp
> This file contains the functions required to generate the user's desired key size. The functions are:
> * getKeySize() -> gets the desired key size from the user; choices are 64, 128, or 256 bits
> * generatePrime() -> generates a random prime number based on desired key size
> * generateAlpha() -> generates the 'generator' or alpha needed
> * generateKeys() -> uses the above function to generate the public and private key

algorithms.cpp
> This file contains the functions of the algorithms needed for the encryption/decryption. The functions are:
> * letterToInt() -> takes the letters from the message string and converts it to the corresponding number where A=10, B=11, a=43, b=43, and spaces = 99; outputs this as a string
> * intToLetter() -> the opposite of the above function; this will turn the integers back into letters; outputs a string of letters
> * decToBinary() -> takes an integer and convert into binary
> * square_and_multiply() -> modular exponentiation; to compute $a^k(mod n)$
> * millerRabinPrimalityTest() -> used to test primality of a number

## Program Outline
* Get the message from user
* get the desired key size from user
* generate public and private keys
> will also check for primality and perform modular exponentiation
* converts the message into number blocks where each block is a number ≤ p-1
* encrypts the message block to get ciphertext
* decrypts that block of ciphertext
* converts the number block back to letters
* outputs the decrypted ciphertext


## Some Notes
* The boost c++ library was utilized to allow large numbers of up to 256 bits. While the data type is set to `uint1024_t`, the program can only take up to 256 bits before miscalculation occurs. This is a bug that can be fixed in the future. 
* In order to get m into a number, I had to convert each letter where 'A' = 10, 'B' = 11, 'a' = 42, and spaces = 99. Then I used sstream library to transform the string of integers to an actual integer. This may be the reason why characters outside the alphabet will create an error, which can be fixed in the future.
* When converting a string of numbers to an integer type, the variable that holds the converted string, can only take up to 1024 bits, which means long messages will get cut off or cause errors. Therefore, in this program, it will break up the integer message into blocks if message.length() >= 309 (because a 1024 bit number has roughly 309 bits). 