#include <iostream>
using namespace std;

class String {
private:
    char* data;
    size_t length;
    static int count;

public:
    String() : length(80) {
        data = new char[length + 1];
        for (size_t i = 0; i < length; i++) {
            data[i] = '\0';
        }
        data[length] = '\0';
        count++;
    }

    String(size_t size) : length(size) {
        data = new char[length + 1];
        for (size_t i = 0; i < length; i++) {
            data[i] = '\0';
        }
        data[length] = '\0';
        count++;
    }

    String(const char* str) {
        length = 0;
        while (str[length] != '\0') {
            length++;
        }
        data = new char[length + 1];
        for (size_t i = 0; i < length; i++) {
            data[i] = str[i];
        }
        data[length] = '\0';
        count++;
    }

    ~String() {
        delete[] data;
        count--;
    }

    void input() {
        char temp[256];
        cin.getline(temp, 256);
        delete[] data;
        length = 0;
        while (temp[length] != '\0') {
            length++;
        }
        data = new char[length + 1];
        for (size_t i = 0; i < length; i++) {
            data[i] = temp[i];
        }
        data[length] = '\0';
    }

    void output() {
        cout << data << endl;
    }

    static int getCount() {
        return count;
    }
};

int String::count = 0;

int main() {
    String str1;
    str1.input();
    str1.output();

    String str2(20);
    str2.input();
    str2.output();

    String str3("Hello, world!");
    str3.output();

    cout << "Count: " << String::getCount() << endl;

    return 0;
}