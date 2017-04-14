int size = 101;  //TODO

Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);
Eigen::MatrixXf V_vectors(size, size);
Eigen::VectorXf v1(size);
Eigen::VectorXf v2(size);
Eigen::VectorXd sumRows(size);


double prob = 1.0/6.0 ;  //TODO
unsigned int ROLLS = 27; //TODO
double max_prob_per_roll;
int pos_no;
int roll_no;


void SetTransitionMatrix()
{
	TransitionMatrix.setZero();


	V_vectors.setZero();
	max_prob_per_roll = 0.0;
	sumRows.setZero();
	pos_no = 0;
	roll_no = 0;

	//std::cout << sumRows << std::endl;
	//TODO
	for (unsigned int i = 0; i < size - 6; i++)
	{
		TransitionMatrix(i, i + 1) = prob;
		TransitionMatrix(i, i + 2) = prob;
		TransitionMatrix(i, i + 3) = prob;
		TransitionMatrix(i, i + 4) = prob;
		TransitionMatrix(i, i + 5) = prob;
		TransitionMatrix(i, i + 6) = prob;
	}
	//TransitionMatrix(size - 6, size - 6) = prob;
	TransitionMatrix(size - 6, size - 5) = prob;
	TransitionMatrix(size - 6, size - 4) = prob;
	TransitionMatrix(size - 6, size - 3) = prob;
	TransitionMatrix(size - 6, size - 2) = prob;
	TransitionMatrix(size - 6, size-1) = 2.0*prob;
	
	TransitionMatrix(size - 5, size - 4) = prob;
	TransitionMatrix(size - 5, size - 3) = prob;
	TransitionMatrix(size - 5, size - 2) = prob;
	TransitionMatrix(size - 5, size - 1) = 3.0*prob;
	
	TransitionMatrix(size - 4, size - 3) = prob;
	TransitionMatrix(size - 4, size - 2) = prob;
	TransitionMatrix(size - 4, size - 1) = 4.0*prob;

	TransitionMatrix(size - 3, size - 2) = prob;
	TransitionMatrix(size - 3, size - 1) = 5.0*prob;

	TransitionMatrix(size - 2, size - 1) = 6.0*prob;
	TransitionMatrix(size-1, size-1) = 1.0;

	//Manually implementing Snakes and Ladders
		//ladder 3 -> 19
		TransitionMatrix(0, 3) = 0.0;
		TransitionMatrix(0, 9) = TransitionMatrix(0, 9) + 1.0 / 6.0;
		TransitionMatrix(1, 3) = 0.0;
		TransitionMatrix(1, 9) = TransitionMatrix(1, 9) + 1.0 / 6.0;
		TransitionMatrix(2, 3) = 0.0;
		TransitionMatrix(2, 9) = TransitionMatrix(2, 9) + 1.0 / 6.0;
	
		//ladder 15 -> 37
		TransitionMatrix(9, 15) = 0.0;
		TransitionMatrix(9, 37) = TransitionMatrix(9, 37) + 1.0 / 6.0;
		TransitionMatrix(10, 15) = 0.0;
		TransitionMatrix(10, 37) = TransitionMatrix(10, 37) + 1.0 / 6.0;
		TransitionMatrix(11, 15) = 0.0;
		TransitionMatrix(11, 37) = TransitionMatrix(11, 37) + 1.0 / 6.0;
		TransitionMatrix(12, 15) = 0.0;
		TransitionMatrix(12, 37) = TransitionMatrix(12, 37) + 1.0 / 6.0;
		TransitionMatrix(13, 15) = 0.0;
		TransitionMatrix(13, 37) = TransitionMatrix(13, 37) + 1.0 / 6.0;
		TransitionMatrix(14, 15) = 0.0;
		TransitionMatrix(14, 37) = TransitionMatrix(14, 37) + 1.0 / 6.0;

		//Ladder 22 -> 42
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 47) = TransitionMatrix(i, 47) + TransitionMatrix(i, 22);
			TransitionMatrix(i, 22) = 0.0;
		}

		//Ladder 25 -> 64
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 64) = TransitionMatrix(i, 64) + TransitionMatrix(i, 25);
			TransitionMatrix(i, 25) = 0.0;
		}

		//Ladder 41 -> 73
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 73) = TransitionMatrix(i, 73) + TransitionMatrix(i, 41);
			TransitionMatrix(i, 41) = 0.0;
		}

		//Ladder 53 -> 74
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 74) = TransitionMatrix(i, 74) + TransitionMatrix(i, 53);
			TransitionMatrix(i, 53) = 0.0;
		}

		//Ladder 63 -> 86
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 86) = TransitionMatrix(i, 86) + TransitionMatrix(i, 63);
			TransitionMatrix(i, 63) = 0.0;
		}

		//Ladder 76 -> 91
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 91) = TransitionMatrix(i, 91) + TransitionMatrix(i, 76);
			TransitionMatrix(i, 76) = 0.0;
		}

		//Ladder 84 -> 98
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 98) = TransitionMatrix(i, 98) + TransitionMatrix(i, 84);
			TransitionMatrix(i, 84) = 0.0;
		}

		//Snake 11 -> 7
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 7) = TransitionMatrix(i, 7) + TransitionMatrix(i, 11);
			TransitionMatrix(i, 11) = 0.0;
		}

		//Snake 18 -> 13
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 13) = TransitionMatrix(i, 13) + TransitionMatrix(i, 18);
			TransitionMatrix(i, 18) = 0.0;
		}

		//Snake 28 -> 12
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 12) = TransitionMatrix(i, 12) + TransitionMatrix(i, 28);
			TransitionMatrix(i, 28) = 0.0;
		}

		//Snake 36 -> 34
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 34) = TransitionMatrix(i, 34) + TransitionMatrix(i, 36);
			TransitionMatrix(i, 36) = 0.0;
		}

		//Snake 77 -> 16
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 16) = TransitionMatrix(i, 16) + TransitionMatrix(i, 77);
			TransitionMatrix(i, 77) = 0.0;
		}

		//Snake 47 -> 26
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 26) = TransitionMatrix(i, 26) + TransitionMatrix(i, 47);
			TransitionMatrix(i, 47) = 0.0;
		}

		//Snake 83 -> 39
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 39) = TransitionMatrix(i, 39) + TransitionMatrix(i, 83);
			TransitionMatrix(i, 83) = 0.0;
		}

		//Snake 92 -> 75
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 75) = TransitionMatrix(i, 75) + TransitionMatrix(i, 92);
			TransitionMatrix(i, 92) = 0.0;
		}

		//Snake 99 -> 70
		for (unsigned i = 0; i < size; i++)
		{
			TransitionMatrix(i, 70) = TransitionMatrix(i, 70) + TransitionMatrix(i, 99);
			TransitionMatrix(i, 99) = 0.0;
		}
	//std::cout << TransitionMatrix << std::endl;

	//for (unsigned int i = 0; i < size; i++)			//for all rows,
	//{
	//	
	//for (unsigned int j = 0; j < size; j++)		//check that sum row = 1
	//	{
	//		sumRows(i) = sumRows(i) + TransitionMatrix(i, j);
	//		if (TransitionMatrix(i, j) < 0.0)
	//		{
	//			std::cout << "negative value found in row " << i << std::endl;
	//		}
	//	}
	//}
	//std::cout << sumRows << std::endl;
}