/* 
 * File:   DenseFeatures.h
 * Author: zhf
 *
 * Created on 2013年6月3日, 上午12:26
 */

#ifndef DENSEFEATURES_H
#define DENSEFEATURES_H

#include "DotFeatures.h"
#include "../structure/HFMatrix.h"
#include "../structure/Cache.h"

namespace hanfeng
{

template<class T> class CDenseFeatures : public CDotFeatures{
public:
    CDenseFeatures();
    CDenseFeatures(const CDenseFeatures& orig);
    virtual ~CDenseFeatures();

    virtual EFeatureType get_feature_type() const;
    virtual EFeatureClass get_feature_class() const {return C_DENSE;}
    
    T* get_feature_vector(int32_t num, int32_t &len, bool &dofree);
    HFVector<T> get_feature_vecotr(int32_t num);
    
    void free_feature_vector(T *feat_vec, int32_t num, bool dofree);
    
protected:
    int32_t num_vectors;
    int32_t num_features;
    
    HFMatrix<T> feature_matrix;
    CCache<T> *feature_cache;
};

}
#endif	/* DENSEFEATURES_H */
