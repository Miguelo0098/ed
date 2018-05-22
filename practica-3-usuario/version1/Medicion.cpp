/*! 
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
   \author Miguel Ángel Ramírez Ruiz
   \date   05/05/2018
*/


// Ficheros de cabecera
#include <iostream>

// atoi, atof
#include <stdlib.h>

#include "Medicion.hpp"


void ed::Medicion::leerMedicion(){
	std::cout << "Introduce la fecha de la medición:" << std::endl;
	_fecha.leerFecha();
	double precipitacion;

	std::cout << "Introduce la precipitación: ";
	std::cin >> precipitacion;

	setPrecipitacion(precipitacion);
}

void ed::Medicion::escribirMedicion()const{
	std::cout << getFecha() << " " << getPrecipitacion() << std::endl;
}


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Medicion const &medicion)
{
	stream << medicion.getFecha();
	stream << " ";
  	stream << medicion.getPrecipitacion();

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Medicion &medicion)
{
	ed::Fecha fecha;
	stream >> fecha;

	double precipitacion;
	stream >> precipitacion;

	medicion.setFecha(fecha);
	medicion.setPrecipitacion(precipitacion);
	
	return stream;
} 

} // Fin del espacio de nombres ed
