#pragma once

namespace PriceCalc
{
    class Discount
    {
    public:
        virtual ~Discount(){};
        virtual double AcceptCash(const double money) const noexcept = 0;
    };

    class Normal final : public Discount
    {
    public:
        double AcceptCash(const double money) const noexcept override;
    };

    class PercentOff final : public Discount
    {
    public:
        explicit PercentOff(const double rate);
        double AcceptCash(const double money) const noexcept override;

    private:
        double rate;
    };

    class CashBack final : public Discount
    {
    public:
        double AcceptCash(const double money) const noexcept override;
    };
}
