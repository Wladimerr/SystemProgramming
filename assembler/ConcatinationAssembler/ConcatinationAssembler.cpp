// Владимир Труков ПР-315
// Конкатенация

#include <iostream>

int main()
{

    char s[256];
    char a[] = "12345";
    char b[] = "abcdef";
    char f[] = "%s";

    _asm
    {
        lea esi, [a]
        lea edi, [s]

        FOR_1:
        lodsb
            stosb
            cmp al, 0
            jnz FOR_1

            lea esi, [b]
            dec edi

            FOR_2 :
        lodsb
            stosb
            cmp al, 0
            jnz FOR_2

    }
    std::cout << s << std::endl;

    system("pause");
}