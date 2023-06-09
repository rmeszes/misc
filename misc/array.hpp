//
// Created by rmesz on 2023. 06. 09..
//


#include <cstddef>
#include <stdexcept>

template<typename T>
class Array {
    size_t siz;
    size_t cap;
    T *data;
public:
    [[maybe_unused]] explicit Array(const size_t cap) : siz(0), cap(cap) {
        data = new T[cap];
    }
    explicit Array(const int cap) : siz(0), cap(cap) {
        if(cap < 0) throw std::runtime_error("Array capacity cannot be a negative value!");
        data = new T[cap];
    }

    Array(T* first, const size_t size, const size_t cap = 0) : siz(size), cap(cap) {
        if(cap < size) this->cap = size;
        data = new T[this->cap];
        std::copy(first, first + size, data);
    }

    Array(const Array& other) : siz(other.siz), cap(other.cap) {
        data = new T[cap];
        std::copy(other.data, other.data + other.siz, data);
    }

    [[nodiscard]] size_t size() const {
        return siz;
    }

    [[nodiscard]] size_t capacity() const {
        return cap;
    }

    [[nodiscard]] size_t free_size() const {
        return(cap - siz);
    }

    [[nodiscard]] bool empty() const {
        return(siz == 0);
    }

    void write(std::ostream& os = std::cout, const std::string& separator = " ") {
        if (siz != 0) {
            for (size_t i = 0; i < siz - 1; ++i) {
                os << data[i] << separator;
            }
            os << data[siz-1];
        }
    }

    ///átméretezi a tömböt, amennyiben a tömb kisebb lesz, a nem beleférő elemek elvesznek
    void resize(size_t new_cap) {
        T *new_array = new T[new_cap];
        cap = new_cap;
        if(new_cap < siz) siz = new_cap;
        std::copy(data, data + siz, new_array);
        delete[] data;
        data = new_array;
    }

    T& operator[](size_t idx) {
        return data[idx];
    };

    T operator[](size_t idx) const {
        return data[idx];
    }

    ~Array() {
        delete[] data;
    }
};
