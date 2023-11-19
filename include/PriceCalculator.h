#pragma once

#include <cmath>

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
        class Discount
        {
        public:
            virtual ~Discount(){};
            virtual double AcceptCash(const double money) const noexcept = 0;
        };

        class Normal final : public Discount
        {
        public:
            double AcceptCash(const double money) const noexcept override
            {
                return money;
            }
        };

        class PercentOff final : public Discount
        {

        public:
            explicit PercentOff(const double rate) : rate(rate)
            {
            }
            double AcceptCash(const double money) const noexcept override
            {
                return money * rate;
            }

        private:
            double rate;
        };

        class CashBack final : public Discount
        {

        public:
            double AcceptCash(const double money) const noexcept override
            {
                const double threshold = 100.0;
                const double cashback = 20.0;
                return money - std::floor(money / threshold) * cashback;
            }
        };
    };
} // namespace PriceCalc