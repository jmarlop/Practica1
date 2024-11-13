#include <ostream>
#include "List.h"
template <typename T>
class ListArray : public List<T>
{
private:
    int max;
    int n;
    static const int MINSIZE;
    T* arr;
    void resize (int new_size){
        T* newArr = new T[new_size];
        for (int i= 0; i < n; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        max=new_size;
    }

public:
    int size() override{return 0;};
    bool empty()override {return true;};
    void insert(int pos, T e)override{
        if ((pos<1) ||(pos>max-1)){
            throw std::out_of_range("Estas fuera de rango");
        }	
        //Aumentar el tamaño si es necesario 
        if (n == max){
            resize (max * 2);
        }
        //Recorrer el vector desde el final hasta pos
        for (int i = n - 1; pos < i; --i){
            arr[i + 1] = arr[i];
        }
        arr[pos] = e;
        return arr[pos];
        n++;
    }
    void append(T e)override{
	arr[max - 1] = e;
    }
    void prepend(T e)override{
    	int ini=0;
    	arr[ini]=e;
    }
    T remove(int pos) override {
    if ((pos < 1) || (pos > max - 1)) {
        throw std::out_of_range("Estás fuera de rango");
    }
    //Guardamos el elemento a redireccionar
    T element = arr[pos];

    for (int i = pos; i < n-1; i++){
        arr[i] = arr [i + 1];
    }
    //Hacemos que se recorra el vector desde pos hasta el final
    n--;
    //Reducimos el tamaño del arr
    if (n<=max/2){
        resize (max/2);
    }
    //Que se redimensione si es necesario
    return element;
    //Que devuelva el elemento 

}
    T get(int pos)override{
        if((pos<1)|| (pos>max-1)){
 	       throw std::out_of_range("estas fuera de rango");
        }

        return arr[pos];
    }
    int search(T e) override{
    	for(int i; i<max; i++){
		if(arr[i]==e){
			return i;
			break;
		}
		else{ return -1;}

	}
    }
    ListArray(){
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }
    ~ListArray(){
        delete[] arr;
    }
    T& operator[](int pos){
        if((pos<1)|| (pos>max-1)){
 	       throw std::out_of_range("estas fuera de rango");
        }
        return arr[pos];
    }
    friend std::ostream&operator<<(std::ostream &out , const ListArray <T> &list){
        for (int i=0; i < list.n; i++){
            out << list.arr[i] << " ";
        }
        return out;
    }
};
