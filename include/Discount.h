#pragma once

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
    // class Discount
    // {
    // public:
    //     virtual ~Discount(){};
    //     virtual double AcceptCash(const double money) const noexcept = 0;
    // };

    class Normal final
    {
    public:
        // double AcceptCash(const double money) const noexcept override
        // {
        //     return money;
        // }
        void Reg(std::unordered_map<DiscountType, std::function<double(const double)>> &discountMap)
        {
            std::function<double(const double)> acceptCash = [](const double money) noexcept
            { return money; };
            discountMap.emplace(DiscountType::CASH_NORMAL, acceptCash);
        }
    };

    class PercentOff final
    {
    public:
        explicit PercentOff(const double rate) : rate(rate)
        {
        }
        // double AcceptCash(const double money) const noexcept override
        // {
        //     return rate * money;
        // }
        void Reg(std::unordered_map<DiscountType, std::function<double(const double)>> &discountMap)
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

    private:
        double rate;
    };

    class CashBack final
    {
    public:
        explicit CashBack(const double threshold, const double cashback) : threshold(threshold), cashback(cashback)
        {
        }
        // double AcceptCash(const double money) const noexcept override
        // {
        //     return money - std::floor(money / threshold) * cashback;
        // }
        void Reg(std::unordered_map<DiscountType, std::function<double(const double)>> &discountMap)
        {
            std::function<double(const double)> acceptCash = [this](const double money) noexcept
            { return money - std::floor(money / threshold) * cashback; };
            discountMap.emplace(DiscountType::CASH_BACK, acceptCash);
        }

    private:
        double threshold, cashback;
    };

}
