#include <iostream>
#include <cmath>
using namespace std;
class Shape{
    public:
        virtual double Area() const = 0;
        virtual ~Shape() {} 
    
};
class Rectangle:public Shape{
    private:
        double length;
        double width;
    public:
        Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const override {
        return length * width;
    }
};
class Circle:public Shape{
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}
    double Area() const override {
        return M_PI  * radius * radius;
    }
};
int main (){
    double length, width, radius;
    cout << "请输入矩形的长度和宽度：";
    cin >> length >> width;
    cout << "请输入圆的半径：";
    cin >> radius;
    Rectangle rect(length, width);
    Circle circ(radius);
    Shape* shapePtr = &rect;
    cout << "矩形面积是 " << shapePtr->Area() << endl;

    shapePtr = &circ;
    cout << "圆的面积是 " << shapePtr->Area() << endl;

    Shape& shapeRef = rect;
    cout << "通过引用计算的矩形面积： " << shapeRef.Area() << endl;

    Shape& shapeRef2 = circ;
    cout << "通过引用计算的圆形面积：" << shapeRef2.Area() << endl;

    return 0;

}