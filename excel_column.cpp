// excel_column.cpp - Convert Excel column title to number
#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string columnTitle) {
    int result = 0;
    for (char c : columnTitle)
        result = result * 26 + (c - 'A' + 1);
    return result;
}

int main() {
    string title = "AB";
    cout << "Column Number: " << titleToNumber(title) << endl;
    return 0;
}
