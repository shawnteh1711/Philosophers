# Philosophers
this is a 42KL project to learn about 
thread and mutex


# thread
basic unit of CPU utilization

if a process has multiple threads of control,
it can perform more than one task at a time
contain thread id , register and stack

## benefit
1. responsiveness - allow program continue running even part of it is blocked ot perform lengthy operation
2. resource sharing - allow application to have several thread of activity within same address space 
3. economy - more economical to create and context_switch threads then costly process creation
4. utilization of multiprocessor architectures - threads may be running in parallel on different processors, multithreading, increase concurrency

# mutex
Mutex is the short form for ‘Mutual Exclusion object’. 
A mutex allows multiple threads for sharing the same resource
Mutex take value 0 and 1. A mutex can be unlocked only by the 
thread that locked it. Thus a mutex has an owner concept.


# dining philosopher problem
philosopher need to eat, think and sleep

1. input : 
* number of philosopher = number of philosopher and fork. if only one philosopher, only one fork
* times to die = if philosopher didn't eat, times to die begin since their last meal
* times to eat = time for philosopher to eat, need to hold both fork
* times to sleep = time for philosopher to sleep
number of times philosopher to eat =  number of turn philosopher must eat, then stimulation stop. If not specify, stimulation end when philosopher die

2. output:
report philosopher state changes
ms philosopher X has taken a fork
ms philosopher X is eating
ms philosopher X is sleeping
ms philosopher X is thinking
ms philosopher X die

replace ms with actual time and X with number of philosopher

define philosopher class
philosopher is thread
left fork and right fork is mutax lock

## algorithm
1. start
2. declare and initialize mutax variables (fork)
3. declare and initialize thread variables (philosopher)
4. create the threads representing philosopher
5. wait until thread finish execution stop

## algorithms for thread
1. start
2. philosopher lock left fork
3. philosopher lock right fork
4. philosopher is eating
5. philosopher unlock left fork
6. philosopher unlock right fork
7. sleep
8. think

## function
1. pthread_mutex_init(&mutex, NULL) - initialize mutex
2. pthread_mutex_lock(&mutex) - lock a mutex
3. pthread_mutex_unlock(&mutex) - unlock a mutex
4. pthread_create(ptr to thread, NULL, (void*)func, (void*))
5. pthread_join(ptr to thread, &msg) - make the main program wait
called thread is finished executing it's task
6. pthread_mutex_destroy (ptr to thread)
7. pthread_exit(NULL)

do {
	wait (fork[i]);
	wait (fork[(i + 1) % 5]);  // to handle last philosopher

	...
	// eat
	signal(fork[i]);
	signal(fork[(i + 1) % 5]);

	// think
} while (TRUE);

## deadlock 

- all five philosophers become hungry simulateneusly and grabs their left fork. No more fork left. When each philosopher tries to grab his right fork, he will delayed forever.

# Flow chart
start -> parse input -> create mutex fork (pthread_mutex_init)

-> create number of fork based on philo no. 

-> create new philo (assign all value then pthread_create, pass simulation)

-> create philo based on number on philo

-> delete all philo (pthread_join), free

-> delete all mutex fork (pthread_mutex_destroy), free

-> end


# BONUS

fork is representing with semaphore
a philosopher try to grab fork by wait() on that semaphore
a philosopher release fork by signal() on that semaphore
* semaphore fork[5]
* semaphore initialize to 1 mean free
* semaphore initialize to 0 mean not free
* A semaphore is an integer whose value is never allowed to fall below zero.  Two operations can be performed on semaphores:

- increment the semaphore value by one (sem_post(3)); and decrement
the semaphore value by one (sem_wait(3)).
- If the value of a
semaphore is currently zero, then a sem_wait(3) operation will
block until the value becomes greater than zero.

# function
1. sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value)
2. int sem_wait(sem_t *sem) - decrements (locks) the semaphore pointed to by sem.
3. int sem_post(sem_t *sem) - increments (unlocks) the semaphore pointed to by aem.
4. int sem_close(sem_t *sem) - close the semaphore
5. int sem_unlink(const char *name) - when all process have finished using the semaphore, it can removed
from system using sem_unlink().
6. pid_t fork(void) - create a child process
7. int kill(pid_t pid, int sig) - send signal to a process.
8. pid_t waitpid(pid_t pid, int *stat_loc, int options) - wait for a child process to stop

# other function
1. semctl();
2. semget();

# algorithms
1. create fork using semaphore based on philo number by sem_open()
2. create philo using pid by fork()
3. delete philo using waitpid()
4. delete fork using sem_close() and sem_unlink()

# algorithms for semaphore
1. start
2. fork lock using sem_wait
3. philo eat
4. fork unlock using sem_post