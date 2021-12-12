#ifndef __HELLO_H__
#define __HELLO_H__

#if defined(_WIN32)
#if defined(HELLO_EXPORT)
#define HELLO_API __declspec(dllexport)
#else
#define HELLO_API __declspec(dllimport)
#endif
#else
#define HELLO_EXPORT
#endif

class HELLO_API Hello
{
public:
    void print();
};

#endif
