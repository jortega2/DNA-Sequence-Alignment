//Driver program for testing the DNA class
#include "DNA.h"

int main() {

	DNA dna("AGCTAATACCCCATACGTTC", "GTGAACGCTGGCGGCGTGCT");
	dna.calcTable();
	dna.displayTable();
	dna.displayAlignment();
	std::cout << dna.getAlignmentScore() << '\n';

	DNA dna2;
	dna2.setFirstDNA("AGC");
	dna2.setSecondDNA("AGC");
	dna2.calcTable();
	dna2.displayTable();
	dna2.displayAlignment();
	std::cout << dna2.getAlignmentScore() << '\n';

	DNA dna3("ATAT","ATCTTT");
	dna3.calcTable();
	dna3.displayTable();
	dna3.displayAlignment();
	std::cout << dna3.getAlignmentScore() << '\n';

	return 0;
}