// Lab_08_1_string.cpp
// Перельотін Максим Олександрович
// Лабораторна робота № 8.1 (стандартні функції мови C++ для рядків
//     string)
// Дано літерний рядок, який містить послідовність символів s[0], ...,
//     s[n], ...
// 1.   Вияснити, чи є серед цих символів пара сусідніх букв "aa" або "bb"
//     або "cc".
// 2.   Замінити кожну пару сусідніх букв "aa" або "bb" або "cc" трійкою
//     зірочок "***".
// Варіант 10

#include <iostream>
#include <string>

using namespace std;

// Повертає true, якщо рядок s містить пару "aa", "bb" або "cc"
bool HasPair(const string& s)
{
    return s.find("aa") != string::npos
        || s.find("bb") != string::npos
        || s.find("cc") != string::npos;
}

// Повертає копію рядка s, у якій кожна пара "aa", "bb", "cc" замінена на
//     "***"
string ReplacePairs(string s)
{
    size_t pos = 0;
    while ((pos = s.find_first_of("abc", pos)) != string::npos)
    {
        if (pos + 1 < s.length() && s[pos + 1] == s[pos])
        {
            s.replace(pos, 2, "***");     // замінюємо пару трьома зірочками
            pos += 3;                     // переходимо за зірочки
        }
        else
            pos++;
    }
    return s;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    if (HasPair(str))
        cout << "String contains pair aa, bb or cc" << endl;
    else
        cout << "String does not contain pairs aa, bb, cc" << endl;

    cout << "Modified string: " << ReplacePairs(str) << endl;

    return 0;
}