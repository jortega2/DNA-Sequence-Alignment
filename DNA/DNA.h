#pragma once
#ifndef DNA_H_
#define DNA_H_

#include<iostream>
#include<string>
#include<map>
#include<iomanip>

class DNA {
private:
	std::string dna_1;
	std::string dna_2;
	std::string key;
	std::map<std::pair<char,char>, double> cost;
	double table[21][21];
public:
	DNA();
	DNA(std::string a, std::string b);
	void setFirstDNA(std::string a);
	void setSecondDNA(std::string b);
	void calcArray();
	void displayArray();
	void displayAlignment();
};

#endif