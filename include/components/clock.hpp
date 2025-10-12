/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** clock.hpp
*/

#ifndef CLOCK_HPP_
    #define CLOCK_HPP_

    #include <chrono>

typedef std::chrono::high_resolution_clock hr_clock;
typedef std::chrono::time_point<hr_clock> hr_time_point;
typedef std::chrono::milliseconds ms;

struct Clock {
    Clock(double cooldown_ms, bool active = true, size_t delta = 0);
    bool active;
    size_t delta;
    double cooldown_ms;
    hr_time_point last_check;
    
    double getTimeElapsed(void);
    bool checkCooldown(void);
};

#endif