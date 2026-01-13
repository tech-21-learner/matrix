#include "matrix.h" // connects the header file 

MatrixType::MatrixType() // implementing the default constructor that initalize the values of row and columns to zero
{
	values.numRows = 0;
	values.numCols = 0;
	for (int i = 0; i < MAX_ROWS; i++) // using for loop to take each entry of matrix and set it to zero
		for (int j = 0; j < MAX_COLS; j++)
			values.MatrixValue[i][j] = 0;
}

MatrixType::MatrixType(unsigned int numRows, unsigned int numCols, int MatrixValue[MAX_ROWS][MAX_COLS]) 
{
	values.numRows = numRows; // initalizes the rows and columns
	values.numCols = numCols;
	for(int i=0; i<numRows; i++)
		for(int j=0; j<numCols; j++)
        	values.MatrixValue[i][j] = MatrixValue[i][j]; // initalizes each entry of 2D matrix 
}

void MatrixType::setSize() 
{
	cout << "A matrix has been created. Enter number of rows and columns for this new matrix:" << endl;
	cin >> values.numRows; // takes user input for rows
	cout << endl; // prints the newline
	cin >> values.numCols;// takes user input for columns
	if (values.numRows > MAX_ROWS || values.numCols > MAX_COLS) // condition to check the matrix dimensions 
	{
		cout << "Invalid Matrix Size." << endl; 
	}
}

void MatrixType::setValues() // function which is used to set the entries for the user defined 2D Matrix
{
	cout << "Enter the values:" << endl; 
	for (int i = 0; i < values.numRows; i++)  
	{
		for (int j = 0; j < values.numCols; j++)
		{
			cin >> values.MatrixValue[i][j];
			cout << endl;
		}
	}
}

void MatrixType::PrintValues() const // prints each and every value of the matrix 
{
	for (int i = 0; i < values.numRows; i++)
	{
		for (int j = 0; j < values.numCols; j++)
		{
			cout << values.MatrixValue[i][j] << " ";
		}
		cout << endl; // prints the newline
	}
}

unsigned int MatrixType::GetRows() const // returns the number of rows
{
	return values.numRows;
}

unsigned int MatrixType::GetColumns() const // returns the number of columns 
{
	return values.numCols;
}

int MatrixType::GetValues(unsigned int row, unsigned int cols) const // returns the integer value for specific row and columns
{
	return values.MatrixValue[row][cols];
}

MatrixType Add(MatrixType matrix1, MatrixType matrix2) // function takes 2 parameter in order to perform the addition 
{
	int sum[MAX_ROWS][MAX_COLS] = { 0 }; // initialize and declare the sum matrix 
	if (matrix1.GetRows() == matrix2.GetRows() && matrix1.GetColumns() == matrix2.GetColumns()) // condition to check if addition of matrix is possible 
	{
		for(int i=0; i < matrix1.GetRows(); i++) // loop to access the all rows and colums
			for (int j=0; j < matrix1.GetColumns(); j++)
			{
				sum[i][j] = matrix1.GetValues(i,j) + matrix2.GetValues(i,j);// store the result in the sum matrix 
			}
	}
	MatrixType sumMatrix(matrix1.GetRows(), matrix1.GetColumns(), sum); // calls the default constructor in order to store the result
	return sumMatrix;
}

MatrixType Sub(MatrixType matrix1, MatrixType matrix2) // function takes 2 parameter in order to perform the subtraction
{
	int minus[MAX_ROWS][MAX_COLS]{};// initialize and declare the minus matrix
	if (matrix1.GetRows() == matrix2.GetRows() && matrix1.GetColumns() == matrix2.GetColumns())
	{
		for (int i = 0; i < matrix1.GetRows(); i++) // loop to access the all rows and colums
			for (int j = 0; j < matrix1.GetColumns(); j++)
			{
				minus[i][j] = matrix1.GetValues(i, j) - matrix2.GetValues(i, j);// subtract the 2 matrix and store the result in the minus
			}
	}
	MatrixType sumMatrix(matrix1.GetRows(), matrix1.GetColumns(), minus);// calls the default constructor to store the values
	return sumMatrix; // returns thr resultant matrix of type MatrixType
}

