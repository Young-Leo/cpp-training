#include "PriceCalculator.h"

#include <memory>
#include <unordered_map>
#include <functional>

namespace PriceCalc
{
    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        std::unordered_map<DiscountType, std::function<double(const double)>> discountMap;
        Normal normal;
        normal.Reg(discountMap);

        PercentOff percentoff10(0.9);
        percentoff10.Reg(discountMap);

        PercentOff percentoff20(0.8);
        percentoff20.Reg(discountMap);

        PercentOff percentoff30(0.7);
        percentoff30.Reg(discountMap);

        CashBack cashback(100, 20);
        cashback.Reg(discountMap);
        // discountMap.emplace(DiscountType::CASH_NORMAL, std::make_unique<Normal>());
        // discountMap.emplace(DiscountType::CASH_PERCENTOFF_10, std::make_unique<PercentOff>(0.9));
        // discountMap.emplace(DiscountType::CASH_PERCENTOFF_20, std::make_unique<PercentOff>(0.8));
        // discountMap.emplace(DiscountType::CASH_PERCENTOFF_30, std::make_unique<PercentOff>(0.7));
        // discountMap.emplace(DiscountType::CASH_BACK, std::make_unique<CashBack>(100, 20));

        // return discountMap.find(discountType)->second->AcceptCash(money);
        return discountMap.find(discountType)->second(money);
    }
} // namespace PriceCalc