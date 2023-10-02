#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {
    private:
	void resize(int new_size);
	T* arr;
	int max;
	int n;
	static const int MINSIZE;

    public:
        ListArray();
	~ListArray();
	T operator[](int pos);
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
	T remove (int pos);
	T get(int pos);
	int search(T e);
	bool empty();
	int size();
    
};
