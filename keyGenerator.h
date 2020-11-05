#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::uint1024_t;
#ifndef ELGAMALHW_KEYGENERATOR_H
int getKeySize();
uint1024_t generateLargePrime(int key_size);
#endif //ELGAMALHW_KEYGENERATOR_H
