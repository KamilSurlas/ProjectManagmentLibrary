#include "Allocator.h"

template<typename T, int limit>
Allocator<T, limit>::Allocator() {
    this->data = new T[limit];
    counter = 0;
}

template<typename T, int limit>
Allocator<T, limit>::~Allocator() {
    delete[] this->data;
}

template<typename T, int limit>
void Allocator<T, limit>::realloc(int newLimit) {
    if (newLimit <= 0) {
        throw std::invalid_argument("Wrong argument")
    }
    
    T* temp = new T[newLimit];

    if (temp == nullptr) {
        throw std::invalid_argument("Failed allocation");
    }

    for (int i = 0; i < limit; i++) {
        temp[i] = data[i];
    }

    delete[] data;
    data = temp;
    temp = nullptr;
    limit = newLimit;
}

template<typename T, int limit>
void Allocator<T, limit>::addElement(T& element) {
    this->data[counter] = element;
    counter++;
    
    if (counter >= limit)
        realloc(limit + 100);
}

template<typename T, int limit>
T& Allocator<T, limit>::operator[](int idx) {
    if (0 <= idx && idx < limit) {
        return this->data[idx];
    }
    else {
        throw std::out_of_range("Provided index is out of range");
    }
}

template<typename T, int limit>
bool Allocator<T, limit>::removeElement(const T& element)
{
    for (size_t i = 0; i < counter; i++)
    {
        if (this->data[i] == element) {
            std::swap(this->data[i], this->data[counter - 1]);
            counter--;
            return true;
        }
    }
    return false;
}
