#include "fsm_gen.h"

using namespace std;

int main(){
    FSM mach;
    string test1 = "110";                       // 6 remainder 0 (basic tests for remainder 0)
    string test2 = "1010";                      // 10 remainder 1 (basic tests for remainder 1)
    string test3 = "100000";                    // 32 remainder 2 (basic tests for remainder 2)
    string test4 = "111111";                    // 63 remainder 0 (test with all 1's)
    string test5 = "910101";                    // test invalid input at the beginning
    string test6 = "101012";                    // test invalid input at the end
    string test7 = "10801";                     // test invalid input in the middle
    string test8 = "1010101010101111000111";    // 2796487 remainder 1 (larger binary test)
    string test9 = "";                          // empty string

    //Remainder Tests
    if(mach.Remainder(test1)!= 0) cout << "Test1 Failed" << endl;
    else if(mach.Remainder(test2)!= 1) cout << "Test2 Failed" << endl;
    else if(mach.Remainder(test3)!= 2) cout << "Test3 Failed" << endl;
    else if(mach.Remainder(test4)!= 0) cout << "Test4 Failed" << endl;
    else if(mach.Remainder(test5)!= -1) cout << "Test5 Failed" << endl;
    else if(mach.Remainder(test6)!= -1) cout << "Test6 Failed" << endl;
    else if(mach.Remainder(test7)!= -1) cout << "Test7 Failed" << endl;
    else if(mach.Remainder(test8)!= 1) cout << "Test8 Failed" << endl;
    else if(mach.Remainder(test9)!= -1) cout << "Test9 Failed" << endl;
    else cout << "Remainder Function Tests Passed" << endl;

    //Test default constructor
    set<int> inputs = {0, 1};
    set<string> states {"s0", "s1", "s2"};
    string init = "s0";
    set<string> final {"s0", "s1", "s2"};
    map<pair<string, int>, string> transition_map = {
        {{"s0", 0}, "s0"},
        {{"s0", 1}, "s1"},
        {{"s1", 0}, "s2"}, 
        {{"s1", 1}, "s0"},
        {{"s2", 0}, "s1"}, 
        {{"s2", 1}, "s2"}
    };
    if(mach.Q != states) cout << "Default constructor Q failed" << endl;
    else if (mach.sigma != inputs) cout << "Default constructor sigma failed" << endl;
    else if (mach.init_state != init) cout << "Default constructor init failed" << endl;
    else if (mach.F != final) cout << "Default constructor final states failed" << endl;
    else if (mach.transitions != transition_map) cout << "Default constructor sigma failed" << endl;
    else cout << "Default Constructor Tests Passed" << endl;

    //Test custom constructor
    set<int> other_inputs = {0, 1};
    set<string> other_states {"s0", "s1", "s2", "s3", "s4", "s5"};
    string other_init = "s3";
    set<string> other_final {"s0", "s5"};
    map<pair<string, int>, string> other_transition_map = {
        {{"s0", 0}, "s0"},
        {{"s0", 1}, "s0"},
        {{"s1", 0}, "s1"}, 
        {{"s1", 1}, "s0"},
        {{"s2", 0}, "s2"}, 
        {{"s2", 1}, "s1"},
        {{"s3", 0}, "s2"}, 
        {{"s3", 1}, "s4"},
        {{"s4", 0}, "s4"}, 
        {{"s4", 1}, "s5"},
        {{"s5", 0}, "s5"}, 
        {{"s5", 1}, "s5"}

    };
    FSM other(6, {0,1}, "s3", {"s0", "s5"}, other_transition_map);

    if(other.Q != other_states) cout << "Custom constructor Q failed" << endl;
    else if (other.sigma != other_inputs) cout << "Custom constructor sigma failed" << endl;
    else if (other.init_state != other_init) cout << "Custom constructor init failed" << endl;
    else if (other.F != other_final) cout << "Custom constructor final states failed" << endl;
    else if (other.transitions != other_transition_map) cout << "Custom constructor sigma failed" << endl;
    else cout << "Custom Constructor Tests Passed" << endl;

    return 0;
}