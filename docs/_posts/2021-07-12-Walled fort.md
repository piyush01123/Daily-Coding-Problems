---
layout: post
title: "Walled fort"
categories: misc
---

This problem was asked by Slack.

You are given an N by M matrix of 0s and 1s. Starting from the top left corner, how many ways are there to reach the bottom right corner?

You can only move right and down. 0 represents an empty space while 1 represents a wall you cannot walk through.

For example, given the following matrix:
```
[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]
```
Return two, as there are only two ways to get to the bottom right:

- Right, down, down, right
- Down, right, down, right

The top left corner and bottom right corner will always be 0.


My Solution(C++):
```

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

#define ROWS 3
#define COLS 3


struct point{
  int x;
  int y;
  point(int a, int b){
    x = a;
    y = b;
  }
  bool operator<(const point &pt) const {
    return x<pt.x || (x==pt.x && y<pt.y);
  }
  // bool operator>(const point &pt){
  //   return x>pt.x || (x==pt.x && y>pt.y);
  // }
  // bool operator==(const point &pt){
  //   return x==pt.x && y==pt.y;
  // }

  // const point operator+(point other){
  //   return point(x+other.x, y+other.y);
  // }
  // void expensive(){
  //   int x = 1;
  //   for (int i=1; i<=10; i++) x = x*i;
  //   std::cout<<"10 factorial = "<<x<<'\n';
  // }
  // ~point(){std::cout<<"DESTROYED"<<'\n';}
};


std::ostream &operator<<(std::ostream &os, const point &pt){
  return os<<'('<<pt.x<<' '<<pt.y<<')';
}

std::set<point> adj_pts(point p){
  std::set<point> pts;

  // point f = point(p.x-1, p.y);
  // point g = point(p.x, p.y);
  // // (f+g).expensive(); //will give comp. error as f+g is now const
  // bool x = p<g;
  // std::cout<<std::boolalpha<<x;

  if (p.x>0) pts.insert(point(p.x-1, p.y));
  if (p.x<ROWS-1) pts.insert(point(p.x+1, p.y));
  if (p.y>0) pts.insert(point(p.x, p.y-1));
  if (p.y<COLS-1) pts.insert(point(p.x, p.y+1));
  return pts;
}

int numWaysUtil(int matrix[ROWS][COLS], point pt, std::set<point> &path){
  if (pt.x==ROWS-1 && pt.y==COLS-1){
    return 1;
  }
  std::set<point> adjacent = adj_pts(pt);
  std::set<point> candidates;
  std::set_difference(adjacent.begin(), adjacent.end(), path.begin(), path.end(), std::inserter(candidates, candidates.end()));
  std::vector<point> good_candidates;
  for (point p: candidates){
    if (matrix[p.x][p.y]==0) good_candidates.push_back(p);
  }
  path.insert(pt);
  int ctr = 0;
  for (point p: good_candidates){
    ctr += numWaysUtil(matrix, p, path);
  }
  return ctr;
}

int numWays(int matrix[ROWS][COLS]){
  point p = point(0, 0);
  std::set<point> pts;;
  return numWaysUtil(matrix, p, pts);
}

void test(){
  int matrix[ROWS][COLS] = {
    {0, 0, 1},
    {0, 0, },
    {1, 0, 0} };
  std::cout<<numWays(matrix)<<'\n';
}

int main(){
  // point p = point(2, 3);
  // std::cout<<p<<'\n';
  // point q = p+p;
  // std::cout<<q<<'\n';

  test();
  return 0;
}
```
