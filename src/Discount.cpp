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
    CashBack::CashBack(const double threshold, const double cashback) : threshold(threshold), cashback(cashback)
    {
    }
    double CashBack::AcceptCash(const double money) const noexcept
    {
        return money - std::floor(money / threshold) * cashback;
    }
}
