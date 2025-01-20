// excel_sheet_column_title.cpp - Convert number to Excel column title
#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int columnNumber) {
    string result;
    while (columnNumber > 0) {
        columnNumber--;
        result = char('A' + columnNumber % 26) + result;
        columnNumber /= 26;
    }
    return result;
}

int main() {
    int col = 28;
    cout << "Excel Title: " << convertToTitle(col) << endl;
    return 0;
}
