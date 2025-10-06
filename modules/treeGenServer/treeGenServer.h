#ifndef TREE_GEN_SERVER_H
#define TREE_GEN_SERVER_H
#pragma once
#include <atomic>
#include "core/object/object.h"
#include "scene/main/node.h"
#include "core/os/thread.h"
#include "core/os/mutex.h"
#include "core/templates/list.h"
#include "core/templates/rid.h"
#include "servers/rendering_server.h"
#include "core/config/engine.h"
#include "core/variant/variant.h"
namespace mel
{
    enum engine_state
    {
        PROJECT_SELECT,
        EDITOR,
        PLAY
    };
};

class treeGenServerServerInteractions;

class treeGenServer: public Object {
    GDCLASS(treeGenServer, Object);
    
    static treeGenServer* singleton;
    static void thread_func(void *p_udata);

    private:
        static void linkUp();
        bool thread_exited;
        mutable bool exit_thread;
        Thread *thread;
        Mutex *mutex;
        mel::engine_state which_environment;
    public:
        friend class treeGenServerServerInteractions;
        static treeGenServer *get_singleton();
        Error init();
        void lock();
        void unlock();
        void finish();
        void notification_methods();
    protected:
        static void _bind_methods();
        void _notification(int p_what);
    private:
        uint64_t counter;

        //RID_Owner<InfiniteBus> bus_owner;
    //i have no idea where the rid is being defined.
        //Set<RID> buses;
        //void _emit_occupy_room(uint64_t room, RID rid);
    public:
        void connect_signals();
        //RID create_bus();
        Variant simple_output_test();
        //bool empty();
        //bool delete_bus(RID id);
        //void clear();
        void core_treegen_loop();
        int get_something() const;
        treeGenServer();
};

#endif