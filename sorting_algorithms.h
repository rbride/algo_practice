#pragma once
#ifndef SORTING_ALGORITHMS_H_
#define SORTING_ALGORITHMS_H_
/* 
Header for sorting_algorithms.cpp which contains implementation of the sorting algorithms
defined and implemented during the course of this project / exercise
*/

#include <vector>
#include <algorithm>

using std::vector;
using std::size_t;
/**************************************************
* Merge Sort and Merge functions
* P and R are assumed to be the Beginning and end of 
* the Specified vector
**************************************************/
template <class T>
void Merge_Function(vector<T>& Arr, int p, int q, int r){
  /* Add one to q */
  q++;
  /* Create two seperate subvectors with 1 extra space each*/
  vector<T>left_arr;
  vector<T>right_arr;
  /* Copy the first half into the left vector  */
  std::copy(Arr.begin()+p, Arr.begin()+q, std::back_inserter(left_arr));
  // /* Copy the second half into the right vector */
  std::copy(Arr.begin()+q, Arr.begin()+r+1, std::back_inserter(right_arr));
  /* Add the extremes */
  left_arr.push_back(std::numeric_limits<T>::max());
  right_arr.push_back(std::numeric_limits<T>::max());
  
  size_t i = 0; 
  size_t j = 0;
  for (int k = p; k <= r; k++){
    if (left_arr[i] <= right_arr[j]){
        Arr[k] = left_arr[i];
        i++;
    }
    else{
        Arr[k] = right_arr[j];
        j++;
    }
  }   
  /* Print statements used for testing */
  //std::cout << "\tP: " << p << "\tQ: " << q << "\tR: " << r;
  //std::cout << '\n' << "size left: " << left_arr.size() << "\tright Array size: " << right_arr.size() << '\n';
  //std::cout << "left array: " << '\n';
  //std::copy(std::begin(left_arr), std::end(left_arr), std::ostream_iterator<T>(std::cout, "\t"));
  //std::cout << '\n' << "right: " << '\n';
  //std::copy(std::begin(right_arr), std::end(right_arr), std::ostream_iterator<T>(std::cout, "\t"));
  //std::cout<< '\n' << "ordered array" <<  '\n';
  //std::copy(std::begin(Arr), std::end(Arr), std::ostream_iterator<T>(std::cout, "\t"));
  //std::cout << '\n' << '\n';

  return;
}

template<class T>
void Merge_Sort(vector<T>& Arr, int p,  int r) {
  if (p < r) {
    int midp = (p+r)/2;
    /* Divide the array Into 2 Recursively until you get elementary Array */
    Merge_Sort(Arr, p, midp);
    Merge_Sort(Arr, midp+1, r);
    /* Merge the Arrays, Starting with elementaries until the very end */
    Merge_Function(Arr, p, midp, r);
  }

}
/**************************************************
**************************************************/


#endif