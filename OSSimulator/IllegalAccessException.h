#include <exception>
using namespace std;

class IllegalAccessException : public exception
{
public:
    const char * what() const throw()
    {
        return "Illegal Access";
    }

};