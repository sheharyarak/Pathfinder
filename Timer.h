#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>
// #include <thread>

// Timer class used to benchmark programs
struct Timer{
	// Name of timer
	std::string name;
	// start and end points
	std::chrono::steady_clock::time_point start, end;
	// duration
	std::chrono::duration<float> duration;
	// constructor thats sets the start points
	Timer(std::string name){
		this->name = name;
		start = std::chrono::high_resolution_clock::now();
	}
	// destructor thats sets end point, calulates duration,
	//  and prints out the time the object was alive.
	// perfect for benchmarking functions
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << "[" << name << "]" << " : " << duration.count() << "s." <<std::endl;
	}
	// prints the age of the object
	void	age(std::string name)
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << "[" << name << "]" << " : " << duration.count() << "s." <<std::endl;
	}
	// resets the start to current time
	void	reset()
	{
		start = std::chrono::high_resolution_clock::now();
	}
};

#endif
