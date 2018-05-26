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
		la matriz
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
			for (int i = 0; i < getnVertices(); ++i)
			{
				for (int j = 0; j < getnVertices(); ++j)
				{
					_matrizAdyacencia[(i * getnVertices()) + j] = getDistanciaEuclidea(_vertices[i], _vertices[j]);
				}
			}
		}


	public:
		Grafo();
		
		inline int getnVertices(){
			return _vertices.size();
		}
		
	};
}


#endif