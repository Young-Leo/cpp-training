#include "Discount.h"
#include <cmath>
#include <iostream>

namespace PriceCalc
{

    void Normal::Reg(std::unordered_map<DiscountType, std::function<double(const double)>> &discountMap)
    {
        std::function<double(const double)> acceptCash = [](const double money) noexcept
        { return money; };
        discountMap.emplace(DiscountType::CASH_NORMAL, acceptCash);
    }

    PercentOff::PercentOff(const double rate) : rate(rate) {}

    void PercentOff::Reg(std::unordered_map<DiscountType, std::function<double(const double)>> &discountMap)
    {
        std::function<double(const double)> acceptCash = [this](const double money) noexcept
        { return rate * money; };
        if (rate == 0.9)
            discountMap.emplace(DiscountType::CASH_PERCENTOFF_10, acceptCash);
        else if (rate == 0.8)
            discountMap.emplace(DiscountType::CASH_PERCENTOFF_20, acceptCash);
        else if (rate == 0.7)
            discountMap.emplace(DiscountType::CASH_PERCENTOFF_30, acceptCash);
    }

    CashBack::CashBack(double threshold, double cashback) : threshold(threshold), cashback(cashback) {}
    void CashBack::Reg(std::unordered_map<DiscountType, std::function<double(const double)>> &discountMap)
    {
        std::function<double(const double)> acceptCash = [this](const double money) noexcept
        {
            return money - std::floor(money / threshold) * cashback;
        };
        discountMap.emplace(DiscountType::CASH_BACK, acceptCash);
    }
}
