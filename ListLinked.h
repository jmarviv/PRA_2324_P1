#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
	   Node<T>* first;
	    int n;
    public:
	  void insert(int pos, T e){
	  if(0<pos || n<pos){
		  throw std:: out_of_range("Posición inválida");
	  };
	  if(n==0){
		  first = new Node<T>(e);
		  first->next = nullptr;
	  };
	  if (pos ==0){
		  Node<T>*aux = new Node<T>(e);
		  aux->next = first;
		  first = aux;
		  append(e);
	  };
	  if (pos!=0){
		  Node<T>*nuevo_nodo = new Node<T>(e);
		  Node<T> *aux=first;
		  int i = 0;
		  while(aux!=nullptr || i<pos-1){
			  aux=aux->next;
			  i++;
		  };
		  nuevo_nodo->next=aux->next;
		  aux->next=nuevo_nodo;
	  };
	  n++;
	  };

	  void append(T e){
		  insert(n,e);
	  };

	  void prepend(T e){
		  insert(0,e);
	  };

	  T remove (int pos){
		  Node<T>*aux;
		  if(0>pos || pos>n-1)
			  throw std::out_of_range("posición inválida");
		  int i=0;
		  while(aux!=nullptr || i<pos){
			  aux=aux->next;
			  i++;
		  };
		  if(pos==0)
			  first = aux->next;
		  else{
			  Node<T>*prev;
			  while(prev!=nullptr || i<pos-1){
				  prev = prev->next;
				  i++;
			  };
			  prev->next = aux->next;
		  };
		  T d = aux->data;
		  n--;
		  return d;
	  };

	  T get(int pos){
		  Node<T>*aux=first;
		  if(pos<0 || pos>n-1)
			  throw std::out_of_range("fuera de rango");
		  int i=0;
		  while(aux!=nullptr || i<pos){
			  aux=aux->next;
			  i++;
		  };
		  return aux->data;
	  };

	  int search(T e){
		  Node<T>*aux = first;
		  int i=0;
		  while(aux!=nullptr || aux->data!=e){
			  aux=aux->next;
			  i++;
		  };
		  if(aux!=nullptr)
			  return i;
		  else
			  return -1;
	  };

	 bool empty(){
		if(n==0)
		       return true;
		else
			return false;
	 };

	 ListLinked(){
		 first = nullptr;
		 n = 0;
	 };

	 ~ListLinked(){
		 Node<T>*aux= first->next;
		 delete first;
		 while(aux!=nullptr){
			 aux = aux->next;
		 };
	 };

	 T operator[] (int pos){
		 if (pos<0 || pos > n-1)
			 throw std::out_of_range("fuera de rango");
		 else
			 return pos;
	 };

	 friend std::ostream& operator <<(std::ostream &out, const ListLinked<T> &list){
		 out << "list[";
		 Node<T>*aux = list.first;
		 for(int i=0; i<list.n;i++){
			 out<<"\n"<<aux->data;
			 aux = aux->next;
		 };
		 if(list.n>0)
			 out<<"\n";
		 return out;
	 };
};

