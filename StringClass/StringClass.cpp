//
//  main.cpp
//  prStringClass
//
//  Created by Владимир Труков on 20.11.2021.
//

#include <windows.h>
#include <iostream>
using namespace std;

class Strings
{
private:
    char* Str;
    int length;
public:
    // Консуктор
    Strings(const char* data = " ", int len = 0) : length(len)
    {
        Str = new char[length];
        for (int i = 0; i < len; i++)
            Str[i] = data[i];
    }

    // Операторы ввода и вывода
    friend istream& operator>>(istream& in, Strings& str) {
        in >> str.Str;
        str.length = str.StringLength();
        return in;
    }
    friend ostream& operator<<(ostream& out, const Strings& str) {
        out << str.Str;
        return out;
    }

    // Индекс, присваивание, конактенация
    char operator[] (const int index);
    friend Strings operator+(const Strings& str, const Strings& str2) {
        Strings strres;
        strres.length = str.length + str2.length;
        strres.Str = new char[strres.length];
        int i = 0;
        for (int j = 0; i < strres.length; i++)
        {
            if (i < str.length)
                strres.Str[i] = str.Str[i];
            else
            {
                strres.Str[i] = str2.Str[j];
                j++;
            }
        }
        strres.Str[strres.length] = '\0';
        return strres;
    }
    Strings& operator= (const Strings& str) {
        Str = new char[str.length];
        int i;
        for (i = 0; i < str.length; ++i)
            Str[i] = str.Str[i];
        Str[i] = '\0';
        return *this;
    }

    // Условные операторы
    friend bool operator== (const Strings& str, const Strings& str2) {
        return (str.length == str2.length);
    }
    friend bool operator!= (const Strings& str, const Strings& str2) {
        return !(str == str2);
    }
    friend bool operator> (const Strings& str, const Strings& str2) {
        return (str.length > str2.length);
    }
    friend bool operator< (const Strings& str, const Strings& str2) {
        return (str.length < str2.length);
    }
    friend bool operator<= (const Strings& str, const Strings& str2) {
        return (str.length <= str2.length);
    }
    friend bool operator>= (const Strings& str, const Strings& str2) {
        return (str.length >= str2.length);
    }

