
#* File: Makefile for MULTIPLICATION ON COMPLEX_NUM 
#* Author: ANITA BHAT
#* License: Property of Sasken
#* Date: Jul 13 2023

#* This file contains the driver code for airthametic(*) opeartion on two complex number.

CC = g++
CFLAGS = -Wall
SRC_DIR = src
INCLUDE_DIR = include

main: main.o $(SRC_DIR)/read_input.o $(SRC_DIR)/display_result.o
	$(CC) $(CFLAGS) main.o $(SRC_DIR)/read_input.o $(SRC_DIR)/display_result.o -o main

main.o: main.cpp $(INCLUDE_DIR)/complex.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o 

$(SRC_DIR)/read_input.o: $(SRC_DIR)/read_input.cpp $(INCLUDE_DIR)/complex.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/read_input.cpp -o $(SRC_DIR)/read_input.o 

$(SRC_DIR)/display_result.o: $(SRC_DIR)/display_result.cpp $(INCLUDE_DIR)/complex.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/display_result.cpp -o $(SRC_DIR)/display_result.o 

clean:
	rm -f $(SRC_DIR)/*.o main
