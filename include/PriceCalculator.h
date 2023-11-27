#pragma once

#include "Discount.h"

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
    class PriceCalculator final
    {
    public:
        double AcceptCash(const DiscountType discountType, const double money) const noexcept;

    private:
        friend class Discount;
        friend class Normal;
        friend class PercentOff;
        friend class CashBack;
    };
} // namespace PriceCalc