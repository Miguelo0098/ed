/*!
	\file MonticuloMediciones.hpp
	\brief Se define el TAD MonticuloMediciones.
	\author Miguel Ángel Ramírez Ruiz
  \date   05/05/2018
*/

#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP

#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMedicionesInterfaz.hpp"


//! Se incluye la clase MonticuloMediciones dentro del espacio de nombres de la asigantura: ed
/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/

namespace ed
{

//!  Definición de la clase MonticuloMediciones 
/*!
  \class MonticuloMediciones
  \brief Definición de la clase MonticuloMediciones
*/

class MonticuloMediciones : public MonticuloMedicionesInterfaz
{
	private:

		//! \name Atributos privados de la clase MonticuloMediciones

		std::vector<ed::Medicion> _mediciones;	//!< vector stl con las mediciones


		//! \name Métodos privados de la clase MonticuloMediciones

		/*! 
			\brief     Funcion que devuelve el elemento iesimo del vector   
			\note      Función inline
			\param	   i: unsigned int con la posicion del elemento
			\pre       i >= 0; i < tamaño del vector
			\post      Ninguna
			\return    objeto de la clase medicion de esa posicion
		*/
		inline ed::Medicion & getElement(unsigned int i){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert((i) >= 0);
				assert((i) < _mediciones.size());
			#endif //NDEBUG
			return _mediciones[i];
		}

		/*! 
			\brief     Funcion que modifica la posicion iesimo del vector   
			\note      Función inline
			\param 	   i: unsigned int con la posicion a modificar
			\param	   medicion: referencia del objeto medicion que sera asignado a la posicion i
			\pre       i >= 0; i < tamaño del vector
			\post      getElement(i) == medicion
		*/
		inline void setElement(unsigned int i, ed::Medicion const & medicion){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert((i) >= 0);
				assert((i) < _mediciones.size());
			#endif //NDEBUG

			_mediciones[i] = medicion;

			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(getElement(i) == medicion);
			#endif //NDEBUG
		}

		/*! 
			\brief     Funcion que devuelve la posicion del hijo izquierdo 
			\note      Función inline
			\param	   i: unsigned int con la posicion del elemento
			\pre       i >= 0
			\post      valor devuelto = 2*i+1
			\return    2*i + 1 (unsigned int)
		*/
		inline unsigned int getLeftChild(unsigned int i){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert((i) >= 0);
			#endif //NDEBUG

			unsigned int valordevuelto = 2*i + 1;
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(valordevuelto == 2*i + 1);
			#endif //NDEBUG

			return valordevuelto;
		}
		/*! 
			\brief     Funcion que devuelve la posicion del hijo derecho 
			\note      Función inline
			\param	   i: unsigned int con la posicion del elemento
			\pre       i >= 0
			\post      valor devuelto = 2*i+2
			\return    2*i + 2 (unsigned int)
		*/
		inline unsigned int getRightChild(unsigned int i){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert((i) >= 0);
			#endif //NDEBUG

			unsigned int valordevuelto = 2*i + 2;
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(valordevuelto == 2*i + 2);
			#endif //NDEBUG

			return valordevuelto;
		}

		/*! 
			\brief     Funcion que devuelve la posicion del padre
			\note      Función inline
			\param	   i: unsigned int con la posicion del elemento
			\pre       i >= 1
			\post      valor devuelto = (i-1)/2
			\return    (i-1)/2 (unsigned int)
		*/
		inline unsigned int getParent(unsigned int i){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert((i) >= 1);
			#endif //NDEBUG

			unsigned int valordevuelto = (i-1)/2;
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(valordevuelto == (i-1)/2);
			#endif //NDEBUG

			return valordevuelto;
		}

