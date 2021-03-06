// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
       // assert(bi    == 800);  //Wrong.  Will FAIL.  Fix and add test cases.
      //  assert(digit == 250);
    }
    {
        // Setup
        bigint bi(542);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 542);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }
    
    {
        // Setup
        bigint bi("4321");

        // Test 
        int digit = bi[3];
        // Verify
        assert(bi    == "4321");  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }
        
    {
        // Setup
        bigint bi(1234);

        // Test 
        int digit = bi[0];
        // Verify
        assert(bi    == 1234);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }   

    {
        // Setup   
        bigint bi("123492345");

        // Test 
        int digit = bi[3];
        // Verify
        assert(bi    == "123492345");  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 2);
    } 




    {
        // Setup 
        bigint bi(1234);

        // Test 
        int digit = bi[-3];
        // Verify
        assert(bi    == 1234);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 0);
    } 

     {
        // Setup
        bigint bi(1234);

        // Test 
        int digit = bi[CAPACITY + 10];
        // Verify
        assert(bi    == 1234);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 0);
    } 
     {
        // Setup 
        bigint bi(0);

        // Test 
        int digit = bi[1];
        // Verify
        assert(bi    == 0);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 0);
    }  

      {
        // Setup 
        bigint bi(154326);

        // Test 
        int digit = bi[4];
        // Verify
        assert(bi    == 154326);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 5);
    }   


      {
        // Setup 
        bigint bi(154326);

        // Test 
        int digit = bi[0];
        // Verify
        assert(bi    == 154326);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 6);
    }   


      {
        // Setup 
        bigint bi("12345678901234567890123456789");

        // Test 
        int digit = bi[20];
        // Verify
        assert(bi    == "12345678901234567890123456789");  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 9);
    }   
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
}

