#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class Clock {
public:
    void displayTime() {
        time_t now = time(0);  
        tm* localTime = localtime(&now);  
        cout << "当前时间: " 
             << localTime->tm_hour << ":" 
             << localTime->tm_min << ":" 
             << localTime->tm_sec << endl;
    }
};

class Alarm {
public:
    int hour;
    int minute;
    int second;
    string name;
    Alarm(int h, int m, int s, string alarmName) 
        : hour(h), minute(m), second(s), name(alarmName) {}

    bool isTimeToRing(tm* currentTime) {
        return currentTime->tm_hour == hour && 
               currentTime->tm_min == minute && 
               currentTime->tm_sec == second;
    }
};


class AlarmClock {
private:
    Clock clock; 
    vector<Alarm> alarms;  

public:

    void addAlarm(int hour, int minute, int second, string name) {
        alarms.push_back(Alarm(hour, minute, second, name));
    }


    void startClock() {
        while (true) {
            time_t now = time(0);  
            tm* localTime = localtime(&now);

            clock.displayTime();


            for (auto& alarm : alarms) {
                if (alarm.isTimeToRing(localTime)) {
                    cout << "闹铃响了！闹铃名称: " << alarm.name << endl;
                }
            }

            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

int main() {
    AlarmClock alarmClock;
    alarmClock.addAlarm(10, 8, 0, "午餐时间");
    alarmClock.addAlarm(16, 45, 0, "会议提醒");
    alarmClock.addAlarm(11,1,1,"上课");

    alarmClock.startClock();

    return 0;
}