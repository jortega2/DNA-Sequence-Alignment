#include "DNA.h"

DNA::DNA(){
	//cost table
	cost[std::pair<char,char> ('A','A')] = cost[std::pair<char, char>('G', 'G')] 
		= cost[std::pair<char, char>('C', 'C')] = cost[std::pair<char, char>('T', 'T')] = 1;
	cost[std::pair<char, char>('A', 'T')] = cost[std::pair<char, char>('T', 'A')]
		= cost[std::pair<char, char>('C', 'G')] = cost[std::pair<char, char>('G', 'C')] = -0.15;
	cost[std::pair<char, char>('A', 'G')] = cost[std::pair<char, char>('G', 'A')]
		= cost[std::pair<char, char>('A', 'C')] = cost[std::pair<char, char>('C', 'A')]
		= cost[std::pair<char, char>('T', 'G')] = cost[std::pair<char, char>('G', 'T')]
		= cost[std::pair<char, char>('T', 'C')] = cost[std::pair<char, char>('C', 'T')] = -.1;

	//base cases
	table[0][0] = 0;
	for (int i = 1; i <= 20; i++) {
		table[i][0] = table[i - 1][0] - .2;
		table[0][i] = table[0][i - 1] - .2;
	}
}
DNA::DNA(std::string a, std::string b) {
	//might need code from default constructor as well.
	dna_1 = a;
	dna_2 = b;
	//cost table
	cost[std::pair<char, char>('A', 'A')] = cost[std::pair<char, char>('G', 'G')]
		= cost[std::pair<char, char>('C', 'C')] = cost[std::pair<char, char>('T', 'T')] = 1;
	cost[std::pair<char, char>('A', 'T')] = cost[std::pair<char, char>('T', 'A')]
		= cost[std::pair<char, char>('C', 'G')] = cost[std::pair<char, char>('G', 'C')] = -0.15;
	cost[std::pair<char, char>('A', 'G')] = cost[std::pair<char, char>('G', 'A')]
		= cost[std::pair<char, char>('A', 'C')] = cost[std::pair<char, char>('C', 'A')]
		= cost[std::pair<char, char>('T', 'G')] = cost[std::pair<char, char>('G', 'T')]
		= cost[std::pair<char, char>('T', 'C')] = cost[std::pair<char, char>('C', 'T')] = -.1;
	//base cases
	table[0][0] = 0;
	for (int i = 1; i <= 20; i++) {
		table[i][0] = table[i - 1][0] - .2;
		table[0][i] = table[0][i - 1] - .2;
	}
}
void DNA::setFirstDNA(std::string a) {
	dna_1 = a;
}
void DNA::setSecondDNA(std::string a) {
	dna_2 = a;
}
void DNA::calcArray() {
	//fix lookup. Maybe possible without lookUp?
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++) {
			table[i][j] = std::max(std::max(table[i - 1][j - 1] + cost[std::pair<char, char>(dna_1[i-1],dna_2[j-1])], table[i - 1][j] - .2), table[i][j - 1] - .2);
		}
	}
}
void DNA::displayArray() {
	//add arrows, colors, etc..
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			std::cout << std::setw(5) << std::fixed << std::setprecision(2) << table[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
void DNA::displayAlignment() {
	//todo
}