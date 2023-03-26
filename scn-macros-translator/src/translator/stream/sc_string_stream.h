#pragma once

#include <string>
#include <sstream>
#include <iostream>

class ScStringStream
{
public:
    ScStringStream()
    {
        m_instance = std::stringstream();
    }

    virtual ScStringStream &operator<<(std::string const &string)
    {
        m_instance << string;
        return *this;
    }

    void operator>>(std::string &string)
    {
        m_instance >> string;
    }

    virtual operator std::string()
    {
        return m_instance.str();
    }

protected:
    std::stringstream m_instance;
};
