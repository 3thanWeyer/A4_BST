# A4_BST PT 2
Overview
My Binary Search Tree designed to efficiently manage a landing reservation system for the A4_P2 assignment. The implementation confirms that planes reserve landing times without time conflicts.

Functions:
1. checkConflict():
 	Verifies if a proposed landing time conflicts with existing reservations. No two planes should land within a 3-minute interval of each other.
 	Approach: This function recursively traverses the BST to ensure no time conflict within the specified 3-minute window[1].

2. insert():
	Insert a verified landing time into the BST, ensuring no conflicts and duplicates.
    Approach: This function not only places the new node in the correct position within the BST but also updates the subtree size key for later operations. It utilizes recursion for insertion[2].

3. countPlanes():
	Counts the number of planes scheduled to land before or at a specified time.
    Approach: Uses the subtree size data to efficiently count nodes whose landing times meet the criteria. This is achieved through recursive traversal of the BST[3] on the left side.