    // Методы
    int StringLength()
    {
        int Len;
        for (Len = 0; Str[Len] != '\0'; Len++) {}
        return Len;
    }
    Strings CopyingAString(Strings Str, int Start, int Len)
    {
        Strings StrRes;
        int i = 0, StartRem = Start;
        if (Start < 0)
            Start = 0;
        else if (Len + Start > Str.StringLength())
            Len = Str.StringLength() - Start;
        for (i; i < Len || i < Str.StringLength(); i++, Start++)
        {
            if (Len <= 0 || Len == 0 || i > StartRem)
            {
                break;
            }
            StrRes.Str[i] = Str[Start];
        }
        StrRes.Str[i] = '\0';
        return StrRes;
    }
    Strings DeletingASubstring(Strings Str, int Start, int Len)
    {
        Strings StrRes;
        int i = 0, j = 0;
        if (Start < 0)
            Start = 0;
        else if (Len + Start > Str.StringLength())
            Len = Len - Start;
        for (int i = 0; i < Str.StringLength() || (Start < 0 && Len > Str.StringLength()); i++)
            if (!(i >= Start && i < Len + Start))
                StrRes.Str[j++] = Str[i];
        StrRes.Str[j] = '\0';
        return StrRes;
    }
    Strings InsertingASubstring(Strings Str1, int Start, Strings Str2)
    {
        Strings StrRes;
        int i = 0, j = 0, l = 0;
        if (Start < 0)
            Start = 0;
        else if (Start > Str1.StringLength())
            Start = Str1.StringLength();
        for (i = 0; i < Start; i++)
            StrRes.Str[i] = Str1[i];
        l = i;
        for (i, j; j < Str2.StringLength(); i++, j++)
            StrRes.Str[i] = Str2[j];
        for (i, l; i < Str1.StringLength() + Str2.StringLength(); i++, l++)
            StrRes.Str[i] = Str1[l];
        StrRes.Str[i] = '\0';
        return StrRes;
    }
    int SearchForTheFirstOccurrence(Strings Str1, Strings Str2)
    {
        int OccPos = -1, i = 0, j = 0;
        for (i; i < Str1.StringLength(); i++)
            if (Str1[i] == Str2[j] && j++ < Str2.StringLength())
                OccPos = i;
        if (OccPos != -1)
            OccPos = OccPos - Str2.StringLength() + 1;
        return OccPos;
    }
    int SearchForTheLastOccurrence(Strings Str1, Strings Str2)
    {
        int OccPos = -1;
        int Len1 = Str1.StringLength();
        int Len2 = Str2.StringLength();
        for (Len1; Len1 > -1; Len1--)
            if (Str1[Len1] == Str2[Len2])
            {
                Len2--;
                OccPos = Len1;
            }
        if (OccPos == Str1.StringLength())
            OccPos = -1;
        return OccPos;
    }
    Strings RepacingTheFirstOccurrence(Strings Str1, Strings Str2, Strings Str3)
    {
        Strings StrRes;
        int Check = 0, OccNum = -1, i, j, l = 0;
        int Len2_Len3 = abs(Str2.StringLength() - Str3.StringLength());
        for (i = 0, j = 0; Check != Str2.StringLength() && i < Str1.StringLength(); i++) {
            if (Str1[i] == Str2[j++]) {
                if (Check == 0)
                    OccNum = i;
                Check++;
            }
            else {
                if (Check != 0)
                    i--;
                j = 0;
                Check = 0;
                OccNum = -1;
            }
        }
        i = 0, j = 0;
        if (OccNum != -1) {
            for (i; i < OccNum; i++)
                StrRes.Str[i] = Str1[i];
            for (i; i < OccNum + Str3.StringLength(); i++, j++)
                StrRes.Str[i] = Str3[j];
            if (Str2.StringLength() > Str3.StringLength())
            {
                l = i + Len2_Len3;
            }
            else if (Str2.StringLength() < Str3.StringLength())
            {
                l = i - Len2_Len3;
            }
            else {
                l = i;
            }
            for (i; i < Str1.StringLength() + Len2_Len3 || l < Str1.StringLength(); i++, l++)
                StrRes.Str[i] = Str1[l];
            StrRes.Str[i++] = '\0';
        }
        return StrRes;
    }
    Strings ReplacingAllOccurrences(Strings Str1, Strings Str2, Strings Str3)
    {
        Strings StrRes;
        int Check = 0, OccPos = 0, i = 0, j, LenRes, Mem = 0, Check2 = 0;
        int Len2_Len3 = abs(Str2.StringLength() - Str3.StringLength());
        for (int write = 0; write < Str1.StringLength() + 1; write++)
            StrRes.Str[write] = Str1[write];
        while (OccPos != -1) {
            OccPos = -1, Check = 0;
            for (LenRes = 0; StrRes[LenRes] != '\0'; LenRes++) {};
            for (j = 0; Check != Str2.StringLength() && Mem < LenRes; Mem++) {
                if (StrRes[Mem] == Str2[j++]) {
                    if (Check == 0)
                        OccPos = Mem;
                    Check++;
                }
                else {
                    if (Check != 0)
                        Mem--;
                    j = 0, Check = 0, OccPos = -1;
                }
            }
            Mem = OccPos + Str3.StringLength(), j = 0;
            if (OccPos != -1) {
                if (Str3.StringLength() > Str2.StringLength()) {
                    for (i = LenRes - 1; i > OccPos + Str2.StringLength() - 1; i--)
                        StrRes.Str[i + Len2_Len3] = StrRes.Str[i];
                }
                else if (Str2.StringLength() > Str3.StringLength()) {
                    for (i = OccPos + Str2.StringLength() - 1; i < LenRes; i++)
                        StrRes.Str[i - Str2.StringLength() + 1] = StrRes.Str[i];
                    Check2++;
                }
                for (i = OccPos; i < OccPos + Str3.StringLength(); i++, j++)
                    StrRes.Str[i] = Str3[j];

            }
            if (Str2.StringLength() > Str3.StringLength())
                StrRes.Str[(LenRes + Str2.StringLength()) - 1 - Check2] = '\0';
            else
                StrRes.Str[LenRes + Len2_Len3] = '\0';
        }
        return StrRes;
    }