		/*! 
			\brief     Funcion que flota el elemento en la posicion i
			\note      Función inline
			\param	   i: unsigned int con la posicion del elemento
			\pre       i > 0; i < tamaño_vector
			\post      Si no es la cima, el elemento actual es menor o igual que su padre; Si tiene hijo izquierdo, el elemento actual es mayor o igual que él y, además, si tiene hijo derecho, es mayor o igual que él.
		*/
		inline void shiftUp(unsigned int i){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(i > 0);
				assert(i < _mediciones.size());
			#endif //NDEBUG

			if ((i > 0) && (getElement(getParent(i)).getPrecipitacion() <= getElement(i).getPrecipitacion()))
			{
				std::swap(getElement(getParent(i)), getElement(i));
				if(getParent(i) != 0){
					shiftUp(getParent(i));
				}
			}

			#ifndef NDEBUG
				// Se comprueba la postcondicion
				if(i == 0){
					assert(getElement(i).getPrecipitacion() <= getElement(getParent(i)).getPrecipitacion());
				}
				if (getLeftChild(i) < _mediciones.size())
				{
					if (getRightChild(i) < _mediciones.size())
					{
						assert(getElement(getRightChild(i)).getPrecipitacion() <= getElement(i).getPrecipitacion());
					}
					assert(getElement(getLeftChild(i)).getPrecipitacion() <= getElement(i).getPrecipitacion());
				}
			#endif //NDEBUG
		}

		/*! 
			\brief     Funcion que hunde el elemento en la posicion i
			\note      Función inline
			\param	   i: unsigned int con la posicion del elemento
			\pre       i >= 0; i < tamaño_vector
			\post      Si no es la cima, el elemento actual es menor o igual que su padre; Si tiene hijo izquierdo, el elemento actual es mayor o igual que él y, además, si tiene hijo derecho, es mayor o igual que él.
		*/
		inline void shiftDown(unsigned int i){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(i >= 0);
				assert(i < _mediciones.size());
			#endif //NDEBUG

			unsigned int largest = i;
			unsigned int lC = getLeftChild(i);
			unsigned int rC = getRightChild(i);
			if (lC < _mediciones.size() && getElement(lC).getPrecipitacion() > getElement(i).getPrecipitacion())
			{
				largest = lC;
			}
			if (rC < _mediciones.size() && getElement(rC).getPrecipitacion() > getElement(lC).getPrecipitacion())
			{
				largest = rC;
			}
			if (largest < i || largest > i)
			{
				std::swap(getElement(i), getElement(largest));
				shiftDown(largest);
			}

			#ifndef NDEBUG
				// Se comprueba la postcondicion
				if(i != 0){
					assert(getElement(i).getPrecipitacion() <= getElement(getParent(i)).getPrecipitacion());
				}
				if (getLeftChild(i) < _mediciones.size())
				{
					assert(getElement(getLeftChild(i)).getPrecipitacion() <= getElement(i).getPrecipitacion());
					if (getRightChild(i) < _mediciones.size())
					{
						assert(getElement(getRightChild(i)).getPrecipitacion() <= getElement(i).getPrecipitacion());
					}
				}
			#endif //NDEBUG
		}

		/*! 
			\brief     Funcion que comprueba si existe una medicion en el monticulo
			\note      Función inline
			\param	   medicion: referencia a objeto de la clase medicion
			\pre       Ninguna
			\post      Ninguna
			\return	   true, si existe la medicion en el monticulo; en caso contrario, false
		*/
		inline bool has(ed::Medicion & medicion){
			for (std::vector<ed::Medicion>::iterator i = _mediciones.begin(); i != _mediciones.end(); ++i)
			{
				if (*i == medicion)
				{
					return true;
				}
			}
			return false;
		}

	  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor

		/*! 
			\brief     Constructor que crea un monticulo de mediciones
			\note      Función inline
			\pre       Ninguna
			\post      isEmpty() == true
		*/

		inline MonticuloMediciones(){
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(isEmpty() == true);
			#endif //NDEBUG
		}

		//! \name Observadores

