
#include <iostream>
#include <cmath>

template<class T>
class Rectangle{
  T top, left, bottom, right;
public:
  Rectangle(T a, T b, T c, T d){
    left = a;
    top = b;
    right = left+c;
    bottom = top-d;
  }
  T area(){
    return (top-bottom)*(right-left);
  }
  T intersection(Rectangle r){
    T il = std::max(left, r.left); //1
    T it = std::min(top, r.top); //4
    T ir = std::min(right, r.right); //4
    T ib = std::max(bottom, r.bottom); //2
    Rectangle<T> intersect_rect(il, it, ir-il, it-ib);
    return intersect_rect.area();
  }
};

void test(){
  Rectangle<int> R1(1, 4, 3, 3); //1, 4, 4, 1
  Rectangle<int> R2 (0, 5, 4, 3); //0, 5, 4, 2
  std::cout<<"Area of intersection = "<<R1.intersection(R2)<<'\n';
}

int main(){
  test();
  return 0;
}
