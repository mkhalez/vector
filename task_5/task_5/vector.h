#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <stdexcept>

template <typename T>
class Vector {
   private:
    T* ptr;
    size_t our_capacity;
    size_t our_size;

   public:
    using difference_type = ptrdiff_t;
    class Iterator {
       private:
        T* pointer;

       public:
        explicit Iterator(T* p) : pointer(p) {}

        T& operator*() const { return *pointer; }
        T* operator->() const { return pointer; }

        difference_type operator-(const Iterator& other) const {
            return pointer - other.pointer;
        }

        Iterator operator+(difference_type n) const {
            return Iterator(pointer + n);
        }

        Iterator operator-(difference_type n) const {
            return Iterator(pointer - n);
        }

        bool operator<(const Iterator& other) const {
            return pointer < other.pointer;
        }

        bool operator>(const Iterator& other) const {
            return pointer > other.pointer;
        }

        bool operator<=(const Iterator& other) const {
            return pointer <= other.pointer;
        }

        bool operator>=(const Iterator& other) const {
            return pointer >= other.pointer;
        }

        Iterator& operator++() {
            ++pointer;
            return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++pointer;
            return tmp;
        }

        bool operator==(const Iterator& other) const {
            return pointer == other.pointer;
        }
        bool operator!=(const Iterator& other) const {
            return pointer != other.pointer;
        }

        T& operator[](size_t index) { return pointer[index]; }

        const T& operator[](size_t index) const { return pointer[index]; }
    };


    class ReverseIterator {
        T* current;

       public:
        using difference_type = ptrdiff_t;

        explicit ReverseIterator(T* p) : current(p) {}

        T& operator*() const { return *(current - 1); }
        T* operator->() const { return current - 1; }
        T& operator[](difference_type n) const { return *(current - 1 - n); }

        ReverseIterator& operator++() {
            --current;
            return *this;
        }
        ReverseIterator operator++(int) {
            ReverseIterator tmp = *this;
            --current;
            return tmp;
        }
        ReverseIterator& operator--() {
            ++current;
            return *this;
        }
        ReverseIterator operator--(int) {
            ReverseIterator tmp = *this;
            ++current;
            return tmp;
        }

        ReverseIterator operator+(difference_type n) const {
            return ReverseIterator(current - n);
        }
        ReverseIterator operator-(difference_type n) const {
            return ReverseIterator(current + n);
        }
        ReverseIterator& operator+=(difference_type n) {
            current -= n;
            return *this;
        }
        ReverseIterator& operator-=(difference_type n) {
            current += n;
            return *this;
        }

        difference_type operator-(const ReverseIterator& other) const {
            return other.current - current;
        }

        bool operator==(const ReverseIterator& other) const {
            return current == other.current;
        }
        bool operator!=(const ReverseIterator& other) const {
            return current != other.current;
        }
        bool operator<(const ReverseIterator& other) const {
            return current > other.current;
        }
        bool operator>(const ReverseIterator& other) const {
            return current < other.current;
        }
        bool operator<=(const ReverseIterator& other) const {
            return current >= other.current;
        }
        bool operator>=(const ReverseIterator& other) const {
            return current <= other.current;
        }
    };

    class ConstReverseIterator {
        const T* current;

       public:
        using difference_type = ptrdiff_t;

        explicit ConstReverseIterator(const T* p) : current(p) {}

        const T& operator*() const { return *(current - 1); }
        const T* operator->() const { return current - 1; }
        const T& operator[](difference_type n) const {
            return *(current - 1 - n);
        }

        ConstReverseIterator& operator++() {
            --current;
            return *this;
        }
        ConstReverseIterator operator++(int) {
            ConstReverseIterator tmp = *this;
            --current;
            return tmp;
        }
        ConstReverseIterator& operator--() {
            ++current;
            return *this;
        }
        ConstReverseIterator operator--(int) {
            ConstReverseIterator tmp = *this;
            ++current;
            return tmp;
        }

        ConstReverseIterator operator+(difference_type n) const {
            return ConstReverseIterator(current - n);
        }
        ConstReverseIterator operator-(difference_type n) const {
            return ConstReverseIterator(current + n);
        }
        ConstReverseIterator& operator+=(difference_type n) {
            current -= n;
            return *this;
        }
        ConstReverseIterator& operator-=(difference_type n) {
            current += n;
            return *this;
        }

