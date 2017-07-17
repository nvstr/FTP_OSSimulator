#include <exception>
using namespace std;

class OutOfRangeException : public exception
{
public:
    const char * what() const throw()
    {
        return "Out of range exception";
    }
};