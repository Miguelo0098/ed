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
	class Grafo{
	private:
		std::vector<ed::Vertice> _vertices;
		std::vector<double> _matrizAdyacencia;

		inline void _justAddVertice(ed::Vertice & v){
			if (hasVertice(v) == false)
			{
				v.setLabel(getnVertices());
				_vertices.push_back(v);
			}
		}

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


	public:
		
		// Constructor

		inline Grafo(){
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(isEmpty() == true);
			#endif //NDEBUG
		}
		

		// Observadores

		inline unsigned int getnVertices(){
			return _vertices.size();
		}

		inline bool isEmpty(){
			if (_vertices.empty() == true)
			{
				return true;
			}
			return false;
		}

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

		inline ed::Vertice & getVertice(unsigned int i){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(isEmpty() == false);
				assert(i >= 0);
				assert(i < _vertices.size());
			#endif //NDEBUG

			return _vertices[i];
		}

		ed::Grafo getPrimTree();

		ed::Grafo getKruskalTree();

		//Modificadores

		inline void addVertex(ed::Vertice & vertice){
			_justAddVertice(vertice);
			_remakeMatrix();
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(isEmpty() == false);
			#endif //NDEBUG
		}

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

		inline void removeAll(){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(isEmpty() == false);
			#endif //NDEBUG

			_vertices.clear();
			_remakeMatrix();
		}

		void printGrafo();
		
	};
}


#endif