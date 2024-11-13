#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
	int n;
	Node <T>* first;
        // ...

    public:
	listlinked() : first(nullptr), n(0){}
        ~listlinked(){
		Node <T>* current = first;
		while(current !=nullptr){
			Node<T> temp = current;
			delete temp;
			current = current->next;			
		}
	
	}

	T operator[](int pos){
	
	
		if (pos<0 || pos>=n){
		throw std::out_of_range("La poscion esta fuera de rango");
		}
		Node<T>* current= first;
		for(int i=0; i<n-1; i++){
			current= current->next;
		}
		return current-> data
	}
	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &	list){
		Node<T>* current = first.current;
		out << "[";
		while (current !=nullptr){
			out << current ->data;
			if (current->next != nullptr){
				out << " ' ";
			}
		current->next;
		}
		out << "]";
		return out;
	}
	void addFirst(){
		Node<T>* newNode= new Node<T>(value);
		newNode->next=first;
		first=newNode;
		++n;
		
	}
	int size const(){
	return n;
	}
}
