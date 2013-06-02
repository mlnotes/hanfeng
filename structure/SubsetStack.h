/* 
 * File:   SubsetStack.h
 * Author: zhf
 *
 * Created on 2013年6月2日, 下午12:28
 */

#ifndef SUBSETSTACK_H
#define SUBSETSTACK_H

#include "../base/HFObject.h"
#include "../io/HFIO.h"
#include "../structure/HFVector.h"

namespace hanfeng
{

class CSubsetStack : CHFObject {
public:
    CSubsetStack();
    CSubsetStack(const CSubsetStack& orig);
    virtual ~CSubsetStack();
    
    
    virtual bool has_subsets()
    {
        // TODO
        return false;
    }
    
    inline int32_t get_size()
    {
        if(!has_subsets())
            HF_WARNING("CSubsetStack::get_size() No subset in stack");
        
        // TODO
        return 0;
    }
    
    inline index_t subset_idx_conversion(index_t idx) const
    {
        // TODO
        return 0;
    }
    
    virtual void add_subset(HFVector<index_t> subset);
    virtual void remove_subset();
    virtual void remove_all_subsets();
private:

};

}
#endif	/* SUBSETSTACK_H */
