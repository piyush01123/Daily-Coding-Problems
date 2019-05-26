
/*
types of polymorphism:
1 - ad-hoc; or overloading further subdivided into function overloading and operator overloading.
eg. func(int), func(int, int): same function with 2/more signatures. only by arguments (#args, type of args) not by return type.
2 - parametric; meaning function which can accept any type of argument eg
template<typename T>
func(T t);
This is also called compile time polymorphism
3 - Subtype polymorphism (this is what they mean when they say polymorphism); this is achieved by function overriding ie overriding a function of base class in the child class. Most often, we override a virtual function if the base class is abstract.
Mental note - You cannot have objects of abstract classes(however you can have pointers), hence making this polymorphism extremely useful for such classes.
This is also caled Run-time polymorphism.
4 - coercion polymorphism or casting; is of two types - implicit eg when a func(int x) is called on a double, the compiler accepts it by casting the variable to int, and explicit ie using static_cast, dynamic_cast, interpret_cast.
subtype polymorphism can be seen as a special case of coercion polymorphism.
*/

#include <iostream>
#include <vector>
#include <string>

// ad-hoc polymorphism
int add(int a, int b){
  std::cout<<"add method with 2 args"<<'\n';
  return a+b;
}

int add(int a, int b, int c){
  std::cout<<"add method with 3 args"<<'\n';
  return a+b+c;
}

void test1(){
  add(1, 2);
  add(1, 2, 3);
}


// parametric polymorphism
template<typename T>
T combine(const std::vector<T> &v, T init_val){
  T sum = init_val;
  for (int i=0; i<v.size(); i++){
    sum+=v[i];
  }
  return sum;
}

#define str std::string
void test2(){
  std::cout<<combine({1, 2}, 0)<<'\n';
  std::cout<<combine({str("hello "), str("world")}, str(""))<<'\n';
}


//Subtype polymorphism
class Base_{
public:
  virtual void show() = 0;
};
//example of an abstract class
//above class can't be used to create an object. We must override the show method.

class Child_: public Base_{
public:
  void show(){
    std::cout<<"show method in child"<<'\n';
  }
};
//usable class

void test3(){
  Child_ c;
  c.show();
}


//coercion polymorphism
class crazyInt{
private:
  int val;
public:
  crazyInt(int i){
    val = i;
  }
  operator int() const{
    return val;
  } //this will enable an object of type crazyint to be used as an int
};

void test4(){
  crazyInt c = 25; //possible because of the operator int method
  std::cout<<"tests successful"<<'\n';
}


int main(){
  std::cout<<"--Ad-hoc polymorphism--"<<'\n';
  test1();
  std::cout<<"--Parametric polymorphism--"<<'\n';
  test2();
  std::cout<<"--Subtype polymorphism--"<<'\n';
  test3();
  std::cout<<"--Coercion polymorphism--"<<'\n';
  test4();
  return 0;
}
