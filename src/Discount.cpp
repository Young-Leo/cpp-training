#include "Discount.h"
#include <cmath>

namespace PriceCalc
{

    double Normal::AcceptCash(const double money) const noexcept
    {
        return money;
    }
    PercentOff::PercentOff(const double rate) : rate(rate)
    {
    }
    double PercentOff::AcceptCash(const double money) const noexcept
    {
        return money * rate;
    }
    double CashBack::AcceptCash(const double money) const noexcept
    {
        const double threshold = 100.0;
        const double cashback = 20.0;
        return money - std::floor(money / threshold) * cashback;
    }
}
