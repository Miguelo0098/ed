/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author Miguel Ángel Ramírez Ruiz
  \date   05/05/2018
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_

#include "MonticuloMediciones.hpp"

// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN

namespace ed
{

	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/

 	int menu();

 	/*!
    	\brief  Comprueba si el montículo está vacía
    	\param  monticulo: monticulo de mediciones
    */
 	void comprobarMonticuloVacio(ed::MonticuloMediciones & monticulo);

	/*!
    	\brief  Carga los datos de un fichero en el monticulo
    	\param  nombreFichero: cadena con el nombre del fichero a cargar
    	\param  monticulo: monticulo de mediciones donde cargar los datos
    */
	void cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo); 

	/*!
    	\brief  Carga los datos de un fichero en el monticulo
    	\param  nombreFichero: cadena con el nombre del fichero a grabar
    	\param  monticulo: monticulo de mediciones del que se van a grabar los datos
    */
	void grabarMonticuloEnFichero (std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo); 

	/*!
    	\brief  Muestra las mediciones del montículo en orden secuencial
    	\param  monticulo: monticulo de mediciones
    */
	void consultarMediciones(ed::MonticuloMediciones & monticulo);

	/*!
    	\brief  Modifica la primera de las mediciones del montículo
    	\param  monticulo: monticulo de mediciones
    */
	void modificarMedicionMonticulo(ed::MonticuloMediciones & monticulo);

	/*!
    	\brief  Borra todas las mediciones del montículo
    	\param  monticulo: monticulo de mediciones
    */
	void borrarTodasMediciones(ed::MonticuloMediciones & monticulo);

	/*!
    	\brief  Inserta una medicion dentro del montículo
    	\param  monticulo: monticulo de mediciones
    */
	void insertarMedicionMonticulo(ed::MonticuloMediciones & monticulo);

	/*!
    	\brief  Borra la primera de las mediciones del montículo
    	\param  monticulo: monticulo de mediciones
    */
	void borrarMedicionMonticulo(ed::MonticuloMediciones & monticulo);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FuncionesAuxiliares_HPP_
#endif

