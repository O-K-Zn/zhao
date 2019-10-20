#include "stdafx.h"
#include "CppUnitTest.h"
#include"../zjh first/all.h"
#include<string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			test a;
			int x = 7,y=1;
			int real = a.check(1);
			Assert::AreEqual(x, real);

		}

	};
}