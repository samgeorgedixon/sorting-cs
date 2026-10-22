#pragma once

#include <iostream>
#include <chrono>

#ifdef SORT_DISABLE_LOGGING
	#define SORT_LOG(x)
	#define SORT_TIME(x)
	#define SORT_TIME_END(x, msg)
#else
	#define SORT_LOG(...) printf(__VA_ARGS__)
	#define SORT_TIME(x) std::chrono::steady_clock::time_point x = std::chrono::high_resolution_clock::now()
	#define SORT_TIME_END(x, msg) SORT_LOG("Time - " << msg << ": " << (float)std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - x).count() << " us \n");
#endif
