/* -----------------------------------------------------------------------------
 * Component Name: Downlink Queue
 * Parent Component: Telemetry
 * Author(s): Adam Smialek
 * Purpose: Provide a queue for telemetry messages to be sent to ground.
 *
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//#include "downlink_queue.h"
//#include "global_utils.h"

/*!
 * This module provides a priority queue for the telemetry module. It uses
 * linked list to solve the priority sorting, where the head of the list is
 * of a highest priority.
 *
 * /todo: Question - In header file, do we define every prototype that we need
 *        to use, or just the ones that are used outside, and the rest in the
 *        file locally?
 * /todo: Question - Do we define MAX_LENGTH for the queue? If so, is it max
 *        size of the data in it, or max number of nodes?
 * /todo: Define the data types for the telemetry.
 * /todo: Define priority values for the possible telemetry types.
 */

pthread_mutex_t downlink_mutex = PTHREAD_MUTEX_INITIALIZER;

//int init_downlink_queue(void) {
//    return SUCCESS;
//}

/*!
 * Node structure declaration.
 */
typedef struct node {
    int data;           // Data to be send as a telemetry.
    int priority;       // Lower values indicate higher priority
    struct node *next;  // Pointer to the node next on the list.

} downlink_node;

/*!
 * Function to create a new node
 *
 * @param d     Data to be sent.
 * @param p     Priority of the data.
 */
downlink_node *new_node(int d, int p) {
    downlink_node *temp = (downlink_node *) malloc(sizeof(downlink_node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

/*!
 * Function to check if the list is empty
 *
 * @param head  Pointer to the first node of the linked list.
 * @return      1 if the list is empty, 0 if not.
 */
int is_empty(downlink_node **head) {
    return (*head) == NULL;
}
//int is_empty(downlink_node **head)
//{
//    return (*head) == NULL;
//}

/*!
 * Return the value at head of the list.
 *
 * @param head  Pointer to the first node of the linked list.
 * @return      Data from the head node.
 */
int peek(downlink_node **head) {
    if (!is_empty(head)) {
        return (*head)->data;
    } else {
        return -1;
    }
}

/*!
 * Removes the element with the highest priority form the list and
 * return it's data value.
 *
 * @param head  Pointer to the first node of the linked list.
 * @return      Data from the popped node.
 */
int pop(downlink_node **head) {
    if (!is_empty(head)) {
        downlink_node *temp = *head;
        int data = (*head)->data;
        (*head) = (*head)->next;
        free(temp);
        return data;
    } else {
        return -1;
    }
}

/*!
 * Function to push node to the list according to its priority.
 *
 * @param head  Pointer to the first node of the linked list.
 * @param d     Data to be sent.
 * @param p     Priority of the data.
 */
void push(downlink_node **head, int d, int p) {
    downlink_node *start = (*head);

    // Create new node
    downlink_node *temp = new_node(d, p);

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->priority > p) {
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    } else {
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
               start->next->priority <= p) {
            start = start->next;
        }
        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}

/*!
 * Put data into the queue.
 *
 * @param head  Pointer to the first node of the linked list.
 * @param d     Data to be sent.
 * @param p     Priority of the data.
 * @return      0
 */
int send_telemetry_local(downlink_node **head, int d, int p) {

    pthread_mutex_lock(&downlink_mutex);

    if (!is_empty(head)) {
        push(head, d, p);
    } else {
        *head = new_node(d, p);
    }

    pthread_mutex_unlock(&downlink_mutex);

    return 0;
}

/*!
 * Return the data of the oldest message of the highest priority.
 *
 * @param head  Pointer to the first node of the linked list.
 * @return      Data from the first node of the linked list.
 */
int read_downlink_queue(downlink_node **head) {

    pthread_mutex_lock(&downlink_mutex);

    int data = pop(head);

    pthread_mutex_unlock(&downlink_mutex);

    return data;
}


int main()
{
    // Create a Priority Queue
    // 7->4->5->6
    downlink_node* downlink_queue = NULL;

    downlink_queue = new_node(22, 0);
    push(&downlink_queue, 1, 2);
    push(&downlink_queue, 2, 2);
    push(&downlink_queue, 3, 2);
    push(&downlink_queue, 4, 2);
    push(&downlink_queue, 10, 0);
    push(&downlink_queue, 5, 2);
    push(&downlink_queue, 6, 2);
    push(&downlink_queue, 7, 2);
    push(&downlink_queue, 99, 3);
    push(&downlink_queue, 8, 2);
    push(&downlink_queue, 9, 2);
//    push(&downlink_queue, 6, 3);
//    push(&downlink_queue, 7, 0);

//    while (!is_empty(&pq)) {
    printf("Start\n");
    while (1) {
        while(!is_empty(&downlink_queue)) {
            printf("%d \n", pop(&downlink_queue));
        }
//        send_telemetry_local(&downlink_queue, 2, 3);
//        send_telemetry_local(&downlink_queue, 3, 1);
//        send_telemetry_local(&downlink_queue, 12, 2);
//        send_telemetry_local(&downlink_queue, 15, 0);
    }
    printf("End\n");

    return 0;
}
