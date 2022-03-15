#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

#include <string>
using namespace std;
/*MARTES Lista 8 (con tripla)
CREAR CON UN MENU las Siguientes opciones
1. Insertar Principio
2. Insertar Final
3. Eliminar Principio
4. Eliminar Final
5. Buscar NO Recursivo
6. Buscar Recursivo
7. Buscar iésimo elemento (Primer, segundo, tercer..etc)
8. Mostrar la lista
9. Eliminar Elemento DADO
10. Eliminar Toda la Lista
11. Insertar en la lista 10.000 numeros del archivo
12. Eliminar 5000 numeros de la lista (la mitrad)
*/

template <class T,class J>
class DoubleLinkedList {
private:
	Node<T,J>* first;
	Node<T,J>* last;
	int length;
public:
	DoubleLinkedList() {

		
		first = NULL;
		last = NULL;
		length = 0;
		
	}
	~DoubleLinkedList() {
		deleteTheWholeList();
	}

	Node<T,J>* getfirst() {
		return first;
	}

	void addFirst(J key, T value)
	{
		if (first == NULL)
		{
			Node<T,J>* newNode = new Node<T,J>(key,NULL, value, NULL);
			first = newNode;
			last = newNode;
			length++;
		}
		else {
			Node<T,J>* newNode = new Node<T,J>(key,NULL, value, first);
			first->setPrevious(newNode);
			first = newNode;
			length++;
		}
	}
	void addLast(J key, T value)
	{
		if (first == NULL)
		{
			Node<T,J>* newNode = new Node<T,J>(key,NULL, value, NULL);
			first = newNode;
			last = newNode;

		}
		else {
			Node<T,J>* newNode = new Node<T>(key,last, value, NULL);
			last->setNext(newNode);
			last = newNode;

		}
	}

	bool removeFirst() {
		bool ans = true;
		if (first == NULL && last == NULL) {
			ans = false;
			length--;
		}
		else {
			if (first == last) {
				delete first;
				first = NULL;
				last = NULL;
				length--;
			}
			else {
				Node<T,J>* aux = first->getNext();
				aux->setPrevious(NULL);
				delete first;
				first = aux;
				length--;
			}
		}
		return ans;
	}
	bool removeLast() {
		bool ans = true;
		if (first == NULL && last == NULL) {
			ans = false;
			length--;
		}
		else {
			if (first == last) {
				delete first;
				first = NULL;
				last = NULL;
				length--;
			}
			else {
				Node<T,J>* aux = last->getPrevious();
				aux->setNext(NULL);
				delete last;
				last = aux;
				length--;
			}
		}
		return ans;
	}

	bool search(J key) {
		bool ans = false;
		Node<T,J>* current = first;
		while (current != NULL) {

			if (current->getKey() == key) {
				ans = true;
				break;
			}
			current = current->getNext();
		}
		return ans;
	}

	bool recursiveSearch(J key, Node<T,J>* first) {
		bool ans;
		if (first == NULL) {
			ans = false;
		}
		else	if (first->getKey() == key) {
			ans = true;
		}
		else {
			ans = recursiveSearch(key,first->getNext());
		}
		return ans;
	}



	Node<T,J>* searchByIndex(int index) {
		Node<T,J>* current = first;
		while (index > 0 && current != NULL) {
			current = current->getNext();
			index--;
		}

		return current;
	}
	// entrada:1

	void deleteElement(T value) {
		if (first != NULL)
		{
			Node<T, J>* current = first;
			// chequear si no esta vacia
			while (current != NULL)
			{
				//check compare			
				if (current->getValue() == value)
				{

					//caso 1: elemento unico
					if (current->getPrevious() == NULL && current->getNext() == NULL) {
						delete current;
						first = NULL;
						last = NULL;
						length--;

					}
					// caso 2: elemento es cabeza
					else if (current == first) {
						first = first->getNext();
						first->setPrevious(NULL);
						length--;
					}
					// caso 3: elemento es cola
					else if (current == last) {
						last = last->getPrevious();
						last->setNext(NULL);
						length--;
					}

					//caso 4: elemento esta en medio
					else {
						Node<T>* aux = current->getPrevious();
						aux->setNext(current->getNext());
						Node<T>* aux2 = current->getNext();
						aux2->setPrevious(current->getPrevious());
						delete current;
						// queda el enlace al anterior que en 188 se actualiza a getNext();
						current = aux;
						length--;

					}


				}
				current = current->getNext();
			}
		}
	}
		void deleteElementByKey(J key) {
			if (first != NULL)
			{
				Node<T,J>* current = first;
				// chequear si no esta vacia
				while (current != NULL)
				{
					//check compare			
					if (current->getKey() == key)
					{

						//caso 1: elemento unico
						if (current->getPrevious() == NULL && current->getNext() == NULL) {
							delete current;
							first = NULL;
							last = NULL;
							length--;

						}
						// caso 2: elemento es cabeza
						else if (current == first) {
							first = first->getNext();
							first->setPrevious(NULL);
							length--;
						}
						// caso 3: elemento es cola
						else if (current == last) {
							last = last->getPrevious();
							last->setNext(NULL);
							length--;
						}

						//caso 4: elemento esta en medio
						else {
							Node<T,J>* aux = current->getPrevious();
							aux->setNext(current->getNext());
							Node<T,J>* aux2 = current->getNext();
							aux2->setPrevious(current->getPrevious());
							delete current;
							// queda el enlace al anterior que en 188 se actualiza a getNext();
							current = aux;
							length--;

						}


					}
					current = current->getNext();
				}
			}
		}
	
	/*
	void deleteElement (T value){
		if(first!=NULL)
		{
			Node<T>* current = first;
				// chequear si no esta vacia
				while(current != NULL)
				{
					//check compare
					if(current->getValue()==value)
					{

						//caso 1: elemento unico
							if(current->getPrevious()==NULL && current->getNext() == NULL){
								delete current;
								first=NULL;
								last=NULL;

							}
						// caso 2: elemento es cabeza
							else if(current == first){
									first=first->getNext();
									first->setPrevious(NULL);

							}
							// caso 3: elemento es cola
							else if(current == last){
									last=last->getPrevious();
									last->setNext(NULL);
							}

							//caso 4: elemento esta en medio
							else{
								current->getPrevious()->setNext(current->getNext());
								current->getNext()->setPrevious(current->getPrevious());
							}


					}
					current = current->getNext();
				}
		}
	}*/


	void deleteTheWholeList()
	{
		while (first != last)
			removeFirst();
		removeFirst();
		length = 0;
	}

	DoubleLinkedList<T,J>* readFile(string path) {
		DoubleLinkedList<string,int>* list = new DoubleLinkedList<string,int>();
		ifstream file(path);
		string data;
		if (file.fail()) {
			cerr << "Error: File Cannot Be Opened" << endl;
		}
		else
			while (!file.eof())
			{
				getline(file, data);
				int aux = stoi(data);
				list->addLast(aux);
			}
		return list;
	}

	void deleteElementsUntil(int n) {
		for (int i = 1; i <= n; i++) {
			deleteElement(i);
		}
	}




	void print() {
		if (first != NULL) {
			Node<T,J>* current = first;

			while (current != NULL) {

				cout <<" " << current->getValue() << endl;
				current = current->getNext();
			}
			//cout << "first: " << first->getValue() << endl;
			//cout << "Last: " << last->getValue() << endl;
		}
		else {
			cout << "Empty List" << endl;
		}
	}

	int getLength() {
		return length;
	}
};