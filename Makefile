run: main.c functions.c
	gcc main.c functions.c -o fourth.exe
	fourth.exe 

test: test.c functions.c
	gcc test.c functions.c -o test.exe
	test.exe