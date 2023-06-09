//
// Created by rmesz on 2023. 06. 09..
//


#include <cstddef>
#include <stdexcept>

template<typename T>
class Array {
    size_t cap;
    T *data;
public:
    [[maybe_unused]] explicit Array(const size_t cap) : cap(cap) {
        data = new T[cap];
    }
    explicit Array(const int cap) : cap(cap) {
        if(cap < 0) throw std::runtime_error("Array capacity cannot be a negative value!");
        data = new T[cap];
    }

    Array(T* first, const size_t size, const size_t cap = 0) :  cap(cap) {
        if(cap < size) this->cap = size;
        data = new T[this->cap];
        std::copy(first, first + size, data);
    }

    Array(const Array& other) : cap(other.cap) {
        data = new T[cap];
        std::copy(other.data, other.data + other.cap, data);
    }

    [[nodiscard]] size_t capacity() const {
        return cap;
    }

    ///átméretezi a tömböt, amennyiben a tömb kisebb lesz, a nem beleférő elemek elvesznek
    void resize(size_t new_cap) {
        T *new_array = new T[new_cap];
        cap = new_cap;
        std::copy(data, data + cap, new_array);
        delete[] data;
        data = new_array;
    }

    T& operator[](size_t idx) {
        if(idx >= cap) throw std::out_of_range("Array over-indexed");
        return data[idx];
    };

    T operator[](size_t idx) const {
        if(idx >= cap) throw std::out_of_range("Array over-indexed");
        return data[idx];
    }

    ~Array() {
        delete[] data;
    }

    //Basics of the array END -----------------------------------------


};
