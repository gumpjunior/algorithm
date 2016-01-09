objects = root_to_any_node_main.o binary_tree.o

all : $(objects)
	cc -o root_to_any_node_main $(objects)

root_to_any_node_main.o : ../../data_structure/binary_tree/binary_tree.h
binary_tree.o : ../../data_structure/binary_tree/binary_tree.h \
	../../data_structure/binary_tree/binary_tree.c
	cc -c ../../data_structure/binary_tree/binary_tree.c

.PHONY : clean
clean :
	rm root_to_any_node_main $(objects)