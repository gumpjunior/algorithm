objects = balanced_binary_tree_main.o binary_tree.o

all : $(objects)
	cc -o balanced_binary_tree_main $(objects)

balanced_binary_tree_main.o : ../data_structure/binary_tree/binary_tree.h
binary_tree.o : ../data_structure/binary_tree/binary_tree.h \
	../data_structure/binary_tree/binary_tree.c
	cc -c ../data_structure/binary_tree/binary_tree.c

.PHONY : clean
clean :
	rm balanced_binary_tree_main $(objects)