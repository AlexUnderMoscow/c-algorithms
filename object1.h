#ifndef OBJECT1_H
#define OBJECT1_H

//file object1.h
 typedef struct obj1 {
    void *self;
    int some_value;
    char c;
    void (*method)(void);
    void (*fire)(int);
    /* ... */

} obj1;

void method1(void);
void fire1(int arg);
obj1* new_obj1();
void delete_obj1(obj1* o);

#endif // OBJECT1_H

