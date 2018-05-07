	/*! 
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida 
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

// COMPLETAR, SI ES PRECISO


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$ 
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private:

   double v1_, v2_, v3_;

   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D

   		inline Vector3D(double v1=0.0, double v2=0.0, double v3=0.0){
        set1(v1);
        set2(v2);
        set3(v3);
        #ifndef NDEBUG
          assert( (this->get1() == v1) and (this->get2() == v2) and (this->get3() == v3));
        #endif //NDEBUG
      }

   		inline Vector3D(Vector3D const &v){
        set1(v.get1());
        set2(v.get2());
        set3(v.get3());
        #ifndef NDEBUG
          assert( (this->get1() == v.get1()) and (this->get2() == v.get2()) and (this->get3() == v.get3()) );
        #endif //NDEBUG
      }

	//! \name Observadores: funciones de consulta de Vector3D

   		inline double get1()const{return v1_;}
   		inline double get2()const{return v2_;}
   		inline double get3()const{return v3_;}

   		double modulo()const;
   		double angulo(Vector3D const &v)const;
   		inline double alfa()const{
          Vector3D aux(1.0, 0.0, 0.0);
          return(angulo(aux));
      }
   		inline double beta()const{
          Vector3D aux(0.0, 1.0, 0.0);
          return(angulo(aux));
      }
   		inline double gamma()const{
          Vector3D aux(0.0, 0.0, 1.0);
          return(angulo(aux));
      }
   		inline double dotProduct(Vector3D const &v)const{
        return (get1()*v.get1() + get2()*v.get2() + get3()*v.get3());
      }
   		Vector3D crossProduct(Vector3D const &v)const;
   		inline double productoMixto(Vector3D const &v, Vector3D const &w)const{
        Vector3D aux;
        aux = v.crossProduct(w);
        return(dotProduct(aux));
      }



	//! \name Modificadores: funciones de modificación de Vector3D

   		inline void set1(double x){v1_ = x;}
   		inline void set2(double x){v2_ = x;}
   		inline void set3(double x){v3_ = x;}

   		void sumConst(double k);
   		void sumVect(Vector3D const &v);
   		void multConst(double k);
   		void multVect(Vector3D const &v);

    //! \name Operadores de la clase
  /*! 
    \brief     Operador de asignación: operacor que "copia" un Vector3D en otro Vector3D
    \attention Se sobrecarga el operador de asignación "="
    \warning   Se requiere que las funciones de acceso get1, get2 y get3 tengan el modificador const
    \param     objeto: objeto de tipo Vector3D pasado como referencia constante
    \pre       El Vector3D objeto debe er diferente del vector actual
    \post      El vector actual debe ser igual al vector pasado como argumento
           \n (this->get1() == v.get1()) and (this->get2() == v.get2()) and (this->get3() == v.get3())
  */
	Vector3D & operator=(Vector3D const &objeto);


  /*! 
    \brief     Operador de igualdad: compara si un Vector3D es igual a otro Vector3D
    \attention Se sobrecarga el operador de igualdad "=="
    \param     v: objeto de tipo Vector3D pasado como referencia constante
    \pre       Ninguna
    \post      valorDevuelto == (this->get1() == v.get1()) and (this->get2() == v.get2()) and (this->get3() == v.get3())
          \n Se debe utilizar una cota de error para tener en cuenta la precisión de los números reales
  */
	bool operator == (Vector3D const &objeto) const;

	// COMPLETAR EL RESTO DE OPERADORES
	Vector3D & operator+(Vector3D const &v)const;
	Vector3D & operator+()const;
	Vector3D & operator-(Vector3D const &v)const;
	Vector3D & operator-()const;
	Vector3D & operator*(double k);
	double operator*(Vector3D const &v)const;
	Vector3D operator^(Vector3D const &v)const;

	//! \name Funciones lectura y escritura de la clase Vector3D

	void leerVector3D();
	void escribirVector3D()const;

}; // Fin de la definición de la clase Vector3D


//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	 /*!
      \brief     Sobrecarga del operador "*"
           \n Realiza la multiplicación de una constante k por los elementos de un Vector3D
    \attention Función amiga de la clase Vector3D
    \param     k: constante que va a multiplicar los elementos del Vector3D
    \param     onjeto: Vector3D cuyos elementos serán multiplicados por la constante
    \pre       Ninguna
    \post      Ninguna
    \sa        operator*
    */
    Vector3D & operator* (double k, Vector3D const & objeto);


	/*!
      \brief      Sobrecarga del operador de entrada o lectura ">>"
          \n Lee las coordenadas del vértice separadas por espacios
    \attention  Función amiga de la clase Vector3D
    \param      stream: flujo de entrada
    \param      objeto Vector3D al que se le van a asignar nuevos valores.
    \pre        Ninguna
    \post       Ninguna
    \sa         operator<<
    */
    istream &operator>>(istream &stream, Vector3D &objeto);

	 /*!
      \brief     Sobrecarga del operador de salida o escritura "<<"
           \n Escribe por pantalla las coordenadas de un Vector3D de la forma (v1, v2, v3)
    \attention Función amiga de la clase Vector3D
    \param     stream: flujo de salida
    \param     objeto: Vector3D del cual se van a escribir sus coordenadas por pantalla
    \pre       Ninguna
    \post      Ninguna
    \sa        operator>>
    */    
	ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif 
