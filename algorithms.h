#include <boost/multiprecision/cpp_int.hpp>
#ifndef ELGAMALHW_ALGORITHMS_H
#define ELGAMALHW_ALGORITHMS_H
std::string decToBinary(boost::multiprecision::uint1024_t n);
boost::multiprecision::uint1024_t square_and_multiply(boost::multiprecision::uint1024_t a, boost::multiprecision::uint1024_t k, boost::multiprecision::uint1024_t n);
#endif //ELGAMALHW_ALGORITHMS_H
