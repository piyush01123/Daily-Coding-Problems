---
layout: post
title: "Color image"
categories: misc
---

Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, replace the color of the given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:
```
B B W
W W W
W W W
B B B
```
Becomes
```
B B G
G G G
G G G
B B B
```


My Solution(C++):
```

#include <iostream>

#define cols 3


void colorNeighbors(char image[][cols], int rows, int locX, int locY, char color){
  // soln
  for (int i=-1; i<=1; i++){
    for (int j=-1; j<=1; j++){
      int x = locX+i-1;
      int y = locY+j-1;
      if (x>=0 && x<rows && y>=0 && y<cols && !(x==locX-1 && y==locY-1) && image[x][y]==image[locX-1][locY-1]){
        image[x][y] = color;
      }
    }
  }
  image[locX-1][locY-1] = color;
}


void test(){
  //create, run test
  char image[][cols] = {
      {'B', 'B', 'W'},
      {'W', 'W', 'W'},
      {'W', 'W', 'W'},
      {'B', 'B', 'B'}
    };
    int rows = sizeof(image)/sizeof(image[0]);
    colorNeighbors(image, rows, 2, 2, 'G');
    for (int i=0; i<rows; i++){
      for (int j=0; j<cols; j++) std::cout<<image[i][j]<<' ';
      std::cout<<'\n';
    }
}


int main(){
  //run all
  test();
  return 0;
}
```
