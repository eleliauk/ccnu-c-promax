// 1）定义一个shape抽象类，派生出`Rectangle`类和`Circle`类，二者都包含虚函数`Area( )`
// 用来计算各派生类对象的面积。
// 2）设计主函数，定义一个抽象类`shape`的指针或引用，分别指向两种派生类的对象，
// 使得根据派生类对象的不同，通过该指针或引用，能正确调用派生类的成员函数`Area（）`。
#include <iostream>
using namespace std;
#define PI 3.14
class shape{
    virtual double Area() const = 0;
};
class Rectangle:public shape{
    private:
     int length;
     int width;
    public:
     Rectangle(int l,int w){
        length=l;
        width=w;
     };
     double Area() const {
        return width*length;
     }
};
class Circle:public shape{
    private:
     int raduis;
    public:
     Circle(int r){
        raduis=r;
     };
     virtual double Area(){
        return PI*raduis*raduis;
     }
};
int main(){
    int l,w,r;
    cout<<"shuru l w"<<endl;
    cin>> l >>w;
    cout<<"r"<<endl;
    cin>>r;
    Rectangle rect(l, w);


}
