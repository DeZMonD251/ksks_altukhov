#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "../Server/Parser.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		DATA data;
	public:
		
		TEST_METHOD(parser_1)
		{
			Assert::AreEqual(parser("1:23#41#23#:*adasd", &data), 0);
			Assert::AreEqual(parser("1:asde23#41#23#:*adasd", &data), -1);

			Assert::AreEqual(parser("2:13#23#34#:13@32@:*adasd", &data), 0);
			Assert::AreEqual(parser("2:asd13#23#34#:13@32@:*adasd", &data), -1);

			Assert::AreEqual(parser("3:14#23#45#:123@324@:12@43@:*adasd", &data), 0);
			Assert::AreEqual(parser("3:asd14#23#45#:123@324@:12@43@:*adasd", &data), -1);

			Assert::AreEqual(parser("4:15#16#17#:123@12@:14:34:*adasd", &data), 0);
			Assert::AreEqual(parser("4:asd15#16#17#:123@12@:14:34:*adasd", &data), -1);

			Assert::AreEqual(parser("5:11#12#13#:14@23@:15:123:*adasd", &data), 0);
			Assert::AreEqual(parser("5:as11#12#13#:14@23@:15:123:*adasd", &data), -1);
			
			Assert::AreEqual(parser("6:31#32#33#:12@15@:23:25:*adasd", &data), 0);
			Assert::AreEqual(parser("6:31#32#33#:a12@15@:23:25:*adasd", &data), -1);
			
			Assert::AreEqual(parser("7:31#34#45#:12@32@:34:54:*adasd", &data), 0);
			Assert::AreEqual(parser("7:31#34#45#:12@32@:s34:54:*adasd", &data), -1);
			
			Assert::AreEqual(parser("8:15#16#17#:12@13@:14:*adasd", &data), 0);
			Assert::AreEqual(parser("8:15#16#17#:12@13@:s14:*adasd", &data), -1);
			
			Assert::AreEqual(parser("9:4#5#6#:1@2@:3:*adasd", &data), 0);
			Assert::AreEqual(parser("9:4#5#asd6#:1@2@:3:*adasd", &data), -1);
			
			Assert::AreEqual(parser("10:1#5#5#:12@345@:54:23:14:*adasd", &data), 0);
			Assert::AreEqual(parser("10:as1#5#5#:12@345@:54:23:14:*adasd", &data), -1);
			
			Assert::AreEqual(parser("11:1#2#3#:123@23@:42:123:1252:*adasd", &data), 0);
			Assert::AreEqual(parser("11:ыв1#2#3#:123@23@42:123:1252:*adasd", &data), -1);
			
			Assert::AreEqual(parser("12:41@34@:asefds:12:*adasd", &data), 0);
			Assert::AreEqual(parser("12:aers41@34@:asefds:12:*adasd", &data), -1);
			
			Assert::AreEqual(parser("13:34#23#45#:12@34@:123:456:*adasd", &data), 0);
			
			Assert::AreEqual(parser("14:34#23#45#:12@34@:123:456:*adasd", &data), 0);
			
			Assert::AreEqual(parser("15:34#23#45#:12@34@:123:456:*adasd", &data), 0);
			
			Assert::AreEqual(parser("675:23#45#:12@34@:123:456:*adasd", &data), -2);
		}
	};
}
