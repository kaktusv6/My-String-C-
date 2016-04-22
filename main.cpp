#include <iostream>
#include <gtest/gtest.h>
#include "String.cpp"

using namespace std;

class StringTest : public ::testing::Test
{
protected:
	String string1, string2;
	void SetUp()
	{  }
};
TEST_F(StringTest, TestOperatorEqual)
{
	string1 = String("asd");
	string2 = String("asd");
	ASSERT_TRUE(string1 == string2);

	string1 = String("The to do");
	string2 = String("The to do");
	ASSERT_TRUE(string1 == string2);

	string1 = String("The to do door home words Hi, hello!&&&??");
	string2 = String("The to do door home words Hi, hello!&&&??");
	ASSERT_TRUE(string1 == string2);

	string1 = String("");
	string2 = String("");
	ASSERT_TRUE(string1 == string2);

	string1 = String(" ");
	string2 = String(" ");
	ASSERT_TRUE(string1 == string2);

	string1 = String("     d   ");
	string2 = String("     d   ");
	ASSERT_TRUE(string1 == string2);

	string1 = String("     d   f");
	string2 = String("     d   f");
	ASSERT_TRUE(string1 == string2);

	string1 = String("TOGO");
	string2 = String("TODO");
	ASSERT_FALSE(string1 == string2);

	string1 = String("TODO");
	string2 = String("TODO ");
	ASSERT_FALSE(string1 == string2);

	string1 = String("     d   s");
	string2 = String("     d   f");
	ASSERT_FALSE(string1 == string2);

	string1 = String("    ");
	string2 = String("     ");
	ASSERT_FALSE(string1 == string2);
}
TEST_F(StringTest, TestOperatorInequal)
{
	string1 = String("asd");
	string2 = String("asf");
	ASSERT_FALSE(string1 == string2);

	string1 = String("The to do");
	string2 = String("The to do world");
	ASSERT_FALSE(string1 == string2);

	string1 = String("The to do door home words Hi, hello!&&&??");
	string2 = String("The to do dooe home words Hi, hello!&&&??");
	ASSERT_FALSE(string1 == string2);

	string1 = String("The to do door home words Hi, hello!&&&??");
	string2 = String("The to do dooe!&&&??");
	ASSERT_TRUE(string1 != string2);

	string1 = String("The to home words Hi, hello");
	string2 = String("The to do dooe!&&&??");
	ASSERT_TRUE(string1 != string2);
}
TEST_F(StringTest, TestOperatorAdd)
{
	string1 = String("asd");
	string2 = String("asd");
	EXPECT_EQ(String("asdasd"), string1 + string2);

	string1 = String("q");
	string2 = String("rt");
	EXPECT_EQ(String("qrt"), string1 + string2);

	string1 = String("Hello ");
	string2 = String("my friend!!");
	EXPECT_EQ(String("Hello my friend!!"), string1 + string2);

	string1 = String("foo       ");
	string2 = String("foo       ");
	EXPECT_EQ(String("foo       foo       "), string1 + string2);

	string1 = String("abcd");
	string2 = String("dcba");
	EXPECT_EQ(String("abcddcba"), string1 + string2);


}
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}