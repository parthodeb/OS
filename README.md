Operating System simulation based projects.
Problem:
  1)	There are 3 student processes and 1 teacher process. Students are supposed to do their assignments and they need 3 things for that pen, paper and question paper. The teacher has an infinite supply of all the three things. One students has pen,an other has paper and another has question paper. The teacher places two things on a shared table and the student having the third complementary thing makes the assignment and tells the teacher on completion. The teacher then places another two things out of the three and again the student having the third thing makes the assignment and tells the teacher on completion. This cycle continues. WAP to synchronize the teacher and the students.
  
  Explanation:
    1.	In the given solution I have taken all the student processes and resources in 2D array and initialized then to 0.
    2.	I have made 3 student processes in three different functions which will be executed by single s_thread and one t_thread for               execution of teacher process.
    3.	User will get a menu to select any two out of three resources that are to be placed on shared table.
    4.	If one process is completed there will be a message printed on the screen saying process is completed.
    5.	When one process is executing no other student or teacher process will execute and for achieving this I have used Mutex lock.
    6.	When a process starts to execute it acquires the lock and when it completes the execution releases the lock.
    7.	After completion of all the three processes the program will end.




  2)	Design a scheduling program that is capable of scheduling many processes that comes in at some time interval and are allocated the CPU not more than 10 time units. CPU must schedule processes having short execution time first. CPU is idle for 3 time units and does not entertain any process prior this time. Scheduler must maintain a queue that keeps the order of execution of all the processes. Compute average waiting and turnaround time.
  
  Explanation:
    1.	For solving this problem the processes are scheduled considering their arrival and Wait time. 
    2.	I have made 5 functions:  readData(); Init(); getNextProcess(); dispTime(); computeSRT();
    3.	User will get to enter process burst time and arrival time.
    4.	Depending on that ComputeSRT function will calculate the shortest run time of the processes and it will be entered in gantt chart.
    5.	After every unit time when a process will entered by user ComputeSRT will compare the remaining run time of currently running             process and if less than new process then it will be preumpted.
    6.	After completion of all the processes the program will prepare a gantt chart and program will end
