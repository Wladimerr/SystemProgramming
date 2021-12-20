#ifdef FUNCTIONSFORTEXT_EXPORTS
#define FUNCTIONSFORTEXT_API __declspec(dllexport)
#else
#define FUNCTIONSFORTEXT_API __declspec(dllimport)
#endif


extern "C" FUNCTIONSFORTEXT_API int FindStringLength(char* str);
extern "C" FUNCTIONSFORTEXT_API char *Concatenation(char* str1, char* str2);
extern "C" FUNCTIONSFORTEXT_API char *CopyThePart(char* str, int beginning_of_substr, int lenght_of_substr);
extern "C" FUNCTIONSFORTEXT_API char *DelSubstr(char* str, int beginning_of_substr, int lenght_of_substr);
extern "C" FUNCTIONSFORTEXT_API char *Inserting(char* str, char* substr, int beginning_of_substr);
extern "C" FUNCTIONSFORTEXT_API int SubstringSearchStart(char* str, char* substr);
extern "C" FUNCTIONSFORTEXT_API int SubstringSearchEnd(char* str, char* substr);
extern "C" FUNCTIONSFORTEXT_API char *ReplacingSubstr(char* str1, char* str2, char* str3);
extern "C" FUNCTIONSFORTEXT_API char *ReplacingAllSubstr(char* str1, char* str2, char* str3);