        difference_type operator-(const ConstReverseIterator& other) const {
            return other.current - current;
        }

        bool operator==(const ConstReverseIterator& other) const {
            return current == other.current;
        }
        bool operator!=(const ConstReverseIterator& other) const {
            return current != other.current;
        }
        bool operator<(const ConstReverseIterator& other) const {
            return current > other.current;
        }
        bool operator>(const ConstReverseIterator& other) const {
            return current < other.current;
        }
        bool operator<=(const ConstReverseIterator& other) const {
            return current >= other.current;
        }
        bool operator>=(const ConstReverseIterator& other) const {
            return current <= other.current;
        }
    };


    Vector() : ptr(nullptr), our_capacity(0), our_size(0) {}

    explicit Vector(size_t initial_size, const T& value = T())
        : ptr(reinterpret_cast<T*>(new int8_t[initial_size * sizeof(T)])),
          our_capacity(initial_size),


          our_size(initial_size) {
        size_t i = 0;
        try {


            for (; i < initial_size; ++i) {
                new (ptr + i) T(value);
            }
        } catch (...) {


            for (size_t j = 0; j < i; ++j) {
                (ptr + j)->~T();
            }
            delete[] reinterpret_cast<int8_t*>(ptr);
            ptr = nullptr;
            our_capacity = 0;
            our_size = 0;
            throw;
        }
    }

    Vector(std::initializer_list<T> init_list)
        : ptr(reinterpret_cast<T*>(new int8_t[init_list.size() * sizeof(T)])),
          our_capacity(init_list.size()),
          our_size(init_list.size()) {
        size_t i = 0;
        try {


            for (const auto& item : init_list) {
                new (ptr + i) T(item);
                ++i;
            }
        } catch (...) {


            for (size_t j = 0; j < i; ++j) {
                (ptr + j)->~T();
            }
            delete[] reinterpret_cast<int8_t*>(ptr);
            ptr = nullptr;
            our_capacity = 0;
            our_size = 0;
            throw;
        }
    }

    Vector(const Vector& other) : ptr(nullptr), our_capacity(0), our_size(0) {
        if (other.our_size == 0) {
            return;
        }

        ptr = reinterpret_cast<T*>(new int8_t[other.our_size * sizeof(T)]);
        our_capacity = other.our_size;
        our_size = other.our_size;

        size_t i = 0;
        try {


            for (; i < other.our_size; ++i) {
                new (ptr + i) T(other.ptr[i]);
            }
        } catch (...) {


            for (size_t j = 0; j < i; ++j) {
                (ptr + j)->~T();
            }
            delete[] reinterpret_cast<int8_t*>(ptr);
            ptr = nullptr;
            our_capacity = 0;
            our_size = 0;
            throw;
        }
    }

    T& operator[](size_t index) {
        if (index >= our_size) {
            throw std::out_of_range("Index out of range");
        }
        return ptr[index];
    }

    const T& operator[](size_t index) const {
        if (index >= our_size) {
            throw std::out_of_range("Index out of range");
        }
        return ptr[index];
    }


    void reserve(size_t n) {
        if (n <= our_capacity)
            return;

        T* new_arr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);

        size_t i = 0;

