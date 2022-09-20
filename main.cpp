/**************************************************
 * Main file that serves to call and create data
 * types for the various algorithms being implemented
 * Then feed in and call upon the algorithms 
**************************************************/
#include "algorithms.h"
#include <cstdlib>
#include <ctime>
#include <array> 
#include <algorithm>
#include <iterator>
#include <random>
#include <iostream>

//Random Fill
template<class Integer, size_t SIZE>
void fill_array( std::array<Integer, SIZE>& a, Integer lower = 0, Integer upper = 30000 )
{
  static std::random_device rnd;
  static std::mt19937 mte(rnd()); //


  uniform_int_distribution<Integer> dist(lower, upper);
  std::generate(a.begin(), a.end(), bind(dist, mte) );

}


int main(){
  /* consider using generate and a vector in the second interation of this file*/
  std::array<int, 10000> merge_sort_test_array;
  fill_array(merge_sort_test_array);

  


  // // Forward
  // std::copy(std::begin(merge_sort_test_array),
  //           std::end(merge_sort_test_array),
  //           std::ostream_iterator<int>(std::cout, "\n"));


  return 0;
}