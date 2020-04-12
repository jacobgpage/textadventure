/*

	Name: response.cpp
	Author: Jacob P.
	C++ File that contains functions from "response.h"

*/

#include <iostream>
#include "response.h"

using namespace std;

//Default constructor
Response::Response() {
	
	setResponse( "" );
	setId( 0 );
	
}

//Two parameter constructor that takes a string and integer
Response::Response( string s, int i ) {
	
	setResponse( s );
	setId( i );
	
}

//Copy constructor
Response::Response( const Response& r ) {
	
	setResponse( r.response );
	setId( r.id );
	
}

//Mutator for the response string
void Response::setResponse( string s ) {
	
	response = s;
	
}

//Mutator for the id integer
void Response::setId( int i ) {
	
	id = i;
	
}

//Overloaded out operator that prints out a response
ostream& operator<<( ostream& out, const Response& r ) {
	
	cout << r.getResponse();
	
	return out;
	
}
