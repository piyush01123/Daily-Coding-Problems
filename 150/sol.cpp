
/*
This is the general implementation of KNN.
Optimized implementation uses kD-tree which I've to implement sometime soon.
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>


struct point{
  // point data structure
  int x;
  int y;
  point(int a, int b){
    x = a;
    y = b;
  }
};


std::ostream &operator<<(std::ostream &os, const point &pt){
  // cout for point struct (overloading)
  return os<<'('<<pt.x<<", "<<pt.y<<')';
}


bool comp_fn(std::vector<int>::iterator l, std::vector<int>::iterator r){
  // util fn for forming index array
  return *l < *r;
}


std::vector<int> index_array(std::vector<int> v){
  /*
  This fn can be used to get array of original indices of an array during sorting an array.
  For example:
  v = {22, 1, 53, 4, 3}
  index_array(v) = {1, 4, 3, 0, 2}
  There might be  simpler ways to achieve this
  */
  std::vector<int> indices(v.size()); // index array that will be filled later
  std::vector<int>::iterator it = v.begin();
  std::vector<std::vector<int>::iterator> itrs(v.size());
  for (int i=0; i<v.size(); i++) itrs[i] = it+i; //array of addresses(iterator objects actually)
  std::sort(itrs.begin(), itrs.end(), comp_fn); //sort by where it points to
  for (int i=0; i<v.size(); i++) indices[i] = itrs[i]-it; //reqd index array
  return indices;
}


std::vector<point> kNearestNeighbor(std::vector<point> points, point central_pt, int k){
  // simple implementation of kNN algorithm
  std::vector<int> dists; //distances from central point
  for (auto p: points){
    dists.push_back(pow(central_pt.x-p.x, 2) + pow(central_pt.y-p.y, 2));
  }

  // forming the index array of unsorted distances
  std::vector<int> indices = index_array(dists);

  // the k nearest points
  std::vector<point> k_points;
  for (int i=0; i<k; i++){
    k_points.push_back(points[indices[i]]);
  }
  return k_points;

}


void test(){
  // run a test
  std::vector<point> points = {point(0, 0), point(5, 4), point(3, 1)};
  std::vector<point> close_pts = kNearestNeighbor(points, point(1, 2), 2);
  std::cout << "Closest points to " << point(1, 2) << " are: \n";
  for (int i=0; i<2; i++) std::cout << close_pts[i] << " "; std::cout << '\n';
}


int main(){
  // all the fun
  test();
  return 0;
}
