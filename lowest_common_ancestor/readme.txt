Status: This program is stuck.
Original idea: find all parent nodes of the given nodes(node1, node2), put them into two stacks nodeParents1 and nodeParents2. Then make comparison between nodeParents1 and nodeParent2 from the beginning. The last common node is the LCA.
Block reason: For stack data structure in c++, no API to access stack.end(). So no way to do iteration from the beginning of the stack.
So I AM WRONG from the beginning when chosing the data structure!!

