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
	bool operator==(const CustomAllocator&);
	bool operator!=(const CustomAllocator&);
	void addElement(T& element);
	T& operator[](int idx);
	bool removeElement(const T& element);
	int getSize() { return counter; };
	void removeAll();
	bool isAssigned(T& element);
};

