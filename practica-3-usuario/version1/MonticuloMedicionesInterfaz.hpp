/*!
	\file MonticuloMedicionesInterfaz.hpp
	\brief Se define la interfaz del TAD MonticuloMediciones.
	\author Miguel Ángel Ramírez Ruiz
  \date   05/05/2018
*/

#ifndef _MONTICULO_MEDICIONES_INTERFAZ_HPP
#define _MONTICULO_MEDICIONES_INTERFAZ_HPP

#include "Medicion.hpp"

//! Se incluye la clase MonticuloMedicionesInterfaz dentro del espacio de nombres de la asigantura: ed
/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed
{

//!  Definición de la clase MonticuloMedicionesInterfaz 
/*!
  \class MonticuloMedicionesInterfaz
  \brief Definición de la clase abstracta MonticuloMedicionesInterfaz
*/
	class MonticuloMedicionesInterfaz
	{
		//! \name Funciones o métodos públicos de la clase MonticuloMedicionesInterfaz
		public:

			// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

			//! \name Observadores públicos 

   			/*!
    		    \brief  Comprueba si el montículo está vacio
				\note   Función virtual pura, que deberá ser redefinida en la clase heredera
    		    \return true, si el montículo está vacio; false, en caso contrario
    		*/
			virtual bool isEmpty() = 0;

			/*!
    		    \brief  Función que retorna el primer elemento del monticulo
				\note   Función virtual pura, que deberá ser redefinida en la clase heredera
    		    \return primera medicion del monticulo (clase medicion)
    		*/
			virtual ed::Medicion & top() = 0;

			//!  \name Modificadores públicos
			
			/*!
    		    \brief  Función que inserta una medicion nueva en el monticulo
				\note   Función virtual pura, que deberá ser redefinida en la clase heredera
				\param 	medicion: medicion a insertar en el monticulo
    		*/
			virtual void insert(ed::Medicion & medicion) = 0;

			/*!
    		    \brief  Función que elimina la primera medicion en el monticulo
				\note   Función virtual pura, que deberá ser redefinida en la clase heredera
    		*/
			virtual void remove() = 0;



	}; // Clase MonticuloMedicionesInterfaz

} // Espacio de nombres ed

#endif //  _MONTICULO_MEDICIONES_INTERFAZ_HPP
