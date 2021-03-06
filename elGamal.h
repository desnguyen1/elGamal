#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::uint1024_t;
#ifndef ELGAMALHW_ELGAMAL_H
#define ELGAMALHW_ELGAMAL_H
void encryption(uint1024_t m, uint1024_t p, uint1024_t x, uint1024_t alpha,uint1024_t& gamma, uint1024_t& delta);
uint1024_t decryption(uint1024_t a, uint1024_t p, uint1024_t gamma, uint1024_t delta);
#endif //ELGAMALHW_ELGAMAL_H
