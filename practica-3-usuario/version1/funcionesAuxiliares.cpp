/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author Miguel Ángel Ramírez Ruiz
  \date   05/05/2018  
*/


#include <iostream>

#include <fstream>

#include <string>

#include "funcionesAuxiliares.hpp"
          
#include "MonticuloMediciones.hpp"

#include "Medicion.hpp"

#include "macros.hpp"

int ed::menu()
{
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
	std::cout << "[1] Comprobar si el montículo tiene mediciones";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar las mediciones en el montículo desde el fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar las mediciones del montículo en el fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Consultar mediciones del montículo: ";

	PLACE(posicion++,10);
	std::cout << "[5] Modificar primera medición del montículo";

	PLACE(posicion++,10);
	std::cout << "[6] Borrar todas las mediciones del montículo";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[7] Insertar una medicion";

	PLACE(posicion++,10);
	std::cout << "[8] Borrar una medicion";

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

void ed::comprobarMonticuloVacio(ed::MonticuloMediciones & monticulo){
	if (monticulo.isEmpty() == true)
	{
		std::cout << "El montículo está vacío." << std::endl;
	}
	else{
		std::cout << "El montículo no está vacío." << std::endl;
	}
}

void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo) 
{
	std::cout << "Cargando datos del fichero " << nombreFichero << std::endl;
	std::ifstream flujo_entrada;
	flujo_entrada.open(nombreFichero.c_str(), std::ios::in);
	monticulo.removeAll();
	ed::Medicion aux;
	while(flujo_entrada >> aux){
		monticulo.insert(aux);
	}
	flujo_entrada.close();

	std::cout << "Datos cargados con éxito!" << std::endl;
}


void ed::grabarMonticuloEnFichero(std::string const & nombreFichero, 
							      ed::MonticuloMediciones const & monticulo)
{
	std::cout << "Grabando datos en el fichero " << nombreFichero << std::endl;
	std::ofstream flujo_salida;
	flujo_salida.open(nombreFichero.c_str(), std::ios::out);
	
	ed::MonticuloMediciones aux = monticulo;

	if (aux.isEmpty() == false)
	{
		while(aux.isEmpty() != true){
			flujo_salida << aux.top() <<std::endl;
			aux.remove();
		}
	}

	flujo_salida.close();
	std::cout << "Datos grabados con éxito!" << std::endl;
}

void ed::consultarMediciones(ed::MonticuloMediciones & monticulo){
	std::cout << "DATOS DEL MONTÍCULO" << std::endl;
	monticulo.print();
}

void ed::modificarMedicionMonticulo(ed::MonticuloMediciones & monticulo){
	std::cout << "La primera medición almacenada en el montículo es " << monticulo.top() << std::endl;
	double precip_aux = 0.0;
	std::cout << "Introduzca el nuevo nivel de precipitación: ";
	std::cin >> precip_aux;
	ed::Medicion medicion = monticulo.top();
	medicion.setPrecipitacion(precip_aux);
	monticulo.modify(medicion);

	std::cout << "Se ha modificado con éxito!" << std::endl;
	getchar();
}

void ed::borrarTodasMediciones(ed::MonticuloMediciones & monticulo){
	std::cout << "Borrando todas las mediciones . . ." << std::endl;
	monticulo.removeAll();
	std::cout << "Se han borrado con éxito!" << std::endl;
}

void ed::insertarMedicionMonticulo(ed::MonticuloMediciones & monticulo){
	std::cout << "ADVERTENCIA! si la fecha introducida está incluida en el monticulo, se ignorará la inserción." << std::endl;
	ed::Medicion medicion;
	medicion.leerMedicion();
	monticulo.insert(medicion);
	std::cout << "Se ha insertado con éxito!" << std::endl;
	getchar();
}


void ed::borrarMedicionMonticulo(ed::MonticuloMediciones & monticulo){
	std::cout << "Borrando la primera de las mediciones . . ." << std::endl;
	monticulo.remove();
	std::cout << "Se ha borrado con éxito!" << std::endl;
}