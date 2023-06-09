// misc.cpp : Defines the entry point for the application.
//

#include "misc.h"

using namespace std;

int main()
{
	TEST(minheap, test) {
		min_heap<int> mh;
        int data[5] = { 5, 2, 8, 22, 16};

        for(const int it : data) {
            mh.push(it);
        }

		stringstream ss;
		mh.write(ss);
		EXPECT_STREQ("2 5 8 16 22", ss.str().c_str());
	} END;

	TEST(minheap, separator) {
		min_heap<int> mh;
        int data[5] = { 5, 2, 8, 22, 16};

        for(const int it : data) {
            mh.push(it);
        }

		stringstream ss;
		mh.write(ss, ", ");
		EXPECT_STREQ("2, 5, 8, 16, 22", ss.str().c_str());
	} END;

    TEST(Array, capacity_ctor) {
        Array<int> array1(12);
        EXPECT_EQ(0, array1.size());
        EXPECT_EQ(12, array1.capacity());
        EXPECT_ANY_THROW(Array<int>(-12));
    } ENDM;

    TEST(Array, from_basic_array_ctor) {
        int b_array[] = {12, -23, 42, 54};
        Array<int> array(b_array,4);
    } ENDM;

    TEST(Array, copy) {
        int b_array[] = {12, -23, 42, 54};
        Array<int> array(b_array,4);
        Array<int> array1(array);
        stringstream ss;
        array1.write(ss);
        EXPECT_STREQ("12 -23 42 54", ss.str().c_str());
    } ENDM;

    TEST(Array, resize) {
        int b_array[] = {12, -23, 42, 54};
        Array<int> array(b_array,4);
        array.resize(12);
        EXPECT_EQ(12, array.capacity());
        EXPECT_EQ(4, array.size());
        EXPECT_EQ(8, array.free_size());
        stringstream ss;
        array.write(ss);
        EXPECT_STREQ("12 -23 42 54", ss.str().c_str());
        array.resize(2);
        EXPECT_EQ(2, array.size());
        EXPECT_EQ(2, array.capacity());
        EXPECT_EQ(0, array.free_size());
        stringstream ss2;
        array.write(ss2);
        EXPECT_STREQ("12 -23", ss2.str().c_str());
    } ENDM;


	return 0;
}
