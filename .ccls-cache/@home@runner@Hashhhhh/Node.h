#pragma once        
using namespace std;
template <class T>
class Node {
private:
    T value;
    Node<T>* next;
    
public:
    Node(T _value, Node<T>* _next) {

        value = _value;
        next = _next;
      }

    
    void setNext(Node* _next) {
        next = _next;
    }
    
    Node* getNext() {
        return next;
    }
    
    T getValue() {
        return value;
    }
    void setValue(T _value) {
        value = _value;
    }

};