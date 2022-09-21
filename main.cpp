/**************************************************
 * Main file that serves to call and create data
 * types for the various algorithms being implemented
 * Then feed in and call upon the algorithms 
**************************************************/
#include "algorithms.h"
#include <cstdlib>
#include <ctime>
#include <vector> 
#include <algorithm>
#include <iterator>
#include <random>
#include <iostream>
#include <type_traits>

using std::size_t; 
using std::vector;
using std::is_same;
//Forward Declare Merge Function to keep the same order I have in the my Notes
template<class T>
void Merge_Function(vector<T>&, int, int, int);

/**************************************************
* Random Fill Function, fills an vector    
**************************************************/
template<class T>
void fill_vector( std::vector<T>& a, int lower = 1, int upper = 30000 )
{
  T temp;
  static std::random_device rnd;
  static std::mt19937 mte(rnd()); //
  //std::cout << std::boolalpha << '\n' << is_same<int, decltype(t)>::value << '\n';
  
  if( is_same<int, decltype(temp)>::value ){
      std::uniform_int_distribution<int> dist(lower, upper);
      a.resize(10000);
      std::generate(a.begin(), a.end(), std::bind(dist, mte) );
  }
  else if( is_same<double, decltype(temp)>::value ){
      std::cout << "\nFloats are broken\nSad!\n"
      /*
      std::uniform_real_distribution<double> dist(1.0, 1000.0);
      a.resize(10000);
      std::generate(a.begin(), a.end(), std::bind(dist, mte) );
      */
  }
  else{
    std::cout << "Can only generate random vector of type int and Double\n";
  }
  
  return;
}

/**************************************************
* Merge Sort and Merge functions
* P and R are assumed to be the Beginning and end of 
* the Specified vector
**************************************************/
// TODO: Design it so that it takes optional inputs for P and R, and if none are given
//       Specify P and R as Arr.begin() and Arr.End()
template<class T>
void Merge_Sort(vector<T>& Arr, int p,  int r) {
  //Return the Sorted vector if the vector is of size 1
  if(Arr.size() == 1){
    return;
  }

  int midpoint = (static_cast<int>(Arr.size())-1)/2;
  //Divide in 2 and recursively call
  Merge_Sort(Arr, p, midpoint);
  Merge_Sort(Arr, midpoint+1, r);

  /* Merge */
  Merge_Function(Arr, p, midpoint, r);
  
  return; 
}

template <class T>
void Merge_Function(vector<T>& Arr, int p, int midpoint, int r){
  /* Get the Length of Each Subvector*/
  int lsa1 = midpoint - p + 1;
  int lsa2 = r - midpoint;
  
  /* Create two seperate subvectors with 1 extra space each*/
  vector<T>left_arr;
  vector<T>right_arr;



  return;
}
/**************************************************
**************************************************/

int main(){
  /* consider using generate and a vector in the second interation of this file*/
  vector<int> test;
  fill_vector(test);
  // std::copy(std::begin(test), std::end(test), 
  //           std::ostream_iterator<int>(std::cout, "\t"));
  
  vector<int> test1 = {71,50,57,61,21,12,24,51,20,7,
                       2,91,11,36,71,21,78,56,8,14,
                       90,25,28,29,32 };


  Merge_Sort(test1, 0, static_cast<int>(test1.size())-1);
  std::copy(std::begin(test1), std::end(test1), 
            std::ostream_iterator<int>(std::cout, "\n"));
  
  std::cout << '\n';

  vector<double> test2 = {31.120, 8.145, .0005, 17.1};
  //Merge_Sort(test2, 0, test2.size()-1);

  //std::cout << '\n';
  vector<double> test3 = {1.1556};
  //Merge_Sort(test3, 0, test3.size()-1);
  
  

  return 0;
}


// Print vector
//  std::copy(std::begin(Arr),
//           std::end(Arr),
//           std::ostream_iterator<Int_or_Float>(std::cout, "\n"));
// }