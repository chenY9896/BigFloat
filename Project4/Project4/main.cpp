#ifdef _DEBUG
#include "gtest\gtest.h"
#else
extern void TEST();
#endif

int main(int argc, char **argv)
{
	#ifdef _DEBUG
	::testing::InitGoogleTest(&argc, argv);
	int a= RUN_ALL_TESTS();
	system("pause");
	return 0;
	
#else
	TEST();
	return 0;
#endif
}

