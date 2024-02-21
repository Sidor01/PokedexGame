#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
using namespace std;

/**
 * @brief The MyException class is a custom exception class that inherits from the standard exception class.
 *
 * This class is designed to be used for handling custom exceptions in C++ programs. It provides a simple mechanism
 * to throw and catch exceptions with a custom error message.
 */
class MyException:public exception
{
    const char* msg; ///< A pointer to the error message associated with the exception.
public:
    /**
     * @brief Constructor for MyException class.
     * @param message A C-style string representing the error message.
     */
    MyException(const char *message): msg(message){};
    /**
     * @brief Returns the error message associated with the exception.
     * @return A pointer to the C-style string containing the error message.
     */
    const char* what() const noexcept {
        return msg;
    }

};

#endif // MYEXCEPTION_H
