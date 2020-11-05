#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::uint1024_t;
#ifndef ELGAMALHW_ALGORITHMS_H
#define ELGAMALHW_ALGORITHMS_H
std::string decToBinary(uint1024_t n);
uint1024_t square_and_multiply(uint1024_t a, uint1024_t k, uint1024_t n);
bool millerRabinPrimalityTest(uint1024_t randomNum, int t);
#endif //ELGAMALHW_ALGORITHMS_H
