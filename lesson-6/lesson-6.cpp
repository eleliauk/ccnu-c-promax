#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

unordered_map<string, string> englishToChinese;
unordered_map<string, vector<string>> chineseToEnglish;
void loadDictionary(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string english, chinese;
        size_t pos = line.find("   ");
        if (pos != string::npos) {
            english = line.substr(0, pos);
            chinese = line.substr(pos + 3); 
            englishToChinese[english] = chinese;
            size_t start = 0, end;
            string word = chinese.substr(start);
            chineseToEnglish[word].push_back(english);
        }
    }

    file.close();
}

// 英 对 中
void queryEnglish(const string &word) {
    if (englishToChinese.find(word) != englishToChinese.end()) {
        cout << "中文解释: " << englishToChinese[word] << endl;
    } else {
        cout << "未找到英文单词: " << word << endl;
    }
}
// 中 对 英

void queryChinese(const string &word) {
    if (chineseToEnglish.find(word) != chineseToEnglish.end()) {
        cout << "相关英文单词: ";
        for (const auto &english : chineseToEnglish[word]) {
            cout << english << " ";
        }
        cout << endl;
    } else {
        cout << "未找到中文词汇: " << word << endl;
    }
}

int main() {
    string filename = "vocabulary.txt"; 
    loadDictionary(filename);

    cout << "英汉-汉英字典程序启动！" << endl;
    while (true) {
        cout << "输入单词进行查询（输入 'exit' 退出）：";
        string input;
        cin >> input;
        if (input == "exit") break;
        if (isalpha(input[0])) {
            queryEnglish(input);
        } else {
            queryChinese(input);
        }
    }

    cout << "程序退出。" << endl;
    return 0;
}