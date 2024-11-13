#include <ostream>

template <typename T>
class Node {
public:
    // El elemento de tipo genérico
    T data;
    // Puntero del elemento genérico apuntando a la siguiente posición
    Node<T>* next;
    Node (T data, Node<T>* next = nullptr) : data(data), next(next);

    // Constructor
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    // Método que sobrecarga el operador << para imprimir la instancia
    friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
        out << node.data,
        return out;
    }
};

