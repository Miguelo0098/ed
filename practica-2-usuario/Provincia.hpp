/*!	
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author  Miguel Ángel Ramírez Ruiz
	\date  
	\version 1.0

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"


// DEBES COMPLETAR O MODIFICAR EL CÓDIGO DE LA CLASE Provincia

// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN

// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones


/*!	
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!	

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string      _nombre;     //!<  \brief Nombre de la Provincia
		int              _codigo;	  //!<  \brief Código de la Provincia

	  ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public: 

	//!	\name Constructor

    /*! 
      \brief Construye una provincia
      \note  Función inline
      \post  hayMunicipios() == false
    */

  	inline Provincia(std::string name = "", int code = 0){
  		setNombre(name);
  		setCodigo(code);

  		#ifndef NDEBUG
  			assert((getNombre() == name) and (getCodigo() == code) and (hayMunicipios() == false));
  		#endif
  	}

	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores
  	inline std::string getNombre()const{
  		return _nombre;
  	}

  	inline int getCodigo()const{
  		return _codigo;
  	}

    /*!
        \brief  Comprueba si la provincia tiene municipios
        \note   Función inline
        \note   Función de tipo "const": no puede modificar al objeto actual
        \return true, si hay al menos un municipio; false, si no hay municipios
    */

  	inline bool hayMunicipios()const{
  		if (_listaMunicipios.isEmpty() == true)
  		{
  			return false;
  		}
  		return true;
  	}

    /*!
        \brief  Devuelve el número municipios de la provincia
        \note   Función inline
        \note   Función de tipo "const": no puede modificar al objeto actual
        \return Número entero que representa el número de municipios
    */

  	inline int getNumeroMunicipios()const{
  		return _listaMunicipios.nItems();
  	}

    /*!
      \brief  Comprueba si existe un municipio con el nombre pasado por parámetro
      \param  name: cadena con el nombre del municipio a buscar
      \return true, si el municipio existe; false, en caso contrario
    */

  	bool existeMunicipio(std::string name);

    /*!
    \brief  Devuelve el Municipio con el nombre pasado por parámetro
    \param  name: cadena con el nombre del municipio a devolver
    \pre    existeMunicipio(name) == true
    \return Una referencia constante al municipio con el nombre del parámetro
    */

  	ed::Municipio const & getMunicipio(std::string name);

    /*!
        \brief  Devuelve el número total de hombres en la provincia
        \return Número entero que representa el número total de hombres
    */

  	int getTotalHombres();

    /*!
        \brief  Devuelve el número total de Mujeres en la provincia
        \return Número entero que representa el número total de Mujeres
    */

  	int getTotalMujeres();

    /*!
        \brief  Devuelve el número total de habitantes en la provincia
        \note   Función inline
        \return Número entero que representa el número total de habitantes
    */

  	inline int getTotalHabitantes(){
      int retval = getTotalHombres() + getTotalMujeres();
      #ifndef NDEBUG
        // Se comprueba la postcondición
        assert(retval == (getTotalHombres() + getTotalMujeres()));
      #endif //NDEBUG
      return retval;
  	}

	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

    /*!
        \brief  Modifica el nombre de la provincia
        \note   Función inline
        \param  name: cadena con el nombre nuevo de la provincia
    */

  	inline void setNombre(std::string name){
  		_nombre = name;
      #ifndef NDEBUG
        // Se comprueba la postcondición
        assert(getNombre() == name);
      #endif //NDEBUG
  	}

    /*!
        \brief  Modifica el código de la provincia
        \note   Función inline
        \param  name: entero con el código nuevo de la provincia
    */

  	inline void setCodigo(int code){
  		_codigo = code;
      #ifndef NDEBUG
        // Se comprueba la postcondición
        assert(getCodigo() == code);
      #endif //NDEBUG
  	}

    /*!
    \brief Inserta un Municipio de forma ordenada por apellidos y nombre
    \note  Función inline
    \param municipio: objeto de la clase Municipio que va a ser insertado
    */

  	inline void insertarMunicipio(ed::Municipio municipio){
      #ifndef NDEBUG
        // Se comprueba la precondición
        assert(this->existeMunicipio(municipio.getNombre()) == false);
      #endif //NDEBUG

      int oldnmunicipios = this->getNumeroMunicipios();
      _listaMunicipios.insert(municipio);
      
      #ifndef NDEBUG
        // Se comprueba la postcondición
        assert(this->existeMunicipio(municipio.getNombre()) == true);
        assert(oldnmunicipios + 1 == this->getNumeroMunicipios());
      #endif //NDEBUG
    }

    /*!
    \brief Borra un Municipio con el nombre pasado por parámetro
    \param name: nombre del municipio a borrar
    */

  	void borrarMunicipio(std::string name);

    /*!
    \brief  Borra todos los municipios
    \note   Función inline
    \return void
    */

  	inline void borrarTodosLosMunicipios(){
      _listaMunicipios.removeAll();

      #ifndef NDEBUG
        // Se comprueba la postcondición
        assert(this->hayMunicipios() == false);
      #endif //NDEBUG
    }

	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia

    /*!
    \brief  Escribe todos los municipios de la provincia
    \return void
    */

  	void escribirMunicipios();

	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros

     /*!
    \brief  Carga los datos de un fichero en la provincia
    \param  fichero: cadena con el nombre del fichero a cargar
    \return true, si se cargan los datos con éxito; false, en el caso contrario
    */

  	bool cargarFichero(std::string fichero);

     /*!
    \brief  Graba los datos de la provincia en un fichero 
    \param  fichero: cadena con el nombre del fichero donde grabar
    \return true, si se graban los datos con éxito; false, en el caso contrario
    */

  	bool grabarFichero(std::string fichero);

}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
