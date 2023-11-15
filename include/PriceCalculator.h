#pragma once

namespace PriceCal
{
    enum class DiscountType
    {
        CASH_NORMAL,
        CASH_90PERCENTOFF,
        CASH_80PERCENTOFF,
        CASH_70PERCENTOFF,
        CASH_BACK
    };

    class PriceCalculator final
    {
    public:
        double AcceptCash(const DiscountType type, const double money) const noexcept;
    };
}
