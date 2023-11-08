#include <ostream>
#include "List.h"
using namespace std;
template <typename T>

class ListArray : public List<T> {
   private:
	T* arr;
	int max;
	int n;
	static const int MINSIZE=2;

	void resize(int new_size){
	int i;
	T* new_arr;
	new_arr= new T[new_size];
	for (i=0; i<new_size;i++){
		new_arr[i] = arr[i];
	};
	delete [] arr;
	arr = new_arr;
	max = new_size;
	};

    public:
	void insert(int pos, T e){		
		if(0>pos || n<pos){
			throw std::out_of_range("Posición inválida");
		}
		if(pos >= max){
			resize(2*max);
		}
		if(n == 0){
			arr[n] = e;
		}
	 	if(pos==n){
			arr[pos] = e;
		}
		for(int i = n; i >= pos; i--){
			arr[i]=arr[i-1];
		}
		arr[pos]=e;
		n++;
        };
	void append (T e){
		insert(n,e);
	};
	void prepend(T e){
		insert(0,e);
	};		

	T remove (int pos){
	int i;
	if (pos<0 || pos >n){
	       throw std::out_of_range("fuera de rango");
 	};
	for (i=pos;i<n-1;i++){
		arr[i] = arr[i+1];
	};
	n--;
	return arr[pos];
	};

	T get(int pos){
	int i;
	if(pos<0 || pos>n){
		throw std::out_of_range("fuera de rango");
	};
	return arr[pos];
	};

	int search(T e){
	int i;
	for (i=0;i<n;i++){
		if (arr[i]==e)
			return arr[e];
	}
	return -1;
	};

	bool empty(){
	if (n==0)
		return true;
	else
		return false;
	};

	int size(){
	return n;
	};
    
	ListArray(){
	arr = new T[MINSIZE];
	max = MINSIZE;
	n =0;
	};

	~ListArray(){
	delete [] arr;
	};

	
	T operator[](int pos){
	return get(pos);
	};

	friend ostream& operator<<(ostream &out, const ListArray<T> &list){
	int i;
	out << "ARRAY [";
       	for (i=0; i < list.n;i++){
	out << "\n" << list.arr[i];
	};
	if (list.n>0)
		out << "\n";

	out << "]";
	return out;
	};

};
