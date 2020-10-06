#ifndef _INFO_INIT_H_
#define _INFO_INIT_H_
#include "CL/cl.h"

class Info{
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

        virtual cl_platform_id get_platform();
        virtual cl_device_id get_device();
        virtual cl_context get_context();
        virtual cl_command_queue get_command_queue();

        virtual char * get_platform_name();
        virtual char * get_platform_vendor();
        virtual char * get_platform_version();
        virtual char * get_platform_profile();

        virtual char * get_device_name();
        virtual char * get_deice_vendor();
        virtual long get_device_mem_size();

};



#endif 