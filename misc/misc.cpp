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
        EXPECT_EQ(12, array1[0]);
    } ENDM;

    TEST(Array, resize) {
        int b_array[] = {12, -23, 42, 54};
        Array<int> array(b_array,4);
        array.resize(12);
        EXPECT_EQ(12, array.capacity());
        EXPECT_EQ(12, array[0]);
        array.resize(2);
        EXPECT_EQ(2, array.capacity());
        EXPECT_EQ(12, array[0]);
    } ENDM;

    TEST(Array, index) {
        Array<int> array(3);
        EXPECT_ANY_THROW(array[3]);
    } ENDM;

	return 0;
}
