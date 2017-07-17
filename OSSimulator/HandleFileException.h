#include <exception>
using namespace std;

class HandleFileException : public exception
{
public:
    const char * what() const throw()
    {
        return "Handle file exception";
    }
};