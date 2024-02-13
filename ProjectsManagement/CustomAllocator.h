#pragma once
#include <stdexcept>

template<typename T, size_t sizeLimit = 100>
class CustomAllocator
{
private:
	T* data = nullptr;
	int counter;
	int limit;
	void realloc(int newLimit);
public:
	CustomAllocator();
	~CustomAllocator();
	CustomAllocator(const CustomAllocator&) = delete;
	CustomAllocator(CustomAllocator&&) = delete;
	CustomAllocator& operator=(const CustomAllocator&) = delete;
	CustomAllocator& operator=(CustomAllocator&&) = delete;
	void addElement(T& element);
	T& operator[](int idx);
	bool removeElement(const T& element);
};

