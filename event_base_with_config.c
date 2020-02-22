/**
 * 创建 event_base 并传入参数
 */

#include <event2/event.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    //创建config
    struct event_config *config = NULL;
    config = event_config_new();


    //避免使用，某些method
    event_config_avoid_method(config, "kqueue");


    //用 config 创建 event_base
    struct event_base *base = NULL;
    base = event_base_new_with_config(config);

    // 还可调用其他函数，设置 config ...

    //释放 config
    event_config_free(config);


    const char** meths = event_get_supported_methods();
    for (int i = 0; meths[i] != NULL; ++i) {
        printf("%s\n",meths[i]);
    }

    printf("current = %s\n",event_base_get_method(base));

    event_base_free(base);
    return 0;
}