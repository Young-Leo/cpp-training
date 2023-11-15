#include <gtest/gtest.h>

#include "PriceCalculator.h"

using namespace PriceCal;

TEST(PriceCalculator, should_return_100_when_given_cash_normal_and_price_100)
{
    PriceCalculator priceCalculator;

    double cash = priceCalculator.AcceptCash(DiscountType::CASH_NORMAL, 100.0);

    EXPECT_DOUBLE_EQ(100, cash);
}