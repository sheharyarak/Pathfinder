#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>
// #include <thread>

struct Timer{
	std::string name;
	std::chrono::system_clock::time_point start, end;
	std::chrono::duration<float> duration;
	Timer(std::string name){
		this->name = name;
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << "[" << name << "]" << " : " << duration.count() << "s." <<std::endl;
	}
	void	age(std::string name)
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << "[" << name << "]" << " : " << duration.count() << "s." <<std::endl;
	}
	void	reset()
	{
		start = std::chrono::high_resolution_clock::now();
	}
};

#endif
