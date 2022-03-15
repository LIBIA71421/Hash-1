#include "Lista7.h"
#include <sstream>
#define A 0.618
#define TAM 20023
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

	T add(T value){
		T ans = arr[hashFunction(value)].addFirst(value);
		return ans;
	}

	T remove(T value){
		T ans = arr[hashFunction(value)].deleteElement(value);
		return ans;
	}

	bool search(T key) {
		int pos = hashFunction(key);
		return arr[pos]->recursiveSearch(key, arr[pos]->getFirst());
	}

void print() {
		for (int i = 0; i < TAM; i++) {
			cout << "LIST " << i << endl;
			arr[i]->print();
		}
	}


};