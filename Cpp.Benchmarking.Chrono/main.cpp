#include <iostream>
#include <chrono>
#include <windows.h>

using namespace std;

//g++ -std=c++17 "main.cpp" -o main
//g++ -std=c++14 "main.cpp" -o main

int main(int argc, char** argv)
{
	///////////////////////////////////////////////////////////////////// Start chrono
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::time_t start_time = std::chrono::system_clock::to_time_t(start);
	char startStr[26];
	ctime_s(startStr, sizeof startStr, &start_time);
	std::cout << "Started computation at " << startStr;

	///////////////////////////////////////////////////////////////////// Start long task

	Sleep(3000);

	///////////////////////////////////////////////////////////////////// Finish chrono
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	char endStr[26];
	ctime_s(endStr, sizeof endStr, &end_time);
	std::cout << "Finished computation at " << endStr;

	std::chrono::duration<double> elapsed_time = end - start;
	double count = elapsed_time.count();
	std::cout << "Task took: " << count << ((count > 1.0) ? " seconds\n" : " milliseconds\n");

	///////////////////////////////////////////////////////////////////// End of measurements

    return 0;
}