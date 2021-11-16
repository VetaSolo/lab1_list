#include "pch.h"
#include "CppUnitTest.h"
#include"..\ConsoleApplication1\MyList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Lab1_list)
	{
	public:
		
		TEST_METHOD(push_back_test)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1); // Check the list is empty
			list.push_back(77); // add some number
			Assert::IsTrue(list.isEmpty() == 0); // Check the list is not empty
			Assert::IsTrue(list.at(0) == 77); // check that the new element is equal to the added one
			list.push_back(2);
			Assert::IsTrue(list.at(1) == 2); // check that another item has been added to the end of the list
		}

		TEST_METHOD(push_front_test)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1); // Check the list is empty
			list.push_front(-15); // add some number
			Assert::IsTrue(list.isEmpty() == 0); // Check the list is not empty
			Assert::IsTrue(list.at(0) == -15); // check that the new element is equal to the added one
			list.push_front(99);
			Assert::IsTrue(list.at(0) == 99); // check that another item has been added to the beginning of the list
		}
		TEST_METHOD(pop_back_test)
		{
			MyList list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3); // Create and fill out the list
			Assert::IsTrue(list.at(2) == 3);
			list.pop_back();
			Assert::IsTrue(list.at(1) == 2);
			list.pop_back();
			Assert::IsTrue(list.at(0) == 1);
			list.pop_back();
			Assert::IsTrue(list.isEmpty() == 1); // check that the last item was deleted
		}

		TEST_METHOD(pop_front_test)
		{
			MyList list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);// Create and fill out the list
			Assert::IsTrue(list.at(0) == 1);
			list.pop_front();
			Assert::IsTrue(list.at(0) == 2);
		}

		TEST_METHOD(insert_test)
		{
			MyList list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);// Create and fill out the list
			Assert::IsTrue(list.at(1) == 2);
			list.insert(5, 1); // list[1,2,3,4] -> list[1,5,2,3,4]
			Assert::IsTrue(list.at(1) == 5);
			Assert::IsTrue(list.at(2) == 2);
			Assert::IsTrue(list.at(4) == 4);
		}

		TEST_METHOD(at_test)
		{
			MyList list;
			list.push_back(6);
			list.push_back(-3);
			list.push_back(78);
			list.push_back(-43); // Create and fill out the list
			Assert::IsTrue(list.at(0) == 6);
			Assert::IsTrue(list.at(1) == -3);
			Assert::IsTrue(list.at(2) == 78);
			Assert::IsTrue(list.at(3) == -43);
		}
		
		TEST_METHOD(remove_test)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1);// Check the list is empty
			list.push_front(45);
			Assert::IsTrue(list.isEmpty() == 0);// Check the list is not empty
			list.remove(0);
			Assert::IsTrue(list.isEmpty() == 1);// Check the list is empty
			
			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.remove(0);
			Assert::IsTrue(list.isEmpty() == 0);// Check the list is not empty
			Assert::IsTrue(list.at(0) == 2);
		}

		TEST_METHOD(get_size_test)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1 && list.get_size() == 0);
			list.push_front(345);
			Assert::IsTrue(list.get_size() == 1);
		}

		TEST_METHOD(clear_test)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1);
			list.push_front(345);
			list.push_front(34);
			list.push_front(35);
			list.push_front(45);
			Assert::IsTrue(list.get_size() == 4);
			list.clear();
			Assert::IsTrue(list.isEmpty() == 1);// Check the list is empty
		}

		TEST_METHOD(set_test)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1);
			list.push_front(5);
			list.push_front(6);
			list.push_front(7);
			list.push_front(8);
			Assert::IsTrue(list.at(1)==7);
			list.set(1,1);
			Assert::IsTrue(list.get_size() == 4 && list.at(1) == 1);
			
		}
		TEST_METHOD(isEmpty_test)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1);// Check the list is empty
			list.push_front(5);
			Assert::IsTrue(list.isEmpty() == 0);// Check the list is not empty
		}
		TEST_METHOD(reverse_test)
		{
			MyList list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			list.reverse();
			Assert::IsTrue(list.at(0) == 3 && list.at(1) == 2 && list.at(2) == 1);

			list.reverse();
			Assert::IsTrue(list.at(0) == 1 && list.at(1) == 2 && list.at(2) == 3);
		}
		
	};
}
