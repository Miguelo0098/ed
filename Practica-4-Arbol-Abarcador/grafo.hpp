/*!
  \file   grafo.hpp
  \brief  Fichero de cabecera de la clase Grafo
  \author Miguel Ángel Ramírez Ruiz
  \date   14/05/2018
*/

#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "vertice.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>

namespace ed{

	//!  Definición de la clase Grafo
	class Grafo{

	 //! \name Atributos privados de la clase Grafo
	private:
		std::vector<ed::Vertice> _vertices;		 //!< vector de vértices
		std::vector<double> _matrizAdyacencia;	 //!< matriz de adyacencias


		//! \name Funciones o métodos privados de la clase Grafo

		/*! 
			\brief     Funcion que añade un vertice al vector de vertices
			\note      Función inline
			\note	   No modifica la matriz de adyacencias
			\param	   v: vértice a insertar
			\pre       none
			\post      none
		*/
		inline void _justAddVertice(ed::Vertice & v){
			if (hasVertice(v) == false)
			{
				v.setLabel(getnVertices());
				_vertices.push_back(v);
			}
		}

		/*! 
			\brief     Funcion que reajusta la matriz de adyacencias
			\note      Función inline
			\note	   La matriz queda totalmente conexa
			\pre       none
			\post      none
		*/
		inline void _remakeMatrix(){
			_matrizAdyacencia.resize(getnVertices()*getnVertices());
			for (unsigned int i = 0; i < getnVertices(); ++i)
			{
				for (unsigned int j = 0; j < getnVertices(); ++j)
				{

					_matrizAdyacencia[(i * getnVertices()) + j] = getDistanciaEuclidea(_vertices[i], _vertices[j]);
				}
			}
		}

	//! \name Métodos públicos de la clase Grafo
	public:
		
		/*! 
			\brief     Constructor que crea un grafo vacio
			\note      Función inline
			\pre       Ninguna
			\post      isEmpty() == true
		*/


		inline Grafo(){
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(isEmpty() == true);
			#endif //NDEBUG
		}
		

		//! \name Observadores


		/*!
    	    \brief  Funcion que retorna el número de vértices del grafo
			\note   Función inline
			\pre    Ninguna
			\post   Ninguna
    	    \return número de vértices (tipo unsigned int)
    	*/
		inline unsigned int getnVertices(){
			return _vertices.size();
		}


		/*!
    	    \brief  Comprueba si el grafo está vacio
    	    \note   Función inline
			\pre    none
			\post   none
    	    \return true, si el grafo está vacio; false, en caso contrario
    	*/
		inline bool isEmpty(){
			if (_vertices.empty() == true)
			{
				return true;
			}
			return false;
		}


		/*!
    	    \brief  Comprueba si el vértice está dentro del grafo
    	    \note   Función inline
    	    \param	v: Vertice a buscar en el grafo
			\pre    none
			\post   none
    	    \return true, si el vértice está en el grafo; false, en caso contrario
    	*/
		inline bool hasVertice(ed::Vertice & v){
			for (std::vector<ed::Vertice>::iterator i = _vertices.begin(); i != _vertices.end(); ++i)
			{
				if (*i == v)
				{
					return true;
				}
			}

			return false;
		}


		/*!
    	    \brief  Función que devuelve el Vértice iesimo del grafo
    	    \note   Función inline
    	    \param	i: indice del vértice en el vector de vertices (tipo unsigned int)
			\pre    isEmpty() == false; i >= 0; i < _vertices.size()
			\post   none
    	    \return vértice indicado por el indice i
    	*/
		inline ed::Vertice & getVertice(unsigned int i){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(isEmpty() == false);
				assert(i >= 0);
				assert(i < _vertices.size());
			#endif //NDEBUG

			return _vertices[i];
		}
		

		/*!
    	    \brief  Funcion que retorna el Árbol Abarcador de coste mínimo con el algoritmo de Prim
			\pre    Ninguna
			\post   Ninguna
    	    \return Grafo abarcador de coste mínimo
    	*/
		ed::Grafo getPrimTree();
		

		/*!
    	    \brief  Funcion que retorna el Árbol Abarcador de coste mínimo con el algoritmo de Kruskal
			\pre    Ninguna
			\post   Ninguna
    	    \return Grafo abarcador de coste mínimo
    	*/
		ed::Grafo getKruskalTree();


		/*!
    	    \brief  Funcion que retorna la longitud total de todos los lados del grafo
			\note	Funcion inline
			\pre    Ninguna
			\post   Ninguna
    	    \return Grafo abarcador de coste mínimo
    	*/
		inline double getLongitudGrafo(){
			double retval = 0.0;
			if (isEmpty() == true)
			{
				return retval;
			}
			for (unsigned int i = 0; i < getnVertices(); ++i)
			{
				for (unsigned int j = 0; j < getnVertices(); ++j)
				{
					if (i <= j)
					{
						retval = retval + _matrizAdyacencia[i*getnVertices() + j];
					}
				}
			}

			return retval;
		}

		//! \name Operaciones de modificación


		/*!
    	    \brief  Funcion que añade un vértice al grafo
    	    \note	Funcion inline
    	    \param	vertice: vértice a insertar
			\pre    Ninguna
			\post   isEmprty() == false
    	*/
		inline void addVertex(ed::Vertice & vertice){
			_justAddVertice(vertice);
			_remakeMatrix();
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(isEmpty() == false);
			#endif //NDEBUG
		}

		/*!
    	    \brief  Funcion que borra el vértice iesimo del grafo
    	    \note	Funcion inline
    	    \param	i: indice del vertice a borrar
			\pre    isEmpty() == false; i >= 0; i < _vertices.size()
			\post   None
    	*/
		inline void removeVertex(unsigned int i){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(isEmpty() == false);
				assert(i >= 0);
				assert(i < _vertices.size());
			#endif //NDEBUG

			_vertices.erase(_vertices.begin() + i);
			_remakeMatrix();
		}

		/*!
    	    \brief  Funcion que borra todos los vértices del grafo
    	    \note	Funcion inline
			\pre    isEmpty() == false
			\post   isEmpty() == true
    	*/
		inline void removeAll(){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(isEmpty() == false);
			#endif //NDEBUG

			_vertices.clear();
			_remakeMatrix();
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(isEmpty() == true);
			#endif //NDEBUG
		}

		/*!
    	    \brief  Funcion que imprime los datos del grafo
			\pre    None
			\post   None
    	*/
		void printGrafo();
		
	};
}


#endif