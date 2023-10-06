# 42-Philosophers
The Dining Philosopher Problem states that K philosophers are seated around a circular table with one chopstick between each pair of philosophers. There is one chopstick between each philosopher. A philosopher may eat if he can pick up the two chopsticks adjacent to him.

  ### useful resources 
| STEP TO TAKE                                | video                                             |
| --------------------------------------------| ------------------------------------------------- |
|          ...                                |[![process vs threads](https://ytcards.demolab.com/?id=4rLW7zg21gI)](https://www.youtube.com/watch?v=4rLW7zg21gI)
|          ...                                |[![process vs threads](https://ytcards.demolab.com/?id=Dhf-DYO1K78)](https://youtu.be/Dhf-DYO1K78?feature=shared)|
|          ...                                |[![process vs threads](https://ytcards.demolab.com/?id=K1aoimUYTK8)](https://www.youtube.com/watch?v=K1aoimUYTK8)|
|          ...                                |[![process vs threads](https://ytcards.demolab.com/?id=raLCgPK-Igc)](https://www.youtube.com/watch?v=raLCgPK-Igc)|



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

| Function                   | Library                  | Prototype                                       |  video    |
|----------------------------|--------------------------|-------------------------------------------------|-----------|
| usleep                     | unistd.h                 | int usleep(useconds_t usec);                   |[![](https://ytcards.demolab.com/?id=SjOPUr7Bkmo&ab_channel=PortfolioCourses&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&width=250 "")](https://youtu.be/SjOPUr7Bkmo?feature=shared)

| gettimeofday               | sys/time.h               | int gettimeofday(struct timeval *tv, struct timezone *tz); |

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



