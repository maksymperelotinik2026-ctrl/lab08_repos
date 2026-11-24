// Lab_08_2.cpp
// Перельотін Максим Олександрович
// Лабораторна робота № 8.2
// Дано літерний рядок, який містить послідовність символів s[0], ...,
//     s[n], ...
// Групи символів, відокремлені пробілами (одним або кількома) і які не
//     містять
// пробілів, називаємо словами. Визначити, чи рядок містить слово,
// яке починається з букви "a".
// Варіант 10

#include <iostream>
#include <string>

using namespace std;

// Повертає true, якщо рядок s містить слово, яке починається з букви 'a'
// (слово починається там, де символ не є пробілом, а попередній символ -
//     пробіл або початок рядка)
bool HasWordStartingWithA(const string& s)
{
    for (size_t i = 0; i < s.length(); i++)
        if (s[i] == 'a' && (i == 0 || s[i - 1] == ' '))
            return true;
    return false;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    if (HasWordStartingWithA(str))
        cout << "String contains a word that starts with 'a'" << endl;
    else
        cout << "String does not contain words that start with 'a'" << endl;

    return 0;
}