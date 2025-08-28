#pragma once
#include "Dictionary.hpp"
#include <cstddef>
#include <vector>


class SortedVectorDict :
        public Dictionary {
    public:
        void insert(int value) override;
        bool lookup(int value) const override;
        void remove(int value) override;
    private:
        std::vector<int> data;
};