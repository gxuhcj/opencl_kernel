#ifndef _ARM_SINGLE_GPU_INFO_INIT_H_
#define _ARM_SINGLE_GPU_INFO_INIT_H_

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

};



#endif 