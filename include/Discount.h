#pragma once

#include <iostream>
#include <cmath>
#include <functional>
#include <unordered_map>

enum class DiscountType
{
    CASH_NORMAL,
    CASH_PERCENTOFF_10,
    CASH_PERCENTOFF_20,
    CASH_PERCENTOFF_30,
    CASH_BACK,
};

namespace PriceCalc
{

    class Normal final
    {
    public:
        void Reg(std::unordered_map<DiscountType, std::function<double(const double)>> &discountMap);
    };

    class PercentOff final
    {
    public:
        explicit PercentOff(const double rate);
        void Reg(std::unordered_map<DiscountType, std::function<double(const double)>> &discountMap);

    private:
        double rate;
    };

    class CashBack final
    {
    public:
        explicit CashBack(double threshold, double cashback);
        void Reg(std::unordered_map<DiscountType, std::function<double(const double)>> &discountMap);

    private:
        double threshold, cashback;
    };
}
