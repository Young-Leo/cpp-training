#include "PriceCalculator.h"

namespace PriceCal
{
    double PriceCalculator::AcceptCash(const DiscountType type, const double money) const noexcept
    {
        double cash = 0.0;
        switch (type)
        {
        case DiscountType::CASH_NORMAL:
        {
            cash = money;
            break;
        }
        case DiscountType::CASH_90PERCENTOFF:
        {
            cash = money * 0.9;
            break;
        }
        case DiscountType::CASH_80PERCENTOFF:
        {
            cash = money * 0.8;
            break;
        }
        case DiscountType::CASH_70PERCENTOFF:
        {
            cash = money * 0.7;
            break;
        }
        case DiscountType::CASH_BACK:
        {
            cash = (money >= 100) ? money - 20 : money;
            break;
        }
        default:
        {
            break;
        }
        }
        return cash;
    }
}
