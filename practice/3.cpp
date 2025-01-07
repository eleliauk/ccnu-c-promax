//时间加法
//一种是时钟加秒数 一种是时钟加时 分 秒
#include <iostream>
using namespace std;

class Clock {
    private:
        int H,M,S;
    public:
     void SetTime(int h,int m,int s){
        H=h,M=m,S=s;
    };
    void ShowTime(){
        cout<<H<<M<<S<<endl;
    }
    Clock(int h=0,int m=0,int s=0){
        H=h,M=m,S=s;
    }
    Clock (Clock &p){
        H=p.H,M=p.M;S=p.S;
    }
    void TimeAdd(int s);
    void TimeAdd(int h,int m,int s);
    void TimeAdd(Clock *Cp);
};
void Clock::TimeAdd(int s){
    S=(s+S)%60;
    M=(M+(S+s)/60)%60;
    H=(H+((M+(S+s)/60)%60)/60)%60;
}
void Clock::TimeAdd(Clock *Cp){
    S=(S+Cp->S)%60;
    M=(M+Cp->M+((S+Cp->S)%60)/60)%60;
    H=(H+Cp->H+((M+Cp->M+((S+Cp->S)%60)/60)%60)/60)%60;
}