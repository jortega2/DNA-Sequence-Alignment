#include "DNA.h"

int main() {

	DNA dna("AGCTAATACCCCATACGTTC", "GTGAACGCTGGCGGCGTGCT");
	dna.calcArray();
	dna.displayArray();
	dna.dispAlignment();
	}