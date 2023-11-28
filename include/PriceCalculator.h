#pragma once

#include "Discount.h"

namespace PriceCalc
{
    class PriceCalculator final
    {
    public:
        double AcceptCash(const DiscountType discountType, const double money) const noexcept;

    private:
        // friend class Discount;
        friend class Normal;
        friend class PercentOff;
        friend class CashBack;
    };
} // namespace PriceCalc