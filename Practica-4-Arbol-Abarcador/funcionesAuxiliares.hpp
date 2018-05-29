/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author Miguel Ángel Ramírez Ruiz
  \date   05/05/2018
*/

#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP

#include "grafo.hpp"

namespace ed{

	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/

	int menu();

	/*!
    	\brief  Comprueba si el grafo está vacía
    	\param  grafo: grafo a comprobar
    */

	void comprobarGrafoVacio(ed::Grafo & grafo);

	/*!
    	\brief  Carga los vertices de un fichero en el grafo
    	\param  grafo: grafo donde cargar los vértices
    */

	void cargarVerticesFichero(ed::Grafo & grafo);

	/*!
    	\brief  Carga los vértices de un fichero en el grafo
    	\param  grafo: grafo del que se van a grabar los vértices
    */

	void grabarVerticesFichero(ed::Grafo & grafo);

	/*!
    	\brief  Muestra los vértices y la matriz de adyacencias del grafo
    	\param  grafo: grafo
    */

	void mostrarGrafo(ed::Grafo & grafo);

	/*!
    	\brief  Aplica el algoritmo de Prim y muestra el Arbol Abarcador de coste mínimo 
    	\param  grafo: grafo
    */

	void aplicarPrim(ed::Grafo & grafo);

	/*!
    	\brief  Aplica el algoritmo de Kruskal y muestra el Arbol Abarcador de coste mínimo 
    	\param  grafo: grafo
    */

	void aplicarKruskal(ed::Grafo & grafo);

	/*!
    	\brief  Imprime la longitud del arbol abarcador de coste mínimo (Prim)
    	\param  grafo: grafo
    */

	void printLongitudAACM(ed::Grafo & grafo);

	/*!
    	\brief  Muestra un vértice del grafo
    	\param  grafo: grafo
    */

	void consultarVertice(ed::Grafo & grafo);

	/*!
    	\brief  Inserta un vértice del grafo
    	\param  grafo: grafo
    */

	void insertarVertice(ed::Grafo & grafo);

	/*!
    	\brief  Borra un vértice del grafo
    	\param  grafo: grafo
    */

	void borrarVertice(ed::Grafo & grafo);
}

#endif