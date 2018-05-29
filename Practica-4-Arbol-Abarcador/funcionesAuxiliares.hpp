#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP

#include "grafo.hpp"

namespace ed{

	int menu();


	void comprobarGrafoVacio(ed::Grafo & grafo);


	void cargarVerticesFichero(ed::Grafo & grafo);


	void grabarVerticesFichero(ed::Grafo & grafo);


	void mostrarGrafo(ed::Grafo & grafo);


	void aplicarPrim(ed::Grafo & grafo);


	void aplicarKruskal(ed::Grafo & grafo);


	void printLongitudAACM(ed::Grafo & grafo);


	void consultarVertice(ed::Grafo & grafo);


	void insertarVertice(ed::Grafo & grafo);


	void borrarVertice(ed::Grafo & grafo);
}

#endif