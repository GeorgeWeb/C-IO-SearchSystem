#Making sure that we are clear from any leftovers from previious builds 
#Not using * because I wanna make sure that no matter in which directory my program is stored, it will not affect any files not connected to it.
clean:
	find.obj
	find.exe
	help.obj
	help.exe
#Building our program/s
find:
#...building the find tool
	cl /Fe:find.exe files.c course.c
#...building my support app that guides you in how to use the find tool
	cl /Fe:help.exe help.c
#Default/Example command to be executed right after build using our find tool functionality
	find hello -i input.txt -o output.txt -c
#ENJOY (: