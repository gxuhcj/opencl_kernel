#ifndef _PARAM_H_
#define _PARAM_H_
#include "CL/cl.h"
#include "arm_single_gpu_info_init.h"
#include "info_init.h"


template<class T>
class Param {
public:

    T info;

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

    cl_program get_program(char *code_file){
        cl_program program;
        try{
            FILE *program_handle = fopen(code_file, "r");
            fseek(program_handle, 0, SEEK_END);
            int program_size = ftell(program_handle);
            rewind(program_handle);
            char *program_buffer = (char*)malloc(program_size+1);
            program_buffer[program_size] = '\0';
            fread(program_buffer, sizeof(char), program_size, program_handle);
            fclose(program_handle);
            size_t sourceSize[] = { strlen(program_buffer) };
            const char *program_buffer_f = program_buffer;
            program = clCreateProgramWithSource(context, 1, &program_buffer_f, sourceSize, NULL);
            status = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
        }
        catch(exception e){
            return NULL;
        }
        return program;
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
};
#endif 