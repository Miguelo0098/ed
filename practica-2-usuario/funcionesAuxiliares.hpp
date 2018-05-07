/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author Miguel Ángel Ramírez Ruiz
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Provincia.hpp"


// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN DE CADA FUNCIÓN

namespace ed
{

	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/

 	int menu();

	///////////////////////////////////////////////////////////////////

 	/*! 
		\brief  Comprueba si la provincia pasada por referencia está vacía
		\param  provincia: objeto de la clase provincia
	*/
	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*! 
		\brief  Carga los datos de un fichero en la provincia pasada por referencia
		\param  provincia: objeto de la clase provincia
	*/
	void cargarProvincia(ed::Provincia & provincia);

	/*! 
		\brief  Graba los datos de la provincia pasada por referencia en un fichero
		\param  provincia: objeto de la clase provincia
	*/
	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*! 
		\brief  Muestra los datos de la provincia pasada por referencia
		\param  provincia: objeto de la clase provincia
	*/
	void consultarDatosDeProvincia(ed::Provincia & provincia);

	/*! 
		\brief  Muestra los municipios de la provincia pasada por referencia
		\param  provincia: objeto de la clase provincia
	*/
	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*! 
		\brief  Permite modificar los datos de la provincia pasada por referencia
		\param  provincia: objeto de la clase provincia
	*/
	void modificarDatosDeProvincia(ed::Provincia & provincia);

	/*! 
		\brief  Borra todos los municipios de la provincia pasada por referencia
		\param  provincia: objeto de la clase provincia
	*/
	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////

	/*! 
		\brief  Permite consultar los datos de un municipio de la provincia pasada por referencia
		\param  provincia: objeto de la clase provincia
	*/
	void consultarMunicipioDeProvincia(ed::Provincia & provincia);

	/*! 
		\brief  Permite insertar un municipio en la provincia pasada por referencia
		\param  provincia: objeto de la clase provincia
	*/
	void insertarMunicipioEnProvincia(ed::Provincia & provincia);

	/*! 
		\brief  Permite borrar un municipio de la provincia pasada por referencia
		\param  provincia: objeto de la clase provincia
	*/
	void borrarMunicipioDeProvincia(ed::Provincia & provincia);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

