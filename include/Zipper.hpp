/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** Zipper.hpp
*/

#ifndef ZIPPER_ITERATOR_HPP_
    #define ZIPPER_ITERATOR_HPP_

    #include <tuple>

template <class... Containers>
class Zipper;

template <class... Containers>
class ZipperIterator {
    public:
        using value_type = std::tuple<Containers&...>;
        using reference = value_type;
        using pointer = void;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        friend Zipper<Containers ...>;
        ZipperIterator(const value_type& it_tuple, size_t max) : _current(it_tuple), _max(max) {}

    public:
        ZipperIterator(const ZipperIterator& z) = default;
        ZipperIterator& operator++() {
            ++_current;
            return *this;
        }
        ZipperIterator operator++(int) {
            ZipperIterator tmp = *this;
            ++_current;
            return tmp;
        }
        value_type operator*() {
            return *_current;
        }
        value_type operator->() {
            return _current;
        }
        friend bool operator==(const ZipperIterator& lhs,
            const ZipperIterator& rhs) {
            return lhs._current == rhs._current;
        }
        friend bool operator!=(const ZipperIterator& lhs,
            const ZipperIterator& rhs) {
            return lhs._current != rhs._current;
        }

    private:
        template<size_t... Is>
        void incr_all(std::index_sequence<Is ...>) {

        }

        template<size_t... Is>
        bool all_set(std::index_sequence<Is ...>) {

        }

        template<size_t... Is>
        value_type to_value(std::index_sequence<Is ...>) {

        }

    private:
        value_type _current;
        size_t _max;
        size_t _idx;
        static constexpr std::index_sequence_for<Containers ...> _seq {};
};

template <class... Containers>
class Zipper {
    public:
        using iterator = ZipperIterator<Containers...>;
        using iterator_tuple = typename iterator::iterator_tuple;

        Zipper(Containers&... cs) {
            _begin = cs;
        }
        iterator begin() {
            return _begin;
        }
        iterator end() {
            return _end;
        }

    private:
        static size_t _compute_size(Containers&... containers) {

        }
        static iterator_tuple _compute_end(Containers&... containers) {

        }

    private:
        iterator_tuple _begin;
        iterator_tuple _end;
        size_t _size;
};

#endif