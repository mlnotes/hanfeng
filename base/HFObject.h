/* 
 * File:   HFObject.h
 * Author: zhf
 *
 * Created on 2013年6月2日, 上午1:45
 */

#ifndef BASE_HFOBJECT_H
#define BASE_HFOBJECT_H

namespace hanfeng
{

    // TODO
#define HF_REF(x)
#define HF_UNREF(x)
    
class CHFObject {
public:
    CHFObject();
    CHFObject(const CHFObject& orig);
    virtual ~CHFObject();
private:

};

}

#endif	/* BASE_HFOBJECT_H */
