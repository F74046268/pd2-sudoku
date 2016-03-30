giveQuestion:Sudoku.o giveQuestion.o
	g++ -o giveQuestion giveQuestion.o Sudoku.o

solve:Sudoku.o solve.o
	g++ -o solve solve.o Sudoku.o

transform:Sudoku.o transform.o
	g++ -o transform transform.o Sudoku.o

giveQuestion.o:giveQuestion.cpp Sudoku.h
	g++ -c giveQuestion.cpp

solve.o:solve.cpp Sudoku.h
	g++ -c solve.cpp

transform.o:transform.cpp Sudoku.h
	g++ -c transform.cpp

Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp


