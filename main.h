#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printc(va_list c);
int _prints(va_list s);
int _printl(void);
int _printf(const char *format, ...);


#endif /*MAIN_H*/
