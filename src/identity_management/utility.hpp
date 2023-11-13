#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>

template <typename T>
T findMax(const std::vector<T> &items)
{
    if (items.empty())
    {
        throw std::runtime_error("The container is empty.");
    }

    T maxItem = items[0];
    for (const T &item : items)
    {
        if (item > maxItem)
        {
            maxItem = item;
        }
    }

    return maxItem;
}

#endif
