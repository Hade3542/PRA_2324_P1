#include <ostream>

template <typename T> 
class Node {
public:
    T data;              // Dato almacenado
    Node<T>* next;       // Puntero al siguiente nodo

    // Constructor
    Node(T data, Node<T>* next = nullptr) {
        this->data = data;
        this->next = next;
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;
        return out;
    }
};