		/*!
    	    \brief  Comprueba si el montículo está vacio
			\pre    Ninguna
			\post   retval == (size() == 0)
    	    \return true, si el montículo está vacio; false, en caso contrario
    	*/
		inline bool isEmpty(){
			bool retval = _mediciones.empty();
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(retval == (size() == 0));
			#endif //NDEBUG

			return retval;
		}

		/*!
    	    \brief  Funcion que retorna el tamaño del montículo
			\pre    Ninguna
			\post   Ninguna
    	    \return tamaño del monticulo (tipo unsigned int)
    	*/
		inline unsigned int size(){
			return _mediciones.size();
		}

		/*!
    	    \brief  Funcion que retorna el primer elemento del monticulo
			\pre    isEmpty() == false
			\post   retval == getElement(0)
    	    \return primer elemento del monticulo (clase Medicion)
    	*/
		inline ed::Medicion & top(){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(isEmpty() == false);
			#endif //NDEBUG

			ed::Medicion &retval = getElement(0);

			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(retval == getElement(0));
			#endif //NDEBUG

			return retval;
		}

		////////////////////////////////////////////////////////////

		//! \name Operaciones de modificación

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

		/*!
    		\brief  Función que inserta una medicion nueva en el monticulo
			\pre    Ninguna
			\post   isEmpty() == false;  has(medicion) == true;
			\param 	medicion: medicion a insertar en el monticulo
    	*/
		inline void insert(ed::Medicion &medicion){

			if (has(medicion) == false)
			{
			 	_mediciones.push_back(medicion);
				if (size() != 1)
				{
					shiftUp(size() - 1);
				}

			}
			
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(isEmpty() == false);
				assert(has(medicion) == true);
			#endif //NDEBUG
		}

		/*!
    	    \brief  Función que elimina la primera medicion en el monticulo
    	    \pre    isEmpty() == false;
			\post   Ninguna
    	*/
		inline void remove(){
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(isEmpty() == false);
			#endif //NDEBUG

			std::swap(getElement(0), getElement(size() - 1));
			_mediciones.pop_back();

			if (isEmpty() == false)
			{
				shiftDown(0);
			}
			
		}


		/*!
    	    \brief  Función que elimina todas las mediciones en el monticulo
    	    \pre    Ninguna
			\post   isEmpty() == true;
    	*/
		inline void removeAll(){

			_mediciones.clear();

			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(isEmpty() == true);
			#endif //NDEBUG
		}


		/*!
    	    \brief  Función que modifica el primer elemento en el monticulo
    	    \param	medicion: referencia a objeto de la clase medicion
    	    \pre    isEmpty() == false
			\post   has(medicion) == true
    	*/
		inline void modify (ed::Medicion & medicion){
			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(isEmpty() == false);
			#endif //NDEBUG

				setElement(0, medicion);
				shiftDown(0);


			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(has(medicion) == true);
			#endif //NDEBUG
		} 

		//! \name Operadores
   
		/*!
    	    \brief  Operador de asignacion
    	    \param	m: referencia a objeto de la clase MonticuloMediciones
    	    \pre    Ninguna
			\post   Ninguna
			\return	Se retorna a si mismo con las variables del monticulo pasado por referencia
    	*/
 		inline MonticuloMediciones & operator=(MonticuloMediciones & m){
 			if (this != &m)
 			{
 				_mediciones = m._mediciones;
 			}
 			return (*this);
 		}

		////////////////////////////////////////////////////////////////////

		//! \name Función de escritura

		/*!
    	    \brief  Imprime los valores del monticulo en el orden en el que estan
    	    \pre    Ninguna
			\post   Ninguna
    	*/

		inline void print(){
			for (std::vector<ed::Medicion>::iterator i = _mediciones.begin(); i != _mediciones.end(); ++i)
			{
				std::cout<<(*i)<<std::endl;
			}
		}

	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
