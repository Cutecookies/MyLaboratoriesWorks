# include <assert.h>
# include <memory.h>
# include <stdio.h>
# include <stdbool.h>
# include "ordered_array_set.h"

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

ordered_array_set ordered_array_set_create_from_array(const int *a,
                                                      size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++){
        ordered_array_set_insert(&set, a[i]);
    }
    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

bool ordered_array_set_isEqual(ordered_array_set set1,
                               ordered_array_set set2) {
    return memcmp(set1.data, set2.data, set1.size) == 0;
}

bool ordered_array_set_isSubset(ordered_array_set subset,
                                ordered_array_set set) {
    int amount_equal = 0;
    int i = 0;
    int j = 0;
    while (i < subset.size && j < set.size) {
        if (subset.data[i] == set.data[j]) {
            amount_equal++;
            i++;
            j++;
        } else if (subset.data[i] > set.data[j])
            j++;
        else
            i++;
    }

    return amount_equal == subset.size;
}


void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) == set->size) {
        ordered_array_set_isAbleAppend(set);
        size_t index = binarySearchMoreOrEqual_(set->data, set->size, value);
        insert_(set->data, &set->size, index, value);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) != set->size){
        size_t ind = ordered_array_set_in(set, value);
        deleteByPosSaveOrder_(set->data, &set->size, ind);
    }
}

ordered_array_set ordered_array_set_union(ordered_array_set set1,
                                          ordered_array_set set2) {
    ordered_array_set set_res = ordered_array_set_create(0);
    int i = 0;
    int j = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] == set2.data[j]) {
            set_res.data[set_res.size++] = set2.data[j++];
            i++;
        }
        else if (set1.data[i] > set2.data[j]){
            set_res.data[set_res.size++] = set2.data[j++];
        } else {
            set_res.data[set_res.size++] = set1.data[i++];
        }
    }

    while (i < set1.size) {
        set_res.data[set_res.size++] = set1.data[i++];
    }
    while (j < set2.size) {
        set_res.data[set_res.size++] = set2.data[j++];
    }
    set_res.capacity = set_res.size;

    return set_res;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set
                                                 set1, ordered_array_set set2) {
    ordered_array_set set_res = ordered_array_set_create(0);
    int i = 0;
    int j = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] == set2.data[j]) {
            set_res.data[set_res.size++] = set2.data[j++];
            i++;
        }
        else if (set1.data[i] > set2.data[j]){
            j++;
        } else {
            i++;
        }
    }
    set_res.capacity = set_res.size;

    return set_res;
}

ordered_array_set ordered_array_set_difference(ordered_array_set
                                               set1, ordered_array_set set2) {
    ordered_array_set set_res = ordered_array_set_create(0);
    int i = 0;
    int j = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] == set2.data[j]) {
            i++;
            j++;
        }
        else if (set1.data[i] < set2.data[j]){
            set_res.data[set_res.size++] = set1.data[i++];
        } else {
            j++;
        }
    }

    while (i < set1.size) {
        set_res.data[set_res.size++] = set1.data[i++];
    }

    set_res.capacity = set_res.size;

    return set_res;
}

ordered_array_set ordered_array_set_symmetricDifference(
        ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set_res = ordered_array_set_create(0);
    int i = 0;
    int j = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] == set2.data[j]) {
            i++;
            j++;
        }
        else if (set1.data[i] < set2.data[j]){
            set_res.data[set_res.size++] = set1.data[i++];
        } else {
            set_res.data[set_res.size++] = set2.data[j++];
        }
    }

    while (i < set1.size)
        set_res.data[set_res.size++] = set1.data[i++];
    while (j < set2.size)
        set_res.data[set_res.size++] = set2.data[j++];

    set_res.capacity = set_res.size;

    return set_res;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set,
                                               ordered_array_set universumSet) {
    ordered_array_set set_res = ordered_array_set_create(0);
    int i = 0;
    int j = 0;
    while (i < universumSet.size && j < set.size) {
        if (universumSet.data[i] == set.data[j]) {
            i++;
            j++;
        }
        else if (universumSet.data[i] < set.data[j]){
            set_res.data[set_res.size++] = universumSet.data[i++];
        } else {
            j++;
        }
    }

    while (i < universumSet.size) {
        set_res.data[set_res.size++] = universumSet.data[i++];
    }

    set_res.capacity = set_res.size;

    return set_res;
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++)
        printf("%d, ", set.data[i]);

    if (!set.size)
        printf("}\n");
    else
        printf("\b\b}\n");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
    set.size = 0;
    set.capacity = 0;
}