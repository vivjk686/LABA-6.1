#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING
#include "../LABA-6.1/LABA-6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
    TEST_CLASS(UnitTest61)
    {
    public:
        TEST_METHOD(TestCriterion)
        {
            // Odd multiple of 3 -> false
            Assert::IsFalse(Criterion(15));
            Assert::IsFalse(Criterion(21));
            Assert::IsFalse(Criterion(27));
            Assert::IsFalse(Criterion(33));

            // Even multiple of 3 -> true (not odd)
            Assert::IsTrue(Criterion(12));
            Assert::IsTrue(Criterion(18));
            Assert::IsTrue(Criterion(24));

            // Odd not multiple of 3 -> true
            Assert::IsTrue(Criterion(11));
            Assert::IsTrue(Criterion(13));
            Assert::IsTrue(Criterion(17));

            // Even not multiple of 3 -> true
            Assert::IsTrue(Criterion(10));
            Assert::IsTrue(Criterion(14));
            Assert::IsTrue(Criterion(20));
        }

        TEST_METHOD(TestCount_MixedArray)
        {
            // 15 and 21 are odd multiples of 3 (do NOT satisfy criterion)
            // 10, 12, 14, 17 satisfy criterion (4 elements)
            int arr[] = { 10, 15, 12, 21, 14, 17 };
            int count = Count(arr, 6, 0);
            Assert::AreEqual(4, count);
        }

        TEST_METHOD(TestSum_MixedArray)
        {
            // satisfying: 10 + 12 + 14 + 17 = 53
            int arr[] = { 10, 15, 12, 21, 14, 17 };
            int sum = Sum(arr, 6, 0);
            Assert::AreEqual(53, sum);
        }

        TEST_METHOD(TestReplace_MixedArray)
        {
            int arr[] = { 10, 15, 12, 21, 14, 17 };
            Replace(arr, 6, 0);
            Assert::AreEqual(0, arr[0]);   // 10 -> 0
            Assert::AreEqual(15, arr[1]);  // 15 -> unchanged
            Assert::AreEqual(0, arr[2]);   // 12 -> 0
            Assert::AreEqual(21, arr[3]);  // 21 -> unchanged
            Assert::AreEqual(0, arr[4]);   // 14 -> 0
            Assert::AreEqual(0, arr[5]);   // 17 -> 0
        }

        TEST_METHOD(TestAllExcluded)
        {
            // All elements are odd multiples of 3 -> count 0, sum 0
            int arr[] = { 15, 21, 27, 33, 39 };
            Assert::AreEqual(0, Count(arr, 5, 0));
            Assert::AreEqual(0, Sum(arr, 5, 0));
            Replace(arr, 5, 0);
            Assert::AreEqual(15, arr[0]);
            Assert::AreEqual(21, arr[1]);
            Assert::AreEqual(27, arr[2]);
            Assert::AreEqual(33, arr[3]);
            Assert::AreEqual(39, arr[4]);
        }

        TEST_METHOD(TestAllIncluded)
        {
            // No element is odd multiple of 3
            int arr[] = { 10, 12, 14, 16 };
            Assert::AreEqual(4, Count(arr, 4, 0));
            Assert::AreEqual(52, Sum(arr, 4, 0));
            Replace(arr, 4, 0);
            for (int i = 0; i < 4; i++)
                Assert::AreEqual(0, arr[i]);
        }

        TEST_METHOD(TestSingleElement)
        {
            int arr1[] = { 15 }; // excluded
            Assert::AreEqual(0, Count(arr1, 1, 0));
            Assert::AreEqual(0, Sum(arr1, 1, 0));

            int arr2[] = { 18 }; // included
            Assert::AreEqual(1, Count(arr2, 1, 0));
            Assert::AreEqual(18, Sum(arr2, 1, 0));
        }
    };
}
