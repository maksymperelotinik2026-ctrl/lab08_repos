// Lab_08_1_cstr.cpp
// Перельотін Максим Олександрович
// Лабораторна робота № 8.1 (стандартні функції мови C для рядків char[])
// Дано літерний рядок, який містить послідовність символів s[0], ...,
//     s[n], ...
// 1.   Вияснити, чи є серед цих символів пара сусідніх букв "aa" або "bb"
//     або "cc".
// 2.   Замінити кожну пару сусідніх букв "aa" або "bb" або "cc" трійкою
//     зірочок "***".
// Варіант 10

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Повертає вказівник на першу пару "aa", "bb" або "cc" у рядку s (або
//     NULL, якщо пари немає)
const char* FindFirstPair(const char* s)
{
    const char* p[3] = { strstr(s, "aa"), strstr(s, "bb"), strstr(s, "cc") };
    const char* first = NULL;
    for (int k = 0; k < 3; k++)
        if (p[k] != NULL && (first == NULL || p[k] < first))
            first = p[k];
    return first;
}

// Повертає true, якщо рядок s містить пару "aa", "bb" або "cc"
bool HasPair(const char* s)
{
    return FindFirstPair(s) != NULL;
}

// Записує у dest копію рядка src, у якій кожна пара "aa", "bb", "cc"
//     замінена на "***".
// Повертає dest (розмір dest має бути не менший за 1,5 * strlen(src) + 1)
char* ReplacePairs(const char* src, char* dest)
{
    const char* cur = src;    // позиція, з якої продовжуємо пошук
    const char* p;            // знайдена пара
    dest[0] = '\0';
    while ((p = FindFirstPair(cur)) != NULL)
    {
        strncat(dest, cur, p - cur);    // копіюємо частину рядка перед парою
        strcat(dest, "***");            // замість пари дописуємо зірочки
        cur = p + 2;                    // переходимо за пару
    }
    strcat(dest, cur);                  // копіюємо залишок рядка
    return dest;
}

int main()
{
    char str[101];
    char dest[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (HasPair(str))
        cout << "String contains pair aa, bb or cc" << endl;
    else
        cout << "String does not contain pairs aa, bb, cc" << endl;

    cout << "Modified string: " << ReplacePairs(str, dest) << endl;

    return 0;
}