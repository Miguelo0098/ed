#include <iostream>


#include <string>

#include "vertice.hpp"
#include "grafo.hpp"

#include "funcionesAuxiliares.hpp"
#include "macros.hpp"



/*! 
	\brief   Programa principal de la práctica 4:
	\return  int
*/
int main(){
	ed::Grafo grafo;

	int opcion;

	do{
		// Se elige la opción del menún
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
					std::cout << INVERSE;
					std::cout << "Fin del programa" << std::endl;
					std::cout << RESET;
			break;

		   ///////////////////////////////////////////////////////////////////

			case 1: 
					std::cout << "[1] Comprobar si el grafo está vacío" << std::endl;
					ed::comprobarGrafoVacio(grafo);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 2: 
					std::cout << "[2] Cargar los vértices desde un fichero" << std::endl;
					ed::cargarVerticesFichero(grafo);
				break;

			case 3: 
					std::cout << "[3] Grabar los vértices en un fichero" << std::endl;
					ed::grabarVerticesFichero(grafo);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 4: 
				  	std::cout << "[4] Mostrar Grafo" << std::endl; 
					ed::mostrarGrafo(grafo);
					break;

			case 5: 
				  	std::cout << "[5] Mostrar Árbol Abarcador de Coste Mínimo (PRIM)" << std::endl; 
					ed::aplicarPrim(grafo);
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 6: 
					std::cout << "[6] Mostrar Árbol Abarcador de Coste Mínimo (KRUSKAL)" 
							  << std::endl;
				  	ed::aplicarKruskal(grafo);
					break;


			case 7: 
					std::cout << "[7] Mostrar longitud del Arbol Abarcador de Coste Mínimo" << std::endl;
				 	ed::printLongitudAACM(grafo);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 8: 
					std::cout << "[8] Consultar un vértice" << std::endl;
			    	ed::consultarVertice(grafo);
					break;

			case 9: 
					std::cout << "[9] Insertar un vértice" << std::endl;
				  	ed::insertarVertice(grafo);
					break;

			case 10: 
					std::cout << "[10] Borrar un vértice" << std::endl;
					ed::borrarVertice(grafo);
					break;

			//////////////////////////////////////////////////////////////////////////////
			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
     }
  
    if (opcion !=0)
    {
		PLACE(25,1);
		std::cout << "Pulse ";
		std::cout << BIGREEN;
		std::cout << "ENTER";
		std::cout << RESET;
		std::cout << " para mostrar el ";
		std::cout << INVERSE;
		std::cout << "menú"; 
		std::cout << RESET;

		// Pausa
		std::cin.ignore();

		std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

	return 0;
}