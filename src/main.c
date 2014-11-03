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

char version[7] = "v0.1";

void printCopyright();
void printAllCopyright();
void printWarranty();

int main(int argc, char **argv) {
	if(argc < 2 || argc > 3) {
		printf("Inappropriate amount of arguments.");
		printf("Usage: %s [num_trials]\n", argv[0]);
		return 1;
	}

	if(strcmp(argv[1], "-c") == 0) {
		printAllCopyright();
		return 0;
	} else if(strcmp(argv[1], "-w") == 0) {
		printWarranty();
		return 0;
	} else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		printf("Usage: %s [num_trials]\n\
 -c		-- Print copyright info\n\
 -h | --help	-- Print this help information\n\
 -w		-- Print warranty information\n", argv[0]);
		return 0;
	} else {
		int i = 0;
		while(argv[1][i] != '\0') {
			printf("%c", argv[1][i]);
			if(isdigit(argv[1][i] - '0') != 0) {
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

	srand(time(NULL));

	printf("Calculating random numbers...\n");
	for(int i = 0; i < trials; i++) {
		if(i % 100000000 == 0) printf("Working...\n");
		int r = rand() % 100 + 1;
		if(r <= 50) heads++;
		else tails++;
	}

	printf("Done.\n");
	printf("Heads: %i\n", heads);
	printf("Tails: %i\n", tails);
	return 0;
}

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
HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY\n\
OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,\n\
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n\
PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM\n\
IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF\n\
ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n");
}
