objects = binary_tree_main.o binary_tree.o

binary_tree_main : $(objects)
	cc -o binary_tree_main $(objects)

binary_tree.o : binary_tree.h
binary_tree_main.o : binary_tree.h

.PHONY : clean
clean :
	-rm binary_tree_main $(objects)

