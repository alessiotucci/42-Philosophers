# 42-Philosophers
The Dining Philosopher Problem states that K philosophers are seated around a circular table with one chopstick between each pair of philosophers. There is one chopstick between each philosopher. A philosopher may eat if he can pick up the two chopsticks adjacent to him.

# this project should have been failed for FORBIDDEN FUNCTION ❌
I used the exit() function in the error handling and it was not allowed 😣


# My approach
I have decided to create a single thread for each philospher and then create a monitor thread to monitor them. I will explain how it works...
On the table I have few philosopher and few forks, shared among philos, then there is a single thread that monitor each philosopher, for this reason the total number of thread will be n of philo + 1. 
With the other approach you will have 2x more thread, (if each philo has a thread to monitor himself).

  ### useful resources 
| STEP TO TAKE                                | video                                             |
| --------------------------------------------| ------------------------------------------------- |
|          ...                                |[![process vs threads](https://ytcards.demolab.com/?id=4rLW7zg21gI)](https://www.youtube.com/watch?v=4rLW7zg21gI)
|          ...                                |[![process vs threads](https://ytcards.demolab.com/?id=Dhf-DYO1K78)](https://youtu.be/Dhf-DYO1K78?feature=shared)|
|          ...                                |[![process vs threads](https://ytcards.demolab.com/?id=K1aoimUYTK8)](https://www.youtube.com/watch?v=K1aoimUYTK8)|
|          ...                                |[![process vs threads](https://ytcards.demolab.com/?id=raLCgPK-Igc)](https://www.youtube.com/watch?v=raLCgPK-Igc)|

---

# Allowed Function 
Those are the only function I am allowed to use in this project.

## Functions

| Function                   | Library                  | Prototype                                       |
|----------------------------|--------------------------|-------------------------------------------------|
| memset                     | string.h                 | void *memset(void *s, int c, size_t n);          |
| printf                     | stdio.h                  | int printf(const char *format, ...);            |
| malloc                     | stdlib.h                 | void *malloc(size_t size);                      |
| free                       | stdlib.h                 | void free(void *ptr);                           |
| write                      | unistd.h                 | ssize_t write(int fd, const void *buf, size_t count); |

<br>

---


| Function                   | Library                  | Prototype                                       |  video    |
|----------------------------|--------------------------|-------------------------------------------------|-----------|
| usleep                     | unistd.h                 | int usleep(useconds_t usec);                   |[![](https://ytcards.demolab.com/?id=SjOPUr7Bkmo&ab_channel=PortfolioCourses&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&width=250 "")](https://youtu.be/SjOPUr7Bkmo?feature=shared)
| gettimeofday               | sys/time.h               | int gettimeofday(struct timeval *tv, struct timezone *tz); |[![](https://ytcards.demolab.com/?id=cunJcNgtxMk "")](https://youtu.be/cunJcNgtxMk?feature=shared) |
<br>

## Conversion inside the `my_get_time`

| Variable | Unit         | Description                        | Conversion to Milliseconds (ms) |
|----------|--------------|------------------------------------|---------------------------------|
| `tv_sec` | Seconds (s)  | Whole seconds since the epoch     | `tv_sec * 1000`                 |
| `tv_usec`| Microseconds (μs) | Fractional seconds (microseconds) | `tv_usec / 1000`                |

- `tv_sec` represents the number of whole seconds since the Unix epoch (January 1, 1970).
- `tv_usec` represents the number of microseconds, which is a fraction of a second.

To convert these values to milliseconds:

- For `tv_sec`, you multiply it by 1000 because there are 1000 milliseconds in a second.
- For `tv_usec`, you divide it by 1000 to convert microseconds to milliseconds.

This conversion is often used when working with time-related data in C, as it allows you to work with consistent units (milliseconds) for various time-related calculations.

<br> 
<br>
---
<br>

| Function                   | Library                  | Prototype                                       |
|----------------------------|--------------------------|-------------------------------------------------|
| pthread_create             | pthread.h                | int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg); |
| pthread_detach             | pthread.h                | int pthread_detach(pthread_t thread);          |
| pthread_join               | pthread.h                | int pthread_join(pthread_t thread, void **retval); |
| pthread_mutex_init         | pthread.h                | int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr); |
| pthread_mutex_destroy      | pthread.h                | int pthread_mutex_destroy(pthread_mutex_t *mutex); |
| pthread_mutex_lock         | pthread.h                | int pthread_mutex_lock(pthread_mutex_t *mutex); |
| pthread_mutex_unlock       | pthread.h                | int pthread_mutex_unlock(pthread_mutex_t *mutex); |

I had to watch few videos before fully understanding the mutex concept, after that I had to syncronize the philosopher, to do so I added a very short delay when I create and set the threads

# Bonus part

## Functions

| Function         | Library          | Prototype                                      |
|------------------|------------------|------------------------------------------------|
| fork             | unistd.h         | pid_t fork(void)                               |
| kill             | signal.h         | int kill(pid_t pid, int sig)                   |
| exit             | stdlib.h         | void exit(int status)                         |
| waitpid          | sys/types.h, sys/wait.h | pid_t waitpid(pid_t pid, int *status, int options) |

## 🚦 Semaphores 🚦

| Function         | Library          | Prototype                                      |
|------------------|------------------|------------------------------------------------|
| sem_open         | semaphore.h      | sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value) |
| sem_close        | semaphore.h      | int sem_close(sem_t *sem)                    |
| sem_post         | semaphore.h      | int sem_post(sem_t *sem)                     |
| sem_wait         | semaphore.h      | int sem_wait(sem_t *sem)                     |
| sem_unlink       | semaphore.h      | int sem_unlink(const char *name)             |


<img width="438" alt="image" src="https://github.com/alessiotucci/42-Philosophers/assets/116757689/5558e409-e85e-4fcc-9508-6b319d91099d">
The tester above doens't work vey well, So I was thinking about make my own in the perl programming language.



