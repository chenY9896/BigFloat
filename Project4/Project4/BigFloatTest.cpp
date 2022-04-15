#ifdef _DEBUG
#include "gtest\gtest.h"
#include "BigFloat.h"
#include <Windows.h> 

TEST(testBigFloatCreate, normalTest)
{
	ASSERT_TRUE(BigFloat().toString() == "0");
	ASSERT_TRUE(BigFloat("").toString() == "0");
	
	ASSERT_TRUE(BigFloat(123456789).toString() == "123456789");
	ASSERT_TRUE(BigFloat(-123456789).toString() == "-123456789");
	ASSERT_TRUE(BigFloat("12345678900").toString() == "12345678900");
	ASSERT_TRUE(BigFloat("-12345678900").toString() == "-12345678900");

	ASSERT_TRUE(BigFloat("00012345678901234567890.123456789123456789").toString() == "12345678901234567890.123456789123456789");
	ASSERT_TRUE(BigFloat("000000.000000012345678901234567890").toString() == "0.00000001234567890123456789");
	ASSERT_TRUE(BigFloat("-0000001234567890.12345678900000").toString() == "-1234567890.123456789");
	ASSERT_TRUE(BigFloat("-0000000000.000000000012345678901234567890").toString() == "-0.00000000001234567890123456789");
}
TEST(testBigFloatCompare, normalTest)
{
	ASSERT_TRUE(BigFloat() == BigFloat());
	ASSERT_TRUE(BigFloat(0) != BigFloat(1));
	ASSERT_TRUE(BigFloat(1) > BigFloat(0));
	ASSERT_TRUE(BigFloat("123") == BigFloat("00123"));
}
TEST(testBigFloatAdd, normalTest)
{
	ASSERT_TRUE(BigFloat(0) + BigFloat(1) == BigFloat(1));
	ASSERT_TRUE(BigFloat() + BigFloat("") == BigFloat(0));
	ASSERT_TRUE(BigFloat("7605238944.5970453086") + BigFloat("12846.402760423075135") == BigFloat("7605251790.999805731675135"));
	ASSERT_TRUE(BigFloat("31889126274868846012") + BigFloat("14766385524402442372") == BigFloat("46655511799271288384"));
	ASSERT_TRUE(BigFloat("-1771300020.2289702504") + BigFloat("-24371.700374213880894") == BigFloat("-1771324391.929344464280894"));
	ASSERT_TRUE(BigFloat("0.00000892867576199747") + BigFloat("0.00000000112793671906") == BigFloat("0.00000892980369871653"));
	ASSERT_TRUE(BigFloat("0.00000741543109356401") + BigFloat("47985892.828021333671") == BigFloat("47985892.82802874910209356401"));
	ASSERT_TRUE(BigFloat("0.00073891398197675339") + BigFloat("-0.00085461831694011879") == BigFloat("-0.0001157043349633654"));
	ASSERT_TRUE(BigFloat("0.00023952437358729524") + BigFloat("0.00084037575198185663") == BigFloat("0.00107990012556915187"));

}

TEST(testBigFloatSub, normalTest)
{
	ASSERT_TRUE(BigFloat(0) - BigFloat(1) == BigFloat(-1));
	ASSERT_TRUE(BigFloat() - BigFloat("") == BigFloat(0));
	ASSERT_TRUE(BigFloat("7605238944.5970453086") - BigFloat("12846.402760423075135") == BigFloat("7605226098.194284885524865"));
	ASSERT_TRUE(BigFloat("31889126274868846012") - BigFloat("14766385524402442372") == BigFloat("17122740750466403640"));
	ASSERT_TRUE(BigFloat("-1771300020.2289702504") - BigFloat("-24371.700374213880894") == BigFloat("-1771275648.528596036519106"));
	ASSERT_TRUE(BigFloat("0.00000892867576199747") - BigFloat("0.00000000112793671906") == BigFloat("0.00000892754782527841"));
	ASSERT_TRUE(BigFloat("0.00000741543109356401") - BigFloat("47985892.828021333671") == BigFloat("-47985892.82801391823990643599"));
	ASSERT_TRUE(BigFloat("0.00073891398197675339") - BigFloat("-0.00085461831694011879") == BigFloat("0.00159353229891687218"));
	ASSERT_TRUE(BigFloat("0.00023952437358729524") - BigFloat("0.00084037575198185663") == BigFloat("-0.00060085137839456139"));
}

TEST(testBigFloatMul, normalTest)
{
	ASSERT_TRUE(BigFloat(0) * BigFloat(1) == BigFloat(0));
	ASSERT_TRUE(BigFloat(1000000000) * BigFloat("2000000000") == BigFloat("2000000000000000000"));
	ASSERT_TRUE(BigFloat("7605238944.5970453086") * BigFloat("12846.402760423075135") == BigFloat("97699962571548.557433436744200537061661"));
	ASSERT_TRUE(BigFloat("31889126274868846012") * BigFloat("14766385524402442372") == BigFloat("470887132611064908369247672665972020464"));
	ASSERT_TRUE(BigFloat("-1771300020.2289702504") * BigFloat("-24371.700374213880894") == BigFloat("43169593365859.4490491773438914549558576"));
	ASSERT_TRUE(BigFloat("0.00000892867576199747") * BigFloat("0.00000000112793671906") == BigFloat("0.0000000000000100709812445379717438207782"));
	ASSERT_TRUE(BigFloat("0.00000741543109356401") * BigFloat("47985892.828021333671") == BigFloat("355.83608172933962278519354480678071"));
	ASSERT_TRUE(BigFloat("0.00073891398197675339") * BigFloat("-0.00085461831694011879") == BigFloat("-0.0000006314894236404942519591584451351981"));
	ASSERT_TRUE(BigFloat("0.00023952437358729524") * BigFloat("0.00084037575198185663") == BigFloat("0.0000002012904755714063956270079551614412"));

}

TEST(testBigFloatDiv, normalTest)
{
	ASSERT_TRUE(BigFloat(0) / BigFloat(1) == BigFloat(0));
	ASSERT_TRUE(BigFloat(1000000000) / BigFloat("2000000000") == BigFloat("0.5"));
	ASSERT_TRUE(BigFloat(2000000000) / BigFloat("1000000000") == BigFloat(2));
	ASSERT_TRUE(BigFloat("7605238944.5970453086") / BigFloat("12846.402760423075135") == BigFloat("592013117323948.76891329845989189"));
	ASSERT_TRUE(BigFloat("31889126274868846012") / BigFloat("14766385524402442372") == BigFloat("2.159575626829593893"));
	ASSERT_TRUE(BigFloat("-1771300020.2289702504") / BigFloat("-24371.700374213880894") == BigFloat("72678.557221352851660774602307908"));
	ASSERT_TRUE(BigFloat("0.00000892867576199747") / BigFloat("0.00000000112793671906") == BigFloat("7915.936781842203501391"));
	ASSERT_TRUE(BigFloat("0.00000741543109356401") / BigFloat("47985892.828021333671") == BigFloat("0.000000000000154533565107155272283758"));
	ASSERT_TRUE(BigFloat("0.00073891398197675339") / BigFloat("-0.00085461831694011879") == BigFloat("-0.864612853867169633658951048"));
	ASSERT_TRUE(BigFloat("0.00023952437358729524") / BigFloat("0.00084037575198185663") == BigFloat("0.285020567314591525256667021"));

}

#endif