#include "PriceCalculator.h"

#include <memory>
#include <unordered_map>
#include <functional>

namespace PriceCalc
{
    class DiscountMap
    {
    public:
        static DiscountMap &GetInstance()
        {
            static DiscountMap instance;
            return instance;
        }

        std::function<double(const double)> &GetDiscount(const DiscountType discountType)
        {
            return discountMap[discountType];
        }

    private:
        DiscountMap()
        {
            std::shared_ptr<Normal> normal = std::make_shared<Normal>();
            normal->Reg(discountMap);

            std::shared_ptr<PercentOff> percentoff10 = std::make_shared<PercentOff>(0.9);
            percentoff10->Reg(discountMap);

            std::shared_ptr<PercentOff> percentoff20 = std::make_shared<PercentOff>(0.8);
            percentoff20->Reg(discountMap);

            std::shared_ptr<PercentOff> percentoff30 = std::make_shared<PercentOff>(0.7);
            percentoff30->Reg(discountMap);

            std::shared_ptr<CashBack> cashback = std::make_shared<CashBack>(100.0, 20.0);
            cashback->Reg(discountMap);
        }

        std::unordered_map<DiscountType, std::function<double(const double)>> discountMap;
    };

    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        return DiscountMap::GetInstance().GetDiscount(discountType)(money);
    }
} // namespace PriceCalc