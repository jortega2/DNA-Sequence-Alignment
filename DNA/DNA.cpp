#include "DNA.h"

DNA::DNA(){
	cols = 0;
	rows = 0;
	table = { 0 };

	//cost table
	cost[std::pair<char, char>('A', 'A')] = cost[std::pair<char, char>('G', 'G')]
		= cost[std::pair<char, char>('C', 'C')] = cost[std::pair<char, char>('T', 'T')] = 1;
	cost[std::pair<char, char>('A', 'T')] = cost[std::pair<char, char>('T', 'A')]
		= cost[std::pair<char, char>('C', 'G')] = cost[std::pair<char, char>('G', 'C')] = -0.15;
	cost[std::pair<char, char>('A', 'G')] = cost[std::pair<char, char>('G', 'A')]
		= cost[std::pair<char, char>('A', 'C')] = cost[std::pair<char, char>('C', 'A')]
		= cost[std::pair<char, char>('T', 'G')] = cost[std::pair<char, char>('G', 'T')]
		= cost[std::pair<char, char>('T', 'C')] = cost[std::pair<char, char>('C', 'T')] = -.1;
}
DNA::DNA(std::string a, std::string b) {
	//Add 0 to the start of the strings. This is necessary to have the correct dimensions for the table, as 0s are used in the base case. 
	a[0] == '0' ? dna_1 = a : dna_1 = '0' + a;
	b[0] == '0' ? dna_2 = b : dna_2 = '0' + b;
	rows = dna_1.length();
	cols = dna_2.length();

	//dynamic 2d array
	table = new double* [rows];
	for (int i = 0; i < rows; i++) {
		table[i] = new double[cols];
	}
	//base cases
	table[0][0] = 0;
	for (int i = 1; i < rows; i++) {
		table[i][0] = table[i - 1][0] - .2;
	}
	for (int i = 1; i < cols; i++) {
		table[0][i] = table[0][i - 1] - .2;
	}

	//cost table
	cost[std::pair<char, char>('A', 'A')] = cost[std::pair<char, char>('G', 'G')]
		= cost[std::pair<char, char>('C', 'C')] = cost[std::pair<char, char>('T', 'T')] = 1;
	cost[std::pair<char, char>('A', 'T')] = cost[std::pair<char, char>('T', 'A')]
		= cost[std::pair<char, char>('C', 'G')] = cost[std::pair<char, char>('G', 'C')] = -0.15;
	cost[std::pair<char, char>('A', 'G')] = cost[std::pair<char, char>('G', 'A')]
		= cost[std::pair<char, char>('A', 'C')] = cost[std::pair<char, char>('C', 'A')]
		= cost[std::pair<char, char>('T', 'G')] = cost[std::pair<char, char>('G', 'T')]
		= cost[std::pair<char, char>('T', 'C')] = cost[std::pair<char, char>('C', 'T')] = -.1;
}
DNA::~DNA() {
	//delete dynamic array
	for (int i = 0; i < rows; i++) {
		delete[] table[i];
	}
	delete[] table;
}
void DNA::setFirstDNA(std::string a) {
	a[0] == '0' ? dna_1 = a : dna_1 = '0' + a;
	cols = dna_1.length();
}
void DNA::setSecondDNA(std::string a) {
	a[0] == '0' ? dna_2 = a : dna_2 = '0' + a;
	rows = dna_2.length();
}
void DNA::calcArray() {
	for (int i = 1; i < rows; i++) {
		for (int j = 1; j < cols; j++) {
			table[i][j] = std::max(std::max(table[i - 1][j - 1] + cost[std::make_pair(dna_1[i], dna_2[j])], table[i - 1][j] - .2), table[i][j - 1] - .2);
		}
	}
}
void DNA::displayArray() {
	//add arrows, colors, etc..
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << std::setw(5) << std::fixed << std::setprecision(1) << table[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
void DNA::displayAlignment() {
	//todo
}
double DNA::getAlignmentScore() {
	return table[rows-1][cols-1];
}