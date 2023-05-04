#include "../inc/libmx.h"

static t_list *create_node(void *data) {
    t_list *node = malloc(sizeof(t_list));
    node->data = data;
    node->next = NULL;
    return node;
}

void mx_push_front(t_list **list, void *data) {
    t_list *front = create_node(data);
    front->next = *list;
    *list = front;
}

