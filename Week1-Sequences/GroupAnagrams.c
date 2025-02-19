int compare(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}
void sort_string(char *str) {
    qsort(str, strlen(str), sizeof(char), compare);
}
void print_groups(char ***result, int group_count, int *group_sizes) {
    for (int i = 0; i < group_count; i++) {
        printf("Group %d: ", i + 1);
        for (int j = 0; j < group_sizes[i]; j++) {
            printf("%s ", result[i][j]);
        }
        printf("\n");
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    
    char*** result = (char ***)malloc(strsSize * sizeof(char **));
    *returnColumnSizes = (int *)malloc(strsSize * sizeof(int));
    int group_count = 0;


    char*** groups = (char ***)malloc(strsSize * sizeof(char **));
    int* group_sizes = (int *)malloc(strsSize * sizeof(int));
    char** keys = (char **)malloc(strsSize * sizeof(char *));
    
 
    for (int i = 0; i < strsSize; i++) {
        group_sizes[i] = 0;
    }


    for (int i = 0; i < strsSize; i++) {
    
        char* sorted_str = strdup(strs[i]);
        sort_string(sorted_str);
        
        int found_group = 0;

        for (int j = 0; j < group_count; j++) {
            if (strcmp(keys[j], sorted_str) == 0) {
                groups[j] = (char **)realloc(groups[j], (group_sizes[j] + 1) * sizeof(char *));
                groups[j][group_sizes[j]] = strs[i];
                group_sizes[j]++;
                found_group = 1;
                break;
            }
        }


        if (!found_group) {
            groups[group_count] = (char **)malloc(sizeof(char *));
            groups[group_count][0] = strs[i];
            keys[group_count] = sorted_str;
            group_sizes[group_count] = 1;
            group_count++;
        } else {
            free(sorted_str); 
        }
    }

    *returnSize = group_count;
    for (int i = 0; i < group_count; i++) {
        (*returnColumnSizes)[i] = group_sizes[i];
        result[i] = groups[i];
    }

    free(groups);
    free(group_sizes);
    free(keys);


    return result;
}
