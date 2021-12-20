#include "pch.h"
#include "framework.h"
#include "FunctionsForText.h"

extern "C" __declspec(dllexport) int FindStringLength(char* str) {
	int num_of_char = 0;
	while (str[num_of_char] != '\0') {
		num_of_char++;
	}
	return num_of_char;
}

extern "C" __declspec(dllexport) char *Concatenation(char* str1, char* str2) {
    char concatenation[1024];
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        concatenation[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        concatenation[i] = str2[j];
        i++, j++;
    }
    concatenation[i++] = '\0';
    return concatenation;
}

extern "C" __declspec(dllexport) char *CopyThePart(char* str, int beginning_of_substr, int lenght_of_substr) {
    char substr[1024];
    int lenght_of_str = FindStringLength(str);
    int d_pos = 0;

    if ((lenght_of_substr > 0) && (beginning_of_substr < lenght_of_str + 1)) {
        if (beginning_of_substr < 0) {
            beginning_of_substr = 0;
        }
        if ((beginning_of_substr + lenght_of_substr) > lenght_of_str) {
            lenght_of_substr = lenght_of_str;
        }
        for (d_pos; d_pos < lenght_of_substr; d_pos++)
        {
            substr[d_pos] = str[beginning_of_substr];
            beginning_of_substr++;
        }
        substr[d_pos] = '\0';
        return substr;
    }
    else {
        return 0;
    }
}

extern "C" __declspec(dllexport) char *DelSubstr(char* str, int beginning_of_substr, int lenght_of_substr) {
    int lenght_of_str = FindStringLength(str);
    char substr[1024];
    int d_pos = 0;
    int d_pos2 = 0;
    if (lenght_of_substr > 0) {
        if (beginning_of_substr < 0) {
            beginning_of_substr = 0;
        }
        if ((beginning_of_substr + lenght_of_substr) > lenght_of_str) {
            lenght_of_substr = lenght_of_str;
        }
        d_pos = lenght_of_substr + beginning_of_substr;
        for (int i = beginning_of_substr; i < d_pos; i++) {
            substr[d_pos2++] = str[i];
        }
        for (; beginning_of_substr < lenght_of_str; beginning_of_substr++) {
            str[beginning_of_substr] = str[d_pos++];
        }
        substr[d_pos2] = '\0';
        /*if (beginning_of_substr > lenght_of_str + 1) {
            std::cout << "Удалённая область: \n";
        }
        else {
            std::cout << "Удалённая область: \n" << substr << '\n';
        }*/
        return str;
    }
    else {
        return 0;
    }
}

extern "C" __declspec(dllexport) char *Inserting(char* str, char* substr, int beginning_of_substr) {
    int lenght_of_str = FindStringLength(str);
    int lenght_of_substr = FindStringLength(substr);
    int d_pos = 0;
    if (beginning_of_substr < 0) {
        beginning_of_substr = 0;
    }
    if (beginning_of_substr < lenght_of_str) {
        for (int i = lenght_of_str - 1; i >= beginning_of_substr; i--) {
            str[i + lenght_of_substr] = str[i];
        }str[lenght_of_substr + lenght_of_str] = '\0';
        for (int i = beginning_of_substr; i < beginning_of_substr + lenght_of_substr; i++) {
            str[i] = substr[d_pos++];
        }
    }
    else {
        for (int i = lenght_of_str; i < lenght_of_str + lenght_of_substr; i++) {
            str[i] = substr[d_pos++];
        }
    }
    str[lenght_of_substr + lenght_of_str] = '\0';
    return str;
}

extern "C" __declspec(dllexport) int SubstringSearchStart(char* str, char* substr) {
    int lenght_of_str = FindStringLength(str);
    int lenght_of_substr = FindStringLength(substr);
    int d_pos = 0;
    int coincidence = 0;
    int first_in = -1;
    for (int i = 0; (coincidence != lenght_of_substr) && (i < lenght_of_str); i++) {
        if (str[i] == substr[d_pos++]) {
            if (coincidence == 0) {
                first_in = i;
            }
            coincidence++;
        }
        else {
            if (coincidence != 0) {
                i--;
            }
            d_pos = 0;
            coincidence = 0;
            first_in = -1;
        }
    }
    return first_in;
}

