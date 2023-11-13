#ifndef NAMEDVALUE_HPP
#define NAMEDVALUE_HPP

#include <string>

template <typename T>
class NamedValue
{
public:
    NamedValue(const std::string &name, const T &value) : name(name), value(value) {}

    const std::string &getName() const
    {
        return name;
    }

    const T &getValue() const
    {
        return value;
    }

    bool operator>(const NamedValue<T> &other) const
    {
        return value > other.value;
    }

private:
    std::string name;
    T value;
};

#endif
