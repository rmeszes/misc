// misc.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <sstream>

#include "gtest_lite.h"
#include "memtrace.h"

#include "misc.h"
#include "min_heap.h"

using namespace std;

int main()
{
	TEST(minheap, test) {
		min_heap<int> mh;
		mh.push(2);
		mh.push(5);
		mh.push(8);
		mh.push(16);
		mh.push(22);

		stringstream ss;
		mh.write(ss);
		EXPECT_STREQ("2 5 8 16 22", ss.str().c_str());
	} END;

	TEST(minheap, separator) {
		min_heap<int> mh;
		mh.push(2);
		mh.push(5);
		mh.push(8);
		mh.push(16);
		mh.push(22);

		stringstream ss;
		mh.write(ss, ", ");
		EXPECT_STREQ("2, 5, 8, 16, 22", ss.str().c_str());
	} END;

	return 0;
}
