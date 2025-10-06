#ifndef TREE_GEN_SERVER_INTERACTIONS_H
#define TREE_GEN_SERVER_INTERACTIONS_H
#pragma once
#include <atomic>
#include "core/object/object.h"
#include "scene/main/node.h"
#include "scene/main/scene_tree.h"
#include "core/os/thread.h"
#include "core/os/mutex.h"
#include "core/templates/list.h"
#include "core/templates/rid.h"
#include "servers/rendering_server.h"
#include "core/config/engine.h"
#include "core/variant/variant.h"
class treeGenServer;
class treeGenNode;
//let this be a singleton node
class treeGenServerServerInteractions: public Node
{
    GDCLASS(treeGenServerServerInteractions, Node);
    static treeGenServerServerInteractions * singleton;
    friend class treeGenServer;
    friend class treeGenNode;
    protected:
        static void _bind_methods();
        void _notification(int p_what);
    public:
        static bool create_singleton(SceneTree* st);
        static treeGenServerServerInteractions * get_singleton();
        treeGenServerServerInteractions();
        ~treeGenServerServerInteractions();
};
#endif