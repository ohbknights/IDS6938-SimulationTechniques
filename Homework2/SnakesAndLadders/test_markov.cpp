#include <iostream>
#include <functional>   
#include <numeric> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <Eigen\dense>

#include "markov.h"
#include "TransitionMatrix.h"

int main(){

	SetTransitionMatrix();

	//Output Vector
	v.setZero();
	//v(0) = 1.0;
	V_vectors(0, 0) = 1.0;

	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	
   // TODO add Markov vector - Matrix multiplication
	
	//std::cout << V_vectors << std::endl;
	for (unsigned int k = 0; k < ROLLS + 1; k++)
	{
		V_vectors.col(k+1) = V_vectors.col(k).transpose() * TransitionMatrix;
		//max_prob_per_roll = std::max_element(V_vectors.col(k + 1));
	}
	/*for (unsigned int i = 0; i < size + 1; i++)
	{
		for (unsigned int j = 0; j < size + 1; j++)
		{
			if (V_vectors(j, i) < max_prob_per_roll)
			{
				max_prob_per_roll = max_prob_per_roll;
				roll_no = i;
				pos_no = j;
			}
			else
			{
				max_prob_per_roll = V_vectors(j, i);
				roll_no = i;
				pos_no = j;
			}

		}

	}*/
	//std::cout << "Max element in V_vectors" << max_prob_per_roll << std::endl;
	myfile << V_vectors << std::endl;  //this is just a sample, becareful how you print to file so you can mine useful stats
	
	myfile.close();


  return 1;
}