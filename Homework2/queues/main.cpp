/*

A simple program that simulates 5 MM1 queues at an airport. The first queue

feeds 3 other queues that work in parallel. These feed a final queue.

Simulation runs until error below threshold and, at the end,

a performance evaluation report is shown, and logs are generated

for plotting and analysis.

*/



using namespace std;



#include <random>

#include "customer.h"

#include "mm1_queue.h"





std::random_device rd;



void pause()

{

	std::string sInputString;

	// Wait for input from stdin (the keyboard)

	cout << "Continue (y)?";

	std::cin >> sInputString;

}


int main(int argc, char* argv[])

{

	int next = 0;

	//   test_random_number_generator();

	
	for (int cur_lambda = 3; cur_lambda < 34; cur_lambda++)

	{
		//TODO Create MM1_Queue objects to capture the airport senario.
		
		//************************************************************
		std::cout << "lambda " << cur_lambda << std::endl;
		MM1_Queue CUST_IDCONTROL;
		CUST_IDCONTROL.set_file_names("01_log.txt", "01_wait.txt", "01_service.txt");
		CUST_IDCONTROL.set_lambda(cur_lambda); 
		CUST_IDCONTROL.set_mu(53);
		CUST_IDCONTROL.initialize();
		CUST_IDCONTROL.set_seed(1, rd());
		CUST_IDCONTROL.is_within_confidence_interval();

		MM1_Queue CUST_SECURITY1;
		CUST_SECURITY1.set_file_names("02_log.txt", "02_wait.txt", "02_service.txt");
		CUST_SECURITY1.set_lambda(cur_lambda/3);
		CUST_SECURITY1.set_mu(20);
		CUST_SECURITY1.autogenerate_new_arrivals(false);
		CUST_SECURITY1.initialize();
		CUST_SECURITY1.set_seed(rd(), rd()); 
		

		MM1_Queue CUST_SECURITY2;
		CUST_SECURITY2.set_file_names("03_log.txt", "03_wait.txt", "03_service.txt");
		CUST_SECURITY2.set_lambda(cur_lambda/3);
		CUST_SECURITY2.set_mu(20);
		CUST_SECURITY2.autogenerate_new_arrivals(false);
		CUST_SECURITY2.initialize();
		CUST_SECURITY2.set_seed(rd(), rd()); 
		

		MM1_Queue CUST_SECURITY3;
		CUST_SECURITY3.set_file_names("04_log.txt", "04_wait.txt", "04_service.txt");
		CUST_SECURITY3.set_lambda(cur_lambda/3);
		CUST_SECURITY3.set_mu(20);
		CUST_SECURITY3.autogenerate_new_arrivals(false);
		CUST_SECURITY3.initialize();
		CUST_SECURITY3.set_seed(rd(), rd()); 
		

		MM1_Queue CUST_BOARDING;
		CUST_BOARDING.set_file_names("05_log.txt", "05_wait.txt", "05_service.txt");
		CUST_BOARDING.set_lambda(cur_lambda); 
		CUST_BOARDING.set_mu(80);
		//CUST_BOARDING.autogenerate_new_arrivals(false);
		CUST_BOARDING.initialize();
		CUST_BOARDING.set_seed(rd(), rd());
		

		for (;

			//TODO: add is_within_error_range check
			!CUST_IDCONTROL.is_within_error_range(0.002) ||
			!CUST_SECURITY1.is_within_error_range(0.002) ||
			!CUST_SECURITY2.is_within_error_range(0.002) ||
			!CUST_SECURITY3.is_within_error_range(0.002) ||
			!CUST_BOARDING.is_within_error_range(0.002)
			;)

		{

			Customer cust = CUST_IDCONTROL.process_next_event();   // =  TODO: process next event;
			Customer cust2 = CUST_SECURITY1.process_next_event();   // =  TODO: process next event;
			Customer cust3 = CUST_SECURITY2.process_next_event();   // =  TODO: process next event;
			Customer cust4 = CUST_SECURITY3.process_next_event();   // =  TODO: process next event;
			Customer cust5 = CUST_BOARDING.process_next_event();    //TODO: one more process_next_event for the last object.



			if (cust.get_type() == Customer::COMPLETED())

			{
				switch (next)

				{

				case 0:

					//TODO add_external_arrival() for your security gates;
					CUST_SECURITY1.add_external_arrival();
					break;

				case 1:

					//TODO add_external_arrival() for your security gates;
					CUST_SECURITY2.add_external_arrival();
					break;

				case 2:

					//TODO add_external_arrival() for your security gates;
					CUST_SECURITY3.add_external_arrival();
					break;

				}

				next++;

				if (next % 3 == 0) next = 0;

			}

			if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED())

			{
				//TODO add_external_arrival(); on your final boarding MM1_Queue object
				CUST_BOARDING.add_external_arrival();
			}

		}


		//TODO Output statistics airport senario.


		CUST_IDCONTROL.output(); cout << "*********" << endl;
		CUST_IDCONTROL.get_current_time();
		CUST_IDCONTROL.plot_results_output();
		std::cout << "sec1 stats" << std::endl;
		CUST_SECURITY1.output(); cout << "*********" << endl;
		CUST_SECURITY1.get_current_time();

		std::cout << "sec2 stats" << std::endl;
		CUST_SECURITY2.output(); cout << "*********" << endl;
		CUST_SECURITY2.get_current_time();

		std::cout << "sec3 stats" << std::endl;
		CUST_SECURITY3.output(); cout << "*********" << endl;
		CUST_SECURITY3.get_current_time();

		std::cout << "Boarding stats" << std::endl;
		CUST_BOARDING.output(); cout << "*********" << endl;
		CUST_BOARDING.get_current_time();
		

		//**************************************************************************


		}

	
	return(0);
	
}
