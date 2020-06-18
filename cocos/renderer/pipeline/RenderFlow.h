#pragma once

#include "Define.h"

namespace cc {
namespace pipeline {

class RenderPipeline;
class RenderStage;
class RenderView;

struct CC_DLL RenderFlowInfo {
    //TODO
};

class CC_DLL RenderFlow : public gfx::Object {
public:
    RenderFlow() = default;
    virtual ~RenderFlow() = default;

    virtual bool initialize(const RenderFlowInfo &info);
    virtual void activate(RenderPipeline *pipeline);
    virtual void resize(uint width, uint height);
    virtual void render(RenderView *view);

    virtual void destroy() = 0;
    virtual void rebuild() = 0;

    void destroyStages();

    CC_INLINE const gfx::GFXDevice *getDevice() const { return _device; }
    CC_INLINE const RenderPipeline *getPipeline() const { return _pipeline; }
    CC_INLINE const gfx::String &getName() const { return _name; }
    CC_INLINE int getPriority() const { return _priority; }
    CC_INLINE const RenderStageList &getStages() const { return _stages; }
    //    CC_INLINE const Material *getMaterial() const { return _material; }
    //    CC_INLINE RenderFlowType getType() const { return _type; }

protected:
    void activateStages();

protected:
    gfx::GFXDevice *_device = nullptr;
    RenderPipeline *_pipeline = nullptr;
    gfx::String _name;
    int _priority = 0;
    RenderStageList _stages;
    //    Material *_material = nullptr;
    //    RenderFlowType _type = ;
};

} // namespace pipeline
} // namespace cc