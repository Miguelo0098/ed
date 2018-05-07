/*!	

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author  Miguel Ángel Ramírez Ruiz
	\date  
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <iostream>

// Para comprobar las pre y post condiciones
#include <cassert>

#include "Provincia.hpp"


// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia

///////////////////////////////////////////////////////////////////////////////

// OSBSERVADORES

// TODO: modificar algunos observadores para que no falle al modificar la lista

bool ed::Provincia::existeMunicipio(std::string name){
	if (_listaMunicipios.isEmpty() == true)
	{
		return false;
	}

	_listaMunicipios.gotoHead();
	if (_listaMunicipios.getCurrentItem().getNombre() == name)
	{
		return true;
	}

	while(_listaMunicipios.isLastItem() == false){
		_listaMunicipios.gotoNext();
		if (_listaMunicipios.getCurrentItem().getNombre() == name)
		{
			return true;
		}
		
	};

	return false;
}

ed::Municipio const & ed::Provincia::getMunicipio(std::string name){
	#ifndef NDEBUG
		// Se comprueba la precondición
		assert(this->existeMunicipio(name) == true);
	#endif //NDEBUG

	this->existeMunicipio(name);
	return _listaMunicipios.getCurrentItem();
}

int ed::Provincia::getTotalHombres(){
	int nhombres = 0;
	if (_listaMunicipios.isEmpty() == true)
	{
		return 0;
	}

	_listaMunicipios.gotoHead();
	do{
		nhombres += _listaMunicipios.getCurrentItem().getHombres();
		_listaMunicipios.gotoNext();

	}while(_listaMunicipios.isLastItem() == false);
	
	nhombres += _listaMunicipios.getCurrentItem().getHombres();
	return nhombres;
}

int ed::Provincia::getTotalMujeres(){
	int nmujeres = 0;
	if (_listaMunicipios.isEmpty() == true)
	{
		return 0;
	}

	_listaMunicipios.gotoHead();
	do{
		nmujeres += _listaMunicipios.getCurrentItem().getMujeres();
		_listaMunicipios.gotoNext();

	}while(_listaMunicipios.isLastItem() == false);
	
	nmujeres += _listaMunicipios.getCurrentItem().getMujeres();
	return nmujeres;
}

/////////////////////////////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Provincia::borrarMunicipio(std::string name){
	#ifndef NDEBUG
    	// Se comprueba la precondición
    	assert(this->existeMunicipio(name) == true);
    #endif //NDEBUG

    int oldnmunicipios = this->getNumeroMunicipios();
    this->existeMunicipio(name);
    _listaMunicipios.remove();

    #ifndef NDEBUG
        // Se comprueba la postcondición
        assert(this->existeMunicipio(name) == false);
        assert(oldnmunicipios - 1 == getNumeroMunicipios());
      #endif //NDEBUG
}


///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA

void ed::Provincia::escribirMunicipios(){
	std::cout <<"Código: "<<getCodigo() << std::endl;
	std::cout <<"Nombre: "<<getNombre() << std::endl;
	std::cout  << "CÓDIGO";
	std::cout  << "\t"; 
	std::cout  << "NOMBRE"; 
	std::cout  << "\t\t"; 
	std::cout  << "HOMBRES";
	std::cout  << "\t"; 
	std::cout  << "MUJERES";
	std::cout  << "\t"; 
	std::cout  << "HABITANTES" << std::endl;

	if (_listaMunicipios.isEmpty() == false)
	{
		_listaMunicipios.gotoHead();
		_listaMunicipios.getCurrentItem().escribirMunicipio();
		while(_listaMunicipios.isLastItem() == false){
			_listaMunicipios.gotoNext();
			_listaMunicipios.getCurrentItem().escribirMunicipio();	
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS

bool ed::Provincia::cargarFichero(std::string fichero){
	std::ifstream flujo_entrada;
	flujo_entrada.open(fichero.c_str(), std::ios::in);
	if (!flujo_entrada)
	{
		return false;
	}

	flujo_entrada >> _codigo >> _nombre;
	ed::Municipio aux;
	_listaMunicipios.removeAll();
	while(flujo_entrada >> aux){
		insertarMunicipio(aux);
	}
	flujo_entrada.close();

	return true;
}

bool ed::Provincia::grabarFichero(std::string fichero){
	std::ofstream flujo_salida;
	flujo_salida.open(fichero.c_str(), std::ios::out);
	if (!flujo_salida)
	{
		return false;
	}

	flujo_salida << _codigo << _nombre;
	
	if (hayMunicipios() == false)
	{
		flujo_salida.close();
		return true;
	}

	_listaMunicipios.gotoHead();
	flujo_salida << _listaMunicipios.getCurrentItem();
	while(_listaMunicipios.isLastItem() == false){
		_listaMunicipios.gotoNext();
		flujo_salida << _listaMunicipios.getCurrentItem();
	}

	flujo_salida.close();

	return true;
}

