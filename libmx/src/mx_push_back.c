#include "../inc/libmx.h"

static t_list *create_node(void *data) {
    t_list *node = malloc(sizeof(t_list));
    node->data = data;
    node->next = NULL;
    return node;
}

void mx_push_back(t_list **list, void *data) {
    t_list *back = create_node(data);
    t_list *temp = NULL;
    if (*list == NULL || list == NULL)
        *list = back;
    else {
        temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = back;
    }
}

