/*
* ProjectInfo: 
* File name:  slabs.h
* @author:    pandaychen
* @version:     
* Description: 	SLAB内存分配算法的接口定义
* Log:
*/


#ifndef _SLABS_H
#define _SLABS_H

//slab 算法定义

#ifdef __cplusplus
extern "C"
{
#endif

    unsigned int slabs_clsid(unsigned int size);

    void slabs_init(unsigned int limit);

    int slabs_newslab(unsigned int id);

    void *slabs_alloc(unsigned int size);
    
    void slabs_free(void *ptr, unsigned int size);

    char* print_slabs_stats(int *buflen);

#ifdef __cplusplus
}
#endif



#endif
