###
# CoinToss, a probability simulator.
# Copyright (C) 2014 Nicolas A. Ortega
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License or
# (at your option) any later.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
##

import sys
from random import randint

version = "v0.3"

### DEFINE FUNCTIONS ###
def printUsage():
	print "Usage:", sys.argv[0], "[[num_trials] | [args]]\nUse -h or --help for more information."

def printCopyright():
	print """CoinToss""", version, """Copyright (C) 2014 Nicolas A. Ortega\n
This program comes with ABSOLUTELY NO WARRANTY; for details use `-w'.
This is free software, and you are welcome to redistribute it
under certain conditions; use `-c' for details\n"""

def printAllCopyright():
	print """CoinToss, a probability simulator.
Copyright (C) 2014 Nicolas A. Ortega\n
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.\n
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.\n
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.\n"""

def printWarranty():
	print """  THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY
OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM
IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF
ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n"""

def printHelp():
	printUsage()
	print """ -c		-- Print copyright information
 -h | --help	-- Print this help information
 -w		-- Print warranty information
 -v		-- Print version"""


### MAIN ###

# If no arguments specified
if len(sys.argv) == 1:
	printCopyright()
	printUsage()
	sys.exit(0)
# Check if appropriate number of arguments
elif len(sys.argv) != 2:
	print "Inappropriate number of arguments."
	printUsage()
	sys.exit(0)
# Check if copyright argument is passed
elif sys.argv[1] == "-c":
	printAllCopyright()
	sys.exit(0)
# Check if warranty argument is passed
elif sys.argv[1] == "-w":
	printWarranty()
	sys.exit(0)
# Check if help argument is passed
elif sys.argv[1] == "-h" or sys.argv[1] == "--help":
	printHelp()
	sys.exit(0)
# Check if version argument is passed
elif sys.argv[1] == "-v":
	print "CoinToss", version
	sys.exit(0)

if sys.argv[1] is not int:
	print "Please give an integer."
	sys.exit(0)

printCopyright()

# Create necessary variables
trials = int(sys.argv[1])
heads = 0
tails = 0

oldProgress = 0

print "Calculating random numbers..."
print "Progress: 0 %"
for i in range(0, trials):
	progress = (i * 100) / trials
	if progress is not oldProgress and progress % 10 is 0:
		print "Progress:", progress, "%"
		oldProgress = progress
	
	if randint(1, 10) <= 5:
		heads += 1
	else:
		tails += 1

print "Progress: 100 %"
print "Done.\n"
print "Heads:", heads
print "Tails:", tails

sys.exit(0)
