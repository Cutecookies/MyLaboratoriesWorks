add_library(data_structures
        bitset/bitset.c
        bitset/bitset.h
        vector/vector.c
        vector/vectorVoid.c
        matrix/matrix.c

)

target_link_libraries(data_structures algorithms)