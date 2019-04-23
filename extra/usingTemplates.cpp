
#include <iostream>

template<typename T>
T getMax(T a, T b){
  return (a>b)?a:b;
}


// template<class T>

class Polynomial{
private:
  int a, b, c;
public:
  Polynomial(int a, int b, int c){
    this->a = a;
    this->b = b;
    this->c = c;
  }
  void getPoly(){
    std::cout << a << "x^2 + " << b << "x + " << c << std::endl;
  }
};


// class Complex{
// private:
//   int real, imag;
// public:
//   Complex(int r, int i){
//     real = r;
//     imag = i;
//   }
//   void print(){std::cout << real << '+' << imag <<'i' << std::endl;}
//   // void add(Complex *other){
//   // void add(Complex other){
//   Complex add(Complex other){
//     // std::cout << this->real+other->real << ", " << this->imag+other->imag << std::endl;
//     // std::cout << real+other.real << ", " << imag+other.imag << std::endl;
//     return Complex(real+other.real, imag+other.imag);
//   }
// };


class Complex{
private:
  int real, imag;
public:
  Complex(int r, int i){
    real = r;
    imag = i;
  }
  void print(){
    std::cout << real << '+' << imag << 'i' << std::endl;
  }
  Complex operator+(Complex); //simpler implementation.
  // friend Complex operator +(Complex, Complex);
  //the reason both of the above is correct is because of the rule that
  //Operator overloading function can be a member function if the Left operand is an Object of that class, but if the Left operand is different, then Operator overloading function must be a non-member function.
  //for + we are returning a complex so its okay to make it a member function

  Complex operator*(Complex);
  friend std::ostream& operator<<(std::ostream&, Complex);
};

Complex Complex::operator+(Complex other){
  return Complex(real+other.real, imag+other.imag);
}

// Complex operator +(Complex me, Complex other){
//   return Complex(me.real+other.real, me.imag+other.imag);
// }

Complex Complex::operator*(Complex other){
  return Complex(
    real*other.real - imag*other.imag,
    real*other.imag + imag*other.real
  );

}

std::ostream& operator<<(std::ostream &outit, Complex me){
  outit << me.real << " + " << me.imag << " iota" << std::endl;
  return outit;
}

int main(){
  // std::cout << getMax(5, 7) << std::endl;
  // // use as   getMax<int>(5, 7)
  // std::cout << getMax(3.1, 1.8) << std::endl;
  // // use as   getMax<double>(3.1, 1.8)
  // std::cout << getMax('a', 'b') << std::endl;
  // // use as   getMax<char>('a', 'b')
  // Polynomial p(1,2,3);
  // p.getPoly();

  // Complex c1 = Complex(1, 2);
  // Complex c2 = Complex(2, 3);
  // Complex c = c1.add(c2);
  // c.print();

  Complex c1 = Complex(1, 2);
  Complex c2 = Complex(2, 3);
  Complex c3 = Complex(3, 4);
  Complex c = c1*c2*c3;
  c.print();
  std::cout << c;



  return 0;
}
