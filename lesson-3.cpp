#include <iostream>
using namespace std;

class Person {
protected:
    static int personCount; // 记录Person对象的数量
public:
    Person() { personCount++; }
    Person(const Person& p) { personCount++; } // 拷贝构造函数
    virtual ~Person() { personCount--; }
    static int getPersonCount() { return personCount; }
};

int Person::personCount = 0;

class Teacher : public Person {
protected:
    static int teacherCount;
public:
    Teacher() { teacherCount++; }
    Teacher(const Teacher& t) : Person(t) { teacherCount++; } // 拷贝构造函数
    ~Teacher() { teacherCount--; }
    static int getTeacherCount() { return teacherCount; }
};

int Teacher::teacherCount = 0;

class Student : public Person {
protected:
    static int studentCount;
public:
    Student() { studentCount++; }
    Student(const Student& s) : Person(s) { studentCount++; } // 拷贝构造函数
    ~Student() { studentCount--; }
    static int getStudentCount() { return studentCount; }
};

int Student::studentCount = 0;

class Graduate : public Student {
protected:
    static int graduateCount;
public:
    Graduate() { graduateCount++; }
    Graduate(const Graduate& g) : Student(g) { graduateCount++; } // 拷贝构造函数
    ~Graduate() { graduateCount--; }
    static int getGraduateCount() { return graduateCount; }
};

int Graduate::graduateCount = 0;

class Undergraduate : public Student {
protected:
    static int undergraduateCount;
public:
    Undergraduate() { undergraduateCount++; }
    Undergraduate(const Undergraduate& u) : Student(u) { undergraduateCount++; } // 拷贝构造函数
    ~Undergraduate() { undergraduateCount--; }
    static int getUndergraduateCount() { return undergraduateCount; }
};

int Undergraduate::undergraduateCount = 0;

int main() {
    Person p1;  // 建立一个Person对象
    Teacher tn[5];  // 以数组方式建立Teacher对象
    Teacher t2;  // 单独建立一个Teacher对象
    Graduate* gn = new Graduate[100]; // 在堆中建立Graduate对象
    Person p2 = t2; // 调用拷贝构造函数

    cout << "Person objects: " << Person::getPersonCount() << endl;
    cout << "Teacher objects: " << Teacher::getTeacherCount() << endl;
    cout << "Student objects: " << Student::getStudentCount() << endl;
    cout << "Graduate objects: " << Graduate::getGraduateCount() << endl;
    cout << "Undergraduate objects: " << Undergraduate::getUndergraduateCount() << endl;

    delete[] gn; // 释放堆内存

    return 0;
}