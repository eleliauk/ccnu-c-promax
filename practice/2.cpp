#include <iostream>
 
using namespace std;
 
class Cat
{
public:
    ~Cat()
    {
        cout << "猫挂了" << endl;
    }
};
 
 
int main()
{
    cout << "主函数开始" << endl;
 
//    Cat c1;
 
    Cat* c2 = new Cat;
    cout << "1" << endl;
    delete c2;
 
    cout << "主函数结束" << endl;
    return 0;
}