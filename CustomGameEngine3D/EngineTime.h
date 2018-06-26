#pragma once

#include <SDL/SDL_timer.h>
#include <chrono>

static auto g_start_time = std::chrono::high_resolution_clock::now();

class EngineTime
{
public:
	static long GetTime()
	{
		auto g_finish_time = std::chrono::high_resolution_clock::now();
		long time = std::chrono::duration_cast<std::chrono::nanoseconds>(g_finish_time - g_start_time).count();

		return time;
	}

	static double GetDelta() {
		return ms_delta;
	}

	static void SetDelta(const double _delta) {
		ms_delta = _delta;
	}

	const static long SECOND = 1000000000L;

private:
	static double ms_delta;
};