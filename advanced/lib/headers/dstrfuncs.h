#ifndef DSTRINGFUNCS_H_INCLUDED
#define DSTRINGFUNCS_H_INCLUDED

int count( char* string, char ch);
int strcopy(char* buffer, char* string);
int strlength(char* const string);
char* strconcat(char* str1, char* str2);
int findSub(char* string, char* subString);

#endif // DSTRINGFUNCS_H_INCLUDED