/**************************************************
 * Main file that serves to call and create data
 * types for the various algorithms being implemented
 * Then feed in and call upon the algorithms 
**************************************************/
#include <cstddef>
#include <vector> 
#include <algorithm> 
#include <random> 
#include <iostream> 
#include <type_traits> 
#include <fstream>
#include "sorting_algorithms.h"

using std::size_t; 
using std::vector;
template<class T> //Forward Declare Merge Function to keep the same order I have in the my Notes
void Merge_Function(vector<T>&, int, int, int);

/**************************************************
* Random Fill Function, fills an vector    
**************************************************/
template<class T>
void fill_vector( std::vector<T>& a, int lower = 1, int upper = 30000 )
{
  using std::is_same;
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

int main(){
   //Large random 10000 entry test Int and Double vector generation 
  /* Large random 10000 entry test Int and Double vector generation */  
  vector<int> test_int;
  fill_vector(test_int);
  vector<double> test_double;
  fill_vector(test_double);
  /* Make an exact copy of the test vectors to run using a standard sort to test for accuracy */
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

/*
Merge sort functions called and used in the first iteration of main
 //Large random 10000 entry test Int and Double vector generation 
  vector<int> test_int;
  fill_vector(test_int);
  vector<double> test_double;
  fill_vector(test_double);
  //Make an exact copy of the test vectors to run using a standard sort to test for accuracy
  vector<int> test_int_copy = test_int;
  Merge_Sort(test_int, 0, static_cast<int>(test_int.size()));
  //Run Standard Sort on the same array to have a benchmark to test against
  std::sort(test_int_copy.begin(), test_int_copy.end(), std::less_equal<int>());
  
  //Output The Array Sorted via Merge sort to a file 
  std::ofstream output_file1("./merge_sort_outp.txt");
  for (const auto &e : test_int) output_file1 << e << "\n";
  output_file1.close();
  //Output The Array Sorted via Standard Sort to a file
  std::ofstream output_file2("./standard_sort_outp.txt");
  for (const auto &e : test_int_copy) output_file2 << e << "\n";
  output_file2.close();

*/
/* Example of print function I used throughout the file */
//std::copy(std::begin(merge_fun_test_vec), std::end(merge_fun_test_vec), 
//      std::ostream_iterator<int>(std::cout, "\n"));