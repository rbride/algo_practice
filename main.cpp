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
// TODO: Design it so that it takes optional inputs for P and R, and if none are given
//       Specify P and R as Arr.begin() and Arr.End()
template<class Int_or_Float, size_t Size_Arr>
void Merge_Sort(std::array<Int_or_Float, Size_Arr>& Arr, int p,  int r) {
  //Return the Sorted Array if the Array is of size 1
  if(Arr.size() == 1){
    return;
  }

  size_t midpoint = (Arr.size()-1)/2;
  //Divide in 2 and recursively call
  Merge_Sort(Arr, p, midpoint);
  Merge_Sort(Arr, midpoint+1, r);

  /* Merge */
  Merge_Function(Arr, p, midpoint, r);
  
  return; 
}

template <class Int_or_Float, size_t Size_Arr>
void Merge_Function(std::array<Int_or_Float, Size_Arr>& Arr, int p, int midpoint, int r){
  /* Get the Length of Each Subarray*/
  int lsa1 = midpoint - p + 1;
  int lsa2 = r - midpoint;

  /* Create two seperate subarrays with 1 extra space each*/
  left = std::array<Int_or_Float, lsa1+1>;
  std::array<Int_or_Float, lsa2+1>right;
  

  return;
}
/**************************************************
**************************************************/

int main(){
  /* consider using generate and a vector in the second interation of this file*/
  std::array<int, 10000> merge_sort_test_array;
  fill_array(merge_sort_test_array);

  std::array<int, 25> test1 = {71,50,57,61,21,12,24,51,20,7,
                               2,91,11,36,71,21,78,56,8,14,
                               90,25,28,29,32 };
  Merge_Sort(test1, 0, test1.size()-1);
  std::copy(std::begin(test1), std::end(test1), 
            std::ostream_iterator<int>(std::cout, "\n"));
  std::cout << '\n';

  std::array<double, 5> test2 = {31.120, 8.145, .0005, 17.1};
  //Merge_Sort(test2, 0, test2.size()-1);

  //std::cout << '\n';
  std::array<double, 1> test3 = {1.1556};
  //Merge_Sort(test3, 0, test3.size()-1);
  
  

  return 0;
}


// Print array
//  std::copy(std::begin(Arr),
//           std::end(Arr),
//           std::ostream_iterator<Int_or_Float>(std::cout, "\n"));
// }