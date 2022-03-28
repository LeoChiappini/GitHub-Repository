#pragma once
#include <iostream>
//#include "leaker.h"

using namespace std;

template<typename T> 
class ABQ {

    private:
        const float scaleFactor = 2.0f;
        unsigned int maxCapacity;
        unsigned int size;
        T* q_arr;

    public:
        ABQ() {
            maxCapacity = 1;
            size = 0;
            q_arr = new T[maxCapacity];
        }

        ABQ(int capacity) {
            maxCapacity = capacity;
            size = 0;
            q_arr = new T[maxCapacity];
        }

        // Copy Constructor
        ABQ(const ABQ &d) {
            maxCapacity = d.getMaxCapacity();
            size = d.getSize();
            q_arr = new T[maxCapacity];
            for(int i=0; i < (int)size; i += 1) {
                q_arr[i] = d.getData()[i];
            }
            delete[] d.q_arr;
        }

        // Assignment Operator
        ABQ &operator=(const ABQ &d) {
            maxCapacity = d.getMaxCapacity();
            size = d.getSize();
            q_arr = d.getData();
        }

        // Destructor
        ~ABQ() {
            delete[] q_arr;
        }

        void enqueue(T data) {
            // Resizes if necessary
            if (size == maxCapacity) {
                maxCapacity = (unsigned int)(maxCapacity * scaleFactor);
                T* hold = new T[maxCapacity];
                for(int i = 0; i < (int)size; i += 1) {
                    hold[i] = q_arr[i];
                }
                delete[] q_arr;
                q_arr = hold;
            }

            // Pushes element on top of queue
            q_arr[size] = data;
            size += 1;
        }

        T dequeue() {
            // Throws error if queue is empty
            if (size == 0)
                throw std::runtime_error("Queue is empty");

            // Removes item on top of queue
            T item = q_arr[0];

            // Shifts elements in the array downwards to reflect dequeuing 
            for(int i = 1; i < (int)size; i += 1) {
                q_arr[i-1] = q_arr[i];
            }

            size -= 1;
            if (((float)(size)/(float)maxCapacity) < (float)(1/scaleFactor)) {
                maxCapacity = maxCapacity/(int)scaleFactor;
                T* hold = new T[(int)(maxCapacity)];
                for(int i = 0; i < (int)size; i += 1) {
                    hold[i] = q_arr[i];
                }
                delete[] q_arr;
                q_arr = hold;
            }

            return item;
        }

        T peek() {
            if (size == 0)
                    throw std::runtime_error("Queue is empty");
            return q_arr[0];
        }

        unsigned int getSize() { return size; }

        unsigned int getMaxCapacity() { return maxCapacity; }

        T* getData() { return q_arr;}
};