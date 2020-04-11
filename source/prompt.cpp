/*

	Name: prompt.cpp
	Author: Jacob P.
	C++ File that contains the functions from "prompt.h"

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>   
#include <fstream>
#include <vector>

#include "prompt.h"
#include "response.h"

using namespace std;

//Default constructor
Prompt::Prompt() {

	this->setQuestion( "" );
	this->setId( 0 );
	
	responses.reserve(1);
	
}

//Constructor with string parameter
Prompt::Prompt( string in ) {
	
	this->setQuestion( in );
	this->setId( 0 );
	
}

//Copy constructor
Prompt::Prompt( const Prompt& prompt ) {

	question = prompt.question;
	id = prompt.id;
	
	responses = prompt.responses;
	
}

void Prompt::setQuestion( string input ) {
	
	question = input;
	
}

void Prompt::setId( int i ) {

	id = i;
	
}

void Prompt::addResponse( const Response r ) {

	responses.push_back( r ); 
	
}

void Prompt::clearReponses() {
	
	responses.clear();
	
}

ostream& operator<<( ostream& out, const Prompt& prompt ) {
	
	int randNum;
	
	cout << prompt.getQuestion() << endl;
	
	srand( time( NULL ) );
	randNum = rand() % 10 + 0
	;
	
	for ( int i = 0; i < 3; i++ ) {
	
		Response response ( prompt.getResponse( i ) );
		
		cout << i << ") " << response.getResponse() << endl;
		
		if (response.getId() == -1) {
		
			 i = 3;
			
		}
		
	}

	cout << prompt.outputs[ randNum ];
	
	return out;
	
}

istream& operator>>( istream& in, Prompt& prompts ) {
	
	string input;
	prompts.clearReponses(); //Clears responses
	
	for ( int i = 0; i < 5; i++ ) {
		
		getline( in, input, '|' );
		
		if ( i == 0 ) { //Sets the ID for the prompt
			
			prompts.setId( stoi( input ) );
	
		} else if ( i == 1 ) { //Sets the question for the prompt
			
			prompts.setQuestion( input );
			
		} else { //Sets the responses for this prompt! 
			
			Response response;
			
			response.setResponse( input );
			getline( in, input, '|' );
			response.setId( stoi( input ) );
			prompts.addResponse( response );

			
			if ( response.getId() == -1 ) { //Prevents it from running 3 times if there are only two responses in the case of an end game
				
				i = 5;
				getline( in, input, '\n' );
				
			}
			
		}
		
		if( i == 4) { //Consumes the end line character
				
			getline( in, input, '\n' );
				
		}
		
	}
	
	return in;
	
}