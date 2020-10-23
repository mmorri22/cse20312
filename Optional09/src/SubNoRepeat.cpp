#include <unordered_map>
#include <string>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

int getLongestNonRepeat( const std::string& testString ){
	
	int current = 0;	int maximum = 0;
	std::unordered_map< char, int > charHash;
	
	for( int iter = (int)testString.size() - 1; iter >= 0; iter-- ){
		
		if( charHash.count( testString.at(iter) ) == 0 ){
			
			charHash.insert( { testString.at(iter), iter } );
			current++;
		}
		else{
			current++;
			
			current = ( current < charHash[ testString.at(iter) ] - iter ) ? current : charHash[ testString.at(iter) ] - iter;
			
			charHash[ testString.at(iter) ] = iter;
		}
		
		maximum = ( current > maximum ) ? current : maximum;
	}
	return maximum;
}

void runAlgorithm( const std::string& test ){
	
	COUT << "Longest Non-Repeating Substring of " << test << " is length ";
	COUT << getLongestNonRepeat( test ) << ENDL;
	
}


int main() {
	
	runAlgorithm( "cnwibfpsilmioeo" );
	runAlgorithm( "abcabcbb" );
	runAlgorithm( "bbbbb" );
	runAlgorithm( "pwwkew" );
	runAlgorithm( "bacadaelmnofghijaka" );
	runAlgorithm( "hgklcyvlstwhjhighssw" );
	runAlgorithm( "umwoleylehugrayqoz" );
	
	return 0;
}