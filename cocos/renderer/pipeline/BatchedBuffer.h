#pragma once

#include "Define.h"

namespace cc {
class Pass;
class SubModel;

namespace pipeline {

struct CC_DLL BatchedItem {
    gfx::GFXBufferList vbs;
    uint8_t *vbDatas = nullptr;
    gfx::GFXBuffer *vbIdx = nullptr;
    float *vbIdxData = nullptr;
    uint mergCount = 0;
    gfx::GFXInputAssembler *ia = nullptr;
    gfx::GFXBuffer *ubo = nullptr;
    cc::PSOCreateInfo *psoCreatedInfo = nullptr;
};
typedef gfx::vector<BatchedItem> BatchedItemList;

class CC_DLL BatchedBuffer : public gfx::Object {
public:
    BatchedBuffer(cc::Pass *pass);
    ~BatchedBuffer() = default;

    void destroy();
    void merge(cc::SubModel *, uint passIdx, RenderObject *);
    void clear();
    void clearUBO();

    CC_INLINE const BatchedItemList &getBaches() const { return _batchedItems; }
    CC_INLINE cc::Pass *getPass() const { return _pass; }

private:
    //    const _localBatched = new UBOLocalBatched();
    BatchedItemList _batchedItems;
    cc::Pass *_pass = nullptr;
};

} // namespace pipeline
} // namespace cc