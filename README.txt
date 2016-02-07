The MAKEFILE does a few commands for you using the Microsoft Compiler:
-> Making sure that we are clear from any leftovers from previious builds with the clean: command
	- clean:
		find.obj
		find.exe
		help.obj
		help.exe
		clear.obj
		clear.exe
-> Then it builds the find AND help programs
	- cl /Fe:find.exe files.c course.c
	- cl /Fe:help.exe help.c
	- cl /Fe:clear.exe clear.c
-> In the end it runs the find tool(program) with the example arguments given in CW1 Specification
	- find hello -i input.txt -o output.txt
	- find hello -i input.txt -o output.txt -c
	
	
INSTRUCTIONS
-> In order to start the MAKEFILE type the following in the console:
	- cd /PathToYourDestinationWhereTheMakeFileIsStored
	- nmake find
-> Your find tool + its helper app will be built and executed in a few.
-> For usage instructions after the MakeFile has been run and all builds are ready type in the console:
	- help
-> To clean the text in the console just type the following in the console:
	- clear
-> Enjoy. :)