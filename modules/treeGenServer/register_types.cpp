#include "register_types.h"

#include "core/object/class_db.h"
#include "core/os/os.h"
#include "core/config/engine.h"

#include "treeGenServer.h"

static treeGenServer *tree_Gen_Server = NULL;


void initialize_treeGenServer_module(ModuleInitializationLevel p_level)
{
    switch(p_level)
    {
        case MODULE_INITIALIZATION_LEVEL_CORE:
            break;
        case MODULE_INITIALIZATION_LEVEL_SERVERS:
            {
                tree_Gen_Server = memnew(treeGenServer);
                tree_Gen_Server->init();
        //_tree_Gen_Server = memnew(_treeGenServer);
                ClassDB::register_class<treeGenServer>();
                Engine::Singleton tTS_singleton = Engine::Singleton("treeTestServer", treeGenServer::get_singleton());
                tTS_singleton.editor_only=true;
                Engine::get_singleton()->add_singleton(tTS_singleton);
            }
            break;
        case MODULE_INITIALIZATION_LEVEL_SCENE:
            break;
        case MODULE_INITIALIZATION_LEVEL_EDITOR:
            break;
        default:
            break;
    }
	if (p_level != MODULE_INITIALIZATION_LEVEL_SERVERS) {
        return;
    }
    //if(just_seeing_if_it_exists) print_line("THIS IS REGISTERED");
    //print_line("init was called");
    //if(MODULE_INITIALIZATION_LEVEL_EDITOR){}
    

    
    
}

void uninitialize_treeGenServer_module(ModuleInitializationLevel p_level){
    
    if (p_level != MODULE_INITIALIZATION_LEVEL_SERVERS)
    {
        return;
    }
    if (tree_Gen_Server)
    {
        tree_Gen_Server->finish();
        Engine::get_singleton()->remove_singleton("treeTestServer");
        memdelete(tree_Gen_Server);
        tree_Gen_Server=nullptr;
    }
}
