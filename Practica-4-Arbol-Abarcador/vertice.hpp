/*!
  \file   vertice.hpp
  \brief  Fichero de cabecera de la clase Vertice
  \author Miguel Ángel Ramírez Ruiz
  \date   14/05/2018
*/

#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <iostream>
#include <cassert>
#include <cmath>

#define COTA_ERROR 1.0e-6 //!< Cota de error para la comparación de números reales

using std::istream;
using std::ostream;

namespace ed{

	//!  Definición de la clase Vertice
	class Vertice{

	//! \name Atributos privados de la clase Vertice
	private:
		double _x;	//!< coordenada x
		double _y;	//!< coordenada y
		int _label;	//!< etiqueta


	//! \name Métodos públicos de la clase Vertice
	public:

		//! \name Constructores de la clase Vertice
		/*! 
			\brief     Constructor que crea una Vertice
			\attention Función sobrecargada        
			\note      Función inline
		 	\warning   Los parámetros tienen valores por defecto
			\param     x: coordenada x; valor por defecto: 0.0
			\param     y: coordenada y; valor por defecto: 0.0
			\param     label: etiqueta; valor por defecto: -1
			\pre       Ninguna
			\post      aseguramos los valores insertados
		*/
		inline Vertice(double x=0.0, double y=0.0, int label=-1){
			setX(x);
			setY(y);
			setLabel(label);
			#ifndef NDEBUG
          		assert(std::abs(getX() - x) <= COTA_ERROR);
          		assert(std::abs(getY() - y) <= COTA_ERROR);
          		assert(getLabel() == label);
        	#endif //NDEBUG
		}


		/*! 
			\brief     Constructor de "copia" que crea un Vertice a partir de otro
			\attention Función sobrecargada        
			\note      Función inline
			\param     v: objeto de la clase Vertice utilizado para proporcionar los valores iniciales del nuevo vértice
			\pre       Ninguna
			\post      Los atributos de ambos objetos deben ser los mismos
		*/
		inline Vertice(Vertice const &v){
			setX(v.getX());
			setY(v.getY());
			setLabel(v.getLabel());
			#ifndef NDEBUG
          		assert(std::abs(getX() - v.getX()) <= COTA_ERROR);
          		assert(std::abs(getY() - v.getY()) <= COTA_ERROR);
          		assert(getLabel() == v.getLabel());
        	#endif //NDEBUG
		}


		/*! 
			\brief     Función que devuelve la coordenada x del vértice
			\note      Función inline 
			\return    coordenada x
			\pre       Ninguna
			\post      Ninguna
		*/
		inline double getX()const{
			return _x;
		}

		/*! 
			\brief     Función que devuelve la coordenada y del vértice
			\note      Función inline 
			\return    coordenada y
			\pre       Ninguna
			\post      Ninguna
		*/
		inline double getY()const{
			return _y;
		}


		/*! 
			\brief     Función que devuelve la etiqueta del vértice
			\note      Función inline 
			\return    etiqueta
			\pre       Ninguna
			\post      Ninguna
		*/
		inline int getLabel()const{
			return _label;
		}

		/*! 
			\brief     	Función que modifica la coordenada x del vértice
			\note      	Función inline 
			\param		x: nueva coordenada x
			\pre       	Ninguna
			\post      	la nueva coordenada x debe ser la pasada por parámetro
		*/
		inline void setX(double x){
			_x = x;

			#ifndef NDEBUG
          		assert(std::abs(getX() - x) < COTA_ERROR);
        	#endif //NDEBUG
		}


		/*! 
			\brief     	Función que modifica la coordenada y del vértice
			\note      	Función inline 
			\param		y: nueva coordenada y
			\pre       	Ninguna
			\post      	la nueva coordenada y debe ser la pasada por parámetro
		*/
		inline void setY(double y){
			_y = y;

			#ifndef NDEBUG
          		assert(std::abs(getY() - y) < COTA_ERROR);
        	#endif //NDEBUG
		}


		/*! 
			\brief     	Función que modifica la etiqueta del vértice
			\note      	Función inline 
			\param		label: nueva etiqueta
			\pre       	Ninguna
			\post      	la nueva etiqueta debe ser la pasada por parámetro
		*/
		inline void setLabel(int label){
			_label = label;

			#ifndef NDEBUG
          		assert(getLabel() == label);
        	#endif //NDEBUG
		}
		
		/*! 
			\brief     Operador de asignación: operador que "copia" un Vertice en otro Vertice
			\attention Se sobrecarga el operador de asignación "="
			\note      Función inline
			\param     v: objeto de la clase Vertice pasado como referencia constante
			\pre       El objeto es distinto del objeto actual
			\post      Los atributos del objeto deben tener los valores de los atributos del objeto pasado como argumento
		*/
		inline Vertice & operator=(ed::Vertice const &v)
		{
			// Se comprueba que no sean el mismo objeto
			if (this != &v) 
			{
				setX(v.getX());
				setY(v.getY());
				setLabel(v.getLabel());

				#ifndef NDEBUG
					// Se comprueba la postcondición
					assert( std::abs (this->getX() - v.getX()) < COTA_ERROR ); 
					assert( std::abs (this->getY() - v.getY()) < COTA_ERROR );   
					assert(this->getLabel() == v.getLabel());
				#endif //NDEBUG
			}	

			return *this;
		}
		
		/*! 
			\brief     Operador de igualdad: compara si dos Vertices son iguales
			\attention Se sobrecarga el operador de asignación "=="
			\note      Función inline
			\param     v: Vertice pasado como referencia constante
			\pre       Ninguna
			\post      Ninguna
		*/
		inline bool operator ==(ed::Vertice const &v) const
		{
  			// Se utiliza COTA_ERROR para controlar la precisión de los números reales
    		return 	(
    	              	(std::abs (v.getX() - this->getX()) < COTA_ERROR)   
    	          		and (std::abs (v.getY() - this->getY()) < COTA_ERROR)
    	        	);
		}

		//! \name Funciones de lectura y escritura de la clase Vertice

		/*! 
			\brief Lee desde el teclado los nuevos valores de los atributos de un Vértice
			\pre   Ninguna
			\post  Ninguna
		*/
		void leerVertice();

		/*! 
			\brief Escribe por pantalla los valores de los atributos de un Vértice
			\pre   Ninguna
			\post  Ninguna
		*/
		void escribirVertice();


	}; //Fin de la clase vértice

	//! \name Funciones externas de la clase Vertice

	/*! 
			\brief     	Función que retorna la distancia euclidea entre dos vertices
			\param		v1: primer vertice
			\param		v2: segundo vertice
			\pre       	Ninguna
			\post      	Ninguna
			\return		Distancia entre v1 y v2
		*/
	double getDistanciaEuclidea(Vertice const & v1, Vertice const & v2);

	/*!
  		\brief     Sobrecarga del operador de entrada o lectura "<<"
		\param     stream Flujo de entrada
		\param     v: vertice pasado como referencia constante
		\pre       Ninguna
		\post      Ninguna
		\sa        operator>>()
    */
	istream &operator>>(istream &stream, ed::Vertice &v);

	/*!
  		\brief     Sobrecarga del operador de salida o escritura "<<"
		\param     stream Flujo de salida
		\param     v: vertice pasado como referencia constante
		\pre       Ninguna
		\post      Ninguna
		\sa        operator>>()
    */
	ostream &operator<<(ostream &stream, ed::Vertice const &v);



}	// \brief Fin de namespace ed.

#endif