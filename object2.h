#ifndef OBJECT2_H
#define OBJECT2_H

//file object2.h
typedef struct obj2 {
    int some_value;
    char c;
    void (*method)(void);
    void (*fire)(int);
    /* ... */

} obj2;

void method2(void);
void fire2(int arg);
obj2* new_obj2();
void delete_obj2(obj2* o);

#endif // OBJECT2_H

