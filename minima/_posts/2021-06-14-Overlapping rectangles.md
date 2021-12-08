---
layout: post
title: "Overlapping rectangles"
categories: misc
---

This problem was asked by Google.

You are given given a list of rectangles represented by min and max x- and y-coordinates. Compute whether or not a pair of rectangles overlap each other. If one rectangle completely covers another, it is considered overlapping.

For example, given the following rectangles:
```
{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
},
{
    "top_left": (-1, 3),
    "dimensions": (2, 1)
},
{
    "top_left": (0, 5),
    "dimensions": (4, 3)
}
```
return `true` as the first and third rectangle overlap each other.


My Solution(C++):
```

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

class Rectangle{
  int top, left, bottom, right;
public:
  Rectangle(int a, int b, int c, int d){
    left = a;
    top = b;
    right = left+c;
    bottom = top-d;
  }
  int area(){
    return (top-bottom)*(right-left);
  }
  bool is_intersection(Rectangle r){
    int il = std::max(left, r.left); //1
    int it = std::min(top, r.top); //4
    int ir = std::min(right, r.right); //4
    int ib = std::max(bottom, r.bottom); //2
    return (it>ib) && (ir>il);
  }
};

bool contains_intersecting_rects(std::vector<Rectangle> rects){
  std::vector<std::pair<Rectangle, Rectangle>> pairs;
  for (int i=0; i<rects.size(); i++){
    for (int j=i+1; j<rects.size(); j++) pairs.push_back(std::make_pair(rects[i], rects[j]));
  }
  for (auto p: pairs){
    if (p.first.is_intersection(p.second)) return true;
  }
  return false;
}

void test(){
  Rectangle R1(1, 4, 3, 3); //1, 4, 4, 1
  Rectangle R2 (-1, 3, 2, 1); //0, 5, 4, 2
  Rectangle R3 (0, 5, 4, 3);
  std::cout<<std::boolalpha<<"Contains Intersecting Rectangles: "<<contains_intersecting_rects({R1, R2, R3})<<'\n';
}

int main(){
  test();
  return 0;
}
```
