#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

//193 = avg;
int main(int argc, char* argv[])
{
	bool gtgChk = true;

	if(argc == 4 && std::string(argv[1]) == "-a" && (std::string(argv[3]) == "+" || std::string(argv[3]) == "-"))
	{
		int number = std::atoi(argv[2]);
		if(number != 0 || std::string(argv[2]) == "0")
		{
			std::string avgSMaker;
			std::string inSMaker;
			std::string outSMaker;
			if(std::string(argv[3]) == "+")
			{
				avgSMaker = "avg" + std::to_string(number) + ".txt";
				inSMaker = "output" + std::to_string(number) + ".txt";
				outSMaker = "final" + std::to_string(number) + ".txt";
			}else{
				avgSMaker = "negAvg" + std::to_string(number) + ".txt";
				inSMaker = "negative" + std::to_string(number) + ".txt";
				outSMaker = "negFinal" + std::to_string(number) + ".txt";
			}
			std::ifstream avgInFile(avgSMaker);
			std::ifstream infile(inSMaker);
			std::ofstream outfile(outSMaker);

			if(!infile.is_open() || !outfile.is_open() || !avgInFile.is_open())
			{
				std::cerr << "Error opening files!" << std::endl;
				return 1;
			}
			std::string avgS;
			getline(avgInFile, avgS);
			int avg = std::stoi(avgS);
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
						if(length < avg)
						{
							gtgChk = false;
						}else{
							gtgChk = true;
						}
					}
				}else{

					if(gtgChk)
					{
						outfile << line.substr(0, avg) << std::endl;
					}
				}
			}
			infile.close();
			avgInFile.close();
			outfile.close();
		}else{
			std::cout << "Error: please enter an integer after -a " <<std::endl;
		}
	}else{
		std::cout << "Error: please enter -a (int)  " << std::endl;
	}

	return 0;
}
