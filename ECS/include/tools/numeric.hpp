/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** numeric.hpp
*/

#ifndef NUMERIC_HPP_
    #define NUMERIC_HPP_

template<typename Val>
concept numeric = std::is_integral_v<Val> || std::is_floating_point_v<Val>;

#endif