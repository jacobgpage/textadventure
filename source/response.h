/*

	Name: response.h
	Author: Jacob P.
	Header file that contains the Response class

*/

#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

using namespace std;

class Response {
	
	private:
		string response; 
		int id; //Id that leads to the next prompt for this response
	
	public:
	
		//A default constructor, a two para constructor, and a copy constructor
		Response();
		Response( string, int );
		Response( const Response& );
		
		//Mutator functions
		void setResponse( string );
		void setId( int );
		
		//Accessor functions
		string getResponse() const { return response; }
		int getId() const { return id; }
		
		friend ostream& operator<<( ostream&, const Response& );
	
};

#endif
