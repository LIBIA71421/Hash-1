#include <iostream>
#include "HashTable.h"
#include <fstream>
#include "Diccionario.h"
#include <fcntl.h>


int main() {

  HashTable<string> HASH;
  int cont[50];
 	ifstream archi;

	archi.open("HASH_ESP(2).txt");

  	if (archi.is_open()) {
		string linea;
		while (getline(archi, linea))
		{
      HASH.add(linea);
		}
		archi.close();
	}
	else {
		cout << "no se encontro el archivo....";
	}
  HASH.print();
  /*for (int i = 0; i < 50; i++)
	{
		cont[i] = 0;
	}
	double totPalabras = 0;

	for (int i = 0; i < 50; i++)
  {		
    cout << "existen " << i << " palabras" << endl;
    totPalabras = totPalabras + i;
	}
	return 0;*/
  
}






















/*

	Hash<PalabraLibro> palabras(15361);
	int cont[10000];
	leerDeArchivo(palabras);


	palabras.mostrar(PalabraLibro::mostrarPalabra);

	for (int i = 0; i < 10000; i++)
	{
		cont[i] = 0;
	}

	palabras.contarCajas(cont);

	int totPalabrasDistintas = 0;
	double totPalabras = 0;

	for (int i = 0; i < 10000; i++)
	{
		
		if (cont[i] != 0)
		{
			cout << "existen " << cont[i] << " cajas con " << i << " archivos" << endl;
			totPalabras = totPalabras + i;
			if (i != 0)
			{
				totPalabrasDistintas = totPalabrasDistintas + cont[i];
			}
		}
	}

	cout << "total de palabras distintas dentro del libro " << totPalabrasDistintas << endl;
	//cout << "total de palabras dentro del libro " << totPalabras << endl;

	//cout<<palabras.buscar(palabraABuscar)<<endl;
	return 0;
}


//main para pruebas
/*
int main()
{
	Hash<PalabraLibro> palabras(278261);
	PalabraLibro* c1 = new PalabraLibro(1, "Azul");
	PalabraLibro* c2 = new PalabraLibro(2, "Verde");
	PalabraLibro* c3 = new PalabraLibro(3, "Rojo");
	PalabraLibro* c4 = new PalabraLibro(4, "Amarillo");
	PalabraLibro* c41 = new PalabraLibro(4, "Amarillo");
	PalabraLibro* c42 = new PalabraLibro(4, "Amarillo");
	PalabraLibro* c5 = new PalabraLibro(5, "Negro");

	PalabraLibro* palabraABuscar = new PalabraLibro("Verde");

	palabras.insertarEnHash(PalabraLibro::getTot, c1);
	palabras.insertarEnHash(PalabraLibro::getTot, c2);
	palabras.insertarEnHash(PalabraLibro::getTot, c3);
	palabras.insertarEnHash(PalabraLibro::getTot, c4);
	palabras.insertarEnHash(PalabraLibro::getTot, c5);
	palabras.insertarEnHash(PalabraLibro::getTot, c41);
	palabras.insertarEnHash(PalabraLibro::getTot, c42);
	palabras.mostrar(PalabraLibro::mostrarPalabra);

	cout<<palabras.buscar(PalabraLibro::getTot,palabraABuscar)<<endl;
	palabras.eliminarEnHash(PalabraLibro::getTot, c41);
	palabras.mostrar(PalabraLibro::mostrarPalabra);
	return 0;
}*/

//lo intente
/*
int wmain(int argc, wchar_t* argv[])
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"Testing unicode -- English -- Ελληνικά -- Españoló." <<endl;
	Hash<PalabraLibro> palabras(278261);
	leerDeArchivo(palabras);
	palabras.mostrar(PalabraLibro::mostrarPalabra);
}*/
