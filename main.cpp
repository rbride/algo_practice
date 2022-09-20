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

/**************************************************
* Random Fill Function, fills an Array    
**************************************************/
template<class Integer, size_t SIZE>
void fill_array( std::array<Integer, SIZE>& a, Integer lower = 0, Integer upper = 30000 )
{
  static std::random_device rnd;
  static std::mt19937 mte(rnd()); //


  std::uniform_int_distribution<Integer> dist(lower, upper);
  std::generate(a.begin(), a.end(), bind(dist, mte) );

}

/**************************************************
* Merge Sort and Merge functions
* P and R are assumed to be the Beginning and end of 
* the Specified Array
**************************************************/
template <class Int_or_Float, size_t Size_Arr>
void Merge_Sort(std::array<Int_or_Float, Size_Arr>& Arr) {
  if(Arr.size() == 1){
    std::cout << '\n' << Arr[0] << "\nSorted Prime Array";
    return;
  }

  std::copy(std::begin(Arr),
    std::end(Arr),
    std::ostream_iterator<Int_or_Float>(std::cout, "\n"));

  


  return; 
}

template <class Int_or_Float, size_t Size_Arr>
void merge_function(std::array<Int_or_Float, Size_Arr>& Arr){




  return;
}
/**************************************************
**************************************************/

int main(){
  /* consider using generate and a vector in the second interation of this file*/
  std::array<int, 10000> merge_sort_test_array;
  fill_array(merge_sort_test_array);

  std::array<double, 5> test_test = {31.120, 8.145, .0005, 17.1};
  
  Merge_Sort(test_test);

  std::cout << '\n';

  std::array<double, 1> test2 = {1.1556};
  Merge_Sort(test2);


  return 0;
}


// Print array
//  std::copy(std::begin(Arr),
//           std::end(Arr),
//           std::ostream_iterator<Int_or_Float>(std::cout, "\n"));
// }