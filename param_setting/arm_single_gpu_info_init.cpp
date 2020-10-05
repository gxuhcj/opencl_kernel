#include "CL/cl.h"
#include "arm_single_gpu_info_init.h"
#include<iostream>

using namespace std;

class ASGInfo{
    private:
        cl_platform_id platform;
        cl_device_id  device;
        cl_context  context;
        cl_command_queue commandQueue;

        char platform_name[40];
        char platform_vendor[40];
        char platform_version[40];
        char platform_profile[40];

        char device_name[40];
        char device_vendor[40];
        long device_mem_size;
    
    public:
        ASGInfo();

        cl_platform_id get_platform();
        cl_device_id get_device();
        cl_context get_context();
        cl_command_queue get_command_queue();

        char * get_platform_name();
        char * get_platform_vendor();
        char * get_platform_version();
        char * get_platform_profile();

        char * get_device_name();
        char * get_deice_vendor();
        long get_device_mem_size();

}

/*
这里假设只有一种平台，只有一个GPU
*/
Info::ASGInfo(void){
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

Info:: cl_platform_id get_platform(){
    return platform;
}

Info:: cl_device_id get_device(){
    return device;
}

Info:: cl_context get_context(){
    return context;
}

Info:: cl_command_queue get_command_queue(){
    return commandQueue;
}

Info:: char * get_platform_name(){
    return platform_name;
}

Info:: char * get_platform_vendor(){
    return platform_vendor;
}

Info:: char * get_platform_version(){
    return platform_version;
}

Info:: char * get_platform_profile(){
    return platform_profile;
}

Info:: char * get_device_name(){
    return device_name;
}

Info:: char * get_deice_vendor(){
    return device_vendor;
}

Info:: long get_device_mem_size(){
    return device_mem_size;
}

