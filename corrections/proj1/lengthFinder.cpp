#include <iostream>
#include <string>
#include <fstream>
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
			std::cout << "Error: the second argument is not an integer" << std::endl;
		}
	}else{
		std::cout << "Error: please enter -a and a integer and either a + or a -" << std::endl;
	}

	if(gtg)
	{
		std::string inSMaker;
		std::string outSMaker;
		std::string seqSMaker;
		if(std::string(argv[3]) == "+")
		{
			inSMaker = "output" + std::to_string(number) + ".txt";
			outSMaker = "length" + std::to_string(number) + ".txt";
			seqSMaker = "seq" + std::to_string(number) + ".txt";
		}else{
			inSMaker = "negative" + std::to_string(number) + ".txt";
			outSMaker = "negLength" + std::to_string(number) + ".txt";
			seqSMaker = "negSeq" + std::to_string(number) + ".txt";
		}
		std::ifstream infile(inSMaker);
		std::ofstream outfile(outSMaker);
		std::ofstream outseq(seqSMaker);
		if(!infile.is_open() || !outfile.is_open())
		{
			printf("Error opening files!");
			return 1;
		}
		std::string line;
		while(getline(infile, line))
		{
			if(line.rfind(">chr1:", 0) == 0)
			{
				size_t colonPos = line.find(':');
				size_t dashPos = line.find('-', colonPos);
				if(colonPos != std::string::npos && dashPos != std::string::npos)
				{
					int start = std::stoi(line.substr(colonPos + 1, dashPos - colonPos - 1));
					int end = std::stoi(line.substr(dashPos + 1));
					int length = end - start;

					outfile << length << std::endl;
				}
			}else{
				outseq << line << std::endl;
			}
		}
		infile.close();
		outfile.close();
	}
	return 0;
}
