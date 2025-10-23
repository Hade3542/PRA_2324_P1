#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;
    int n;

public:
    // Constructor
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;
            delete first;
            first = aux;
        }
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++)
            aux = aux->next;
        return aux->data;
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "List => [";
        Node<T>* aux = list.first;
        while (aux != nullptr) {
            out << "\n  " << aux->data;
            aux = aux->next;
        }
        out << "\n]";
        return out;
    }

    // Métodos heredados de List<T> (esqueleto mínimo)
    int size() const override { return n; }
    bool empty() const override { return n == 0; }
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición inválida");

        if (pos == 0)
            first = new Node<T>(e, first);
        else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");

        Node<T>* toDelete;
        T data;

        if (pos == 0) {
            toDelete = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;
            toDelete = prev->next;
            prev->next = toDelete->next;
        }

        data = toDelete->data;
        delete toDelete;
        n--;
        return data;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++)
            aux = aux->next;
        return aux->data;
    }

    int search(T e) const override {
        Node<T>* aux = first;
        int pos = 0;
        while (aux != nullptr) {
            if (aux->data == e)
                return pos;
            aux = aux->next;
            pos++;
        }
        return -1;
    }
};

