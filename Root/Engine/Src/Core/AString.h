#ifndef _ASTRING_H
#define _ASTRING_H

#ifdef _UNICODE
typedef wchar_t achar;
#define TEXT(x) L ## x
#else
typedef char achar;
#define TEXT(x) x
#endif




#endif

