#ifndef ARRAY_ITER_H
#define ARRAY_ITER_H

template <typename T>
class Array {
    T* data;
    int size;

    bool isValidIndex(int index) const {
        return (index >= 0 && index < size);
    }

public:
   
    Array() : data(nullptr), size(0) {}

    Array(int s) : Array() {
        if (s > 0) {
            size = s;
            data = new T[size];
        }
    }

    Array(const Array& other) : Array() {
        size = other.size;
        if (size > 0) {
            data = new T[size];
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this == &other)
            return *this;
        delete[] data;
        size = other.size;
        if (size > 0) {
            data = new T[size];
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        else {
            data = nullptr;
        }
        return *this;
    }

    ~Array() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

   
    T& operator[](int index) {
        if (!isValidIndex(index)) {
            cout << "Index out of bounds\n";
            exit(0);
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (!isValidIndex(index)) {
            cout << "Index out of bounds\n";
            exit(0);
        }
        return data[index];
    }

    int getSize() const { return size; }

   
    class Iterator {
        T* ptr;
    public:
        Iterator(T* p = nullptr) : ptr(p) {}

       
        T& operator*() const { return *ptr; }

       
        Iterator& operator++() { ++ptr; return *this; }       // pre-increment
        Iterator operator++(int) { Iterator temp = *this; ++ptr; return temp; } // post-increment

       
        Iterator& operator--() { --ptr; return *this; }
        Iterator operator--(int) { Iterator temp = *this; --ptr; return temp; }

        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    class ReverseIterator {
        T* ptr;
    public:
        ReverseIterator(T* p = nullptr) : ptr(p) {}

       
        T& operator*() const { return *ptr; }

      
        ReverseIterator& operator++() { --ptr; return *this; }       
        ReverseIterator operator++(int) { ReverseIterator temp = *this; --ptr; return temp; }

        
        ReverseIterator& operator--() { ++ptr; return *this; }
        ReverseIterator operator--(int) { ReverseIterator temp = *this; ++ptr; return temp; }

        bool operator==(const ReverseIterator& other) const { return ptr == other.ptr; }
        bool operator!=(const ReverseIterator& other) const { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

    ReverseIterator rbegin() { return ReverseIterator(data + size - 1); }
    ReverseIterator rend() { return ReverseIterator(data - 1); }
};
#endif
