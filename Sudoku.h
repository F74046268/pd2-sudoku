#include <iostream>
using namespace std;
class Sudoku{
	public:
		void giveQuestion();
		void setQuestion(int *map);
		void readIn();
		void solve();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
	    static const int  sudokuSize=9;
	private:
		int map[sudokuSize][sudokuSize];
		bool checkUnity(int *unity, int a, int b);
		void checkPossible(int row, int column);
		bool Validable();
		void back(int &i, int &j);
		void getFirst(int &i, int &j);
		void getNext(int &i, int &j);
		int arr[9][9];
		int unity[9];
		int temp[9][9];
		int answer[9][9];
		bool possible[9][9][9];
};
