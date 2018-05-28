#include "grafo.hpp"

#include <iostream>
#include <cfloat>

ed::Grafo & ed::Grafo::getPrimTree(){

	// Creación del grafo a retornar
	ed::Grafo primTree;
	primTree._vertices = _vertices;
	primTree._matrizAdyacencia = _matrizAdyacencia;
	primTree._matrizAdyacencia.assign(primTree._matrizAdyacencia.size(), 0.0); // Matriz vacia a rellenar

	// Vector con vertices conocidos (insertamos el primero)
	std::vector<int> vertices_conocidos;
	vertices_conocidos.push_back(0);

	while(vertices_conocidos.size() < getnVertices()){
		double minval = DBL_MAX;
		int fila = -1;
		int columna = -1;

		// Iteraciones de vertices conocidos
		for (int i = 0; i < vertices_conocidos.size(); ++i)
		{

			// Iteraciones de lados de los nodos conocidos
			for (int j = 0; j < getnVertices(); ++j)
			{

				// Iteraciones para comprobar que el vertice j es desconocido
				for (int k = 0; k < vertices_conocidos.size(); ++k)
				{
					if (vertices_usados[k] != j
						&& _matrizAdyacencia[vertices_conocidos[i]*getnElements() + j] < minval)
					{

						// Se actualiza el valor del lado mas corto y se busca los nodos origen y destino
						minval = _matrizAdyacencia[vertices_conocidos[i]*getnElements() + j];
						fila = vertices_conocidos[i];
						columna = j;
					}
				}
			}
		}

		// Guardamos los valores en la matriz del grafo a retornar.
		primTree._matrizAdyacencia[fila*primTree.getnElements() + columna] = _matrizAdyacencia[fila*primTree.getnElements() + columna];
		primTree._matrizAdyacencia[columna*primTree.getnElements() + fila] = _matrizAdyacencia[columna*primTree.getnElements() + fila];
		vertices_conocidos.push_back(columna);

	}

	return primTree;

}


ed::Grafo & ed::Grafo::getKruskalTree(){

	// Creación del grafo a retornar
	ed::Grafo kruskalTree;
	kruskalTree._vertices = _vertices;
	kruskalTree._matrizAdyacencia = _matrizAdyacencia;
	kruskalTree._matrizAdyacencia.assign(kruskalTree._matrizAdyacencia.size(), 0.0); // Matriz vacia a rellenar

	// Vector con vertices conocidos (insertamos el primero)
	std::vector<int> vertices_conocidos;

	while(vertices_conocidos.size() < getnVertices()){
		double minval = DBL_MAX;
		int fila = -1;
		int columna = -1;

		// Iteraciones de filas
		for (int i = 0; i < getnVertices(); ++i)
		{

			// Iteraciones de columnas
			for (int j = 0; j < getnVertices(); ++j)
			{

				// Iteraciones para comprobar que tanto los vertices i como j son desconocidos
				if (vertices_conocidos.size() == 0)
				{
					if (_matrizAdyacencia[i*getnElements() + j] < minval)
					{

						// Se actualiza el valor del lado mas corto y se busca los nodos origen y destino
						minval = _matrizAdyacencia[i*getnElements() + j];
						fila = i;
						columna = j;
					}
				}

				else{
					for (int k = 0; k < vertices_conocidos.size(); ++k)
					{
						if (vertices_conocidos[k] != j
							&& vertices_conocidos[k] != i
							&& _matrizAdyacencia[i*getnElements() + j] < minval)
						{

							// Se actualiza el valor del lado mas corto y se busca los nodos origen y destino
							minval = _matrizAdyacencia[i*getnElements() + j];
							fila = i;
							columna = j;
						}	
					}
				}

				
			}
		}

		// Guardamos los valores en la matriz del grafo a retornar.
		kruskalTree._matrizAdyacencia[fila*kruskalTree.getnElements() + columna] = _matrizAdyacencia[fila*kruskalTree.getnElements() + columna];
		kruskalTree._matrizAdyacencia[columna*kruskalTree.getnElements() + fila] = _matrizAdyacencia[columna*kruskalTree.getnElements() + fila];
		if (vertices_conocidos.size() == 0)
		{
			vertices_conocidos.push_back(fila);
		}

		vertices_conocidos.push_back(columna);
		
	}

	return kruskalTree;

}


void ed::Grafo::printGrafo(){
	std::cout << "VERTICES:" << std::endl;
	for (int i = 0; i < getnVertices(); ++i)
	{
		std::cout << "Nº " << i << ": " << getVertice(i) << std::endl;
	}

	std::cout << "MATRIZ DE CONEXIONES:" << std::endl;

	for (int i = 0; i < getnVertices(); ++i)
	{
		for (int j = 0; j < getnVertices(); ++j)
		{
			std::cout << "M[" << i << "][" << j << "]: " << _matrizAdyacencia[i]*getnElements() + j] << "\t";
		}
		std::cout << std::endl;
	}
}