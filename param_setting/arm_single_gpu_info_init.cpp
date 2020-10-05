#include "arm_single_gpu_info_init.h"
#include<iostream>

using namespace std;

/*
这里假设只有一种平台，只有一个GPU
*/
ASGInfo::ASGInfo(void){
    //获取平台信息
    clGetPlatformIDs(1, &platform, NULL);
    clGetPlatformInfo(platform, CL_PLATFORM_NAME, sizeof(platform_name), &platform_name, NULL);
    clGetPlatformInfo(platform, CL_PLATFORM_VENDOR, sizeof(platform_vendor), &platform_vendor, NULL);
    clGetPlatformInfo(platform, CL_PLATFORM_VERSION, sizeof(platform_version), &platform_version, NULL);
    clGetPlatformInfo(platform, CL_PLATFORM_PROFILE, sizeof(platform_profile), &platform_profile, NULL);

    //获取设备信息
    clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
    clGetDeviceInfo(device, CL_DEVICE_NAME, sizeof(device_name), &device_name, NULL);
    clGetDeviceInfo(device, CL_DEVICE_VENDOR, sizeof(device_vendor), &device_vendor, NULL);
    clGetDeviceInfo(device, CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(device_mem_size), &device_mem_size, NULL);

    //获取上下文
    //clCreateContext(properties, num_devices, devices, pfn_notify, user_data_ptr, errcode_ret);
    context = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);

    //获取命令队列,好像是clCreateCommandQueue这个函数接口被废弃了
    commandQueue = clCreateCommandQueueWithProperties(context, device, NULL, NULL);

}

cl_platform_id ASGInfo::get_platform(){
    return platform;
}

cl_device_id ASGInfo::get_device(){
    return device;
}

cl_context ASGInfo::get_context(){
    return context;
}

cl_command_queue ASGInfo::get_command_queue(){
    return commandQueue;
}

char *  ASGInfo::get_platform_name(){
    return platform_name;
}

char * ASGInfo::get_platform_vendor(){
    return platform_vendor;
}

char *  ASGInfo::get_platform_version(){
    return platform_version;
}

char *  ASGInfo::get_platform_profile(){
    return platform_profile;
}

char *  ASGInfo::get_device_name(){
    return device_name;
}

char *  ASGInfo::get_deice_vendor(){
    return device_vendor;
}

long  ASGInfo::get_device_mem_size(){
    return device_mem_size;
}

