/**
 * 查看支持的 io 多路复用模型；和当前使用的模型；
 */

#include <event2/event.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    struct event_base *base = NULL;

    base = event_base_new();

    const char** meths = event_get_supported_methods();
    for (int i = 0; meths[i] != NULL; ++i) {
        printf("%s\n",meths[i]);
    }

    printf("current = %s\n",event_base_get_method(base));

    event_base_free(base);
    return 0;
}