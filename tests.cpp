#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <sstream>
#define private public
#include "code.hpp"
#undef private

// Add your test cases

TEST_CASE("Account- Balance Enquiry", "[printBalance]") {
    StatusCode status;

    //valid enquiry
    Account account1(1000, "Alice", "Alice@1234");
    account1.balance = 1000;
    // Redirect cout to our stringstream buffer
    std::streambuf* coutBuf = std::cout.rdbuf();
    std::stringstream out;
    std::cout.rdbuf(out.rdbuf());
    status = account1.printBalance("Alice@1234");
    // Restore the original buffer so further cout calls are normal
    std::cout.rdbuf(coutBuf);
    REQUIRE(status == StatusCode::success);
    REQUIRE(out.str() == "Balance for Account Number 1000: $1000\n");

}

TEST_CASE("Account- Valid Transaction History", "[printTransactionHistory]") {
    StatusCode status;

    //valid enquiry
    Account account1(1000, "Alice", "Alice@1234");
    account1.transactionHistory = { 1000, 500, -700 };
    // Redirect cout to our stringstream buffer
    std::streambuf* coutBuf = std::cout.rdbuf();
    std::stringstream out;
    std::cout.rdbuf(out.rdbuf());
    status = account1.printTransactionHistory("Alice@1234");
    // Restore the original buffer so further cout calls are normal
    std::cout.rdbuf(coutBuf);
    REQUIRE(status == StatusCode::success);
    REQUIRE(out.str() == "Transaction History for Account Number 1000:\n-700\t500\t1000\t\n");

}
