objects = binary_tree_max_depth_main.o binary_tree.o

all : $(objects)
	cc -o binary_tree_max_depth_main $(objects)

binary_tree_max_depth_main.o : ../data_structure/binary_tree/binary_tree.h
binary_tree.o : ../data_structure/binary_tree/binary_tree.h \
	../data_structure/binary_tree/binary_tree.c
	cc -c ../data_structure/binary_tree/binary_tree.c

.PHONY : clean
clean :
	rm binary_tree_max_depth_main $(objects)
