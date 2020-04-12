#include <stdio.h>
#include <fstream>

#include "prompt.h"
#include "response.h"

using namespace std;

int GAME_OVER = 0; //Used to mark when the user wants to exit the program

int main() {
	
	ifstream fileIn;	
	
	string input;
	int fileLen = 0;
	int curPrompt = 0;
	
	vector<Prompt> prompts;
	Prompt prompt;
	
	fileIn.open( "GameInput.csv");
	
	while ( getline( fileIn, input ) ) { //Gets length of file
	
		fileLen++;
		
	}
	
	fileIn.close();
	fileIn.open( "GameInput.csv");
	
	prompts.reserve( fileLen );
	
	for(int i = 0; i < fileLen; i++) { //Reads from file into vector of prompt classes
		
		fileIn >> prompt;
		prompts.push_back( prompt );
		
	}
	
	while( GAME_OVER == 0 ) {
	
		input = to_string( -1 );
		
		while ( stoi ( input ) > 2 || stoi ( input ) < 0 ) { //Stays in loop until user inputs a valid number
			
			cout << prompts[ curPrompt ];
			cin >> input;
			
			Response tempResponse ( prompts[ curPrompt ].getResponse( 1 ) );
			
			if ( tempResponse.getId() == -1 ) { //Makes sure user puts 0 or 1 when there are only two options
				
				if ( stoi ( input ) > 1 ) { //User inputed a wrong number
				
					input = to_string( -1 );
					cout << endl;
					cout << "Please input a valid integer!" << endl << endl;
					
				} 
				
			} else if ( stoi ( input ) > 2 || stoi ( input ) < 0 ) {
				
					cout << endl;
					cout << "Please input a valid integer!" << endl << endl;
			
			}
			
		}
		
		cout << endl << endl;
		
		Response response( prompts[ curPrompt ].getResponse( stoi( input ) ) );
		
		curPrompt = response.getId(); //Next prompt to move too
		
		if ( curPrompt == -1 ) { //User chose to exit the game
			
			GAME_OVER = -1;
			
		} 
	
	}
	
}
