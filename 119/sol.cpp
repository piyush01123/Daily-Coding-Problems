
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


vector<int> shortestCoveringInterval(vector<vector<int>> intervals){
  // Actual function for the solution
  vector<int> best_interval;
  vector<int> start_times, end_times;
  for (auto v: intervals){
    start_times.push_back(v[0]);
    end_times.push_back(v[1]);
  }
  int start = *min_element(end_times.begin(), end_times.end());
  int end =  *max_element(start_times.begin(), start_times.end());
  if (end<start) end = start;
  return vector<int> {start, end};
}


void test(){
  // Create and run a test case
  vector<vector<int>> intervals {{0, 3}, {2, 6}, {3, 4}, {6, 9}};
  vector<int> best_interval = shortestCoveringInterval(intervals);
  cout << "Required Interval = {" << best_interval[0] << ", " << \
  best_interval[1] << "}" << endl;
}


int main(){
  // Run the test
  test();
}
