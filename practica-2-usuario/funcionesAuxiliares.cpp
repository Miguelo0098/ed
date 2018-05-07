/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author Miguel Ángel Ramírez Ruiz
  \date   
*/

#include <iostream>
#include <string>  

// Para usar atoi
#include <stdlib.h>

#include "Provincia.hpp"

#include "Municipio.hpp"

#include "funcionesAuxiliares.hpp"


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
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

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


//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia)
{
	if (provincia.hayMunicipios() == true)
	{
		std::cout << "La Provincia tiene al menos 1 municipio" << std::endl;
	}
	else
	{
		std::cout << "La provincia no tiene municipios" << std::endl;
	}

	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia)
{	
	std::string fichero;
	std::cout << "Introduzca el nombre del fichero a cargar: " << std::endl;
	std::cin >> fichero;
	if (provincia.cargarFichero(fichero) == false)
	{
		std::cout << "ERROR: no se pudo cargar el fichero." << std::endl;
		getchar();
		return;
	}
	std::cout << "Fichero cargado con éxito." << std::endl;
	getchar();
	return;
}

void ed::grabarProvincia(ed::Provincia  &provincia)
{
	std::string fichero;
	std::cout << "Introduzca el nombre del fichero a grabar: " << std::endl;
	std::cin >> fichero;
	if (provincia.grabarFichero(fichero) == false)
	{
		std::cout << "ERROR: no se pudo grabar en el fichero." << std::endl;
		getchar();
		return;
	}
	std::cout << "Fichero grabado con éxito." << std::endl;
	getchar();
	return;
}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia)
{
	std::cout << "Nombre: " << provincia.getNombre() << std::endl;
	std::cout << "Código: " << provincia.getCodigo() << std::endl;
	std::cout << "Nº municipios: " << provincia.getNumeroMunicipios() << std::endl;
	std::cout << "Hombres: " << provincia.getTotalHombres() << std::endl;
	std::cout << "Mujeres: " << provincia.getTotalMujeres() << std::endl;
	std::cout << "Habitantes: " << provincia.getTotalHabitantes() << std::endl;
	return;
}


//
void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia)
{
	provincia.escribirMunicipios();
	return;
}


////////////////////////////////////////////////////////////////////////
void ed::modificarDatosDeProvincia(ed::Provincia &provincia)
{

// QUITAR LOS COMENTARIOS CUANDO SE HAYA CODIFICADO LA CLASE Provincia


	int opcion, codigo;
	std::string nombre; 

	do{
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << BIGREEN;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;
			
		switch(opcion)
		{
			case 0: 
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << BIGREEN;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << BIGREEN;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;
			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET 
							  << opcion << std::endl;
		}
	}while (opcion != 0);

	return;
}


void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia)
{
	std::cout << "Borrando todos los municipios..." << std::endl;
	provincia.borrarTodosLosMunicipios();
	std::cout << "Municipios borrados con éxito!" << std::endl;
	getchar();
	return;
}


void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia)
{
	std::string nombre;
	std::cout << "Nombre del municipio a consultar: " << std::endl;
	std::cin >> nombre;

	std::cout << "Buscando municipio..." << std::endl;

	if (provincia.existeMunicipio(nombre) == false)
	{
		std::cout << "Error: la provincia no existe." << std::endl;
		getchar();
		return;
	}
	std::cout << "Código Nombre;Hombres;Mujeres;" << std::endl;
	std::cout << provincia.getMunicipio(nombre) << std::endl;
	getchar();
	
	return;
}

void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia)
{
	ed::Municipio nuevo;
	nuevo.leerMunicipio();

	std::cout << "Insertando municipio..." << std::endl;
	provincia.insertarMunicipio(nuevo);
	std::cout << "Municipio insertado con éxito!" << std::endl;
	getchar();
	return;
}

  


void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia)
{
	std::string nombre;
	std::cout << "Nombre del municipio a borrar:" << std::endl;
	std::cin >> nombre;
	std::cout << "Borrando municipio..." << std::endl;
	provincia.borrarMunicipio(nombre);
	std::cout << "Municipio borrado con éxito!" <<std::endl;
	getchar();
	return;
}




