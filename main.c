#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "slabs.h"
#include "hashtable.h"


//main
int main(void) {
    slabs_init(60240000);
    
    FILE *fp = fopen("data.txt", "r");
    HashTable *ht = _create_hashtable(1024);
    int counter = 0;
    while (!feof(fp) ) {
        char buf[1024] = {0};
        fgets(buf,1024,fp);
        char key[8] = {0};
        char value[100] = {0};
        sscanf(buf, "%s\t%s\n", key, value);
        if (hash_add(ht, key, str_hval(value)) == -1) {
            printf("add key error:key= %s\n", key);
	    exit(1);
        } 
        counter++;
    }
    fclose(fp);


    HValue *ret = NULL;
    hash_find(ht, "key3", &ret);
    printf("result = %s\n", ret->str.val);
    return 0;
}
