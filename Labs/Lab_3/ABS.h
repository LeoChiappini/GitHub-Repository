#pragma once
#include <iostream>
//#include "leaker.h"

using namespace std;

template<typename T> 
class ABS {

    private:
        const float scaleFactor = 2.0f;
        unsigned int maxCapacity;
        unsigned int size;
        T* stack_arr;

    public:
        ABS() {
            maxCapacity = 1;
            size = 0;
            stack_arr = new T[maxCapacity];
        }

        ABS(int capacity) {
            maxCapacity = capacity;
            size = 0;
            stack_arr = new T[maxCapacity];
        }

        // Copy Constructor
        ABS(const ABS &d) {
            maxCapacity = d.getMaxCapacity();
            size = d.getSize();
            stack_arr = new T[maxCapacity];
            for(int i=0; i < (int)size; i += 1) {
                stack_arr[i] = d.getData()[i];
            }
            delete[] d.stack_arr;
        }

        // Assignment Operator
        ABS &operator=(const ABS &d){
            maxCapacity = d.getMaxCapacity();
            size = d.getSize();
            stack_arr = d.getData();
        }

        // Destructor
        ~ABS() {
            delete[] stack_arr;
        }

        void push(T data) {
            // Resizes if necessary
            if (size == maxCapacity) {
                maxCapacity = (unsigned int)(maxCapacity * scaleFactor);
                T* hold = new T[maxCapacity];
                for(int i = 0; i < (int)size; i += 1) {
                    hold[i] = stack_arr[i];
                }
                delete[] stack_arr;
                stack_arr = hold;
            }

            // Pushes element on top of stack
            stack_arr[size] = data;
            size += 1;
        }

        T pop() {
            // Resizes (if necessary)
            if (size == 0)
                throw std::runtime_error("Stack is empty");

            // Removes item on top of stack
            size -= 1;
            T item = stack_arr[size];

            if (((float)(size)/(float)maxCapacity) < (float)(1/scaleFactor)) {
                maxCapacity = maxCapacity/(int)scaleFactor;
                T* hold = new T[(int)(maxCapacity)]; // Overflows
                for(int i = 0; i < (int)size; i += 1) {
                    hold[i] = stack_arr[i];
                }
                delete[] stack_arr;
                stack_arr = hold;
            }

            return item;
        }

        T peek() {
            if (size == 0)
                    throw std::runtime_error("Stack is empty");

            return stack_arr[size - 1];
        }

        unsigned int getSize(){return size;}

        unsigned int getMaxCapacity() {return maxCapacity;}

        T* getData() {return &stack_arr;}

};