#include "Lista7.h"
#include <sstream>

#define TAM 1
//#define TAM 20023
using namespace std;


template <class T>
class HashTable {
  private:
	  Lista7<T>* arr[TAM];
  public:	

	HashTable() {
		for (int i = 0; i < TAM; i++)
			arr[i] = new Lista7<T>();
		cout << "se crea objeto TABLA DE HASH" << endl;
	}

	int hashFunction(int key) {
		return key % TAM;
	}

	void add(T value){
		arr[hashFunction(value)]->insertarPrincipio(value);
		}

	void remove(T value){
		arr[hashFunction(value)]->eliminarElemDado(value);
		}

	bool search(T val) {
		int pos = hashFunction(val);
		return arr[pos]->recursiveSearch(val, arr[pos]->getPrimer());
	}

	void print() {
		for (int i = 0; i < TAM; i++) {
			cout << "LIST " << i << endl;
			arr[i]->print();
		}
	}

};