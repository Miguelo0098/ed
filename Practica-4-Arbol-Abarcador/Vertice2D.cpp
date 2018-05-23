/*! 
   \file Vertice2D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vertice2D
*/


// Ficheros de cabecera
#include <iostream>

#include "Vertice2D.hpp"

/*
 Definiciones de las funciones lectura y escritura de la clase Vertice2D
*/

void ed::Vertice2D::leerVertice2D()
{

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


void ed::Vertice2D::escribirVertice2D()
{
  std::cout << "(" << this->getX() << ", " << this->getY() << ")" << std::endl; 
}

////////////////////////////////////////////////////////////////////////////////



// Se incluyen en el espacio de nombres "ed" las funciones externas que utilizan argumentos de la clase Vertice2D

namespace ed{


double calcularDistanciaEuclidea2D(ed::Vertice2D const & v1, ed::Vertice2D const & v2)
{
  return sqrt ( 
                  (v2.getX() - v1.getX()) * (v2.getX() - v1.getX())
                + (v2.getY() - v1.getY()) * (v2.getY() - v1.getY())
	          );
}

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Vertice2D const &v)
{
  std::cout << "(";
  stream << v.getX();
  stream << ", ";
  stream << v.getY();
  std::cout << ")";

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vertice2D &v)
{
  double numero;

  stream >> numero;
  v.setX(numero);

  stream >> numero;
  v.setY(numero);

  return stream;
} 

} // Fin del espacio de nombres ed
