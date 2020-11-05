#include <boost/multiprecision/cpp_int.hpp>
#ifndef ELGAMALHW_KEYGENERATOR_H
int getKeySize();
boost::multiprecision::uint1024_t generateLargePrime(int key_size);
#endif //ELGAMALHW_KEYGENERATOR_H
