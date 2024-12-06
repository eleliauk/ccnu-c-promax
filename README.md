# C++课程要求

## 成绩构成

平时考勤：10%

课堂讨论活动：10%

平时上机：40%

期末考试：40%

## 实验1：函数重载
设计一组重载函数`add()`,至少包括:
```cpp
char add(char,int);
int add(int,int);
int add(int,int,int);
int add(int,int,double);
char * add(char *,char *);将两个字符串连接。
```
给出多种调用示例
## 实验2闹钟
利用课本中已实现了的Clock类，以组合对象的方式设计一个闹钟类。建立闹钟对象，设定闹钟。启动时钟后，在屏幕上按秒显示时钟。当时钟运行到设定的闹铃时间，屏幕显示闹铃名称后继续按秒显示时钟。
要求可以设置多个（至少两个）闹铃的时间以及名称。
可使用时钟函数 `time_t time(time_t * timer)`获取系统的时间。

## 实验3 类族对象统计
类person派生出派生类teacher和student，student派生出类graduate和undergraduate, 用各种方式建立各个类的对象，统计各类族中各类对象的个数，并显示统计结果。
```cpp
例如：person p1;//建立一个对象(调用构造函数)
teacher tn[5],t2;//以数组方式建立对象
graduate *gn=new grauate[100];//在堆中建立对象
person p2=t2;//建立一个对象(调用拷贝构造函数)
```
## 实验5
1）定义一个shape抽象类，派生出`Rectangle`类和`Circle`类，二者都包含虚函数`Area( )`，用来计算各派生类对象的面积。
2）设计主函数，定义一个抽象类`shape`的指针或引用，分别指向两种派生类的对象，使得根据派生类对象的不同，通过该指针或引用，能正确调用派生类的成员函数`Area（）`。