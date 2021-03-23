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
	//initialize variables 
	dna_1 = a;
	dna_2 = b;
	rows = dna_1.length();
	cols = dna_2.length();

	//dynamic 2d array
	table = new double* [rows+1];
	for (int i = 0; i < rows+1; i++) {
		table[i] = new double[cols+1];
	}
	//base cases
	table[0][0] = 0;
	for (int i = 1; i <= rows; i++) {
		table[i][0] = table[i - 1][0] - .2;
	}
	for (int i = 1; i <= cols; i++) {
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
	for (int i = 0; i <= rows; i++) {
		delete[] table[i];
	}
	delete[] table;
}
void DNA::setFirstDNA(std::string a) {
	//a[0] == '0' ? dna_1 = a : dna_1 = '0' + a;
	dna_1 = a;
	cols = dna_1.length();
}
void DNA::setSecondDNA(std::string a) {
	//a[0] == '0' ? dna_2 = a : dna_2 = '0' + a;
	dna_2 = a;
	rows = dna_2.length();
}
void DNA::calcArray() {
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			table[i][j] = std::max({table[i - 1][j - 1] + cost[std::make_pair(dna_1[i-1], dna_2[j-1])],
									table[i - 1][j] - .2										  ,
									table[i][j - 1] - .2										  });
		}
	}
}
void DNA::displayArray() {
	//add arrows, colors, etc..
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			std::cout << std::setw(5) << std::fixed << std::setprecision(1) << table[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
void DNA::dispAlignment() {
	int i = int(rows);
	int j = int(cols);

	std::string dna1 = "";
	std::string dna2 = "";
	while (!(i == 0 || j == 0)) {
		if (table[i-1][j-1] + cost[std::make_pair(dna_1[i-1], dna_2[j-1])] == table[i][j]) {
			dna1.insert(0, 1, dna_1[--i]);
			dna2.insert(0, 1, dna_2[--j]);
		}
		else if (table[i - 1][j] - .2 == table[i][j]) {
			dna1.insert(0, 1, dna_1[--i]);
			dna2.insert(0, 1, '_');
		}
		else if (table[i][j - 1] - .2 == table[i][j]) {
			dna1.insert(0, 1, '_');
			dna2.insert(0, 1, dna_2[--j]);
		}
	}
	if (i == 0) {
		while (j > 0) {
			dna1.insert(0, 1, '_');
			dna2.insert(0, 1, dna_2[--j]);
		}
	}
	else if (j == 0) {
		while (i > 0) {
			dna1.insert(0, 1, dna_1[--i]);
			dna2.insert(0, 1, '_');
		}
	}
	
	std::cout << dna2 << ' ' << '\n';
	std::cout << dna1 << ' ' << '\n';
}
double DNA::getAlignmentScore() {
	return table[rows-1][cols-1];
}