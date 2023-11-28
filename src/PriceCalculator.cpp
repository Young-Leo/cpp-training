#include "PriceCalculator.h"

#include <memory>
#include <unordered_map>
#include <functional>

namespace PriceCalc
{
    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        return DiscountMap::GetInstance().GetDiscount(discountType)(money);
    }
} // namespace PriceCalc