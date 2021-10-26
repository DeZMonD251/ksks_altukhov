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
			Assert::AreEqual(parser("4:34#23#45#:12@34@:123:456:*adasd", &data), 34);
			Assert::AreEqual(parser("4:4#23#45#:12@34@:123:456:*adasd", &data), 4);
			Assert::AreEqual(parser("4:3423#45#:12@34@:123:456:*adasd", &data), 34);
		}
	};
}
