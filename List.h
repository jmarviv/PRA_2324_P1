#include <iostream>
using namespace std;

template <typename T> 
class List {
    public:
	void instert(int pos, T e);
	void append(T e);
	void prepend(T e);
	T remove(int pos);
	T get(int pos);
	int search(T e);
	bool empty();
	int size();
};

