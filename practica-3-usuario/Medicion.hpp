/*! 
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica 
   \author Miguel Ángel Ramírez Ruiz
  \date   05/05/2018
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>
#include <cmath>

// Definición de la clase Fecha
#include "Fecha.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion 
class Medicion
{
  //! \name Atributos privados de la clase Medicion
   private: 

   	ed::Fecha _fecha; //!< fecha de la medición
   	double _precipitacion; //!< nivel de precipitacion

   //! \name Funciones o métodos públicos de la clase Medicion
   public:

	//! \name Constructor de la clase Medicion


   	/*! 
		\brief     Constructor que crea una Medicion
		\attention Función sobrecargada        
		\note      Función inline
	 	\warning   Los parámetros tienen valores por defecto
		\param     fecha: fecha de la medicion; valor por defecto: 1-1-1
		\param     precipitacion: double con el nivel de precipitacion; valor por defecto: 0.0
		\pre       Ninguna
		\post      La fecha y la precipitación deben ser igual a las recibidas
	*/
		inline Medicion(ed::Fecha const & fecha = ed::Fecha (1,1,1), double precipitacion = 0.0){
			setFecha(fecha);
			setPrecipitacion(precipitacion);
			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert(getFecha() == fecha);
				assert(abs(getPrecipitacion() - precipitacion) <= COTA_ERROR);
			#endif //NDEBUG	
		}

	/*! 
		\brief     Constructor de "copia" que crea una Medicion
		\attention Función sobrecargada        
		\note      Función inline
		\param     medicion: objeto de la clase Medicion de la que se toman sus valores
		\pre       Ninguna
		\post      La fecha y la precipitación deben ser igual a las recibidas de la medicion correspondiente
	*/
		inline Medicion(ed::Medicion const & medicion){
			setFecha(medicion.getFecha());
			setPrecipitacion(medicion.getPrecipitacion());
			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert(getFecha() == medicion.getFecha());
				assert(abs(getPrecipitacion() - medicion.getPrecipitacion()) <= COTA_ERROR);
			#endif //NDEBUG
		}

	//! \name Observadores: funciones de consulta de la clase Medicion

	/*! 
		\brief     Funcion que devuelve la fecha de una medicion     
		\note      Función inline
		\pre       Ninguna
		\post      Ninguna
		\return    Valor del atributo que representa la fecha (clase fecha)
	*/
		inline ed::Fecha const & getFecha()const{
			return _fecha;
		}

	/*! 
		\brief     Funcion que devuelve la precipitacion de una medicion     
		\note      Función inline
		\pre       Ninguna
		\post      Ninguna
		\return    Valor del atributo que representa la precipitacion (tipo double)
	*/
		inline double const getPrecipitacion()const{
			return _precipitacion;
		}

	//! \name Funciones de modificación de la clase Medicion

	/*! 
		\brief     Funcion que modifica la fecha de una medicion     
		\note      Función inline
		\param	   fecha: objeto de la clase fecha a asignar
		\pre       Ninguna
		\post      La fecha debe ser igual a la asignada
	*/
		inline void setFecha(ed::Fecha const & fecha){
			_fecha = fecha;
			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert(getFecha() == fecha);
			#endif //NDEBUG
		}

	/*! 
		\brief     Funcion que modifica la precipitacion de una medicion     
		\note      Función inline
		\param	   precipitacion: double float
		\pre       La precipitacion debe ser positiva
		\post      La precipitacion debe ser igual a la asignada con una cota de error determinada
	*/
		inline void setPrecipitacion(double precipitacion){
			#ifndef NDEBUG
				// Se comprueba la precondición
				assert(getPrecipitacion() >= 0.0);
			#endif //NDEBUG

			_precipitacion = precipitacion;

			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert(abs(getPrecipitacion() - precipitacion) <= COTA_ERROR);
			#endif //NDEBUG
		}

	//! \name Operadores
    
    /*! 
		\brief     Operador booleano de igualdad de una medicion   
		\note      Función inline
		\param	   medicion: objeto de la clase Medicion a comparar
		\pre       Ninguna
		\post      valor devuelto = expresion de igualdad entre fechas
		\return    true, si las fechas son iguales; false, en caso contrario
	*/
		inline bool operator ==(Medicion const & medicion)const{
			bool retval = (getFecha() == medicion.getFecha());
			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert(retval == (getFecha() == medicion.getFecha()));
			#endif //NDEBUG	
			return retval;
		}

	/*! 
		\brief     Operador de asignacion de una medicion   
		\note      Función inline
		\param	   medicion: bjeto de la clase Medicion a asignar
		\pre       Ninguna
		\post      las variables de ambos objetos deben coincidir
		\return    esta funcion se retorna a sí misma modificada
	*/
		inline Medicion & operator =(Medicion const & medicion){
			if (this != &medicion)
			{
				setFecha(medicion.getFecha());
				setPrecipitacion(medicion.getPrecipitacion());
			}
			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert(getFecha() == medicion.getFecha());
				assert(abs(getPrecipitacion() - medicion.getPrecipitacion()) <= COTA_ERROR);
			#endif //NDEBUG

			return(*this);
		}

	//! \name Funciones de lectura y escritura de la clase Medicion

	/*! 
		\brief     Lee una medicion por teclado   
		\pre       Ninguna
		\post      Ninguna
	*/
		void leerMedicion();

	/*! 
		\brief     Muestra una medicion por pantalla  
		\pre       Ninguna
		\post      Ninguna
	*/
		void escribirMedicion()const;


}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

	/*!
  		\brief     Sobrecarga del operador de entrada o lectura ">>"
		\param     stream Flujo de entrada
		\param     medicion pasada como referencia 
		\pre       Ninguna
		\post      Ninguna
		\sa        operator<<()
    */
		istream &operator>>(istream &stream, ed::Medicion & medicion);

	/*!
  		\brief     Sobrecarga del operador de salida o escritura "<<"
		\param     stream Flujo de salida
		\param     medicion pasada como referencia constante
		\pre       Ninguna
		\post      Ninguna
		\sa        operator>>()
    */
		ostream &operator<<(ostream &stream, ed::Medicion const & medicion);


} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif 
