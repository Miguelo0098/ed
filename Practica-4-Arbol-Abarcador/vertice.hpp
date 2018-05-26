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

define COTA_ERROR 1.0e-6

using std::istream;
using std::ostream;

namespace ed{

	class Vertice{
	private:
		double _x;
		double _y;
		int _label


	public:
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

		inline double getX(){
			return _x;
		}

		inline double getY(){
			return _y;
		}

		inline int getLabel(){
			return _label;
		}

		inline void setX(double x){
			_x = x;

			#ifndef NDEBUG
          		assert(std::abs(getX() - x) < COTA_ERROR);
        	#endif //NDEBUG
		}

		inline void setY(double y){
			_y = y;

			#ifndef NDEBUG
          		assert(std::abs(getY() - y) < COTA_ERROR);
        	#endif //NDEBUG
		}

		inline void setLabel(int label){
			_label = label;

			#ifndef NDEBUG
          		assert(getLabel() == label);
        	#endif //NDEBUG
		}
		
		inline vertice & operator=(ed::vertice const &v)
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
		

		inline bool operator == (ed::Vertice2D const &v) const
		{
  			// Se utiliza COTA_ERROR para controlar la precisión de los números reales
    		return 	(
    	              	(std::abs (v.getX() - this->getX()) < COTA_ERROR)   
    	          		and (std::abs (v.getY() - this->getY()) < COTA_ERROR)
    	        	);
		}

		void leerVertice();

		void escribirVertice();


	}; //Fin de la clase vértice

	double getDistanciaEuclidea(Vertice const & v1, Vertice const & v2);

	istream &operator>>(istream &stream, ed::Vertice &v);

	ostream &operator<<(ostream &stream, ed::Vertice const &v);



}

#endif