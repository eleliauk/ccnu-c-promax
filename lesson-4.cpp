#include <iostream>

using namespace std;
class Complex{
    private:
        double real;
        double image;
    public:
        Complex(double read=0.0, double image=0.0){
            this->real = real;
            this->image = image;
        };
        void display(){
            cout << real << "+" << image << "i" << endl;
        }
        friend Complex operator+(Complex &A, Complex &B){
            return Complex(A.real+B.real, A.image+B.image);
        };
        friend Complex operator-(Complex &A, Complex &B);
         friend Complex operator-(Complex A);
        //   friend Complex operator++(Complex &A);
          friend Complex operator++(Complex &A,int);



};

// 前置++运算符重载
Complex& operator++(Complex &A){
    // 假设这里对A进行了自增操作
    return A;
}
// 后置++运算符重载
Complex operator++(Complex &A, int){
    Complex temp = A;
    // 假设这里对A进行了自增操作
    return temp;
}