extern "C" __declspec(dllexport) int SubstringSearchEnd(char* str, char* substr) {
    int lenght_of_str = FindStringLength(str);
    int lenght_of_substr = FindStringLength(substr);
    int d_pos = lenght_of_substr - 1;
    int coincidence = 0;
    int first_in = -1;
    for (int i = lenght_of_str; (coincidence != lenght_of_substr) && (i > 0); i--) {
        if (str[i] == substr[d_pos--]) {
            if (coincidence == 0) {
                first_in = i;
            }
            coincidence++;
        }
        else {
            d_pos = lenght_of_substr - 1;
            coincidence = 0;
            first_in = -1;
        }
    }
    first_in -= lenght_of_substr - 1;
    return first_in;
}

extern "C" __declspec(dllexport) char* ReplacingSubstr(char* str1, char* str2, char* str3) {
    int lenght_of_str1 = FindStringLength(str1);
    int lenght_of_str2 = FindStringLength(str2);
    int lenght_of_str3 = FindStringLength(str3);
    int d_pos = 0;
    int coincidence = 0;
    int first_in = -1;
    for (int i = 0; (coincidence != lenght_of_str2) && (i < lenght_of_str1); i++) {
        if (str1[i] == str2[d_pos++]) {
            if (coincidence == 0) {
                first_in = i;
            }
            coincidence++;
        }
        else {
            if (coincidence != 0) {
                i--;
            }
            d_pos = 0;
            coincidence = 0;
            first_in = -1;
        }
    }
    d_pos = 0;

    if (first_in != -1) {
        if ((first_in + lenght_of_str2 - 1) < lenght_of_str1) {
            if (lenght_of_str3 >= lenght_of_str2) {
                for (int i = lenght_of_str1 - 1; i > (first_in + lenght_of_str2 - 1); i--) {
                    str1[i + (lenght_of_str3 - lenght_of_str2)] = str1[i];
                }
            }
            else
            {
                for (int i = first_in + lenght_of_str2; i < lenght_of_str1; i++) {
                    str1[i - (lenght_of_str2 - 1)] = str1[i];
                }
            }
            for (int i = first_in; i < first_in + lenght_of_str3; i++) {
                str1[i] = str3[d_pos++];
            }
        }
        else {
            for (int i = lenght_of_str1; i < lenght_of_str1 + lenght_of_str3; i++) {
                str1[i] = str3[d_pos++];
            }
        }
        str1[(lenght_of_str3 - lenght_of_str2) + lenght_of_str1] = '\0';
    }
    return str1;
}

extern "C" __declspec(dllexport) char* ReplacingAllSubstr(char* str1, char* str2, char* str3) {
    int lenght_of_str1 = FindStringLength(str1);
    int lenght_of_str2 = FindStringLength(str2);
    int lenght_of_str3 = FindStringLength(str3);
    int d_pos = 0;
    int memory_pos = 0;
    int coincidence = 0;
    int first_in = 0;
    while (first_in != -1) {
        first_in = -1;
        coincidence = 0;
        d_pos = 0;
        lenght_of_str1 = 0;
        for (lenght_of_str1; str1[lenght_of_str1] != '\0'; lenght_of_str1++) {}; //Длина первой строки
        for (; (coincidence != lenght_of_str2) && (memory_pos < lenght_of_str1); memory_pos++) {
            if (str1[memory_pos] == str2[d_pos++]) {
                if (coincidence == 0) {
                    first_in = memory_pos;
                }
                coincidence++;
            }
            else {
                if (coincidence != 0) {
                    memory_pos--;
                }
                d_pos = 0;
                coincidence = 0;
                first_in = -1;
            }
        }
        memory_pos = first_in + lenght_of_str3;
        d_pos = 0;

        if (first_in != -1) {
            if ((first_in + lenght_of_str2 - 1) < lenght_of_str1) {
                if (lenght_of_str3 >= lenght_of_str2) {
                    for (int i = lenght_of_str1 - 1; i > (first_in + lenght_of_str2 - 1); i--) {
                        str1[i + (lenght_of_str3 - lenght_of_str2)] = str1[i];
                    }
                }
                else
                {
                    for (int i = first_in + lenght_of_str2; i < lenght_of_str1; i++) {
                        str1[i - (lenght_of_str2 - 1)] = str1[i];
                    }
                }
                for (int i = first_in; i < first_in + lenght_of_str3; i++) {
                    str1[i] = str3[d_pos++];
                }
            }
            else {
                for (int i = lenght_of_str1; i < lenght_of_str1 + lenght_of_str3; i++) {
                    str1[i] = str3[d_pos++];
                }
            }
            str1[(lenght_of_str3 - lenght_of_str2) + lenght_of_str1] = '\0';
        }
    }
    return str1;
}

