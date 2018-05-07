/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include "Vector3D.hpp"

// OBSERVADORES
double ed::Vector3D::modulo()const{
	return(sqrt(get1()*get1() + get2()*get2() + get3()*get3()));
}

double ed::Vector3D::angulo(Vector3D const &v)const{
	if (modulo()*v.modulo()==0)
	{
		return 0;
	}
	return(acos((dotProduct(v))/(modulo()*v.modulo())));
}

ed::Vector3D ed::Vector3D::crossProduct(Vector3D const &v)const{
	ed::Vector3D aux;
	if (angulo(v)==0)
	{
		aux.set1(0.0);
		aux.set2(0.0);
		aux.set3(0.0);
		return aux;
	}

	aux.set1(get2()*v.get3() - get3()*v.get2());
	aux.set2(get3()*v.get1() - get1()*v.get3());
	aux.set3(get1()*v.get2() - get2()*v.get1());


	return aux;
}

////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Vector3D::sumConst(double k){
	set1(get1() + k);
	set2(get2() + k);
	set3(get3() + k);
}

void ed::Vector3D::sumVect(Vector3D const &v){
	set1(get1() + v.get1());
	set2(get2() + v.get2());
	set3(get3() + v.get3());
}

void ed::Vector3D::multConst(double k){
	set1(get1() * k);
	set2(get2() * k);
	set3(get3() * k);
}

void ed::Vector3D::multVect(Vector3D const &v){
	set1(get1() * v.get1());
	set2(get2() * v.get2());
	set3(get3() * v.get3());
}


////////////////////////////////////////////////////////////////////////////////

// OPERADORES

bool ed::Vector3D::operator == (Vector3D const &objeto) const{
	return (
				(std::abs (objeto.get1() - this->get1()) < COTA_ERROR)
			and	(std::abs (objeto.get2() - this->get2()) < COTA_ERROR)
			and	(std::abs (objeto.get3() - this->get3()) < COTA_ERROR)
			);
}

ed::Vector3D & ed::Vector3D::operator=(Vector3D const &objeto){
	if (this != &objeto)
	{
		set1(objeto.get1());
		set2(objeto.get2());
		set3(objeto.get3());

		#ifndef NDEBUG
			assert( (this->get1() == objeto.get1()) and (this->get2() == objeto.get2()) and (this->get3() == objeto.get3()) );
		#endif
	}
	return(*this);
}

ed::Vector3D & ed::Vector3D::operator+(Vector3D const &v)const{
	Vector3D *aux = new Vector3D;
	aux->set1(get1() + v.get1());
	aux->set2(get2() + v.get2());
	aux->set3(get3() + v.get3());
	return *aux;
}

ed::Vector3D & ed::Vector3D::operator+()const{
	Vector3D *aux = new Vector3D;
	aux->set1(+get1());
	aux->set2(+get2());
	aux->set3(+get3());
	return *aux;
}

ed::Vector3D & ed::Vector3D::operator-(Vector3D const &v)const{
	Vector3D *aux = new Vector3D;
	aux->set1(get1() - v.get1());
	aux->set2(get2() - v.get2());
	aux->set3(get3() - v.get3());
	return *aux;
}

ed::Vector3D & ed::Vector3D::operator-()const{
	Vector3D *aux = new Vector3D;
	aux->set1(-get1());
	aux->set2(-get2());
	aux->set3(-get3());
	return *aux;
}

ed::Vector3D & ed::Vector3D::operator*(double k){
	ed::Vector3D *aux = new ed::Vector3D();
	aux->set1(get1()*k);
	aux->set2(get2()*k);
	aux->set3(get3()*k);
	return *aux;
}

double ed::Vector3D::operator*(Vector3D const &v)const{
	double result;
	result = ed::Vector3D::dotProduct(v);
	return result;
}

ed::Vector3D ed::Vector3D::operator^(Vector3D const &v)const{
	return ed::Vector3D::crossProduct(v);
}
////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA

void ed::Vector3D::leerVector3D(){
	std::cout<<"Introduzca el primer elemento: "<<std::endl;
	std::cin>>v_[0];
	std::cout<<"Introduzca el segundo elemento: "<<std::endl;
	std::cin>>v_[1];
	std::cout<<"Introduzca el tercer elemento: "<<std::endl;
	std::cin>>v_[2];
}

void ed::Vector3D::escribirVector3D()const{
	std::cout<<"Elemento 1: "<<get1()<<std::endl;
	std::cout<<"Elemento 2: "<<get2()<<std::endl;
	std::cout<<"Elemento 3: "<<get3()<<std::endl;
}

////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

	vectorResultado->set1(k*objeto.get1());
	vectorResultado->set2(k*objeto.get2());
	vectorResultado->set3(k*objeto.get3());

	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
	std::cout << "(";
	stream << objeto.get1();
	stream << ", ";
	stream << objeto.get2();
	stream << ", ";
	stream << objeto.get3();
	std::cout << ")";

	return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
	double numero;

	stream >> numero;
	objeto.set1(numero);
	stream >> numero;
	objeto.set2(numero);
	stream >> numero;
	objeto.set3(numero);

	return stream;
} 

} // Fin del espacio de nombres ed