MatrixType Mult(MatrixType matrix1, MatrixType matrix2)// function takes 2 parameter in order to perform the subtraction
{
	int product[MAX_ROWS][MAX_COLS]{};// initialize and declare the product matrix
	if (matrix1.GetColumns() == matrix2.GetRows())
	{
		for (int i = 0; i < matrix1.GetRows(); i++)// loop to access the all rows and colums
			for (int j = 0; j < matrix2.GetColumns(); j++)
			{
				product[i][j] = 0;
				for (int k = 0; k < matrix1.GetColumns(); k++)
				{
					product[i][j] += matrix1.GetValues(i, k) * matrix2.GetValues(k, j);
				}
			}
	}
	MatrixType productMatrix(matrix1.GetRows(), matrix2.GetColumns(), product);// calls the default constructor to store the values
	return productMatrix; // returns thr resultant matrix of type MatrixType
}

bool AddSubCompatible(MatrixNode* matrix1, MatrixNode* matrix2) // function used to check the compabilityo matrices to perform add and sub
{
	return (matrix1->matrix.GetRows() == matrix2->matrix.GetRows() && matrix1->matrix.GetColumns() == matrix2->matrix.GetColumns());
}

bool MultCompatible(MatrixNode* matrix1, MatrixNode* matrix2)// function used to check the compabilityo matrices to perform multiply
{
	return (matrix1->matrix.GetColumns() == matrix2->matrix.GetRows());
}

Matrix::Matrix() // default constructor set matrix as null
{
	matrix = nullptr;
}

unsigned int Matrix::GetLength() const // returns the integer value stating all the number of matrices in the list
{
	int length = 0; // initalize to zero
	
	MatrixNode*temp = matrix; // declare the new pointer to the matrix 
	while (temp != nullptr) // loop until we reach at the end of linked list
	{
		length++; // increament the length
		temp = temp->next; // increament the pointer
	}
	return length; // returns the interger
}

MatrixNode* Matrix::FindNode(int n) const
{
	int index = 1;
	MatrixNode* temp = matrix;
	while (temp != nullptr)
	{
		if (index == n)
		{
			return temp;
		}
		index++;
		temp = temp->next;
	}
	return nullptr;
}

void Matrix::Print() const // prints all the matrices in linked list
{
	if (GetLength() != 0) // list is non-empty, print all the matrices.
	{
		MatrixNode* temp = matrix;
		int index = 1;
		cout << "All matrices are in the following." << endl;
		while (temp != nullptr) // loop until all matrix are printed
		{
			cout << "Matrix " << index << ":" << endl;
			temp->matrix.PrintValues(); // pointer pointes to print the matrix
			temp = temp->next; // update the pointer and index
			index++;
		}
	}
	 else // if the list is empty
	 {
		 cout << "The list is empty. Try this operation after inserting a matrix." << endl;
	}
}

void Matrix::insert() // insert matrix to the top of linked list 
{
	MatrixNode* node = new MatrixNode; // create memory space for the new matrix
	node->matrix.setSize(); // get the size and values for matrix
	node->matrix.setValues();	
	node->next = matrix; // set new matrix to top of linked list
	matrix = node;
}

MatrixNode* Add(MatrixNode* matrix1, MatrixNode* matrix2) // add the two matrices and store the result to the new matrix
{
	if (!AddSubCompatible(matrix1, matrix2)) // check the compatibility
	{ 
		cout << "The operation is not compatible." << endl;
		return nullptr;
	}
	else 
	{
		MatrixNode* sumNode = new MatrixNode; // declare the new node 
		sumNode -> matrix = Add(matrix1->matrix, matrix2->matrix); // use add function 
		sumNode->next = nullptr; 
		return sumNode;
	}
}

MatrixNode* Sub(MatrixNode* matrix1, MatrixNode* matrix2)
{
	if (!AddSubCompatible(matrix1, matrix2))// check the compatibility
	{
		cout << "The operation is not compatible." << endl;
		return nullptr;
	}
	else
	{
		MatrixNode* subNode = new MatrixNode; // declare the new node 
		subNode->matrix = Sub(matrix1->matrix, matrix2->matrix); // use sub function 
		subNode->next = nullptr;
		return subNode;
	}
}

MatrixNode* Mult(MatrixNode* matrix1, MatrixNode* matrix2)
{
	if (!MultCompatible(matrix1, matrix2))// check the compatibility
	{
		cout << "The operation is not compatible." << endl;
		return nullptr;
	}
	else
	{
		MatrixNode* multNode = new MatrixNode; // declare the new node
		multNode->matrix = Mult(matrix1->matrix, matrix2->matrix);// use nult function 
		multNode->next = nullptr;
		return multNode;
	}
}