/* 
 * File:   Parameter.h
 * Author: zhf
 *
 * Created on 2013年6月6日, 下午9:17
 */

#ifndef PARAMETER_H
#define PARAMETER_H

#include "../base/common.h"
#include "../structure/DynArray.h"

namespace hanfeng
{

struct TParameter
{
    
};
    
class Parameter
{
public:
    explicit Parameter();
    virtual ~Parameter();

    virtual void print(const char *prefix="");

    virtual int32_t get_num_parameters()
    {
        // TODO
    }
    
    void set_from_parameters(Parameter *params);
    void add_parameters(Parameter *params);
    bool contains_paramter(const char *name);
    
    inline TParameter* get_parameter(int32_t idx)
    {
        // TODO
    }
    
    inline TParameter* get_parameter(const char *name)
    {
        // TODO
    }
    
    void add(float64_t *param, char *name, const char *description="");
private:
    
protected:
    DynArray<TParameter*> params_;

};


}

#endif	/* PARAMETER_H */
