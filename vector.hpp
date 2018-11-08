#ifndef CH17_STUDY_VECTOR_HPP
#define CH17_STUDY_VECTOR_HPP

//#include <cstddef>
#include <initializer_list>
#include <iostream>

/**
 * @brief A simplified vector of doubles
 */
class vector
{
    int size_;
    double* elements_; ///< Pointer to the first element

public:
    /** \brief Constructor to allocate n doubles
     *  \param n[in] the number of elements to allocate
     */
    explicit vector(int n);

    /// \brief Copy constructor
    vector(const vector& source);

    /// \brief Move constructor
    vector(vector&& source) noexcept;

    /**
     * @brief Initializer list constructor
     * @param list The list of doubles used to initialize the vector
     */
    vector(std::initializer_list<double> list);

    /// \brief Destructor
    ~vector();

    /// \return The current number of elements in the vector
    int size() const { return size_; }

    /// Subscript operator for non-const vector[s]
    double& operator[](int index) { return elements_[index]; }

    double operator[](int index) const { return elements_[index]; }

    /// \brief Copy assignment
    vector& operator=(const vector& source);

    /// \brief Move assignment
    vector& operator=(vector&& source) noexcept;

    double* elementsAddress() const { return elements_; }

private:
    friend std::ostream& operator<<(std::ostream& out, const vector& v);
};

inline std::ostream& operator<<(std::ostream& out, const vector& v)
{
    out << "{\n";
    for (int i = 0; i < v.size_; ++i) {
        out << "\t" << v.elements_[i] << '\n';
    }
    out << "}";
    return out;
}

#endif //CH17_STUDY_VECTOR_HPP
