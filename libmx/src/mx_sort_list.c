#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool(*cmp)(void *a, void *b)) {
    if (list == NULL || cmp == NULL)
        return NULL;
    t_list *temp = list;
    int count_size = 0;
    while (temp) {
        temp = temp->next;
        count_size++;
    }
    for (int i = 0; i < count_size; i++) {
        temp = list;
        for (int j = 0; j < count_size - 1; j++) {
            if (cmp(temp->data, temp->next->data)) {
                void *temp_data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp_data;
            }
            temp = temp->next;
        }
    }
    return list;
}

