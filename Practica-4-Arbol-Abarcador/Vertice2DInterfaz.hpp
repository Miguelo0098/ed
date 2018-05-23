/*! 
   \file Vertice2DInterfaz.hpp
   \brief Fichero de la clase Vertice2DInterfaz: clase de interfaz del vértice del plano euclídeo 
*/

#ifndef _VERTICE2DINTERFAZ_HPP_
#define _VERTICE2DINTERFAZ_HPP_


//! Espacio de nombres de la asignatura de Estructura de Datos
namespace ed {

// Se incluye la clase Vertice2DInterfaz dentro del espacio de nombre de la asigantura: ed
//!  Definición de la clase Vertice2DInterfaz
class Vertice2DInterfaz 
{
   //! \name Funciones o métodos públicos de la clase Vertice2DInterfaz
   public:

	//! \name Observadores: funciones de consulta de Vertice2DInterfaz

	/*! 
		\brief   Función que devuelve la abscisa o coordenada "x" de un Vertice2DInterfaz
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
		\return  Componente "x" del Vertice2DInterfaz (tipo double)
		\pre     Ninguna
		\post    Ninguna
		\sa      getY()
	*/
	virtual double getX()const = 0;


	/*! 
		\brief   Función que devuelve la ordenada o coordenada "y" de un Vertice2DInterfaz
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
		\return  Componente "y" del Vertice2DInterfaz (tipo double)
		\pre     Ninguna
		\post    Ninguna
		\sa      getX()
	*/
	virtual double getY()const = 0;


	//! \name Modificadores: funciones de modificación de Vertice2DInterfaz

	/*! 
		\fn    virtual void setX(double v) = 0;
		\brief Función que asigna un valor "v" a la coordenada "x" de un Vertice2DInterfaz
		\note  Función virtual pura que deberá ser redefinida por la clase heredera
		\param v: nuevo valor de la abscisa del Vertice2DInterfaz
		\pre   Ninguna
		\post  getX() == v
		\sa    setY()
	*/
	virtual void setX(double v) = 0;


	/*! 
		\fn    virtual void setY(double v) = 0;
		\brief Función que asigna un valor "v" a la coordenada "y" de un Vertice2D
		\note  Función virtual pura que deberá ser redefinida por la clase heredera
		\param v Nuevo valor de la ordenada del Vertice2D
		\pre   Ninguna
		\post  getY() == v
		\sa    setX()
	*/
	virtual void setY(double v) = 0;

}; // Fin de la definición de la clase Vertice2DInterfaz


}//  _VERTICE2DINTERFAZ_HPP_
#endif 
