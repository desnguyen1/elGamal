#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::uint1024_t;
#ifndef ELGAMALHW_KEYGENERATOR_H
int getKeySize();
uint1024_t generatePrime(int key_size);
uint1024_t generateAlpha(uint1024_t prime);
void generateKeys(uint1024_t& p, uint1024_t& alpha, uint1024_t& x, uint1024_t& privateKey);
#endif //ELGAMALHW_KEYGENERATOR_H
