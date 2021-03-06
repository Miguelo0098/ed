#include "grafo.hpp"

#include <iostream>
#include <cfloat>

ed::Grafo ed::Grafo::getPrimTree(){

	// Creación del grafo a retornar
	ed::Grafo primTree;
	primTree._vertices = _vertices;
	primTree._matrizAdyacencia = _matrizAdyacencia;
	primTree._matrizAdyacencia.assign(primTree._matrizAdyacencia.size(), 0.0); // Matriz vacia a rellenar

	// Vector con vertices conocidos (insertamos el primero)
	std::vector<unsigned int> vertices_conocidos;
	vertices_conocidos.push_back(0);

	while(vertices_conocidos.size() < getnVertices()){
		double minval = DBL_MAX;
		unsigned int fila = -1;
		unsigned int columna = -1;

		// Iteraciones de vertices conocidos
		for (unsigned int i = 0; i < vertices_conocidos.size(); ++i)
		{

			// Iteraciones de lados de los nodos conocidos
			for (unsigned int j = 0; j < getnVertices(); ++j)
			{
				int conocido = 0;
				// Iteraciones para comprobar que el vertice j es desconocido
				for (unsigned int k = 0; k < vertices_conocidos.size(); ++k)
				{
					if (vertices_conocidos[k] == j)
					{
						conocido = 1;
					}
				}

				if (conocido == 0 && _matrizAdyacencia[vertices_conocidos[i]*getnVertices() + j] < minval)
				{
					// Se actualiza el valor del lado mas corto y se busca los nodos origen y destino
					minval = _matrizAdyacencia[vertices_conocidos[i]*getnVertices() + j];
					fila = vertices_conocidos[i];
					columna = j;
				}
			}
		}

		// Guardamos los valores en la matriz del grafo a retornar.
		primTree._matrizAdyacencia[fila*primTree.getnVertices() + columna] = _matrizAdyacencia[fila*primTree.getnVertices() + columna];
		primTree._matrizAdyacencia[columna*primTree.getnVertices() + fila] = _matrizAdyacencia[columna*primTree.getnVertices() + fila];
		vertices_conocidos.push_back(columna);

	}

	return primTree;

}


ed::Grafo ed::Grafo::getKruskalTree(){

	// Creación del grafo a retornar
	ed::Grafo kruskalTree;
	kruskalTree._vertices = _vertices;
	kruskalTree._matrizAdyacencia = _matrizAdyacencia;
	kruskalTree._matrizAdyacencia.assign(kruskalTree._matrizAdyacencia.size(), 0.0); // Matriz vacia a rellenar

	// Vector con vertices conocidos (insertamos el primero)
	std::vector<unsigned int> vertices_conocidos;

	while(vertices_conocidos.size() < getnVertices()){
		double minval = DBL_MAX;
		unsigned int fila = -1;
		unsigned int columna = -1;
		int insertunknown_i = 0;
		int insertunknown_j = 0;

		// Iteraciones de filas
		for (unsigned int i = 0; i < getnVertices(); ++i)
		{

			// Iteraciones de columnas
			for (unsigned int j = 0; j < getnVertices(); ++j)
			{

				// Iteraciones para comprobar que tanto los vertices i como j son desconocidos
				int conocido_i = 0;
				int conocido_j = 0;

				for (unsigned int k = 0; k < vertices_conocidos.size(); ++k)
				{
					if (vertices_conocidos[k] == i)
					{
						conocido_i = 1;
					}
					if (vertices_conocidos[k] == j)
					{
						conocido_j = 1;
					}
				}

				if (vertices_conocidos.size() == 0)
				{
					if ((conocido_i == 0 || conocido_j == 0)
						&& _matrizAdyacencia[i*getnVertices() + j] < minval
						&& _matrizAdyacencia[i*getnVertices() + j] > 0)
					{
						minval = _matrizAdyacencia[i*getnVertices() + j];
						fila = i;
						columna = j;
						insertunknown_i = conocido_i;
						insertunknown_j = conocido_j;
					}
				}
				else{
					if (((conocido_i == 0) ^ (conocido_j == 0))
						&& _matrizAdyacencia[i*getnVertices() + j] < minval
						&& _matrizAdyacencia[i*getnVertices() + j] > 0)
					{
						minval = _matrizAdyacencia[i*getnVertices() + j];
						fila = i;
						columna = j;
						insertunknown_i = conocido_i;
						insertunknown_j = conocido_j;
					}
				}
				
			}
		}

		// Guardamos los valores en la matriz del grafo a retornar.
		kruskalTree._matrizAdyacencia[fila*kruskalTree.getnVertices() + columna] = _matrizAdyacencia[fila*kruskalTree.getnVertices() + columna];
		kruskalTree._matrizAdyacencia[columna*kruskalTree.getnVertices() + fila] = _matrizAdyacencia[columna*kruskalTree.getnVertices() + fila];
		if (insertunknown_i == 0 || insertunknown_j == 0)
		{
			if (insertunknown_i == 0)
			{
				vertices_conocidos.push_back(fila);
			}
			if (insertunknown_j == 0)
			{
				vertices_conocidos.push_back(columna);
			}
		}

		
		
	}

	return kruskalTree;

}


void ed::Grafo::printGrafo(){
	std::cout << "VERTICES:" << std::endl;
	for (unsigned int i = 0; i < getnVertices(); ++i)
	{
		std::cout << "Nº " << i << ": " << getVertice(i) << std::endl;
	}

	std::cout << "MATRIZ DE CONEXIONES:" << std::endl;

	for (unsigned int i = 0; i < getnVertices(); ++i)
	{
		for (unsigned int j = 0; j < getnVertices(); ++j)
		{
			std::cout << "M[" << i << "][" << j << "]: " << _matrizAdyacencia[i*getnVertices() + j] << "\t";
		}
		std::cout << std::endl;
	}
}