#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>

using namespace std;

class Diccionario
{
private:
	int ci;
	string nombre;
	public:
	Diccionario(int ci, string nombre);
	Diccionario(string nombre);
	Diccionario();
	~Diccionario();
	int getCi();
	string getNombre();
	void mostrar();
	void mostrarPalabra();
	bool operator==(Diccionario* Diccionario);
	static void mostrar(Diccionario* Diccionario);
	static void mostrarPalabra(Diccionario* Diccionario);
	static int getCi(Diccionario* Diccionario);

	int transformarstringAInt();
	static int getTot(Diccionario* Diccionario);
};

Diccionario::Diccionario(int ci, string nombre)
{
	this->ci = ci;
	if (nombre.back() == '.' || nombre.back() == ',' || nombre.back() == ';' || nombre.back() == ':')
		this->nombre = nombre.substr(0,nombre.size()-1);
	else
	{
		this->nombre = nombre;
	}
}

Diccionario::Diccionario(string nombre)
{
	this->nombre = nombre;
}

Diccionario::Diccionario()
{

}

Diccionario::~Diccionario()
{

}

int Diccionario::getCi()
{
	return ci;
}

string Diccionario::getNombre()
{
	return nombre;
}

void Diccionario::mostrar()
{
	cout << "Diccionario:" << endl;
	cout << "ci: " << ci << endl;
	cout << "nombre: " << nombre << endl;
}

void Diccionario::mostrarPalabra()
{
	cout << nombre;
}

bool Diccionario::operator==(Diccionario* Diccionario)
{
	return nombre == Diccionario->nombre;
}

void Diccionario::mostrar(Diccionario* Diccionario)
{
	if (Diccionario != NULL)
	{
		Diccionario->mostrar();
	}
}

void Diccionario::mostrarPalabra(Diccionario* Diccionario)
{
	if (Diccionario != NULL)
	{
		Diccionario->mostrarPalabra();
	}
}

int Diccionario::getCi(Diccionario* Diccionario)
{
	if (Diccionario != NULL)
	{
		return Diccionario->getCi();
	}
}


int Diccionario::transformarstringAInt()
{
	double tot = 0;
	int cont = 0;
	
	char* palabrasUnicode = new char[nombre.length()];
	//strcpy_s(palabrasUnicode, nombre.length() + 1, nombre.c_str());

	while (cont != nombre.length())
	{
		if (palabrasUnicode[cont] != '.' && palabrasUnicode[cont] != ',' && palabrasUnicode[cont] != ';'
			&& palabrasUnicode[cont] != ':')
		{
			tot = tot + (int(palabrasUnicode[cont]) * (2 ^ cont));
		}
		cont++;
	}
	return abs(tot);
}

int Diccionario::getTot(Diccionario* Diccionario)
{
	if (Diccionario != NULL)
	{
		return Diccionario->transformarstringAInt();
	}
}
