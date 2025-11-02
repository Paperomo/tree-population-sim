#ifndef TEST_MOD_H
#define TEST_MOD_H
#include "scene/3d/mesh_instance_3d.h"
#include "scene/resources/mesh.h"
#include "scene/main/node.h"
#include "core/object/object.h"
#include "scene/resources/mesh.h"
#include <atomic>

//i have no mood to figure out how to make a mutex


class testMod: public Node3D 
{
    GDCLASS(testMod, Node3D);
    //define friend classes
    unsigned count=0;
    String my_name;
    Node3D my_class_child;
    bool setup;
    protected:
        //void _get_property_list (List< PropertyInfo > *p_list) const;
        static void _bind_methods();
        void _notification(int p_what);
        String get_me_ptr();
        void process(float delta_time);
        
    public:
        const char * notifs_2_string(int id);
        void _process_setup_mode(double delta);
    testMod();
    ~testMod();

};

#endif