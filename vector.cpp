#include <cassert> // Further down the line, we will use exceptions instead
#include <algorithm>

#include "vector.hpp"

vector::vector(int n)
: size_{n}
{
    assert(n >= 0 && "vector size must be non-negative");

    if (size_ == 0) {
        elements_ = nullptr;
        return;
    }

    // Allocate memory and initialize
    elements_ = new double[size_];
    for (int i = 0; i < n; ++i) {
        elements_[i] = 0;
    }
}

vector::vector(const vector& source)
: size_(source.size())
{
    if (size_ == 0) {
        elements_ = nullptr;
        return;
    }

    elements_ = new double[size_];
    std::copy(source.elements_, source.elements_ + size_, elements_);
}

vector::vector(vector&& source) noexcept
: size_{source.size_}
, elements_{source.elements_}
{
    // Leave the source in a null state
    source.size_ = 0;
    source.elements_ = nullptr;
}

vector::vector(std::initializer_list<double> list)
: size_{static_cast<int>(list.size())}
{
    if (size_ == 0) {
        elements_ = nullptr;
        return;
    }

    // Only allocate if list is not empty
    elements_ = new double[size_];
    std::copy(list.begin(), list.end(), elements_);
}

vector::~vector()
{
    delete[] elements_; // Free heap memory
}

vector& vector::operator=(const vector& source)
{
    // Detect self assignment
    if (&source == this) { // No work to do
        return *this;
    }

    // Deallocate old data
    delete[] elements_;

    // Deep copy

    size_ = source.size_;
    if (size_ == 0) { // No need for memory allocation
        elements_ = nullptr;
        return *this;
    }

    elements_ = new double[size_];
    std::copy(source.elements_, source.elements_ + size_, elements_);

    return *this;
}

vector& vector::operator=(vector&& source) noexcept
{
    // Detect self assignment
    if (&source == this) {
        return *this;
    }

    delete[] elements_;

    // Shallow copy
    size_ = source.size_;
    elements_ = source.elements_;

    // Leave the source in a null state
    source.size_ = 0;
    source.elements_ = nullptr;

    return *this;
}