    //Деструктор
    ~Strings()
    {
    }
};
char Strings::operator[] (const int index) {
    return Str[index];
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Strings str1, str2, str3, result, resultStr;

    int startIndex, lengthSubStr;

    //------------------------------------------------------------

    cout << "          --- Конкатенация двух строк ---\n";

    cout << "Строка 1:\n";
    cin >> str1;

    cout << "Строка 2:\n";
    cin >> str2;

    cout << "\nРезультат: \n" << str1 + str2 << endl;

    cout << "__________________________________________\n\n";

    //------------------------------------------------------------

    cout << "          --- Сравнение двух строк ---\n";

    if (str1 == str2)
        cout << "Строка 1 == Строка 2\n";
    else if (str1 > str2)
        cout << "Строка 1 > Строка 2\n";
    else if (str1 < str2)
        cout << "Строка 1 < Строка 2\n";

    cout << "__________________________________________\n\n";

    //------------------------------------------------------------

    cout << "          --- Индекс ---\n";

    cout << "\nУкажите индекс символа для вывода: ";
    cin >> startIndex;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "\nОшибка ввода!\n";
        cout << "\nУкажите индекс символа для вывода: ";
        cin >> startIndex;
    }

    cout << "Строка 1 содержит по индексу " << startIndex << " символ " << str1[startIndex] << endl;

    cout << "__________________________________________\n\n";

    //------------------------------------------------------------

    cout << "          --- Удаление подстроки ---\n";

    cout << "Строка:\n";
    cin >> str1;

    cout << "\nУкажите номер начала удаления: ";
    cin >> startIndex;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "\nОшибка ввода!\n";
        cout << "\nУкажите номер начала удаления: ";
        cin >> startIndex;
    }

    cout << "\nУкажите длину подстроки: ";
    cin >> lengthSubStr;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "\nОшибка ввода!\n";
        cout << "\nУкажите длину подстроки: ";
        cin >> lengthSubStr;
    }

    cout << "\nРезультат: \n" << resultStr.DeletingASubstring(str1, startIndex, lengthSubStr) << endl;

    cout << "__________________________________________\n\n";

    //------------------------------------------------------------

    cout << "          --- Вставка подстроки ---\n";

    cout << "Строка:\n";
    cin >> str1;

    cout << "\nВставляемая строка:\n";
    cin >> str2;

    cout << "\nУкажите индекс начала вставки: ";
    cin >> startIndex;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "\nОшибка ввода!\n";
        cout << "\nУкажите индекс начала вставки: ";
        cin >> startIndex;
    }

    cout << "\nРезультат: \n" << resultStr.InsertingASubstring(str1, startIndex, str2) << endl;

    cout << "__________________________________________\n\n";

    //------------------------------------------------------------

    cout << "          --- Замена подстроки ---\n";

    cout << "Строка:\n";
    cin >> str1;

    cout << "Заменяемая подстрока:\n";
    cin >> str2;

    cout << "На что заменить:\n";
    cin >> result;

    cout << "\nРезультат: \n" << resultStr.ReplacingAllOccurrences(str1, str2, result) << endl;

    cout << "__________________________________________\n\n";

    return 0;
}
