objects = reverse_linked_list_I_main.o linked_list.o

all : $(objects)
	cc -o reverse_linked_list_I_main $(objects)

reverse_linked_list_I_main.o : ../data_structure/linked_list/linked_list.h
linked_list.o : ../data_structure/linked_list/linked_list.h \
	../data_structure/linked_list/linked_list.c
	cc -c ../data_structure/linked_list/linked_list.c

.PHONY : clean
clean :
	rm reverse_linked_list_I_main $(objects)
