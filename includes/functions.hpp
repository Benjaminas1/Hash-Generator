#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>

#include "../hashingAlg/md5.h"
#include "../hashingAlg/sha1.h"
#include "../hashingAlg/sha256.h"

using namespace std;

void inputFromCmd();

void inputFromFile();

void basicTests();

void effectivenessTest();

void collisionTest();

void diversityTest();