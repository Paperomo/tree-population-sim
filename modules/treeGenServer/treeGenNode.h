#ifndef TREE_GEN_NODE_H
#define TREE_GEN_NODE_H
#include "scene/3d/mesh_instance_3d.h"
#include "scene/resources/mesh.h"
#include "scene/main/node.h"
class treeGenServer;
class treeGenServerInteractions;

class treeGenNode: public MeshInstance3D 
{
    GDCLASS(treeGenNode, MeshInstance3D);
    //define friend classes
    friend class treeGenServer;
    friend class treeGenServerInteractions;
    //i dont think i really need to do any custom creation
    //unsigned call_count;
    unsigned count=0;
    
    protected:
        static void _bind_methods();
        void _notification(int p_what);
    
    treeGenNode();

};

#endif