// EXAM.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Труков Владимир ПР-315

#include <iostream>

using namespace std;

// Длина строки для работы другой функции
int GetLength(char* str) {
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

// Функция по заданию
int Function(char* str1, char* str2) {
    int result = 0;
    int str1Length = GetLength(str1);
    for (int i = 0; i < str1Length; i++)
    {
        if (str1[i]== str2[i] && result == 0)
            continue;
        else if (str1[i] == str2[i] && result != 0)
            break;
        else
            result++;
    }

    return result;
}

int main() {
    // Заготовленный пример
    char myStr1[] = "123456789";
    char myStr2[] = "abc456789";

    int result1 = Function(myStr1, myStr2);
    cout << "---Example 1---\n" << "String 1: " << myStr1 << "\n" << "String 2: " << myStr2 << "\n" << "Result: " << result1 << "\n";
    
    // Проверка
    char str1[1024];
    char str2[1024];

    cout << "\n\n---Example 2---\nString 1: ";
    cin >> str1;
    cout << "String 2: ";
    cin >> str2;

    int result2 = Function(str1, str2);
    cout << "\nResult: " << result2 << "\n\n";

    system("pause");
    return 0;
}