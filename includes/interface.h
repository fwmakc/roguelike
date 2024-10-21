#ifndef _INTERFACE_H_
#define _INTERFACE_H_

class Interface
{
  public:
    static void open();

    static void close();

    static void reset();

    static void print(const char* format, ...);

    static const char* get();

    static bool equal(const char* str1, const char* str2);

    static void wait();
}

#endif
;