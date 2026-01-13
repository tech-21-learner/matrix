#pragma once // connecting the files

#include <iostream> // including the libraries
using namespace std;

const unsigned int MAX_ROWS = 10;//declaring the maximum rows and columns of 2D Matrix 
const unsigned int MAX_COLS = 10;

struct MatrixValues // declaring user defined datatype, which have the field numRows,NumCols and 2D Array  
{
	unsigned int numRows;
	unsigned int numCols;
	int MatrixValue[MAX_ROWS][MAX_COLS];
};

class MatrixType // creating class  
{
	MatrixValues values; // private field, which is instance of MatrixValues datatype

public:
	MatrixType(); // default constructor
	MatrixType(unsigned int numRows, unsigned int numCols, int MatrixValue[MAX_ROWS][MAX_COLS]); // constructor having 3 parameters which defines all fields of adstruct datatype
	void setSize(); // member function defines size of array
	void setValues(); // member function which get each entry value from the user
	void PrintValues() const; // function which print 2D matrix on console
	unsigned int GetRows() const; // function returns the row value
	unsigned int GetColumns() const; // function returns the columns value
	int GetValues(unsigned int row, unsigned int cols) const; // funtion that returns the each entry
};

MatrixType Add(MatrixType matrix1, MatrixType matrix2); // Non-Member functions of type MatrixType returns the resultant matrix after add,sub and multiplication
MatrixType Sub(MatrixType matrix1, MatrixType matrix2);
MatrixType Mult(MatrixType matrix1, MatrixType matrix2);

struct MatrixNode // user defined datatype having 2 fields, matrix of type MatrixType and pointer  
{
	MatrixType matrix;
	MatrixNode* next {};
};
// function to check the comptability of matrix while performing the add,sub,mul using the pointers 
bool AddSubCompatible(MatrixNode* matrix1, MatrixNode* matrix2);
bool MultCompatible(MatrixNode* matrix1, MatrixNode* matrix2);

class Matrix // creating abstruct datatype using class keyword
{
public:
	MatrixNode* matrix; // declaring pointer of type MatrixNode
	Matrix(); // default constructor
	unsigned int GetLength() const; // function returns the number of matrix in the list
	MatrixNode* FindNode(int n) const; // funtion used to find the specific type of the matirx node
	void Print() const; // print the whole matrix linked list
	void insert(); // function used to add matrix on the top of linked list
};
// add the 2 object of MatrixNode type and returns result as an object of MatrixNode 
MatrixNode* Add(MatrixNode* matrix1, MatrixNode* matrix2);
// subtract the 2 object of MatrixNode type and returns result as an object of MatrixNode
MatrixNode* Sub(MatrixNode* matrix1, MatrixNode* matrix2);
// multiply the 2 object of MatrixNode type and returns result as an object of MatrixNode
MatrixNode* Mult(MatrixNode* matrix1, MatrixNode* matrix2);