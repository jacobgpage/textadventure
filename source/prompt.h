/*

	Name: prompt.h
	Author: Jacob P.
	Header file that contains the Prompt class

*/

#ifndef PROMPT_H
#define PROMOT_H

#include <string>
#include <vector>
#include <iostream>

#include "response.h"

using namespace std;

class Prompt {
	
	private:
		string question;
		int id;
		vector<Response> responses;
	
	public:
	
		const string outputs[ 10 ] = { "What will you do next? ", "And your decision is? ", "What are you going to do? ", "Which one? ", "And your choice is? ", 
											"What action will you take? ", "What will you do? ", "You next action is? ", "What have you decided to do? ", "You decided to do? "};
		
		//A default constructor, a one para constructor, and a copy constructor
		Prompt();
		Prompt( string );
		Prompt( const Prompt& );
		
		//Mutator functions
		void setQuestion( string );
		void setId( int );
		
		//Accessor functions
		string getQuestion() const { return question; }
		int getId() const { return id; }
		
		//Functions that deal with the responses vector
		void addResponse( const Response );
		Response getResponse( int i ) const { return responses[i]; }
		void clearReponses();
		
		friend ostream& operator<<( ostream&, const Prompt& );
		friend istream& operator>>( istream&, Prompt& );
		
		friend class Response;

};

#endif