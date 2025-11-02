#ifndef TREE_GEN_NODE_H
#define TREE_GEN_NODE_H
#include "scene/3d/mesh_instance_3d.h"
#include "scene/resources/mesh.h"
#include "scene/main/node.h"
#include "core/object/object.h"
#include "scene/resources/mesh.h"

class treeGenServer;
class treeGenServerInteractions;

class treeGenNode: public Node3D 
{
    GDCLASS(treeGenNode, Node3D);
    //define friend classes
    
    unsigned count=0;
    MeshInstance3D my_mesh;
    //MAKE CHILD WHEN CONSTRUCTED AND DESTRUCTED REMOVE CHILD??? NO THIS MAKES NO SENSE
    friend class treeGenServer;
    friend class treeGenServerInteractions;
    //i dont think i really need to do any custom creation
    //unsigned call_count;
    String my_name;
    public:
        void set_mesh(const Ref<Mesh> &p_mesh);
        Ref<Mesh> get_mesh() const;
    protected:
        //void _get_property_list (List< PropertyInfo > *p_list) const;
        static void _bind_methods();
        void _notification(int p_what);
        void _mesh_changed ();
        String get_me_ptr();
    public:
    treeGenNode();
    ~treeGenNode();

};

#endif