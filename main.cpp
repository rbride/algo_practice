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
#include <string>
#include <fstream>

using std::size_t; 
using std::vector;
using std::is_same;
template<class T> //Forward Declare Merge Function to keep the same order I have in the my Notes
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
  if( is_same<int, decltype(temp)>::value ){
      std::uniform_int_distribution<int> dist(lower, upper);
      a.resize(10000);
      std::generate(a.begin(), a.end(), std::bind(dist, mte) );
  }
  else if( is_same<double, decltype(temp)>::value ){
      std::uniform_real_distribution<double> dist(0.0, 1000.0);
      a.resize(10000);
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
  if (p < r) {
    int midp = (p+r)/2;
    //std::cout << '\t' << "midpoint: " << midp << ' ';
    /* Divide the array Into 2 Recursively until you get elementary Array */
    Merge_Sort(Arr, p, midp);
    Merge_Sort(Arr, midp+1, r);
    /* Merge the Arrays, Starting with elementaries until the very end */
    Merge_Function(Arr, p, midp, r);
  }

}

template <class T>
void Merge_Function(vector<T>& Arr, int p, int q, int r){
  /* Get the Length of Each Subvector*/
  q++; //Index q to make it work as a 0 index array instead of a 1 index array
  //std::cout << "\tP: " << p << "\tQ: " << q << "\tR: " << r;
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
  //std::cout << '\n' << "size left: " << left_arr.size() << "\tright Array size: " << right_arr.size() << '\n';
  //std::cout << "left array: " << '\n';
  //std::copy(std::begin(left_arr), std::end(left_arr), std::ostream_iterator<T>(std::cout, "\t"));
  //std::cout << '\n' << "right: " << '\n';
  //std::copy(std::begin(right_arr), std::end(right_arr), std::ostream_iterator<T>(std::cout, "\t"));

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
  //std::cout<< '\n' << "ordered array" <<  '\n';
  //std::copy(std::begin(Arr), std::end(Arr), std::ostream_iterator<T>(std::cout, "\t"));
  //std::cout << '\n' << '\n';
  return;
}
/**************************************************
**************************************************/
int main(){
  /* Basic test Case */
  //vector<int> merge1 = {1,9,12,7,8,10,4,11};
  //Merge_Sort(merge1,1,6);
  /* Large 10000 Entry Test */  
  vector<int> test_int;
  fill_vector(test_int);
  vector<double> test_double;
  fill_vector(test_double);

  vector<int> test_int_copy = test_int;
  Merge_Sort(test_int, 0, static_cast<int>(test_int.size()));
  /* Run Standard Sort on the same array to have a benchmark to test against*/
  std::sort(test_int_copy.begin(), test_int_copy.end(), std::less_equal<int>());
  
  /* Output The Array Sorted via Merge sort to a file */
  std::ofstream output_file1("./merge_sort_outp.txt");
  for (const auto &e : test_int) output_file1 << e << "\n";
  output_file1.close();
  /* Output The Array Sorted via Standard Sort to a file */
  std::ofstream output_file2("./standard_sort_outp.txt");
  for (const auto &e : test_int_copy) output_file2 << e << "\n";
  output_file2.close();
 
  return 0;
}

/* unused test array
  vector<int> test_100;
  test_100 =  {
              29,38,3,93,66,17,63,39,86,57,68,2,76,63,34,1,86,1,31,29,
              97,39,91,82,56,61,16,81,45,87,44,15,14,16,58,79,45,69,7,100
              16,58,33,81,70,43,39,52,86,6,40,86,4,32,5,74,83,82,37,37,
              7,84,84,29,23,27,71,44,71,47,41,47,50,40,14,75,12,81,42,91,
              12,59,69,88,79,76,9,28,32,59,23,46,66,51,47,66,92,10,5,5
              };

  Merge_Sort(test_100, 0, static_cast<int>(test_100.size())-1);
*/

//std::copy(std::begin(merge_fun_test_vec), std::end(merge_fun_test_vec), 
//      std::ostream_iterator<int>(std::cout, "\n"));