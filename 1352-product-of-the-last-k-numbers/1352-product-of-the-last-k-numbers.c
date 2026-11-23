typedef struct {
    int *prefix;
    int size;
    int capacity;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers *obj = (ProductOfNumbers *)malloc(sizeof(ProductOfNumbers));

    obj->capacity = 40001;
    obj->prefix = (int *)malloc(obj->capacity * sizeof(int));

    obj->size = 1;
    obj->prefix[0] = 1;   // prefix product base

    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (num == 0) {
        obj->size = 1;
        obj->prefix[0] = 1;
    } else {
        obj->prefix[obj->size] = obj->prefix[obj->size - 1] * num;
        obj->size++;
    }
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (k >= obj->size)
        return 0;  // a zero exists within last k numbers

    return obj->prefix[obj->size - 1] /
           obj->prefix[obj->size - 1 - k];
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj->prefix);
    free(obj);
}