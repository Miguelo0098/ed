/*!

	\file principalMonticulo2.cpp
	\brief Programa principal mejorado de la practica 3 de Estructuras de Datos
	 \author   Miguel Ángel Ramírez Ruiz
	 \date     05/05/2018
	 \version  2.0
*/


#include <iostream>

#include <string>

#include "funcionesAuxiliares.hpp"

#include "MonticuloMediciones.hpp"
#include "Medicion.hpp"

#include "macros.hpp"


int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		std::cout << "Modo de ejecución" << std::endl;
		std::cout << argv[0] << "<fichero-de-mediciones>  <fichero-ordenado> "  << std::endl;

		return -1;
	}
	
	ed::MonticuloMediciones monticulo;
	std::string nombreFicheroEntrada(argv[1]);
	std::string nombreFicheroSalida(argv[2]);
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
					std::cout << "[1] Comprobar si el montículo tiene mediciones" << std::endl;
					ed::comprobarMonticuloVacio(monticulo);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 2: 
					std::cout << "[2] Cargar las mediciones en el montículo desde el fichero" << std::endl;
					ed::cargarMonticuloDeFichero(nombreFicheroEntrada, monticulo);
				break;

			case 3: 
					std::cout << "[3] Grabar las mediciones del montículo en el fichero" << std::endl;
					ed::grabarMonticuloEnFichero(nombreFicheroSalida, monticulo);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 4: 
				  	std::cout << "[4] Consultar mediciones del montículo: " << std::endl; 
					ed::consultarMediciones(monticulo);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 5: 
					std::cout << "[5] Modificar primera medición del montículo" 
							  << std::endl;
				  	ed::modificarMedicionMonticulo(monticulo);
					break;


			case 6: 
					std::cout << "[6] Borrar todas las mediciones del montículo" << std::endl;
				 	ed::borrarTodasMediciones(monticulo);
					break;

			//////////////////////////////////////////////////////////////////////////////

			case 7: 
					std::cout << "[7] Insertar una medicion" << std::endl;
				  	ed::insertarMedicionMonticulo(monticulo);
					break;

			case 8: 
					std::cout << "[8] Borrar una medicion" << std::endl;
					ed::borrarMedicionMonticulo(monticulo);
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

