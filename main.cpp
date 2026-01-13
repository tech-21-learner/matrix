#include "matrix.h";

int main()
{
	Matrix x;
	int a, b;

	while (true) 
	{
		int choice;
		
		cout << "Enter the corresponding number for your desired operation:" << endl;
		cout << "1-insert a new matrix;" << endl;
		cout << "2- add two matrix and insert the resultant matrix;" << endl;
		cout << "3- subtract a matrix from another and insert the resultant matrix;" << endl;
		cout << "4 - multiply two matrix and insert the resultant matrix;" << endl;
		cout << "5 - print all matrices;" << endl;
		cout << "6 - end the program;" << endl;
		cin >> choice;

		

		switch (choice)
		{
		case 1:
		{
			x.insert();
			break;
		}
		case 2:
		{
			cout << "There are total " << x.GetLength() << "matrices in the list.Enter which matrices you want to add:" << endl;
			cin >> a >> b;

			MatrixNode* m1 = x.FindNode(a);
			MatrixNode* m2 = x.FindNode(b);

			MatrixNode* sumNode = Add(m1, m2);
			if (sumNode != nullptr)
			{
				sumNode->next = x.matrix;
				x.matrix = sumNode;
			}
			break;
		}
		case 3:
		{
			cout << "Ther are total " << x.GetLength() << "matrices in the list.Enter minused matrix first and then subtrahend matrix:" << endl;
			cin >> a >> b;

			MatrixNode* m1 = x.FindNode(a);
			MatrixNode* m2 = x.FindNode(b);

			MatrixNode* subNode = Sub(m1, m2);
			if (subNode != nullptr)
			{
				subNode->next = x.matrix;
				x.matrix = subNode;
			}
			break;
		}
		case 4:
		{
			cout << "Ther are total " << x.GetLength() << "matrices in the list.Enter multiplicand matrix first and then multiplier matrix:" << endl;
			cin >> a >> b;

			MatrixNode* m1 = x.FindNode(a);
			MatrixNode* m2 = x.FindNode(b);

			MatrixNode* multNode = Mult(m1, m2);
			if (multNode != nullptr)
			{
				multNode->next = x.matrix;
				x.matrix = multNode;
			}
			break;
		}
		case 5:
		{
			x.Print();
			break;
		}
		case 6:
		{
			cout << "Thank you" << endl;
			return 1;
		}
		default:
		{
			cout << "Invalid input, please try again" << endl;
			break;
		}
		}
	}
	return 0;
}