#ifdef _DEBUG
#include "gtest\gtest.h"
#include "BigFloat.h"

TEST(testBigFloatCreate, normalTest)
{
	ASSERT_TRUE(BigFloat(12345678).toString() == "12345678");
	ASSERT_TRUE(BigFloat(-1234567).toString() == "-1234567");
	ASSERT_TRUE(BigFloat("123456789123456789.123456789").toString() == "123456789123456789.123456789");
	ASSERT_TRUE(BigFloat("01234567890.123456789").toString() == "1234567890.123456789");
	ASSERT_TRUE(BigFloat("-01234567890.123456789").toString() == "-1234567890.123456789");
}

TEST(testBigFloatCompare, normalTest)
{
	ASSERT_TRUE(BigFloat() == BigFloat());
	ASSERT_TRUE(BigFloat(0) != BigFloat(1));
	ASSERT_TRUE(BigFloat("123456789123456789.123456789") == BigFloat("000123456789123456789.12345678900000"));
	ASSERT_TRUE(BigFloat("123") == BigFloat("00123"));
}

TEST(testBigFloatAdd, normalTest)
{
	ASSERT_TRUE(BigFloat(0) + BigFloat(1) == BigFloat(1));
	ASSERT_TRUE(BigFloat(1234567890) + BigFloat(987654) == BigFloat("1235555544"));
	ASSERT_TRUE(BigFloat("1.849637882") + BigFloat("13.598407630") == BigFloat("15.448045512"));
	ASSERT_TRUE(BigFloat("-1.849637882") + BigFloat("-13.598407630") == BigFloat("-15.448045512"));
	ASSERT_TRUE(BigFloat("232.2168576") + BigFloat("-8927.954312") == BigFloat("-8695.7374544"));
	ASSERT_TRUE(BigFloat("-232.2168576") + BigFloat("8927.954312") == BigFloat("8695.7374544"));
}

TEST(testBigFloatSub, normalTest)
{
	ASSERT_TRUE(BigFloat(1) - BigFloat(0) == BigFloat(1));
	ASSERT_TRUE(BigFloat("1235555544") - BigFloat(987654) == BigFloat("1234567890"));
	ASSERT_TRUE(BigFloat("232.2168576") - BigFloat("8927.954312") == BigFloat("-8695.7374544"));
	ASSERT_TRUE(BigFloat("0") - BigFloat("8695.7374544") == BigFloat("-8695.7374544"));
}

TEST(testLargeIntMul, normalTest1)
{
	ASSERT_TRUE(BigFloat(1) * BigFloat(2) == BigFloat(2));
	ASSERT_TRUE(BigFloat(1234567890) * BigFloat(0) == BigFloat(0));
	ASSERT_TRUE(BigFloat(1234567890) * BigFloat(987654) == BigFloat("1219325914830060"));
	ASSERT_TRUE(BigFloat("898.4143988") * BigFloat("0.877838371") == BigFloat("788.6626323255363548"));
}

TEST(testBigFloatDiv, normalTest)
{
		ASSERT_TRUE(BigFloat(2) / BigFloat(1) == BigFloat(2));
		try {
			ASSERT_TRUE(BigFloat(2) / BigFloat(0) == BigFloat(2));
		}
		catch (ZeroException e) {
			e.error();
		}

		ASSERT_TRUE(BigFloat("1219325914830060") / BigFloat("1234567890") == BigFloat(987654));
		ASSERT_TRUE(BigFloat("1219325914830060") / BigFloat(987654) == BigFloat("1234567890"));
		ASSERT_TRUE(BigFloat("1219325914830060") / BigFloat("1") == BigFloat("1219325914830060"));
		ASSERT_TRUE(BigFloat("315649816498164761562056488065489561.036849876300254661") / BigFloat("1.00") == BigFloat("315649816498164761562056488065489561.036849876300254661"));

	

}
#endif