/**
 * CoinToss, a probability simulator.
 * Copyright (C) 2014 Nicolás A. Ortega
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global version string
char version[7] = "v0.1";

/* Function prototypes start */
void printCopyright();
void printAllCopyright();
void printWarranty();
/* Function prototypes end */

// Main function:
int main(int argc, char **argv) {
	// If inappropriate number of arguments
	if(argc < 2 || argc > 3) { // If inappropriate number of arguments (number required = 2)
		printf("Inappropriate amount of arguments.");
		printf("Usage: %s [num_trials]\n", argv[0]);
		return 1;
	}

	if(strcmp(argv[1], "-c") == 0) { // If argv[1] (the second argument) is equal to "-c" ...
		printAllCopyright();
		return 0;
	} else if(strcmp(argv[1], "-w") == 0) { // If argv[1] is equal to "-w"
		printWarranty();
		return 0;
	} else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) { // If argv[1] is equal to "-h" or "--help"
		printf("Usage: %s [num_trials]\n\
 -c		-- Print copyright info\n\
 -h | --help	-- Print this help information\n\
 -w		-- Print warranty information\n", argv[0]);
		return 0;
	} else {
		int i = 0;
		while(argv[1][i] != '\0') { // While argv[1][i] is not equal to NULL (can't use NULL for pointers)
			if(isdigit(argv[1][i] - '0') != 0) { // if argv[1][i] is not a number between 0 and 9
				printf("You did not specify a number.\n");
				printf("Usage: %s [num_trials]\n", argv[0]);
				return 1;
			}
			i++;
		}
	}

	printCopyright();

	int trials = atoi(argv[1]);
	int heads = 0;
	int tails = 0;

	// Setup the random number generator with the seed being the time
	srand(time(NULL));

	printf("Calculating random numbers...\n");
	for(int i = 0; i < trials; i++) {
		if(i % 100000000 == 0) printf("Working...\n");
		int r = rand() % 100 + 1; // Calculate random number between 1 and 100
		if(r <= 50) heads++;
		else tails++;
	}

	printf("Done.\n");
	printf("Heads: %i\n", heads);
	printf("Tails: %i\n", tails);
	return 0;
}

/* Defined functions start */
void printCopyright() {
	printf("CoinToss %s Copyright (C) 2014  Nicolás A. Ortega\n\
This program comes with ABSOLUTELY NO WARRANTY; for details use `-w'.\n\
This is free software, and you are welcome to redistribute it\n\
under certain conditions; use `-c' for details.\n\n", version);
}

void printAllCopyright() {
	printf("CoinToss, a probability simulator.\n\
Copyright (C) 2014 Nicolás A. Ortega\n\n\
This program is free software: you can redistribute it and/or modify\n\
it under the terms of the GNU General Public License as published by\n\
the Free Software Foundation, either version 3 of the License, or\n\
(at your option) any later version.\n\n\
This program is distributed in the hope that it will be useful,\n\
but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
GNU General Public License for more details.\n\n\
You should have received a copy of the GNU General Public License\n\
along with this program.  If not, see <http://www.gnu.org/licenses/>.\n");
}

void printWarranty() {
	printf("  THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY\n\
APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT\n\
HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM \"AS\" IS WITHOUT WARRANTY\n\
OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,\n\
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n\
PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM\n\
IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF\n\
ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n");
}
/* Defined functions end */
