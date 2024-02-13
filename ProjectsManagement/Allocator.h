#pragma once
#include <stdexcept>
template<typename T, int limit = 100>
class Allocator
{
private:
	T* data;
	int counter;
	void realloc(int newLimit);
public:
	Allocator();
	~Allocator();
	void addElement(T& element);
	T& operator[](int idx);
	bool removeElement(const T& element);
};

