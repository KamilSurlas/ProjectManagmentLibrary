#include "CustomAllocator.h"

template<typename T, size_t sizeLimit>
CustomAllocator<T, sizeLimit>::CustomAllocator() {
    if (sizeLimit <= 0)
        throw std::invalid_argument("Size limit cannot be less or equal 0");
    limit = sizeLimit;
    this->data = new T[limit];
    counter = 0;
}

template<typename T, size_t sizeLimit>
CustomAllocator<T, sizeLimit>::~CustomAllocator() {
    if (this->data != nullptr)
        delete[] this->data;
}

template<typename T, size_t sizeLimit>
void CustomAllocator<T, sizeLimit>::realloc(int newLimit) {
    if (newLimit <= 0) {
        throw std::invalid_argument("Wrong argument");
    }
    
    T* temp = new T[newLimit];

    if (temp == nullptr) {
        throw std::bad_alloc("Failed allocation");
    }

    for (int i = 0; i < sizeLimit; i++) {
        temp[i] = this->data[i];
    }

    delete[] this->data;
    this->data = temp;
    temp = nullptr;
    limit = newLimit;
}

template<typename T, size_t sizeLimit>
void CustomAllocator<T, sizeLimit>::addElement(T& element) {
    this->data[counter] = element;
    counter++;
    
    if (counter >= sizeLimit)
        realloc(sizeLimit + 100);
}

template<typename T, size_t sizeLimit>
T& CustomAllocator<T, sizeLimit>::operator[](int idx) {
    if (0 <= idx && idx < counter) {
        return this->data[idx];
    }
    else {
        throw std::out_of_range("Provided index is out of range");
    }
}

template<typename T, size_t sizeLimit>
bool CustomAllocator<T, sizeLimit>::removeElement(const T& element)
{
    for (size_t i = 0; i < counter; i++)
    {
        if (this->data[i] == element) {
            std::swap(this->data[i], this->data[counter - 1]);
            
            T* temp = new T[limit];
            counter--;
            for (int i = 0; i < counter; i++) {
                temp[i] = this->data[i];
            }
            delete[] this->data;
            this->data = temp;
            temp = nullptr;
            
            return true;
        }
    }
    return false;
}
