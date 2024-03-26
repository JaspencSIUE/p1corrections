#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	bool gtg = false;
	int number = 0;
	if(argc == 4 && std::string(argv[1]) == "-a" && (std::string(argv[3]) == "+" || std::string(argv[3]) == "-"))
	{
		number = std::atoi(argv[2]);
		if(number != 0 || std::string(argv[2]) == "0")
		{
			gtg = true;
		}else{
			std::cout << "error: the second argument is not an int" << std::endl;
		}
	}else{
		std::cout << "Error: please enter -a and an int for the in and out file numbers" << std::endl;
	}
	
	if(gtg)
	{
		std::string inSMaker;
		std::string outSMaker;
		if(std::string(argv[3]) == "+")
		{
			inSMaker = "length" + std::to_string(number) + ".txt";
			outSMaker = "avg" + std::to_string(number) + ".txt";
		}else{
			inSMaker = "negLength" + std::to_string(number) + ".txt";
			outSMaker = "negAvg" + std::to_string(number) + ".txt";
		}
		std::ifstream infile(inSMaker);
		std::ofstream outfile(outSMaker);
	
		if(!infile.is_open() || !outfile.is_open())
		{
			printf("Error opening files!\n");
			return 1;
		}
		int total = 0;
		int counter = 0;
		std::string line;
		while(getline(infile, line))
		{
			total += std::stoi(line);
			counter++;
		}
		total = total / counter;
		outfile << total << std::endl;
		infile.close();
		outfile.close();
	}
	return 0;
}
