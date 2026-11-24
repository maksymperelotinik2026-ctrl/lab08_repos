// Lab_08_1_rec.cpp
// Перельотін Максим Олександрович
// Лабораторна робота № 8.1 (сканування рядка рекурсивним способом)
// Дано літерний рядок, який містить послідовність символів s[0], ...,
//     s[n], ...
// 1.   Вияснити, чи є серед цих символів пара сусідніх букв "aa" або "bb"
//     або "cc".
// 2.   Замінити кожну пару сусідніх букв "aa" або "bb" або "cc" трійкою
//     зірочок "***".
// Варіант 10

#include <iostream>

using namespace std;

// Чи є в рядку s на позиції i пара однакових сусідніх букв "aa", "bb" або
//     "cc"
bool IsPair(const char* s, int i)
{
    return s[i] != '\0' && s[i] == s[i + 1]
        && (s[i] == 'a' || s[i] == 'b' || s[i] == 'c');
}

// Повертає true, якщо рядок s, починаючи з позиції i, містить пару "aa",
//     "bb" або "cc"
bool HasPair(const char* s, int i)
{
    if (s[i] == '\0')
        return false;                 // кінець рядка: пару не знайдено
    if (IsPair(s, i))
        return true;                  // пару знайдено
    return HasPair(s, i + 1);         // шукаємо далі
}

// Записує у dest копію рядка src, у якій кожна пара "aa", "bb", "cc"
//     замінена на "***".
// i - позиція в рядку src, j - позиція в рядку dest. Повертає dest.
char* ReplacePairs(const char* src, char* dest, int i, int j)
{
    if (src[i] == '\0')
    {
        dest[j] = '\0';
        return dest;
    }
    if (IsPair(src, i))
    {
        dest[j] = '*';
        dest[j + 1] = '*';
        dest[j + 2] = '*';
        return ReplacePairs(src, dest, i + 2, j + 3);
    }
    dest[j] = src[i];
    return ReplacePairs(src, dest, i + 1, j + 1);
}

int main()
{
    char str[101];
    char dest[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (HasPair(str, 0))
        cout << "String contains pair aa, bb or cc" << endl;
    else
        cout << "String does not contain pairs aa, bb, cc" << endl;

    cout << "Modified string: " << ReplacePairs(str, dest, 0, 0) << endl;

    return 0;
}
