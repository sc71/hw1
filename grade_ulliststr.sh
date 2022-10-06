#!/bin/bash
sudo apt-get -y -qq update
sudo apt-get -y -qq install pkg-config
g++ ulliststr.cpp grade_ulliststr.cpp -o grade_ulliststr `pkg-config --cflags --libs gtest`
./grade_ulliststr

