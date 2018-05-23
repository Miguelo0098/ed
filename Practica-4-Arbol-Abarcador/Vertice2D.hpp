/*! 
   \file Vertice2D.hpp
   \brief Fichero de la clase Vertice2D: vértice del plano euclídeo 
*/

#ifndef _VERTICE2D_HPP_
#define _VERTICE2D_HPP_

// Entrada y salida 
#include <iostream>

// Para usar abs
#include <cmath>


// Para controlar las pre y post condiciones mediante asertos
#include <cassert>


// Se include la declaración de la clase  Vertice2DInterfaz
#include "Vertice2DInterfaz.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales



// Se incluye la clase Vertice2D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vertice2D
class Vertice2D: public ed::Vertice2DInterfaz
{

  //! \name Atributos privados de la clase Vertice2D
   private: 
      	double _x; //!< abscisa del Vertice2D 
		double _y; //!< ordenada del Vertice2D 


   //! \name Funciones o métodos públicos de la clase Vertice2D
   public:

	//! \name Constructores de la clase Vertice2D
	/*! 
		\brief     Constructor que crea un Vertice2D a partir de sus coordenadas x e y
		\attention Función sobrecargada        
		\note      Función inline
	 	\warning   Los parámetros tienen valores por defecto
		\param     x: abscisa de Vertice2D; valor por defecto 0.0
		\param     y: ordenada de Vertice2D; valor por defecto 0.0
		\pre       Ninguna
		\post      (this->getX() == x) and (this->getY() == y)
		\sa        setX(), setY()
	*/
	inline Vertice2D(double x=0.0, double y=0.0)
	{
		this->setX(x);
		this->setY(y);

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert( std::abs (this->getX() - x) < COTA_ERROR ); 
			assert( std::abs (this->getY() - y) < COTA_ERROR ); 
		#endif //NDEBUG
	}

	/*! 
		\brief     Constructor de "copia" que crea un Vertice2D a partir de otro Vertice2D
		\attention Función sobrecargada        
		\note      Función inline
		\warning   Se requiere que las funciones de acceso getX y getY tengan el modificador const
		\param     v: Vertice2D utilizado para proporcionar los valores iniciales del nuevo Vertice2D
		\pre       Ninguna
		\post 	   (this->getX() == v.getX()) and (this->getY() == v.getY())
		\sa        getX(), getY(), setX(), setY()
	*/
	inline Vertice2D(Vertice2D const &v)
	{
		setX(v.getX());
		setY(v.getY());

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert( std::abs (this->getX() - v.getX()) < COTA_ERROR ); 
			assert( std::abs (this->getY() - v.getY()) < COTA_ERROR );   
		#endif //NDEBUG
	}

	//! \name Observadores: funciones de consulta de Vertice2D

	/*! 
		\brief   Función que devuelve la abscisa o coordenada "x" de un Vertice2D
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\note    Función inline
		\return  Componente "x" del Vertice2D (tipo double)
		\pre     Ninguna
		\post    Ninguna
		\sa      getY()
	*/
	inline double getX() const
	{
		return _x;
	}
	/*! 
		\fn      inline double getY()const
		\brief   Función que devuelve la ordenada o coordenada "y" de un Vertice2D
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\note    Función inline
		\return  Componente "y" del Vertice2D (tipo double)
		\pre     Ninguna
		\post    Ninguna
		\sa      getX()
	*/
	inline double getY() const
	{
		return _y;

	}


	//! \name Funciones de modificación de Vertice2D

	/*! 
		\brief Función que asigna un valor "v" a la coordenada "x" de un Vertice2D
		\note  Función inline
		\param v: nuevo valor de la abscisa del Vertice2D (tipo double)
		\pre   Ninguma
		\post  (this->getX() == v.getX()) and (this->getY() == v.getY())
		\sa setY()
	*/
	inline void setX(double v)
	{
		_x = v;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert( std::abs (this->getX() - v) < COTA_ERROR ); 
		#endif //NDEBUG
	}


	/*! 
		\fn    inline void setY(double v)
		\brief Función que asigna un valor "v" a la coordenada "y" de un Vertice2D
		\note  Función inline
		\param v: nuevo valor de la ordenada del Vertice2D (tipo double)
		\pre   Ninguna
		\post  this->getY() == v.getY()
		\sa    setX()
	*/
	inline void setY(double v)
	{
		_y = v;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert( std::abs (this->getY() - v) < COTA_ERROR );   
		#endif //NDEBUG

	}


    //! \name Operadores
   
