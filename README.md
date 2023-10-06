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

## Library: string.h

| Function | Prototype |
|----------|-----------|
| memset   | `void *memset(void *s, int c, size_t n);` |

## Library: stdio.h

| Function | Prototype                                      |
|----------|------------------------------------------------|
| printf   | `int printf(const char *format, ...);`          |

## Library: stdlib.h

| Function | Prototype                          |
|----------|------------------------------------|
| malloc   | `void *malloc(size_t size);`        |
| free     | `void free(void *ptr);`             |

## Library: unistd.h

| Function   | Prototype                                |
|------------|------------------------------------------|
| write      | `ssize_t write(int fd, const void *buf, size_t count);` |
| usleep     | `int usleep(useconds_t usec);`            |
| gettimeofday | `int gettimeofday(struct timeval *tv, struct timezone *tz);` |

## Library: pthread.h

| Function           | Prototype                                      |
|--------------------|------------------------------------------------|
| pthread_create     | `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);` |
| pthread_detach     | `int pthread_detach(pthread_t thread);`          |
| pthread_join       | `int pthread_join(pthread_t thread, void **retval);` |
| pthread_mutex_init | `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);` |
| pthread_mutex_destroy | `int pthread_mutex_destroy(pthread_mutex_t *mutex);` |
| pthread_mutex_lock | `int pthread_mutex_lock(pthread_mutex_t *mutex);` |
| pthread_mutex_unlock | `int pthread_mutex_unlock(pthread_mutex_t *mutex);` |



