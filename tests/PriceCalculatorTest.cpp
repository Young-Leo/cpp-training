#include <gtest/gtest.h>

#include "PriceCalculator.h"

using namespace PriceCal;

// Seven test cases
TEST(PriceCalculator, should_return_100_when_given_cash_normal_and_price_100)
{
    PriceCalculator priceCalculator;

    double cash = priceCalculator.AcceptCash(DiscountType::CASH_NORMAL, 100.0);

    EXPECT_DOUBLE_EQ(100, cash);
}

TEST(PriceCalculator, should_return_90_when_given_cash_90percentoff_and_price_100)
{
    PriceCalculator priceCalculator;

    double cash = priceCalculator.AcceptCash(DiscountType::CASH_90PERCENTOFF, 100.0);

    EXPECT_DOUBLE_EQ(90, cash);
}

TEST(PriceCalculator, should_return_80_when_given_cash_80percentoff_and_price_100)
{
    PriceCalculator priceCalculator;

    double cash = priceCalculator.AcceptCash(DiscountType::CASH_80PERCENTOFF, 100.0);

    EXPECT_DOUBLE_EQ(80, cash);
}

TEST(PriceCalculator, should_return_70_when_given_cash_70percentoff_and_price_100)
{
    PriceCalculator priceCalculator;

    double cash = priceCalculator.AcceptCash(DiscountType::CASH_70PERCENTOFF, 100.0);

    EXPECT_DOUBLE_EQ(70, cash);
}

TEST(PriceCalculator, should_return_90_when_given_cash_back_and_price_90)
{
    PriceCalculator priceCalculator;

    double cash = priceCalculator.AcceptCash(DiscountType::CASH_BACK, 90.0);

    EXPECT_DOUBLE_EQ(90, cash);
}

TEST(PriceCalculator, should_return_80_when_given_cash_back_and_price_100)
{
    PriceCalculator priceCalculator;

    double cash = priceCalculator.AcceptCash(DiscountType::CASH_BACK, 100.0);

    EXPECT_DOUBLE_EQ(80, cash);
}

TEST(PriceCalculator, should_return_90_when_given_cash_back_and_price_110)
{
    PriceCalculator priceCalculator;

    double cash = priceCalculator.AcceptCash(DiscountType::CASH_BACK, 110.0);

    EXPECT_DOUBLE_EQ(90, cash);
}