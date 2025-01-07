//定义⼀个Student类，其中含学号、姓名、成绩数据成员。建立若⼲个Student类对象，将它们保存到⽂件
//Record.dat中（写⽂件），然后显⽰⽂件中的内容（读⽂件）。（部分主函数如下）
//void main(){ 
//Student S1[3]={Student(200907001,"Tom",76),Student(200907002,"John",82),
//Student(200907003,"Wilson",95) };
//}
#include <iostream>
#include <fstream>
using namespace std;
class Student {
    private:
        long studentId;
        char * Name;
        int score;
    public:
        Student(long studentId=0,char *Name="woshisb",int score=61){

        };
        ~Student(){
        }
        void showStudent(){
            cout<<studentId<<Name<<score<<endl;
        }

};

int main (){
    Student S1[3]={Student(200907001,"Tom",76),Student(200907002,"John",82),
Student(200907003,"Wilson",95) };
    fstream objfile;
    objfile.open("./Record.dat",ios::in|ios::out|ios::binary|ios::trunc);
    for (int i=0;i<3;i++)
    objfile.write((char *)&S1[i],sizeof(S1[i]));
    Student S;
    objfile.seekg(0,ios::beg);
    objfile.read((char *)&S,sizeof(S));
    while(!objfile.eof()){
        S.showStudent();
        objfile.read((char *)&S,sizeof(S));
    }
    return 0;
}
