/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** clock.cpp
*/

#include "components/clock.hpp"

Clock::Clock(double cooldown_ms, bool active, size_t delta)
{
    this->cooldown_ms = cooldown_ms;
    this->active = active;
    this->delta = delta;
    this->last_check = hr_clock::now();
}

double Clock::getTimeElapsed(void)
{
    return std::chrono::duration_cast<ms>(hr_clock::now() - last_check).count();
}

bool Clock::checkCooldown(void)
{
    if (active && getTimeElapsed() > cooldown_ms) {
        last_check = hr_clock::now();
        return true;
    }
    return false;
}
