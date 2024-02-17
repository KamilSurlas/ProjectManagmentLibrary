#pragma once
#include <stdexcept>

template<typename T, size_t sizeLimit = 100>
class CustomAllocator
{
private:
	T* data = nullptr;
	int counter;
	int limit;
	void realloc(int newLimit) {
		if (newLimit <= 0) {
			throw std::invalid_argument("Wrong argument");
		}

		T* temp = new T[newLimit];

		if (temp == nullptr) {
			throw std::bad_alloc();
		}

		for (int i = 0; i < sizeLimit; i++) {
			temp[i] = this->data[i];
		}

		delete[] this->data;
		this->data = temp;
		temp = nullptr;
		limit = newLimit;
	};
public:
	CustomAllocator() {
		if (sizeLimit <= 0)
			throw std::invalid_argument("Size limit cannot be less or equal 0");
		limit = sizeLimit;
		this->data = new T[limit];
		counter = 0;
	};
	~CustomAllocator() {
		if (this->data != nullptr) {
			delete[] this->data;
			this->data = nullptr;
			counter = 0;
		}

	};
	bool operator==(const CustomAllocator& rhs) {
		if (this->counter != rhs.counter)
			return false;

		for (int i = 0; i < counter; i++) {
			if (data[i] != rhs.data[i])
				return false;
		}

		return true;
	};
	bool operator!=(const CustomAllocator& rhs) {
		return !(*this == rhs);
	};
	void addElement(T& element) {
		if (isAssigned(element))
			throw std::invalid_argument("Element is assigned to collection");
		else {
			this->data[counter] = element;
			counter++;

			if (counter >= sizeLimit)
				realloc(sizeLimit + 100);
		}
	};
	T& operator[](int idx) {
		if (0 <= idx && idx < counter) {
			return this->data[idx];
		}
		else {
			throw std::out_of_range("Provided index is out of range");
		}
	};
	bool removeElement(const T& element) {
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
	};
	int getSize() { return counter; };
	void removeAll() {
		if (this->data != nullptr)
			delete[] this->data;
		counter = 0;
		this->data = nullptr;
	};
	bool isAssigned(T& element) {
		for (int i = 0; i < counter; i++) {
			if (element == data[i])
				return true;
		}

		return false;
	};

	CustomAllocator(const CustomAllocator& org) 
		:counter(org.counter)
	{
		if (org.data != nullptr) {
			T* temp = new T[org.limit];
			this->limit = org.limit;
			for (size_t i = 0; i < org.counter; i++)
			{
				this->data[i] = org.data[i];
			}
		}
	}

	CustomAllocator& operator=(const CustomAllocator& org) {
		if (this != &org) {
			if (this->data != nullptr) {
				delete[] this->data;
				this->data = nullptr;
				counter = 0;
			}

			if (org.data != nullptr) {
				this->data = new T[org.limit];
				this->limit = org.limit;
				for (size_t i = 0; i < org.counter; i++) {
					this->data[i] = org.data[i];
				}
				this->counter = org.counter;
			}
			else {
				this->data = nullptr;
				this->limit = 0;
				this->counter = 0;
			}
		}
		return *this;
	}

};

