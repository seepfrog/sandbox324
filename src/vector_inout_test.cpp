#include <vector>
#include <iostream>
#include <fstream>


int main(){
	std::vector<long> enc;
	for (int i = 0; i < 10; i++) {
		enc.push_back(i);
	}

	std::ofstream outputfile("test.txt");

	for ( long data : enc)
	{
		outputfile << data << "\n";
	}

	outputfile.close();

    return 0;
}
