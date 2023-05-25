// chess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "testPawn.h"
#include "testQueen.h"

int main()
{
   TestPawn().run();
   TestQueen().run();
   std::cout << "Tests Passed!\n";
}

