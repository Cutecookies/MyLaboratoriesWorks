# include <assert.h>
# include <stdio.h>
# include <stdbool.h>
# include <malloc.h>
# include "../../algorithms/array/array.h"
# include "unordered_array_set.h"

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

unordered_array_set unordered_array_set_create_from_array(
        const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    return set;
}

size_t unordered_array_set_in(unordered_array_set set, int value) {
    return linearSearch_(set.data, set.size, value);
}

bool unordered_array_set_isSubset(unordered_array_set subset,
                                  unordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++)
        if (unordered_array_set_in(set, subset.data[i]) == set.size)
            return 0;
    return 1;
}

bool unordered_array_set_isEqual(
        unordered_array_set set1, unordered_array_set set2) {
    return unordered_array_set_symmetricDifference(set1, set2).size == 0;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

void unordered_array_set_insert(
        unordered_array_set *set, int value) {
    if (unordered_array_set_in(*set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

void unordered_array_set_deleteElement(
        unordered_array_set *set, int value) {
    if (unordered_array_set_in(*set, value) != set->size)
        deleteByPosUnsaveOrder_(set->data, &set->size,
                                unordered_array_set_in(*set, value));
}

unordered_array_set unordered_array_set_union(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set_res = unordered_array_set_create(set1.capacity);
    set_res.size = set1.size;
    for (size_t i = 0; i < set1.size; i++) {
        set_res.data[i] = set1.data[i];
    }

    for (size_t i = 0; i < set1.size; i++) {
        if (!unordered_array_set_in(set1, set2.data[i]))
            unordered_array_set_insert(&set_res, set2.data[i]);
    }

    return set_res;
}

unordered_array_set unordered_array_set_intersection(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set_res = unordered_array_set_create(0);
    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(set2, set1.data[i])) {
            set_res.data[set_res.size++] = set1.data[i];
            set_res.capacity++;
        }

    return set_res;
}

unordered_array_set unordered_array_set_difference(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set_res = unordered_array_set_create(0);
    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(set2, set1.data[i]) == set2.size) {
            set_res.data[set_res.size++] = set1.data[i];
            set_res.capacity++;
        }

    return set_res;
}

unordered_array_set unordered_array_set_complement(
        unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set set_res =
            unordered_array_set_difference(universumSet, set);
    assert(unordered_array_set_isSubset(set_res, universumSet));
    return set_res;
}

unordered_array_set unordered_array_set_symmetricDifference(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set_res1 = unordered_array_set_create(0);
    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(set2, set1.data[i]) == set2.size) {
            set_res1.data[set_res1.size++] = set1.data[i];
            set_res1.capacity++;
        }


    unordered_array_set set_res2 = unordered_array_set_create(0);
    for (size_t i = 0; i < set2.size; i++)
        if (unordered_array_set_in(set1, set2.data[i]) == set1.size) {
            set_res2.data[set_res2.size++] = set2.data[i];
            set_res2.capacity++;
        }

    unordered_array_set set_res = unordered_array_set_union(set_res1, set_res2);
    unordered_array_set_delete(set_res1);
    unordered_array_set_delete(set_res2);

    return set_res;
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++)
        printf("%d, ", set.data[i]);

    if (!set.size)
        printf("}\n");
    else
        printf("\b\b}\n");
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
    set.size = 0;
    set.capacity = 0;
}
