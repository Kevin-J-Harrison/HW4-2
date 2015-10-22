#include "BinarySearchTree.hpp"
#include "gvsu_cis.h"

#include <algorithm>
#include <vector>
using namespace std;

TEST_CASE("HW04 of nodes")
{
    vector<int> data {50, 25, 78, 15, 66, 92, 9, 20, 63, 76, 95, 68};
    BinarySearchTree<int> t1;
    for (auto x : data)
        t1.insert (x);

    SECTION ("Node counting") {
        REQUIRE (t1.number_of_nodes() == data.size());
        REQUIRE (t1.number_of_leaves() == 5);
        REQUIRE (t1.number_of_full_nodes() == 4);
    }

    SECTION ("Range") {
        auto r1 = t1.get_range(51, 60);
        REQUIRE (r1.size() == 0);
        auto r2 = t1.get_range (100, 200);
        REQUIRE (r2.size() == 0);
        auto r3 = t1.get_range (-10, -7);
        REQUIRE (r3.size() == 0);

        auto r4 = t1.get_range(1, 30);
        REQUIRE (r4.size() == 4);
        REQUIRE (r4[0] == 9);
        REQUIRE (r4[3] == 25);

        auto r5 = t1.get_range (17, 80);
        REQUIRE (r5.size() == 8);
        REQUIRE (r5[0] == 20);
        REQUIRE (r5[2] == 50);
        REQUIRE (r5[7] == 78);
    }

    SECTION ("Remove Leaves") {
        int before, after;
        int leaves;
        vector<int> testvals {20, 15, 66, 78, 50};
        int k = 0;
        while (!t1.isEmpty()) {
            before = t1.number_of_nodes();
            leaves = t1.number_of_leaves();
            auto r = t1.remove_leaves();
            after = t1.number_of_nodes();
            REQUIRE (after < before);
            REQUIRE (r.size() == leaves);
            auto iter = find (r.begin(), r.end(), testvals[k]);
            REQUIRE (iter != r.end());
            k++;
        }
    }
}