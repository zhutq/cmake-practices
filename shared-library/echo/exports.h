#ifndef EXPORTS_H
#define EXPORTS_H

#if defined(_WIN32)
#ifdef ECHO_COMPILE_LIBRARY
#define ECHO_API __declspec(dllexport)
#else
#define ECHO_API __declspec(dllimport)
#endif
#else
#define ECHO_API __attribute__((visibility("default")))
#endif // _WIN32

#endif /* EXPORTS_H */
