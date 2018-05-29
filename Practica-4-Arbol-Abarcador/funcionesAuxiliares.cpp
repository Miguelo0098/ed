/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author Miguel Ángel Ramírez Ruiz
  \date   
*/

#include <iostream>
#include <fstream>
#include <string>  

// Para usar atoi
#include <stdlib.h>

#include "grafo.hpp"

#include "vertice.hpp"

#include "funcionesAuxiliares.hpp"


#include "macros.hpp"

int ed::menu(){
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Comprobar si el grafo está vacío";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar los vértices desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar los vértices en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Mostrar Grafo";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar Árbol Abarcador de Coste Mínimo (PRIM)";

	PLACE(posicion++,10);
	std::cout << "[6] Mostrar Árbol Abarcador de Coste Mínimo (KRUSKAL)";

	PLACE(posicion++,10);
	std::cout << "[7] Mostrar longitud del Arbol Abarcador de Coste Mínimo";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un vértice";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un vértice";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un vértice";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}

void ed::comprobarGrafoVacio(ed::Grafo & grafo){
	if (grafo.isEmpty() == true)
	{
		std::cout << "El grafo está vacío." << std::endl;
		return;
	}
	std::cout << "El grafo tiene contenido." << std::endl;
}


void ed::cargarVerticesFichero(ed::Grafo & grafo){
	std::string fichero;
	std::cout << "Introduzca el nombre del fichero a cargar: " << std::endl;
	std::cin >> fichero;
	getchar();
	std::ifstream flujo_entrada;
	flujo_entrada.open(fichero.c_str(), std::ios::in);
	if (!flujo_entrada)
	{
		std::cout << "ERROR: no se pudo cargar el fichero." << std::endl;
		return;
	}

	if (grafo.isEmpty() == false)
	{
		grafo.removeAll();
	}
	ed::Vertice aux;
	while(flujo_entrada >> aux){
		grafo.addVertex(aux);
	}
	flujo_entrada.close();

	std::cout << "Datos cargados con éxito!" << std::endl;
}


void ed::grabarVerticesFichero(ed::Grafo & grafo){
	std::string fichero;
	std::cout << "Introduzca el nombre del fichero a grabar: " << std::endl;
	std::cin >> fichero;
	getchar();
	std::ofstream salida;
	salida.open(fichero.c_str(), std::ios::out);
	if (!salida)
	{
		std::cout << "ERROR: no se pudo cargar el fichero." << std::endl;

		return;
	}
	if (grafo.isEmpty() == false)
	{
		for (unsigned int i = 0; i < grafo.getnVertices(); ++i)
		{
			salida << grafo.getVertice(i) << std::endl;
		}
	}


	std::cout << "Fichero grabado con éxito." << std::endl;
	return;
}


void ed::mostrarGrafo(ed::Grafo & grafo){
	if (grafo.isEmpty() == true)
	{
		std::cout << "ERROR: no se puede imprimir un grafo vacío." << std::endl;
		return;
	}
	grafo.printGrafo();
}


void ed::aplicarPrim(ed::Grafo & grafo){
	if (grafo.isEmpty() == true)
	{
		std::cout << "ERROR: no se puede obtener el Arbol Abarcador de coste mínimo de un grafo vacío." << std::endl;
		return;
	}
	grafo.getPrimTree().printGrafo();
}


void ed::aplicarKruskal(ed::Grafo & grafo){
	if (grafo.isEmpty() == true)
	{
		std::cout << "ERROR: no se puede obtener el Arbol Abarcador de coste mínimo de un grafo vacío." << std::endl;
		return;
	}
	grafo.getKruskalTree().printGrafo();
}


void ed::printLongitudAACM(ed::Grafo & grafo){
	std::cout << "La longitud del Árbol Abarcador de Coste Mínimo es " << grafo.getPrimTree().getLongitudGrafo() << std::endl;
}


void ed::consultarVertice(ed::Grafo & grafo){
	if (grafo.isEmpty() == true)
	{
		std::cout << "ERROR: el grafo está vacío." << std::endl;
		return;
	}
	unsigned int i = 0;
	std::cout << "Introduzca el indice del vértice (0 por defecto): " << std::endl;
	std::cin >> i;
	getchar();

	if (i < grafo.getnVertices() && i >= 0)
	{
		std::cout << "Vertice nº " << i << ": " << grafo.getVertice(i) << std::endl;
	}
	else{
		std::cout << "ERROR: no existe dicho vertice." << std::endl;
	}
}


void ed::insertarVertice(ed::Grafo & grafo){
	ed::Vertice nuevo;
	nuevo.leerVertice();
	std::cout << "Insertando vértice..." << std::endl;
	grafo.addVertex(nuevo);
	std::cout << "Vertice insertado con éxito!" << std::endl;
}


void ed::borrarVertice(ed::Grafo & grafo){
	if (grafo.isEmpty() == true)
	{
		std::cout << "ERROR: el grafo está vacío." << std::endl;
		return;
	}
	unsigned int i = 0;
	std::cout << "Introduzca el indice del vértice a borrar (0 por defecto): " << std::endl;
	std::cin >> i;
	getchar();

	if (i < grafo.getnVertices() && i >= 0)
	{
		std::cout << "Borrando vértice..." << std::endl;
		grafo.removeVertex(i);
		std::cout << "Vertice borrado con éxito!" << std::endl;
	}
	else{
		std::cout << "ERROR: no existe dicho vertice." << std::endl;
	}
}