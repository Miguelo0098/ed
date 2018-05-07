
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Vector3D.hpp"


namespace ed
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*! 
		\brief  Lee los vectores que se le pasan como parámetros
		\param  u: Vector3D a leer
		\param  v: Vector3D a leer
		\param  w: Vector3D a leer
	*/
	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);

	/*! 
		\brief  Escribe los vectores que se le pasan como parámetros
		\param  u: Vector3D a escribir
		\param  v: Vector3D a escribir
		\param  w: Vector3D a escribir
	*/
	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);


	/*! 
		\brief  Prueba los observadores con los vectores que se le pasan como parámetros
		\param  u: Vector3D a evaluar
		\param  v: Vector3D a evaluar
		\param  w: Vector3D a evaluar
	*/
	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);

	/*! 
		\brief  Prueba los modificadores con los vectores que se le pasan como parámetros
		\param  u: Vector3D de pruebas
		\param  v: Vector3D de pruebas
		\param  w: Vector3D de pruebas
	*/
	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);

	/*! 
		\brief  Muestra el Producto escalar de los vectores que se le pasan como parámetros
		\param  u: Vector3D de pruebas
		\param  v: Vector3D de pruebas
		\param  w: Vector3D de pruebas
	*/
	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v); 

	/*! 
		\brief  Muestra el Producto Vectorial con los vectores que se le pasan como parámetros
		\param  u: Vector3D de pruebas
		\param  v: Vector3D de pruebas
		\param  w: Vector3D de pruebas
	*/
	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);

	/*! 
		\brief  Muestra el producto mixto de los vectores que se le pasan como parámetros
		\param  u: Vector3D de pruebas
		\param  v: Vector3D de pruebas
		\param  w: Vector3D de pruebas
	*/
	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*! 
		\brief  Muestra los operadores con los vectores que se le pasan como parámetros
		\param  u: Vector3D de pruebas
		\param  v: Vector3D de pruebas
		\param  w: Vector3D de pruebas
	*/
	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);



} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

