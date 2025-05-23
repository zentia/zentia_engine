#pragma once

#include "runtime/core/math/transform.h"

#include "runtime/function/framework/component/camera/camera_component.h"
#include "runtime/function/framework/object/object.h"

#include <vector>

namespace Zentia
{
    class Character
    {
        inline static const float s_camera_blend_time {0.3f};

    public:
        Character(std::shared_ptr<AActor> character_object);

        GObjectID getObjectID() const;
        void      setObject(std::shared_ptr<AActor> gobject);
        std::weak_ptr<AActor> getObject() const { return m_character_object; }

        void setPosition(const Vector3& position) { m_position = position; }
        void setRotation(const Quaternion& rotation) { m_rotation = rotation; }

        const Vector3&    getPosition() const { return m_position; }
        const Quaternion& getRotation() const { return m_rotation; }

        void tick(float delta_time);

    private:
        void toggleFreeCamera();

        Vector3    m_position;
        Quaternion m_rotation;

        std::shared_ptr<AActor> m_character_object;

        // hack for setting rotation frame buffer
        Quaternion m_rotation_buffer;
        bool       m_rotation_dirty {false};

        CameraMode m_original_camera_mode;
        bool       m_is_free_camera{false};
    };
} // namespace Zentia