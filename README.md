
1. Implementing a Doubly Linked List of Processes: I defined a process structure with fields like PID, process name, and pointers for next` and prev. I then implemented functions to add, remove, and traverse processes, simulating operations similar to what the Linux kernel does. The project included process navigation to move between processes and a function to simulate process switching.

2. Process Management with Ready and Wait Queues: I extended the process structure to include a state field. I created ready and I/O wait queues using doubly linked lists and implemented functions to add, move, and simulate process execution between these states. A simulation was done where a process moved between CPU execution and I/O waiting, following scenarios like backup processes.

3. Process Creation and Synchronization Using fork(): I wrote a program where a parent process created a child using fork(). The child modified a shared variable, printed its details, and created a grandchild process. The parent waited for the child to finish and printed the final output, showing shared data behavior and process IDs.

4. Collatz Conjecture with fork(): I created a C program where the parent prompted for input, and the child generated the Collatz sequence for a given number. The child printed the sequence until reaching 1, while the parent waited for completion and printed a completion message.

5. Drone Takeoff and Land Simulation: This program involved sequential execution where the child process handled the drone's takeoff and the parent process waited for the child to complete before handling the landing. The program printed process IDs to show which part each process executed.

6. Orphan and Zombie Processes: I explained that an orphan process is left when its parent terminates before it, and a zombie occurs when a child ends, but the parent hasn't collected its exit status. To prevent zombies, the parent should use wait()to collect the child's status.

7. Detecting exec and fork Failures with -1 return value.

8. Multithreaded Statistics Calculation: I wrote a multithreaded program that calculates the average, minimum, and maximum values from command-line input. Each value was calculated by a separate thread, which stored results in global variables, and the parent thread printed the results after the threads completed.

9. Monte Carlo π Approximation: I implemented a multithreaded version of the Monte Carlo method to approximate π. One thread generated random (x, y) points within a square and counted how many fell inside the circle. The parent thread used this count to estimate π after the child thread finished.
