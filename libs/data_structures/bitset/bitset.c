# include <stdio.h>
# include <stdbool.h>
# include <assert.h>
# include "bitset.h"

bitset bitset_create(unsigned maxValue) {
    assert (maxValue < 32);
    return (bitset) {0, maxValue};
}

bool bitset_in(bitset set, unsigned int value) {
    return (set.values >> value) % 2 != 0;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (set.values & subset.values) == subset.values;
}

// добавляет элемент value в множество set
void bitset_insert(bitset *set, unsigned int value) {
    unsigned other_values = 1;
    for (int i = 0; i < value; i++)
        other_values *= 2;
    set->values += other_values;
}

// удаляет элемент value из множества set
void bitset_deleteElement(bitset *set, unsigned int value) {
    unsigned other_values = 1;
    for (int i = 0; i < value; i++)
        other_values *= 2;
    set->values -= other_values;
}

bitset bitset_union(bitset set1, bitset set2) {
    assert (set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert (set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    assert (set1.maxValue == set2.maxValue);
    return (bitset) {((set2.values | set1.values)
                      & set1.values) -
                     (set1.values & set2.values),
                     set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert (set1.maxValue == set2.maxValue);
    return (bitset) {(set2.values | set1.values) -
                     (set1.values & set2.values),
                     set1.maxValue};
}

bitset bitset_complement(bitset set) {
    unsigned all_values = 0;
    unsigned max_values = 1;
    for (int i = 0; i < set.maxValue; i++){
        all_values += max_values;
        max_values *= 2;
    }

    return (bitset) {all_values - set.values,
                     set.maxValue};
}

void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

