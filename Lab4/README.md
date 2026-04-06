<h5>Done</h5>
Block 0  
Block 1: 2, 3  
Block 2: 8  
Block 3: 13  
Block 4: 18  
In blocks 5 and 6 there were no core tasks, so I`ve done this  
Block 5: 20  
Block 6: 22  

Additional:
Tree of tasks
Block 0
Block 1:
    task 2
        task 3
Block 3
Block 4
Block 5
Block 6

It looks quite boring because I\`ve done multiple structures specifically for each block to keep everything simple. 
However, if I\`ve used classes and inherited them, it would look something like that.
Block 0 (Tree)
    Block 1 (path)
        task 2
            task 3 ( - requires 2)
    Block 2 (print)
    Block 3 (delete)
    Block 4 (Binary tree - inherit tree)
        Block 5 (Threaded binary tree - inherit binary tree)
        Block 6 (Arithmetic tree - inherit binary tree)