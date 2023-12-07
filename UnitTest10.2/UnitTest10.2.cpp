#include "pch.h"
#include "CppUnitTest.h"
#include "../PR10.2/PR10.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			rewrite_info("output.txt", "text.txt");
			string expected = "a1sdf3ghww4e6rt AScvjk456-+-=)(hjkb)";
			string actual="";
			ifstream file("output.txt");
			if (file.is_open()) {
				getline(file, actual);
			}
			file.close();
			Assert::AreEqual(expected, actual);
		}
	};
}
