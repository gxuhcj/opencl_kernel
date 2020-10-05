#include "param.h"
#include<iostream>

using namespace std;

ASGInfo info;


cl_platform_id get_platform(){
    return info.get_platform();
}

cl_device_id get_device(){
    return info.get_device();
}

cl_context get_context(){
    return info.get_context();
}

cl_command_queue get_command_queue(){
    return info.get_command_queue();
}


char * get_platform_name(){
    return info.get_platform_name();
}

char * get_platform_vendor(){
    return info.get_platform_vendor();
}

char * get_platform_version(){
    return info.get_platform_version();
}

char * get_platform_profile(){
    return info.get_platform_profile();
}

char * get_device_name(){
    return info.get_device_name();
}

char * get_deice_vendor(){
    return info.get_deice_vendor();
}

long get_device_mem_size(){
    return info.get_device_mem_size();
}