#pragma once

#include "runtime/function/animation/skeleton.h"
#include "runtime/function/framework/component/component.h"
#include "runtime/resource/res_type/components/animation.h"

namespace Zentia
{
    REFLECTION_TYPE(AnimationComponent)
    CLASS(AnimationComponent : public Component, WhiteListFields)
    {
        REFLECTION_BODY(AnimationComponent)

    public:
        AnimationComponent() = default;

        void postLoadResource(AActor* parent_object) override;

        void tick(float delta_time) override;

        const AnimationResult& getResult() const;

        const Skeleton& getSkeleton() const;

    protected:
        META(Enable)
        AnimationComponentRes m_animation_res;

        Skeleton m_skeleton;
    };
} // namespace Zentia
