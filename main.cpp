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
#include <limits>

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
      a.resize(1000);
      std::generate(a.begin(), a.end(), std::bind(dist, mte) );
  }
  else if( is_same<double, decltype(temp)>::value ){
      std::uniform_real_distribution<double> dist(0.0, 1000.0);
      a.resize(10000);
      //auto gen = [&dist, &mte]() { return dist(mte); }; //does the same thing as bind
      std::generate(a.begin(), a.end(), std::bind(dist, mte) );
  }
  else{
    std::cout << "Can only generate random vector of type int and Double\n";
  }

}
/**************************************************
* Merge Sort and Merge functions
* P and R are assumed to be the Beginning and end of 
* the Specified vector
**************************************************/
template<class T>
void Merge_Sort(vector<T>& Arr, int p,  int r) {
  if (p<r){
    int midpoint = ((r-p)/2);
    std::cout << '\t' << "midpoint: " << midpoint << ' ';
    Merge_Sort(Arr, p, midpoint);
    Merge_Sort(Arr,midpoint+1,r);
    /* Merge */
    Merge_Function(Arr, p, midpoint, r);
  }

  //Divide in 2 and recursively call
  // Merge_Sort(Arr, p, midpoint);
  // Merge_Sort(Arr, midpoint+1, r);


}

template <class T>
void Merge_Function(vector<T>& Arr, int p, int q, int r){
  /* Get the Length of Each Subvector*/
  int lsa1 = q - p + 1;
  int lsa2 = r - q;
  /* Create two seperate subvectors with 1 extra space each*/
  vector<T>left_arr;
  vector<T>right_arr;
  /* Copy the first half into the left vector  */
  // std::copy(Arr.begin()+p, Arr.begin()+midpoint, std::back_inserter(left_arr));
  // /* Copy the second half into the right vector */
  // std::copy(Arr.begin()+midpoint+1, Arr.begin()+r, std::back_inserter(right_arr));
  /* Add the extremes */
  std::copy(Arr.begin()+p, Arr.begin()+lsa1, std::back_inserter(left_arr));
  /* Copy the second half into the right vector */
  std::copy(Arr.begin()+lsa2, Arr.begin()+r+1, std::back_inserter(right_arr));

  left_arr.push_back(std::numeric_limits<T>::max());
  right_arr.push_back(std::numeric_limits<T>::max());
  std::cout << '\n' << "size left: " << left_arr.size() << "\tright Array size: " << right_arr.size() << '\n';
  std::cout << "left array: " << '\n';
  std::copy(std::begin(left_arr), std::end(left_arr), std::ostream_iterator<T>(std::cout, "\t"));
  std::cout << '\n' << "right: " << '\n';
  std::copy(std::begin(right_arr), std::end(right_arr), std::ostream_iterator<T>(std::cout, "\t"));

  size_t i = 0; 
  size_t j = 0;

  for (int k = p; k <= r; ++k){
    if (left_arr[i] <= right_arr[j]){
        Arr[k] = left_arr[i];
        i++;
        //std::cout << left_arr[3];
    }
    else{
        Arr[k] = right_arr[j];
        j++;
        //std::cout << "j: " << j;
    }
  }   
  std::cout<< '\n' << "ordered array" <<  '\n';
  std::copy(std::begin(Arr), std::end(Arr), std::ostream_iterator<T>(std::cout, "\t"));

  return;
}
/**************************************************
**************************************************/
//std::copy(std::begin(test1), std::end(test1), 
//          std::ostream_iterator<int>(std::cout, "\n"));
int main(){
  vector<int> test_int;
  fill_vector(test_int);
  vector<double> test_double;
  fill_vector(test_double);
  //Merge_Sort(test_int, 0, static_cast<int>(test_int.size()));
  //Merge_Sort(test_double, 0, static_cast<int>(test_double.size())-1);

  vector<int> merge_fun_test_vec = {1,7,9,12,4,8,10,11};
  Merge_Function(merge_fun_test_vec, 0, 3, 7);
  //Merge_Sort(merge_fun_test_vec, 0, 7);
  /*vector<int> test1 = {71,50,57,61,21,12,24,51,20,7,
                       2,91,11,36,71,21,78,56,8,14,
                       90,25,28,29,32 }; */

  //vector<double> test2 = {31.120, 8.145, .0005, 17.1};
  //Merge_Sort(test2, 0, test2.size()-1);
  //vector<double> test3 = {1.1556};
  //Merge_Sort(test3, 0, test3.size()-1);
  return 0;
}