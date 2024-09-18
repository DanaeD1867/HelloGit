# list/Makefile
#
# Makefile for list implementation and test file.
#
# Author: Danae Dunlap
list: list.c main.c
	gcc list.c main.c -o list
