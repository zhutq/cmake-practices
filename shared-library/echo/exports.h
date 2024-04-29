#ifndef EXPORTS_H
#define EXPORTS_H

#ifdef ECHO_COMPILE_LIBRARY
   #define ECHO_API __declspec(dllexport)
#else
   #define ECHO_API __declspec(dllimport)
#endif

#endif /* EXPORTS_H */
