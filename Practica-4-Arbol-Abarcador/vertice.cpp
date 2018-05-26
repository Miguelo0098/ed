#include "vertice.hpp"

#include <iostream>

void ed::Vertice::leerVertice(){
	double x, y;

  	std::cout << "\n Lectura de las coordenadas de un vertice: (x,y) " << std::endl;

  	std::cout << " Abscisa: x --> ";
  	std::cin >> x;

  	std::cout << " Ordenada: y --> ";
  	std::cin >> y;

  	// Se asignan los valores leídos a los atributos del vertice   
  	this->setX(x);
  	this->setY(y);
}

void ed::Vertice::escribirVertice(){
	std::cout << "(" << this->getX() << ", " << this->getY() << ")" << std::endl; 
}



namespace ed{
	
	double getDistanciaEuclidea(ed::Vertice const & v1, ed::Vertice const & v2){
		return 	std::sqrt(
        	          (v2.getX() - v1.getX()) * (v2.getX() - v1.getX())
            	    + (v2.getY() - v1.getY()) * (v2.getY() - v1.getY())
	        		);
	}

	istream &operator>>(istream &stream, ed::Vertice &v){
		double numero;

  		stream >> numero;
  		v.setX(numero);

  		stream >> numero;
  		v.setY(numero);

  		return stream;
	}

	ostream &operator<<(ostream &stream, ed::Vertice const &v){
		std::cout << "(";
  		stream << v.getX();
  		stream << ", ";
  		stream << v.getY();
  		std::cout << ")";

  		return stream;
	}
}

