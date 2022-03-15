#include <iostream>
#include "HashTable.h"
#include <fstream>
#include "Diccionario.h"


void leerDeArchivo(HashTable<Diccionario>& palabras)
{
	ifstream archi;
	int numerosArchivo;
	int cont = 0;
	string palabrasArchivo;

	archi.open("cien_años_de_soledad.txt");
	//archi.open("prueba.txt");

	if (!archi)
		cout << "No se puede abrir";
	else
		while (!archi.eof() && archi >> palabrasArchivo)
		{
			palabras.add(Diccionario::getTot,new Diccionario(cont,palabrasArchivo));
			cont = cont+1;
		}
	archi.close();
}

int main() {
	/*Lista7<int> L;
	L.insertarPrincipio(1);
	HashTable<int> HT;
	for(int i = 0; i < 10;i++){
		HT.add(i);
	}
	HT.remove(1);
	HT.search(1);
*/
  
  HashTable<int> ci;
  ci.add(32145);
  ci.add(548787);
  ci.add(54);
  ci.print();
  ci.remove(548787);
  ci.print();
  cout << ci.search(54);
}