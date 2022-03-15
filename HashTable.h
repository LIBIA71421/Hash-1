#include "Lista7.h"
#include <sstream>
#include <cmath>
#include <tgmath.h> 
#include <iostream>
#include <cstddef>
#include <string>
#include <string.h>
#include <cmath>
#include <tgmath.h> 

#define TAM 1400

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

 	int hashFunction(string val) {
    int num = 0;
    for(int i=0; i < val.length();i++){
      num = num+(int)val[i];
    }
		return num;
	}

	void add(T value){
		arr[hashFunction(value)]->insertarPrincipio(value);
		}

	void remove(T value){
		arr[hashFunction(value)]->eliminarElemDado(value);
		}

	bool search(T val) {
		//int pos = hashFunction(val);
		//return arr[pos]->recursiveSearch(val, arr[pos]->getPrimer());
	}

	void print() {
		for (int i = 0; i < TAM; i++) {
			cout << i << " = ";
			arr[i]->print();
      cout<<endl;
		}
	}

};