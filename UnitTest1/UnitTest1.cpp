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
			Assert::IsTrue(list.isEmpty() == 1); // проверяем что список пуст
			list.push_back(77); // добавляем какое-то число
			Assert::IsTrue(list.isEmpty() == 0); // проверяем что список теперь не пуст
			Assert::IsTrue(list.at(0) == 77); // проверяем что новый элемент равен добавленному
			list.push_back(2);
			Assert::IsTrue(list.at(1) == 2); // проверям, что был добавлен еще один элемент в конец списка
		}

		TEST_METHOD(push_front_test)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1); // проверяем что список пуст
			list.push_front(-15); // добавляем какое-то число
			Assert::IsTrue(list.isEmpty() == 0); // проверяем что список теперь не пуст
			Assert::IsTrue(list.at(0) == -15); // проверяем что новый элемент равен добавленному
			list.push_front(99);
			Assert::IsTrue(list.at(0) == 99); // проверям, что был добавлен еще один элемент в начало списка
		}
		TEST_METHOD(pop_back_test)
		{
			MyList list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			Assert::IsTrue(list.at(2) == 3);
			list.pop_back();
			Assert::IsTrue(list.at(1) == 2);
			list.pop_back();
			Assert::IsTrue(list.at(0) == 1);
			list.pop_back();
			Assert::IsTrue(list.isEmpty() == 1); // проверяем что был удален последний эл-т
		}

		TEST_METHOD(pop_front_test)
		{
			MyList list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
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
			list.push_back(4);
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
			list.push_back(-43);
			Assert::IsTrue(list.at(0) == 6);
			Assert::IsTrue(list.at(1) == -3);
			Assert::IsTrue(list.at(2) == 78);
			Assert::IsTrue(list.at(3) == -43);
		}
		
		TEST_METHOD(remove_test)
		{
			MyList list;
			Assert::IsTrue(list.isEmpty() == 1);
			list.push_front(45);
			Assert::IsTrue(list.isEmpty() == 0);
			list.remove(0);
			Assert::IsTrue(list.isEmpty() == 1);
			
			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.remove(0);
			Assert::IsTrue(list.isEmpty() == 0);
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
			Assert::IsTrue(list.isEmpty() == 1);
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
			Assert::IsTrue(list.isEmpty() == 1);
			list.push_front(5);
			Assert::IsTrue(list.isEmpty() == 0);
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
