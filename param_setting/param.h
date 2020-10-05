#ifndef _PARAM_H_
#define _PARAM_H_

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

#endif 