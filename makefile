clean:
	find.obj
	find.exe
find:
	cl /Fe:find.exe files.c course.c
	find hello -i input.txt -o output.txt -c