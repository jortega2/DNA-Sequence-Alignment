//header file for DNA class. A DNA object holds two DNA strands in string format and is able to find an optimal alignment between them.
#ifndef DNA_H
#define DNA_H

#include<iostream>
#include<string>
#include<map>
#include<iomanip>
#include<algorithm>

class DNA {
private:
	std::string dna_1;
	std::string dna_2;
	size_t rows;
	size_t cols;
	std::string key;
	std::map<std::pair<char,char>, double> cost;
	double** table;
public:
	DNA();
	DNA(std::string a, std::string b);
	~DNA();
	void setFirstDNA(std::string a);
	void setSecondDNA(std::string b);
	void calcTable();
	void displayTable();
	void displayAlignment();
	double getAlignmentScore();
};

#endif