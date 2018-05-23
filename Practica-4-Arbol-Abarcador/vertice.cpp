#include "vertice.hpp"

#include <iostream>

namespace ed{
	
	double getDistanciaEuclidea(Vertice const & v1, Vertice const & v2){
		return 	sqrt(
        	          (v2.getX() - v1.getX()) * (v2.getX() - v1.getX())
            	    + (v2.getY() - v1.getY()) * (v2.getY() - v1.getY())
	        		);
	}
}

