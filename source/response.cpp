/*

	Name: response.cpp
	Author: Jacob P.
	C++ File that contains functions from "response.h"

*/

#include <iostream>
#include "response.h"

using namespace std;

Response::Response() {
	
	setResponse( "" );
	setId( 0 );
	
}

Response::Response( string s, int i ) {
	
	setResponse( s );
	setId( i );
	
}

Response::Response( const Response& r ) {
	
	setResponse( r.response );
	setId( r.id );
	
}

void Response::setResponse( string s ) {
	
	response = s;
	
}

void Response::setId( int i ) {
	
	id = i;
	
}

ostream& operator<<( ostream& out, const Response& r ) {
	
	cout << r.getResponse();
	
	return out;
	
}