#Making sure that we are clear from any leftovers from previious builds 
#Not using * because I wanna make sure that no matter in which directory my program is stored, it will not affect any files not connected to it.
clean:
	find.obj
	find.exe
	help.obj
	help.exe
	clear.obj
	clear.exe
#Building our program/s
find:
#...building the find tool
	cl /Fe:find.exe files.c course.c
#...building a helper - my support app that guides you in how to use the find tool
	cl /Fe:help.exe help.c
#...building another helper - clear tool, so we can clean the console at some point if it gets too filled...
	cl /Fe:clear.exe clear.c
#Default/Example command(s) to be executed right after build using our find tool functionality
	find hello -i input.txt -o output.txt
	find hello -i input.txt -o output.txt -c
#ENJOY (: