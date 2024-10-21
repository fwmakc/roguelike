#ifndef _DECLENSION_H_
#define _DECLENSION_H_

/*
пример вызова:
const char* string = Interface::declension(11, "Одна монета", "Две монеты",
"Много монет");
*/

const char* declension(int num, const char* str1, const char* str2,
                       const char* str3);

#endif
;
