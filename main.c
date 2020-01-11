#include <stdio.h>
#include <stdlib.h>

typedef void *Any;
typedef Any *Instance;

Instance new(int size) {
    return malloc(size * sizeof(Any));
}

void delete(Instance instance) {
    free(instance);
}

Any get(Instance instance, int index) {
    return instance[index];
}

void set(Instance instance, int index, Any value) {
    instance[index] = value;
}

typedef Instance StringBuilder;

void **StringBuilder() {
    malloc(2 * sizeof(void *));
}

void test() {

}

int main() {
    FILE *source = fopen("main.magma", "r");
    fseek(source, 0, SEEK_END);
    int length = ftell(source);
    fseek(source, 0, SEEK_SET);
    char *buffer = malloc(length);
    if (buffer) {
        fread(buffer, 1, length, source);
    }
    fclose(source);
    char *toWrite = "";
    FILE *out = fopen("out.c", "w");
    fputs("#include <stdio.h>\nint main(){printf(\"Hello World!\");}", out);
    fclose(out);

    system("gcc out.c");
    system("a");

    return 0;
}
