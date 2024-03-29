#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "BST.hpp"
#include "util.hpp"

using namespace std;
using namespace testing;

/* Empty BST test starts here */

TEST(BSTTests, EMPTY_TREE_HEIGHT_TEST) {
    BST<int> bst;
    ASSERT_EQ(bst.height(), -1);
}

/* Small BST test starts here */

/**
 * A simple test fixture from which multiple tests
 * can be created. All fixture tests (denoted by the
 * TEST_F macro) can access the protected members of this
 * fixture. Its data is reset after every test.
 *
 * Builds the following BST:
 *         3
 *        / \
 *       1   4
 *      /     \
 *    -33     100
 */
class SmallBSTFixture : public ::testing::Test {
  protected:
    BST<int> bst;

  public:
    SmallBSTFixture() {
        // initialization code here
        vector<int> input{3, 4, 1, 100, -33};
        insertIntoBST(input, bst);
    }
    // code in SetUp() will execute just before the test ensues
    // void SetUp() {}
};

TEST_F(SmallBSTFixture, SMALL_SIZE_TEST) {
    // assert that the small BST has the correct size
    ASSERT_EQ(bst.size(), 5);
}

TEST_F(SmallBSTFixture, SMALL_INSERT_DUPLICATES_TEST) {
    // assert failed duplicate insertion
    ASSERT_FALSE(bst.insert(3));
}

TEST_F(SmallBSTFixture, SMALL_INSERT_NORMAL_TEST){
	//assert that insertion works fine
	ASSERT_TRUE(bst.insert(101));
}
TEST_F(SmallBSTFixture, SMALL_SIZE_TEST2){

	//assert that the small BST has  correct size after insertion
	ASSERT_TRUE(bst.insert(40));
	ASSERT_EQ(bst.size(), 6); 
}

TEST_F(SmallBSTFixture, IN_ORDER_TRAVERSAL){

	vector<int> list{-33,1,3,4,100};
	ASSERT_EQ(bst.inorder(), list);
}

TEST_F(SmallBSTFixture, INSERT_LEFT_SIDE){

	ASSERT_TRUE(bst.insert(2));
}

TEST_F(SmallBSTFixture, TEST_FIND1){

 	BSTIterator<Data> * iter = new BSTIterator(bst.root);

	ASSERT_EQ( bst.find( bst.root.data, iter);

}

// ADD MORE TESTS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
