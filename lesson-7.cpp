#include <iostream>
#include <string>
#include <regex>
#include <stdexcept>
#include <vector>
using namespace std;
class InvalidCharacterException : public std::runtime_error {
public:
    InvalidCharacterException(const std::string& msg) : std::runtime_error(msg) {}
};

class InvalidLengthException : public std::runtime_error {
public:
    InvalidLengthException(const std::string& msg) : std::runtime_error(msg) {}
};

class InvalidDateException : public std::runtime_error {
public:
    InvalidDateException(const std::string& msg) : std::runtime_error(msg) {}
};
void validateID(const std::string& id) {
    if (id.length() != 18) {
        throw InvalidLengthException("身份证长度不合法：" + id);
    }

    std::regex idPattern("^[0-9]{17}[0-9Xx]$");
    if (!std::regex_match(id, idPattern)) {
        throw InvalidCharacterException("身份证包含不合法字符：" + id);
    }
    std::string birthDate = id.substr(6, 8); 
    int year = std::stoi(birthDate.substr(0, 4));
    int month = std::stoi(birthDate.substr(4, 2));
    int day = std::stoi(birthDate.substr(6, 2));

    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
        throw InvalidDateException("身份证出生日期不合法：" + id);
    }
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int maxDays = (month == 2 && isLeapYear) ? 29 : daysInMonth[month - 1];

    if (day > maxDays) {
        throw InvalidDateException("身份证出生日期不合法：" + id);
    }
}
int main() {
    std::vector<std::string> idList; 
    std::string id;

    std::cout << "请输入若干个学生的身份证号（输入end结束）：\n";

    while (true) {
        std::cin >> id;
        if (id == "end") break;
        idList.push_back(id);
    }

    for (const auto& studentID : idList) {
        try {
            validateID(studentID);
            std::cout << "身份证号合法：" << studentID << "\n";
        } catch (const InvalidCharacterException& e) {
            std::cerr << "错误：" << e.what() << "\n";
        } catch (const InvalidLengthException& e) {
            std::cerr << "错误：" << e.what() << "\n";
        } catch (const InvalidDateException& e) {
            std::cerr << "错误：" << e.what() << "\n";
        }
    }

    return 0;
}