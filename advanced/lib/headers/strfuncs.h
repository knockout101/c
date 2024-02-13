/*
Removed void alphaStrip(char* string);
*/
#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

int count(char* string, char ch);
int strlength(char* string);
char* strconcat(char* str1, char* str2);
int strcopy(char* buffer, char* string);
int findSub(char* string, char* subString);

#endif