        try {
            for (; i < this->our_size; ++i) {
                new (new_arr + i) T(this->ptr[i]);	//placement new
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j) {
                (new_arr + j)->~T();
            }
            delete[] reinterpret_cast<int8_t*>(new_arr);
            throw;
        }
        for (size_t i = 0; i < our_size; ++i) {
            (ptr + i)->~T();
        }
        delete[] reinterpret_cast<int8_t*>(ptr);
        ptr = new_arr;
        our_capacity = n;
    }

    void resize(size_t n, const T& value = T()) {
        if (n > our_capacity)
            reserve(n);

        size_t i = our_size;
        try {


            for (; i < n; ++i) {
                new (ptr + i) T(value);
            }

        } catch (...) {


            for (size_t j = our_size; j < i; ++j) {
                (ptr + j)->~T();
            }
            throw;
        }
        if (n < our_size) {
            for (size_t i = n; i < our_size; ++i) {
                (ptr + i)->~T();
            }
        }

        our_size = n;
    }


    void push_back(const T& value) {
        if (our_capacity == our_size) {
            if (our_size == 0) {
                reserve(1);
            } else {
                reserve(2 * our_size);
            }
        }
        try {
            new (ptr + our_size) T(value);
            ++(this->our_size);
        } catch (...) {
            throw;
        }
    }


    void pop_back() {
        if (this->our_size == 0) {
            throw std::out_of_range("Cannot pop_back() from empry container");
        }
        --(this->our_size);
        (this->ptr + this->our_size)->~T();
    }

    T& at(size_t index) {
        if (index >= this->our_size) {
            throw std::out_of_range("out of range");
        }
        return this->ptr[index];
    }


    ~Vector() {
        if (this->ptr != nullptr) {
            for (size_t i = 0; i < this->our_size; ++i) {
                (this->ptr + i)->~T();
            }
            delete[] reinterpret_cast<int8_t*>(this->ptr);
        }
    }


    size_t size() const { return our_size; }

    Iterator begin() noexcept { return Iterator(ptr); }

    Iterator end() noexcept { return Iterator(ptr + our_size); }

    const Iterator cbegin() const noexcept { return Iterator(ptr); }

    const Iterator cend() const noexcept { return Iterator(ptr + our_size); }

    const Iterator begin() const noexcept { return cbegin(); }

    const Iterator end() const noexcept { return cend(); }


    size_t capacity() const { return our_capacity; }


    void clear() noexcept {


        for (size_t i = 0; i < our_size; ++i) {
            (ptr + i)->~T();
        }

        delete[] reinterpret_cast<int8_t*>(ptr);

        ptr = nullptr;
        our_size = 0;
        our_capacity = 0;
    }


    void assign(size_t count, const T& value = T()) {
        clear();

        ptr = reinterpret_cast<T*>(new int8_t[count * sizeof(T)]);
        our_capacity = count;
        our_size = count;

        size_t i = 0;
        try {


            for (; i < count; ++i) {
                new (ptr + i) T(value);
            }
        } catch (...) {


            for (size_t j = 0; j < i; ++j) {
                (ptr + j)->~T();
            }
            delete[] reinterpret_cast<int8_t*>(ptr);
            ptr = nullptr;
            our_capacity = 0;
            our_size = 0;
            throw;
        }
    }

    T& back() {
        if (our_size == 0) {
            throw std::out_of_range("Vector is empty, no back element");
        }
        return ptr[our_size - 1];
    }

    const T& back() const {
        if (our_size == 0) {
            throw std::out_of_range("Vector is empty, no back element");
        }
        return ptr[our_size - 1];
    }

    T* data() noexcept { return ptr; }

    const T* data() const noexcept { return ptr; }

    template <typename... Args>


    Iterator emplace(Iterator pos, Args... args) {

        if (pos < begin() || pos >= end()) {
            throw std::out_of_range("Invalid iterator position");
        }

        const size_t index = pos - begin();

        if (our_size == our_capacity) {
            reserve(our_capacity == 0 ? 1 : our_capacity * 2);
        }

        if (index != our_size) {
            new (ptr + our_size) T(ptr[our_size - 1]);

            for (size_t i = our_size - 1; i > index; --i) {
                ptr[i] = ptr[i - 1];
            }

            ptr[index].~T();
        }

        try {
            new (ptr + index) T(args...);
        } catch (...) {
            if (index != our_size) {
                for (size_t i = index; i < our_size - 1; ++i) {
                    ptr[i] = ptr[i + 1];
                }
                ptr[our_size - 1].~T();
            }
            throw;
        }

        ++our_size;
        return Iterator(ptr + index);
    }

    template <typename... Args>


    Iterator emplace_back(Args... args) {

        if (our_size == our_capacity) {
            reserve(our_capacity == 0 ? 1 : our_capacity * 2);
        }
        try {
            new (ptr + our_size) T(args...);
        } catch (...) {
            throw;
        }

        ++our_size;

        return Iterator(ptr + our_size - 1);
    }

    bool empty() const noexcept { return our_size == 0; }


    Iterator erase(Iterator pos) {
        if (pos < begin() || pos >= end()) {
            throw std::out_of_range("Invalid iterator position");
        }

        const size_t index = pos - begin();


        for (size_t i = index; i < our_size - 1; ++i) {
            ptr[i] = ptr[i + 1];
        }

        --our_size;

        ptr[our_size].~T();

        return Iterator(ptr + index);
    }


    Iterator erase(Iterator first, Iterator last) {
        if (first > last || first < begin() || last > end()) {
            throw std::out_of_range("Invalid iterator range");
        }

        if (first == last) {
            return first;
        }

        size_t num_erase = last - first;
        size_t start_pos = first - begin();

        for (size_t i = start_pos; i < our_size - num_erase; ++i) {
            ptr[i] = ptr[i + num_erase];
        }

        for (size_t i = our_size - num_erase; i < our_size; i++) {
            ptr[i].~T();
        }

        our_size -= num_erase;
        return Iterator(ptr + start_pos);
    }

    T& front() {
        if (our_size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return ptr[0];
    }

    const T& front() const {
        if (our_size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return ptr[0];
    }


    Iterator insert(Iterator pos, const T& value) {
        return emplace(pos, value);
    }

    //?


    Iterator insert(Iterator pos, size_t count, const T& value) {
        if (pos < begin() || pos > end()) {
            throw std::out_of_range("Invalid insert position");
        }

        if (count == 0)
            return pos;

        const size_t index = pos - begin();	 // 1 2 3 4    1 2 5 5 5 3 4
        size_t j = 0;
        try {
            if (our_size + count > our_capacity) {
                reserve(std::max(our_capacity * 2, our_size + count));
            }

            for (size_t i = our_size; i > index; --i) {
                new (ptr + i + count - 1) T(ptr[i - 1]);
                ptr[i - 1].~T();
            }

            for (; j < count; ++j) {
                new (ptr + index + j) T(value);
            }

            our_size += count;
            return Iterator(ptr + index);

        } catch (...) {
            for (size_t i = 0; i < j; i++) {
                ptr[index + i].~T();
            }

            for (size_t i = 0; i < count; i++) {
                ptr[our_size + i].~T();
            }
            our_size = index;
            throw;
        }
    }

    template <typename InputIt>


    Iterator insert(Iterator pos, InputIt first, InputIt last) {
        if (pos < begin() || pos > end()) {
            throw std::out_of_range("Invalid insert position");
        }

        if (first == last) {
            return pos;
        }

        const size_t index = pos - begin();
        const size_t count = last - first;
        size_t constructed = 0;

        try {
            if (our_size + count > our_capacity) {
                reserve(std::max(our_capacity * 2, our_size + count));
            }

            for (size_t i = our_size; i > index; --i) {
                new (ptr + i + count - 1) T(ptr[i - 1]);
                ptr[i - 1].~T();
            }

            InputIt it = first;
            for (; constructed < count; ++constructed, ++it) {
                new (ptr + index + constructed) T(*it);
            }

            our_size += count;
            return Iterator(ptr + index);

        } catch (...) {
            for (size_t i = 0; i < constructed; ++i) {
                ptr[index + i].~T();
            }

            for (size_t i = 0; i < our_size - index; ++i) {
                new (ptr + index + i) T(ptr[index + count + i]);
                ptr[index + count + i].~T();
            }

            throw;
        }
    }

    size_t max_size() const noexcept { return std::allocator<T>().max_size(); }

    ReverseIterator rbegin() noexcept { return ReverseIterator(end()); }

    ReverseIterator rend() noexcept { return ReverseIterator(begin()); }

    ConstReverseIterator rbegin() const noexcept {
        return ConstReverseIterator(end());
    }

    ConstReverseIterator rend() const noexcept {
        return ConstReverseIterator(begin());
    }

    ConstReverseIterator crbegin() const noexcept {
        return ConstReverseIterator(end());
    }

    ConstReverseIterator crend() const noexcept {
        return ConstReverseIterator(begin());
    }

    void swap(Vector& other) noexcept {
        std::swap(ptr, other.ptr);
        std::swap(our_size, other.our_size);
        std::swap(our_capacity, other.our_capacity);
    }
};

#endif	// VECTOR_H