	/*! 
		\brief     Operador de asignación: operacor que "copia" un Vertice2D en otro Vertice2D
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\warning   Se requiere que las funciones de acceso getX y getY tengan el modificador const
		\param     v: objeto de tipo Vertice2D pasado como referencia constante
		\pre       El Vertice2D v debe er diferente del vértice actual
		\post      El vértice actual debe ser igual al vértice pasado como argumento
				   \n (this->getX() == v.getX()) and (this->getY() == v.getY())
		\sa        getX(), getY(), setX(), setY(), operator==()
	*/
	inline Vertice2D & operator=(ed::Vertice2D const &v)
	{
		// Se comprueba que no sean el mismo objeto
		if (this != &v) 
		{
			setX(v.getX());
			setY(v.getY());

			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert( std::abs (this->getX() - v.getX()) < COTA_ERROR ); 
				assert( std::abs (this->getY() - v.getY()) < COTA_ERROR );   
			#endif //NDEBUG
		}

		return *this;
	}
 


	/*! 
		\brief     Operador de igualdad: compara si un Vertice2D es igual a otro Vertice2D
		\attention Se sobrecarga el operador de igualdad "=="
		\note      Función inline
		\param     v: objeto de tipo Vertice2D pasado como referencia constante
		\pre       Ninguna
		\post      valorDevuelto == (this->getX() == v.getX()) and (this->getY() == v.getY())
				  \n Se debe utilizar una cota de error para tener en cuenta la precisión de los números reales
		\sa        getX(), getY(), setX(), setY(),  operator=()
	*/
	inline bool operator == (ed::Vertice2D const &v) const
  {
  	// Se utiliza COTA_ERROR para controlar la precisión de los números reales
    return (
                  (std::abs (v.getX() - this->getX()) < COTA_ERROR)   
              and (std::abs (v.getY() - this->getY()) < COTA_ERROR)
            );
	}


	//! \name Funciones lectura y escritura de la clase Vertice2D

	/*! 
		\brief   Asigna a un Vertice2D las coordenadas "x" e "y" leídas desde el teclado
		\warning Se deben teclear números
		\pre     Ninunga
		\post    Los atributos _x e _y de Vertice2D deben tener valores numéricos
		\sa      setX(), setY()
	*/
	void leerVertice2D();


	/*! 
		\brief Escribe por pantalla las coordenadas de un Vertice2D de la forma (x,y)
		\pre   Ninguna
		\post  Ninguna
		\sa    getX(), getY()
	*/
	void escribirVertice2D();


}; // Fin de la definición de la clase Vertice2D

//! \name Funciones externas que utilizan argumentos del tipo Vertice2D

	/*! 
		\brief  Calcula la distancia euclídea entre dos Vertice2D: v1 y v2
				\n \f$ \sqrt{ (x_2-x_1)^2 + (y_2 - y_1)^2 } \f$
		\param  v1 Primer Vertice2D 
		\param  v2 Segundo Vertice2D
		\return sqrt (  (v2.getX()-v1.getX() * v2.getX()-v1.getX()) + (v2.getY()-v1.getY() * v2.getY()-v1.getY()) )  
		\pre    Ninguna
		\post   valorDevuelto == sqrt (   (v2.getX()-v1.getX() * v2.getX()-v1.getX()) + (v2.getY()-v1.getY() * v2.getY()-v1.getY()) )  
		\sa     getX(), getY() de la clase Vertice2D
	*/
	double calcularDistanciaEuclidea2D(ed::Vertice2D const&v1, ed::Vertice2D const&v2);

	/*!
  		\brief      Sobrecarga del operador de entrada o lectura ">>"
					\n Lee las coordenadas del vértice separadas por espacios
		\attention  Función amiga de la clase Vertice2D
		\param      stream: flujo de entrada
		\param      v Vertice2D al que se le van a asignar nuevos valores.
		\pre        Ninguna
		\post       Ninguna
		\sa         operator<<
    */
    istream &operator>>(istream &stream, ed::Vertice2D &v);

    /*!
  		\brief     Sobrecarga del operador de salida o escritura "<<"
				   \n Escribe por pantalla las coordenadas de un Vertice2D de la forma (x,y)
		\attention Función amiga de la clase Vertice2D
		\param     stream: flujo de salida
		\param     v: Vertice2D del cual se van a escribir sus coordenadas por pantalla
		\pre       Ninguna
		\post      Ninguna
		\sa        operator>>
    */
    ostream &operator<<(ostream &stream, ed::Vertice2D const &v);


} // \brief Fin de namespace ed.

//  _VERTICE2D_HPP_
#endif 
